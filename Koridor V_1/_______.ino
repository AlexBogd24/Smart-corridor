int PIR = 4;
int photorezist_pin = 1; //A1
int photorezist_data;
int photorezist_light = 100; // здесь настраивается значения с фото резистора ниже которого будет считаться темно
int light = 255; // яркость света от 0 до 255
int mosfet = 3;




void setup() {
  // put your setup code here, to run once:
pinMode (PIR, INPUT);
pinMode(photorezist_pin, INPUT);
pinMode (mosfet, OUTPUT);
Serial.begin (9600);
Serial.println("I'm ready");
Serial.println (analogRead(photorezist_pin));
photorezist_data = analogRead(photorezist_pin);
}

void loop() {
  // put your main code here, to run repeatedly:
if (photorezist_data < photorezist_light)
{
  while(digitalRead (PIR) == 1)
  {
    analogWrite(mosfet, light);
  }
}

}
