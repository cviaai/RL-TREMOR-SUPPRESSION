byte ena = 3;
byte in1 = 4;
byte in2 = 5;
void setup() {
    Serial.begin(9600); 
    pinMode( ena, OUTPUT );
    pinMode( in1, OUTPUT );
    pinMode( in2, OUTPUT );
}
void loop() {
  if (Serial.available()) { 
    int speed = Serial.parseInt();
    Serial.print(speed);Serial.print("\n");
    if (speed >= 0 && speed <= 255) {
      analogWrite( ena, speed );
      digitalWrite( in1, HIGH );
      digitalWrite( in2, LOW );
    }
    if (speed >= 256 && speed <= 511) {
      analogWrite( ena, speed - 256 );
      digitalWrite( in1, LOW );
      digitalWrite( in2, HIGH );
    }
    // выставляем 100% мощность на моторе А - 255 из 255
    //analogWrite( ena, 255 );
    // выставляем режим мотора - вращение по часовой
    //digitalWrite( in1, HIGH );
    //digitalWrite( in2, LOW );
    //delay(3000); // пауза 3сек

    // выставляем мощность на мотора А - 150 из 255
   // analogWrite( ena, 150 );
    // режим мотора - вращение против часовой
    //digitalWrite( in1, LOW );
    //digitalWrite( in2, HIGH );
    //delay(3000); // пауза 3сек
}
}
