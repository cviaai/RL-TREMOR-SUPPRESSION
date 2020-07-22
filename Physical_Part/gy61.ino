// пины подключения x,y,z

const int pinX=A0;

const int pinY=A1;

const int pinZ=A2;

// переменные для хранения значений

unsigned int x, y, z;

bool allow = false;


 

void setup() {

   // запуск последовательного порта

   Serial.begin(9600);

}

 

void loop() {

   if (allow){
    for (int i = 0; i < 1000; i++){
       // получение данных
       x = analogRead(pinX);
       y = analogRead(pinY);
       z = analogRead(pinZ);
       // вывод в последовательный порт
       Serial.print(x);Serial.print(",");Serial.print(y);Serial.print(",");Serial.println(z);
       // пауза
       delay(0);
    }
    Serial.println(0);
    allow = false;
  }
}

void serialEvent() {
  while (Serial.available()){
    int incom = Serial.read() - '0';
    //delay(10);
    Serial.println(incom);
    if (incom == 0){
      allow = false;
      delay(100);
    }
    if (incom == 1){
      allow = true;
      delay(100);
    }
  }
}
