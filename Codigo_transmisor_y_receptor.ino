char usuario[7]="christ";
char destino[7]="camilo";
bool start=1; // Indicador del comienzo de la transmision
char mensaje_rx; // recibido desde modulo bluetooth HC-05
char mensaje_tx=0; // mensaje a transmitir con modulo 
int codF,codC; //codificacion fuente, codificacion canal
int decC,decF;  // decC =bits para realizarle la decodificacion de canal
bool confirmacion=0; //vble que indica si se debe recibir un paquete
int i,j,maximo=0; // contadores i,j , maximo es una variable utilizada para enviar un maximo de caracteres por el RF
void setup()
{  
  pinMode(2,OUTPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);     
  digitalWrite(2,1);  // alto por defecto 
}

void loop()
{
  if (Serial.available()){
    if(start){
      inicializacion();
    }
    mensaje_rx=Serial.read();
    codF=codificacion_huffman(mensaje_rx);    
    codC=codificacion_hamming(codF);
    transmitir(codC);
    if(mensaje_rx=='\n'){     // byte que indica el fin de una transmision
      start=1;   
    }
  }
  if((digitalRead(3)==0)&&(!Serial.available())){ 
    delayMicroseconds(1478);   //ajuste por demora procesando  
    confirmacion=verificacion(); 
    if(confirmacion){
      do
      {
        mensaje_tx=0;
        decC=recibir();
        decF=decodificacion_hamming(decC);
        mensaje_tx=decodificacion_huffman(decF);
        Serial.print(mensaje_tx);
        maximo++;
      }while((mensaje_tx!='\n')&&(maximo<63)); 
      maximo=0;
    }
  }
}

void inicializacion()
{
  int cod;  
  start=0; 
  cod=672;
  transmitir(cod);
  transmitir(cod);
  transmitir(cod);
  transmitir(cod);
  transmitir(cod);
  transmitir(cod);
  transmitir(cod);
  cod=673;
  transmitir(cod);
  delay(60);
  digitalWrite(2,0);
  delay(1);
  for(j=0;j<6;j++)
  {
    cod=codificacion_huffman(destino[j]);
    cod=codificacion_hamming(cod);
    transmitir(cod);
  }
}
bool verificacion()
{
  int dec=0;  // bits a decodificar
  char mensaje=0;
  int confirmacion=0;
  
  for(j=0;j<6;j++)
  {
    dec=recibir();
    dec=decodificacion_hamming(dec);
    mensaje=decodificacion_huffman(dec);
    if(mensaje==usuario[j]){
      confirmacion++;
    }
  }
  if(confirmacion==6)
    return 1;
  else
    return 0;
}
int recibir()
{
  int trama=0;
  for(i=9;i>=0;i--){
    trama|=digitalRead(3)<<i;
    delayMicroseconds(984);    //ajuste por demora procesando
  }  
  return trama;
}
void transmitir(int trama)
{
  for(i=0;i<10;i++){
     digitalWrite(2,(trama&(1<<(9-i)))>>(9-i));  
     delayMicroseconds(983); //ajuste por 1demora procesando
  }
}

int codificacion_huffman(char mensaje)
{
  int cod;
  switch (mensaje) 
  {
     case 'e': 
       cod=0;    
       break;
     case 'a': 
       cod=1;  
       break;
     case 'b':
       cod=16;
       break;
     case 'i':
       cod=17;
       break;
     case 'c':
       cod=18;
       break;
     case 'o':
       cod=19;
       break;
     case 'm':
       cod=32;
       break;
     case 'l':
       cod=33;
       break;
     case 'r':
       cod=34;
       break;
     case 'p':
       cod=35;
       break;
     case 's':
       cod=36;
       break;
     case 't':
       cod=37;
       break;
     case 'n':
       cod=38;
       break;
     case 'd':
       cod=39;
       break;
     case '\r':
       cod=48;
       break;
     case 'f':
       cod=49;
       break;
     case 'g':
       cod=50;
       break;
     case 'w':
       cod=51;
       break;
     case 'k':
       cod=52;
       break;
     case 'y':
       cod=53;
       break;
     case 'j':
       cod=54;
       break;
     case 'v':
       cod=55;
       break;
     case 'u':
       cod=56;
       break;
     case 'q':
       cod=57;
       break;
     case ' ':
       cod=58;
       break;
     case 'z':
       cod=59;
       break;
     case 'x':
       cod=60;
       break;
     case ',':   
       cod=61;
       break;
     case 'h':
       cod=62;
       break;
     case '\n':
       cod=63;
       break;
     default:
       cod=58;  //si no es ninguna letra dentro de la codificacion huffman realizada, entrega un espacio
       break;      
   }
  return cod;
}

char decodificacion_huffman(int cod)
{
  char dec;
  switch (cod) 
  {
     case 0: 
       dec='e';    
       break;
     case 1: 
       dec='a'; 
       break;
     case 16:
       dec='b';
       break;
     case 17:
       dec='i';
       break;
     case 18:
       dec='c';
       break;
     case 19:
       dec='o';
       break;
     case 32:
       dec='m';
       break;
     case 33:
       dec='l';
       break;
     case 34:
       dec='r';
       break;
     case 35:
       dec='p';
       break;
     case 36:
       dec='s';
       break;
     case 37:
       dec='t';
       break;
     case 38:
       dec='n';
       break;
     case 39:
       dec='d';
       break;
     case 48:
       dec='\r';
       break;
     case 49:
       dec='f';;
       break;
     case 50:
       dec='g';
       break;
     case 51:
       dec='w';
       break;
     case 52:
       dec='k';
       break;
     case 53:
       dec='y';
       break;
     case 54:
       dec='j';
       break;
     case 55:
       dec='v';
       break;
     case 56:
       dec='u';
       break;
     case 57:
       dec='q';
       break;
     case 58:
       dec=' ';
       break;
     case 59:
       dec='z';
       break;
     case 60:
       dec='x';
       break;
     case 61:
       dec=',';
       break;
     case 62:
       dec='h';
       break;
     case 63:
       dec='\n';
       break;
     default:
       dec=' ';  //si no es ninguna letra dentro de la codificacion huffman realizada, entrega un espacio
       break;      
   } 
   return dec;
}
int codificacion_hamming(int cod)
{
  char paridad=0;
  cod=(cod&(1<<0))+(cod&(1<<1))+(((cod&(1<<2))+(cod&(1<<3))+(cod&(1<<4)))<<1)+((cod&(1<<5))<<2);
  paridad=((cod&(1<<1))>>1)+((cod&(1<<3))>>3)+((cod&(1<<5))>>5)+((cod&(1<<7))>>7);  //paridad 1 bits 3,5,7,9
  if(paridad&1)   
    cod|=(1<<9);  
  paridad=0;
  paridad=(cod&1)+((cod&(1<<3))>>3)+((cod&(1<<4))>>4)+((cod&(1<<7))>>7); // paridad 2 bits 3,6,7,10
  if(paridad&1)   
    cod|=(1<<8); 
  paridad=0;
  paridad=((cod&(1<<3))>>3)+((cod&(1<<4))>>4)+((cod&(1<<5))>>5);  //paridad 3 bits 5 6 7
  if(paridad&1)   
    cod|=(1<<6);
  paridad=0;
  paridad=(cod&1)+((cod&(1<<1))>>1);   // paridad 4 bits 9 y 10
  if(paridad&1)   
    cod|=(1<<2);
  return cod;
}
int decodificacion_hamming(int mensaje)
{
  int dec;
  dec=(mensaje&(1<<0))+(mensaje&(1<<1))+(((mensaje&(1<<3))+(mensaje&(1<<4))+(mensaje&(1<<5)))>>1)+((mensaje&(1<<7))>>2);    
  return dec;
}

