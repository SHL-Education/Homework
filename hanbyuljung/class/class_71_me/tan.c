#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/freeglut.h>

void originAxis(void);
void tanWave(void);
void idle(void);

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	originAxis();	// 축 설정.
	tanWave();	// 사이파장. 파장은 v=f*λ  ,  c=f*λ

	//printf("%s\n", gluErrorString(glGetError()));
	glutSwapBuffers();	// 전면 버퍼와 후면 버퍼를 바꾼다.
}

void tanWave(void)
{
	float wavelength = 2;	//주기
	float amplitude = 1;	//진폭
	float inc = 0.01;	//각주파수 = 증가폭(샘플링 주기)
	float k, x, y;
	glBegin(GL_LINES);
	glColor3f(1,1,1);
	for(x=-1;x<=1;x+=inc){
		k = 2 * 3.14 / wavelength;	// 2πf
		y = amplitude * tan(k * x);
		glVertex3f(x, y, 0);
	}
	glEnd();

}

void idle(void)
{
	float wavelength = 2;
	float amplitude = 1;
	float inc = 0.01;
	float k, x, y;
	for (x = -1; x <= 1; x += inc){
		glBegin(GL_POINTS);
		glPointSize(200);
		glColor3f(0, 1, 0);
		k = 2 * 3.14 / wavelength;
		y = amplitude * tan(k * x);
		glVertex3f(x, y, 0);
		glEnd();
	}

	glutPostRedisplay();
}

void originAxis(void)
{
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex3f(0,0,0);
	glVertex3f(10, 0, 0);
	glColor3f(0,1,0);
	glVertex3f(0,0,0);
	glVertex3f(0, 10, 0);
	glColor3f(0,0,1);
	glVertex3f(0,0,0);
	glVertex3f(0, 0, 10);
	glEnd();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);	//openGL의 초기값을 설정.내장그래픽 세팅
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	// RGD 색을 쓰기 위한 옵션.
	// double에서 back buffer에서 미리 그림을 그리고 1:모니터가 그 후에 그리는 모드이다.
	// depth는 2D 시스템에서 3D를 구현하기 위해 필요한 옵션.
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tutorial 2"); // 만든 윈도우 창의 제목 설정.

	glOrtho(-4, 4, -4, 4, -4, 4); // 원점을 기준으로 1,1,1,1,육각형을 만듬
	glEnable(GL_DEPTH_TEST); // 모니터안에 깊이값을 설정해준다.

	glutDisplayFunc(display); // 이제 화면에 뿌려.
	glutIdleFunc(idle); // 일반적인 상황에서 아이들이 돌아가라.
	glutMainLoop(); // while문인것 같다.

	return EXIT_SUCCESS;
}
