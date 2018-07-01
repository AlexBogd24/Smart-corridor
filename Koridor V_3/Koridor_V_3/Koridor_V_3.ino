int PIR = 4;
int photorezist_pin = 1; //A1
int photorezist_data;
int photorezist_light = 100; // здесь настраивается значения с фото резистора ниже которого будет считаться темно
int mosfet = 3;
int light; //переменная для записи обратных значений с фото резистора (Напр: 255 = 0, 254 = 1)
int photorezist_min = 0; //минимальное значение с фото резистора
int photorezist_max = 1023; // максимальное значение с фото резистора
int t_on = 5;   // Пин для принудительного включения 
int t_auto = 6;   //Пин для приведения в авто режим
int t_off = 7;    //Пин для принудительного выключения


void setup() {
  // put your setup code here, to run once:
pinMode (PIR, INPUT);
pinMode(photorezist_pin, INPUT);
pinMode (mosfet, OUTPUT);
pinMode (t_on, INPUT);
pinMode (t_auto, INPUT);
pinMode (t_off, INPUT);
Serial.begin (9600);
Serial.println("I'm ready");


}

void loop() {
  photorezist_data = analogRead(photorezist_pin);
  Serial.println (analogRead(photorezist_pin));
  light = map (light, photorezist_min, photorezist_max, 255, 0);
  if(digitalRead(t_auto) == HIGH){
      while (digitalRead(PIR) == 1){
    analogWrite(mosfet, light);
     }
 }
  else if(digitalRead(t_on) == HIGH){
    analogWrite (mosfet, 255);
  }
  else if(digitalRead(t_off) == HIGH){
    analogWrite (mosfet, 0);
  }
}
