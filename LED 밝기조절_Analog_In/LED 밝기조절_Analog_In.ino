void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // 조도 센서의 값을 받아오고 변수에 저장
  int ar = arnalog(A0); // 매개변수에 포트번호를 적는다
  // 어두워지면 센서값이 올라감
  // 대신 전압을 어떻게 설정해 주냐에 따라 센서에서 받아오는 값이 다를수 있다
  if(ar>900) 
  {
    digitalWrite(13,HIGH);
  }
  else if (ar<600)
  {
    digitalWrite(13,LOW);
  }
  Serial.println("analog value : "+(String)ar);
  delay(10);
}
