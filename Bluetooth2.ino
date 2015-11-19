#define bit1 0
#define bit2 16
#define bit3 32
#define bit4 48
#define destinatario 'c'

bool start=1; // Indicador del comienzo de la transmision
char mensaje; // recibido desde bluetooth
int codF,codC; //codificacion fuente, codificacion canal
int i; // contador
void setup()
{  
  pinMode(2,OUTPUT);
  Serial.begin(9600);     
  digitalWrite(2,1);  // alto por defecto 
}

void loop()
{
  if (Serial.available()){
    mensaje=Serial.read();
    codF=codificacion_huffman(mensaje);    
    if(start){
      inicializacion();
    }
    transmitir(codF);
  }
  if(mensaje=='\n'){     // byte que indica el fin de una transmision
    start=1;   
  }
}

void inicializacion()
{
  int cod;   // codificacion de fuente de la bandera
  start=0; 
  cod=codificacion_huffman('a');
  transmitir(cod);
  transmitir(cod);
  transmitir(cod);
  transmitir(cod);
  transmitir(cod);
  delay(20);
  digitalWrite(2,0);
  delay(1);
  cod=codificacion_huffman(destinatario);
  transmitir(cod);
  transmitir(cod);
}
void transmitir(int trama)
{
  for(i=0;i<6;i++){
     digitalWrite(2,(trama&(1<<(5-i)))>>(5-i));  
     delay(1);
  }
}

int codificacion_huffman(char mensaje)
{
  int cod;
  switch (mensaje) 
  {
     case 'e': 
       cod=0+bit1;    
       break;
     case 'a': 
       cod=1+bit1;  
       break;
     case 'b':
       cod=0+bit2;
       break;
     case 'i':
       cod=1+bit2;
       break;
     case 'c':
       cod=2+bit2;
       break;
     case 'o':
       cod=3+bit2;
       break;
     case 'm':
       cod=0+bit3;
       break;
     case 'l':
       cod=1+bit3;
       break;
     case 'r':
       cod=2+bit3;
       break;
     case 'p':
       cod=3+bit3;
       break;
     case 's':
       cod=4+bit3;
       break;
     case 't':
       cod=5+bit3;
       break;
     case 'n':
       cod=6+bit3;
       break;
     case 'd':
       cod=7+bit3;
       break;
     case '\r':
       cod=0+bit4;
       break;
     case 'f':
       cod=1+bit4;
       break;
     case 'g':
       cod=2+bit4;
       break;
     case 'w':
       cod=3+bit4;
       break;
     case 'k':
       cod=4+bit4;
       break;
     case 'y':
       cod=5+bit4;
       break;
     case 'j':
       cod=6+bit4;
       break;
     case 'v':
       cod=7+bit4;
       break;
     case 'u':
       cod=8+bit4;
       break;
     case 'q':
       cod=9+bit4;
       break;
     case ' ':
       cod=10+bit4;
       break;
     case 'z':
       cod=11+bit4;
       break;
     case 'x':
       cod=12+bit4;
       break;
     case 164:   // sigue mostrando error
       cod=13+bit4;
       break;
     case 'h':
       cod=14+bit4;
       break;
     case '\n':
       cod=15+bit4;
       break;
     default:
       cod=10+bit4;  //si no es ninguna letra dentro de la codificacion huffman realizada, entrega un espacio
       break;      
   }
  return cod;
}

