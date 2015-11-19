int i; //contador
bool confirmacion=0;
char mensaje=0;
void setup() {
Serial.begin(9600);
pinMode(2, OUTPUT);
pinMode(3, INPUT);
}
void loop() {
  if(digitalRead(3)==0){   
    confirmacion=verificacion(); 
    if(confirmacion){
      do
      {
        mensaje=0;
        for(i=5;i>=0;i--){
          mensaje|=digitalRead(3)<<i;
          delay(1);     
        }
        Serial.println(mensaje,DEC);
      }while(mensaje!=63); 
    }
  mensaje=0;
  }
}

bool verificacion()
{
  bool conf1=0,conf2=0; //confirmacion 1 y 2
  delayMicroseconds(1500); 
  for(i=5;i>=0;i--){
    mensaje|=digitalRead(3)<<i;
    delay(1);
  }
  if(mensaje==18){
    conf1=1;
    Serial.print('\n');
  }
  mensaje=0;
  for(i=5;i>=0;i--){
      mensaje|=digitalRead(3)<<i;
      delay(1);
  }
  if(mensaje==18){
    conf2=1;
  }
  return conf1&conf2;
}
