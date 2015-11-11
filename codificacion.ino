int mensaje;
void setup()
{
  Serial.begin(9600);
  mensaje=codificacion_huffman('a');
}
void loop()
{
  Serial.println(mensaje);   
}

int codificacion_huffman(char mensaje)
{
  int cod=0;
  if(mensaje=='')
    cod=1; 
  if(mensaje=='')
    cod=1; 
  if(mensaje=='')
    cod=1; 
  if(mensaje=='')
    cod=1; 
  if(mensaje=='')
    cod=1; 
  if(mensaje=='')
    cod=1; 
  if(mensaje=='')
    cod=1; 
  if(mensaje=='')
    cod=1; 
  if(mensaje=='')
    cod=1; 
  if(mensaje=='')
    cod=1; 
  if(mensaje=='')
    cod=1; 
  if(mensaje=='')
    cod=1; 
  if(mensaje=='')
    cod=1; 
  if(mensaje=='')
    cod=1; 
  return cod;
}
