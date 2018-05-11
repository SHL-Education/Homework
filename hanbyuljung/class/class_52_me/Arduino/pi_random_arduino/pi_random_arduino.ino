// 수치 미분

#include<Servo.h>

#define DT 50.0

Servo myservo;
// 정확도를. 위해 길게. 쓴다.
double pi = 3.1415926535897932384626433832795028841971693993751059209;

int theta = 0;      // 각도 의변화
double d_theta= 0.0;

double radian = 0.0;// 180/파이;
double omega =0.0;
double d_omega = 0.0; // 현재. 측정한. 오메가.-이전오메가.

double alpha = 0.0;
double velocity;
double acceleration;

double dt = DT /1000.0; // 0.05초
double time = 0.0;


void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    randomSeed(analogRead(0));
    myservo.attach(9);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  while(theta <180)
  {
    myservo.write(theta);
    delay(DT);

    Serial.print("Theta = ");
    Serial.println(theta);

    Serial.print("DTheta = ");
    Serial.println(d_theta);

    Serial.print("Radian = ");
    radian = (d_theta /360)*2*pi;
    Serial.println(radian);

    time += dt;

    Serial.print("Total Time = ");
    Serial.println(time);
    Serial.print("dt = ");
    Serial.println(dt);

    Serial.print("Omega = ");
    d_omega = (radian /dt) - omega;   //음수가 나올수있는데 torque 가바뀐다는 의미.
    omega = radian /dt;
    Serial.println(omega);

    Serial.print("DOmega = ");
    Serial.println(d_omega);
    
    Serial.print("Velocity = ");
    velocity = 0.01815 * omega ;
    Serial.println(velocity);

    Serial.print("Acceleration = ");
    acceleration = 0.01815 * omega *omega;
    Serial.println(acceleration, 10);   // 10진수 로출력해라.

    Serial.print("Alpha = ");
    alpha = d_omega /dt;    // d_omega 가'-'일수있어서 alpha 도 -일수있다.
    Serial.println(alpha);

    Serial.println();   // 개행문자.

    d_theta = random(1, 11);
    theta +=d_theta;
  }
  for(theta =180; theta >= 1; theta -= random(1,11))
  {
    myservo.write(theta);
    delay(DT);
  }
}
