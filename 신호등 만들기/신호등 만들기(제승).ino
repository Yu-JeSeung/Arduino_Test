  // 자동차 신호등 및 보행자 신호등 변수
  int Rswt = 5;
  int Bswt=4;

void setup() {
  // put your setup code here, to run once:
  // 신호등 활성화
  for(int i = 7; i > 2; i--)
  {
    pinMode(i,1);
  }

  // 스위치 활성화
  pinMode(12,INPUT_PULLUP);

  // 스위치 시리얼 확인
  // Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  /* 스위치 확인
  Serial.println(sw);
  */

  // 스위치 값 변수로 받기
  int sw = digitalRead(12);

  // 자동차가 초록불이면 보행자는 빨간불
  digitalWrite(Rswt,HIGH);
  digitalWrite(Bswt,HIGH);
  if(sw == 0) // 스위치가 활성화 되면
  {
    for(int i = Rswt; i<8;i++) // 자동차 초록불 -> 빨간불
    {
      digitalWrite(i,HIGH);
      delay(500);
      digitalWrite(i,LOW);
    }
    digitalWrite(Bswt,LOW); // 보행자 초록불끄기
    Rswt = 7;
    Bswt = 3;
    digitalWrite(Rswt,HIGH);
    digitalWrite(Bswt,HIGH);
    delay(3000); // 3초 딜레이
    for(int i=0;i<5;i++) // 보행자 초록불 깜빡거리기
    {
      digitalWrite(Bswt,LOW);
      delay(300);
      digitalWrite(Bswt,HIGH);
      delay(300);
    }
    digitalWrite(Rswt,LOW);
    digitalWrite(Bswt,LOW);
    Rswt=5;
    Bswt=4;
  }

}
