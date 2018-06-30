#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <vector>

class LaneDetector {
private:
	double img_size;
	double img_center;
	bool left_flag = false;  // 감지한 선의 왼쪽 경계 여부
	bool right_flag = false; // 오른쪽
	cv::Point right_b;  
	double right_m;          // y = m*x + b
	cv::Point left_b;
	double left_m;

public:
	cv::Mat deNoise(cv::Mat inputImage);      // 입력 잡음 제거를 위한 가우시안 블러링
	cv::Mat edgeDetector(cv::Mat img_noise);  // 에지 필터 적용
	cv::Mat mask(cv::Mat img_edges);          // ROI 영역 매스킹
	std::vector<cv::Vec4i> houghLines(cv::Mat img_mask);  // 매스킹 이미지 내에서 Hough 라인 감지
	std::vector<std::vector<cv::Vec4i> > lineSeparation(std::vector<cv::Vec4i> lines, cv::Mat img_edges);  // 우측, 좌측 선 분리
	std::vector<cv::Point> regression(std::vector<std::vector<cv::Vec4i> > left_right_lines, cv::Mat inputImage);  // 회귀 분석(적합) - Fitting
	std::string predictTurn();  // 소실점을 계산하여 차의 선회 여부 판정
	int plotLane(cv::Mat inputImage, std::vector<cv::Point> lane, std::string turn);  // 결과를 출력하고 예측
};

cv::Mat LaneDetector::deNoise(cv::Mat inputImage) {
		cv::Mat output;

		cv::GaussianBlur(inputImage, output, cv::Size(3, 3), 0, 0);

		return output;
}

cv::Mat LaneDetector::edgeDetector(cv::Mat img_noise) {
		cv::Mat output;
		cv::Mat kernel;
		cv::Point anchor;

		// GRAY 변환
		cv::cvtColor(img_noise, output, cv::COLOR_RGB2GRAY);
		// 임계치 적용
		cv::threshold(output, output, 140, 255, cv::THRESH_BINARY);

		anchor = cv::Point(-1, -1);
		kernel = cv::Mat(1, 3, CV_32F);
		kernel.at<float>(0, 0) = -1;
		kernel.at<float>(0, 1) = 0;
		kernel.at<float>(0, 2) = 1;

		// 엣지 획득
		cv::filter2D(output, output, -1, kernel, anchor, 0, cv::BORDER_DEFAULT);

		return output;
}

cv::Mat LaneDetector::mask(cv::Mat img_edges) {
		cv::Mat output;
		cv::Mat mask = cv::Mat::zeros(img_edges.size(), img_edges.type());

#if 0
		cv::Point pts[4] = {
				cv::Point(210, 720),
				cv::Point(550, 450),
				cv::Point(717, 450),
				cv::Point(1280, 720)
		};
#endif
		// 210 / 1280 ==>> x / 450, 73
		// 550 / 1280 ==>> x / 450, 193
		// 450 / 720  ==>> x / 300, 187
		// 717 / 1280 ==>> x / 450, 252
		cv::Point pts[4] = {
				cv::Point(73, 300),
				cv::Point(193, 187),
				cv::Point(252, 187),
				cv::Point(450, 300)
		};

		// 다각형 매스킹
		cv::fillConvexPoly(mask, pts, 4, cv::Scalar(255, 0, 0));
		// 엣지 이미지에 다각형 매스킹 씌우기
		cv::bitwise_and(img_edges, mask, output);

		return output;
}

std::vector<cv::Vec4i> LaneDetector::houghLines(cv::Mat img_mask) {
		std::vector<cv::Vec4i> line;

		// 허프 변환 기반으로 선을 찾아줌
		HoughLinesP(img_mask, line, 1, CV_PI/180, 20, 20, 30);

		return line;
}

std::vector<std::vector<cv::Vec4i> > LaneDetector::lineSeparation(std::vector<cv::Vec4i> lines, cv::Mat img_edges) {
		std::vector<std::vector<cv::Vec4i> > output(2);
		size_t j = 0;
		cv::Point ini;
		cv::Point fini;
		double slope_thresh = 0.3;
		std::vector<double> slopes;
		std::vector<cv::Vec4i> selected_lines;
		std::vector<cv::Vec4i> right_lines, left_lines;

		// 감지된 모든 선의 기울기 계산
		for (auto i : lines) {
				ini = cv::Point(i[0], i[1]);
				fini = cv::Point(i[2], i[3]);

				// 신호처리 베이스로 기울기 구하기: (y1 - y0) / (x1 - x0)
				double slope = (static_cast<double>(fini.y) - static_cast<double>(ini.y))/(static_cast<double>(fini.x) - static_cast<double>(ini.x) + 0.00001);

				// 심하게 수평이면 선을 버리고 그렇지 않다면 선과 기울기를 저장한다.
				if (std::abs(slope) > slope_thresh) {
						slopes.push_back(slope);
						selected_lines.push_back(i);
				}
		}

		// 우측, 좌측 선으로 분리한다.
		img_center = static_cast<double>((img_edges.cols / 2));
		while (j < selected_lines.size()) {
				ini = cv::Point(selected_lines[j][0], selected_lines[j][1]);
				fini = cv::Point(selected_lines[j][2], selected_lines[j][3]);

				// 우측, 좌측 분리 조건
				if (slopes[j] > 0 && fini.x > img_center && ini.x > img_center) {
						right_lines.push_back(selected_lines[j]);
						right_flag = true;
				} else if (slopes[j] < 0 && fini.x < img_center && ini.x < img_center) {
						left_lines.push_back(selected_lines[j]);
						left_flag = true;
				}
				j++;
		}

		output[0] = right_lines;
		output[1] = left_lines;

		return output;
}

std::vector<cv::Point> LaneDetector::regression(std::vector<std::vector<cv::Vec4i> > left_right_lines, cv::Mat inputImage) {
		std::vector<cv::Point> output(4);
		cv::Point ini;
		cv::Point fini;
		cv::Point ini2;
		cv::Point fini2;
		cv::Vec4d right_line;
		cv::Vec4d left_line;
		std::vector<cv::Point> right_pts;
		std::vector<cv::Point> left_pts;

		// 우측 선이 감지되면 초기점과 마지막 점으로 선을 맞춘다.
		if (right_flag == true) {
				for (auto i : left_right_lines[0]) {
						ini = cv::Point(i[0], i[1]);
						fini = cv::Point(i[2], i[3]);

						right_pts.push_back(ini);
						right_pts.push_back(fini);
				}

				if (right_pts.size() > 0) {
						// 우측 선 형성
						cv::fitLine(right_pts, right_line, CV_DIST_L2, 0, 0.01, 0.01);
						right_m = right_line[1] / right_line[0];
						right_b = cv::Point(right_line[2], right_line[3]);
				}
		}

		// 좌측 선에 대한 작업(우측과 동일)
		if (left_flag == true) {
				for (auto j : left_right_lines[1]) {
						ini2 = cv::Point(j[0], j[1]);
						fini2 = cv::Point(j[2], j[3]);

						left_pts.push_back(ini2);
						left_pts.push_back(fini2);
				}

				if (left_pts.size() > 0) {
						// 좌측 선 형성
						cv::fitLine(left_pts, left_line, CV_DIST_L2, 0, 0.01, 0.01);
						left_m = left_line[1] / left_line[0];
						left_b = cv::Point(left_line[2], left_line[3]);
				}
		}

		// 기울기와 오프셋 점을 얻은 후 직선의 방정식 적용
		int ini_y = inputImage.rows;
		int fin_y = 470;

		double right_ini_x = ((ini_y - right_b.y) / right_m) + right_b.x;
		double right_fin_x = ((fin_y - right_b.y) / right_m) + right_b.x;

		double left_ini_x = ((ini_y - left_b.y) / left_m) + left_b.x;
		double left_fin_x = ((fin_y - left_b.y) / left_m) + left_b.x;

		output[0] = cv::Point(right_ini_x, ini_y);
		output[1] = cv::Point(right_fin_x, fin_y);
		output[2] = cv::Point(left_ini_x, ini_y);
		output[3] = cv::Point(left_fin_x, fin_y);

		return output;
}

std::string LaneDetector::predictTurn() {
		std::string output;
		double vanish_x;
		double thr_vp = 10;

		// 소실점은 두 차선의 경계선이 교차하는 지점이다.
		vanish_x = static_cast<double>(((right_m*right_b.x) - (left_m*left_b.x) - right_b.y + left_b.y) / (right_m - left_m));

		// 소실점의 위치가 선회를 결정함
		if (vanish_x < (img_center - thr_vp))
				output = "Left Turn";
		else if (vanish_x > (img_center + thr_vp))
				output = "Right Turn";
		else if (vanish_x >= (img_center - thr_vp) && vanish_x <= (img_center + thr_vp))
				output = "Straight";

		return output;
}

int LaneDetector::plotLane(cv::Mat inputImage, std::vector<cv::Point> lane, std::string turn) {
		std::vector<cv::Point> poly_points;
		cv::Mat output;

		// 시각화를 위해 투명한 다각형 형성
		inputImage.copyTo(output);
		poly_points.push_back(lane[2]);
		poly_points.push_back(lane[0]);
		poly_points.push_back(lane[1]);
		poly_points.push_back(lane[3]);
		cv::fillConvexPoly(output, poly_points, cv::Scalar(0, 0, 255), CV_AA, 0);
		cv::addWeighted(output, 0.3, inputImage, 1.0 - 0.3, 0, inputImage);

		// 차선 경계의 두 선을 그린다.
		cv::line(inputImage, lane[0], lane[1], cv::Scalar(0, 255, 255), 5, CV_AA);
		cv::line(inputImage, lane[2], lane[3], cv::Scalar(0, 255, 255), 5, CV_AA);

		// 선회 메시지 출력
		cv::putText(inputImage, turn, cv::Point(50, 90), cv::FONT_HERSHEY_COMPLEX_SMALL, 3, cvScalar(0, 255, 0), 1, CV_AA);

		// 최종 결과물 출력
		cv::namedWindow("Lane", CV_WINDOW_AUTOSIZE);
		cv::imshow("Lane", inputImage);
		return 0;
}

int main(int argc, char *argv[]) {
		if (argc != 2) {
				std::cout << "Not enough parameters" << std::endl;
				return -1;
		}

		// 입력 인수는 동영상의 위치다.
		std::string source = argv[1];
		cv::VideoCapture cap(source);
		if (!cap.isOpened())
				return -1;

		LaneDetector lanedetector;
		cv::Mat frame;
		cv::Mat img_denoise;
		cv::Mat img_edges;
		cv::Mat img_mask;
		cv::Mat img_lines;
		std::vector<cv::Vec4i> lines;
		std::vector<std::vector<cv::Vec4i> > left_right_lines;
		std::vector<cv::Point> lane;
		std::string turn;
		int flag_plot = -1;
		int i = 0;

		// 주 알고리즘 시작 - 비디오의 모든 프레임에 대해 반복한다.
		while (i < 540) {
				// Frame 캡쳐
				if (!cap.read(frame))
						break;

				// 가우시안 필터(블러) 적용
				img_denoise = lanedetector.deNoise(frame);

				// 엣지 검출
				img_edges = lanedetector.edgeDetector(img_denoise);

				// ROI 매스킹
				img_mask = lanedetector.mask(img_edges);

				// 매스킹 이미지에서 허프 라인 획득
				lines = lanedetector.houghLines(img_mask);

				if (!lines.empty()) {
						// 우측, 좌측 선으로 분리
						left_right_lines = lanedetector.lineSeparation(lines, img_edges);

						// 차선을 얻기 위한 회귀 분석
						lane = lanedetector.regression(left_right_lines, frame);

						// 선의 소실점을 베이스로 선회를 판정
						turn = lanedetector.predictTurn();

						// 감지한 차선 출력
						flag_plot = lanedetector.plotLane(frame, lane, turn);

						i += 1;
						cv::waitKey(25);
				} else {
						flag_plot = -1;
				}
		}
		return flag_plot;
}

