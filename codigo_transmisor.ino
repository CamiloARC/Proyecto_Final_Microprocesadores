void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(2,OUTPUT);
pinMode(3,INPUT);

}
int data=0,i=0;
bool buff[7];

void loop() {
  // put your main code here, to run repeatedly:

    if (Serial.available() > 0) {
                
                data = Serial.read();
          Serial.println(data,DEC);
          for(i=0;i<8;i++){

               digitalWrite(2,(data&(1<<(7-i)))>>(7-i));
              
              delay(100);
            
          }
                      

                for(i=0;i<8;i++){

               digitalWrite(2,(10&(1<<(7-i)))>>(7-i));
              
              delay(100);
            
          }
                
        }


//valor=float(port.readStringUntil('\n'))


}
