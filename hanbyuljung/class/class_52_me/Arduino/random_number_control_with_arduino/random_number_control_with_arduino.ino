
int randNumber;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Print Random Numbers 0~9");

  for(int i =0; i<20; i++)
  {
    randNumber = random(10);
    Serial.print(randNumber);
    Serial.print(" ");
  }

  Serial.println();
  Serial.println("Print Random Numbers 2~9");

  for(int i= 0; i<20; i++)
  {
    randNumber = random(2,10);
    Serial.print(randNumber);
    Serial.print(" ");
  }
  randomSeed(analogRead(0));
  Serial.println();
  Serial.println("Print Random Numbers 0~9");

  for(int i=0; i<20; i++)
  {
    randNumber = random(10);
    Serial.print(randNumber);
    Serial.print(" ");
    
  }
  Serial.println();
  Serial.println();
 
}

void loop() {
  // put your main code here, to run repeatedly:

}
