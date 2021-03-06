#define bit1 0
#define bit2 16
#define bit3 32
#define bit4 48

char mensaje;
int mensaje_cf,mensaje_cc;
int cod; //codificacion de huffman
void setup()
{
  Serial.begin(9600);
  mensaje_cf=codificacion_huffman('1');
}
void loop()
{
  delay(100);
  Serial.println(mensaje_cf,BIN);   
}

int codificacion_huffman(char mensaje)
{
  switch (mensaje) {
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
     case 164:
       cod=13+bit4;
       break;
     case 'h':
       cod=14+bit4;
       break;
     case '\n':
       cod=15+bit4;
       break;      
   }
  return cod;
}
