//rotation physics with arduino

#include <Servo.h>
#define DT 100.0
#define DTHETA 20.0 //20도 씩 돌아간다는 뜻이다. ->> 1/9파이.

Servo myservo;

int theta =0;

double omega;   // 각속도.(rad/sec)인데 (도/sec)로 되어 있음
double alpha;   // 각가속도.
double velocity;  // 속도.
double acceleration;  // 가속도.
double dt = DT /1000.0; // 0.1초
double time = 0.0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println((double)(DTHETA/(500.0/1000.0)));  //40
  for(theta =0;theta <180;theta += DTHETA)
  {
    myservo.write(theta);
    delay(DT);
    Serial.print("Theta = ");
    Serial.println(theta);
    Serial.print("DTheta = ");
    Serial.println(DTHETA);
    time += dt;
    Serial.print("Total Time = ");
    Serial.print(time);
    Serial.print(" dt= ");
    Serial.print(dt);
    Serial.print(" Omega = ");
    Serial.println((double)(DTHETA)/dt);
    Serial.println();
    //delay(1500);
  }
  for(theta = 180; theta >= 1; theta -= DTHETA)
  {
    myservo.write(theta);
    delay(DT);
  }

}
