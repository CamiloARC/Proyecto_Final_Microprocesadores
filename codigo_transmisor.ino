int data,i;
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3,INPUT);
}
void loop() {
  if (Serial.available() > 0){
    data = Serial.read();
    Serial.println(data,DEC);
    for(i=0;i<8;i++){
      digitalWrite(2,(data&(1<<(7-i)))>>(7-i));
      delay(100);
    }
  }
}
