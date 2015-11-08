char mensaje=0;
void setup() {
Serial.begin(9600);
pinMode(2, OUTPUT);
pinMode(3, INPUT);
}
void loop() {
  for(int i=7;i>=0;i--)
  {
    delay(100);
    mensaje|=digitalRead(3)<<i;
  }
  Serial.println(mensaje);
  mensaje=0;
}
