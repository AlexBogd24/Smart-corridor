int PIR = 4;
int photorezist_pin = 1; //A1
int photorezist_data;
int photorezist_light = 100; // здесь настраивается значения с фото резистора ниже которого будет считаться темно
/*
 * int photorezist_light = 100; // здесь настраивается значения с фото резистора ниже которого будет считаться темно
 * int light_for_dark = 255; // яркость света от 0 до 255 для тёмного времени суток(ночи)
 * int light_for_mid = 255; // яркость света от 0 до 255 для средней яркости естественного освещения
 * int light_for_mid = 255; // яркость света от 0 до 255 для яркого естественного освещения
*/
int mosfet = 3;
int light; //переменная для записи обратных значений с фото резистора (Напр: 255 = 0, 254 = 1)
int photorezist_min = 0; //минимальное значение с фото резистора
int photorezist_max = 1023; // максимальное значение с фото резистора


void setup() {
  // put your setup code here, to run once:
pinMode (PIR, INPUT);
pinMode(photorezist_pin, INPUT);
pinMode (mosfet, OUTPUT);
Serial.begin (9600);
Serial.println("I'm ready");


}

void loop() {
  photorezist_data = analogRead(photorezist_pin);
  Serial.println (analogRead(photorezist_pin));
  light = map (light,photorezist_min, photorezist_max, 255, 0);
  while (digitalRead(PIR) == 1){
    analogWrite(mosfet, light);
  }
  
}

