#include "hamming.h"


int codificacion(int dato){

char data[5],datapp[10],i=0,cont=0,p1[5],p2[5],p4[4],p8[4];
int dato_pp=0;


for(i=0;i<6;i++){    //ciclo decimal a arreglo binario

    data[i]= ((1<<i)&(dato))>>i ;



}

printf("%d %d %d %d %d %d \n",data[5],data[4],data[3],data[2],data[1],data[0]);

for(i=0;i<10;i++){   // data + bits de paridad

	if( (i==2) || (i==6) || (i==8) || (i==9) ){

		datapp[i]='?';

		continue;

	}

	datapp[i]=data[cont];
	cont++;

}

//printf("%c %c %d %c %d %d %d %c %d %d\n",datapp[9],datapp[8],datapp[7],datapp[6],datapp[5],datapp[4],datapp[3],datapp[2],datapp[1],datapp[0]);


//paridad 1


cont=7;
for(i=0;i<4;i++){  //trama paridad 1

	p1[3-i]=datapp[cont];
	cont-=2;
}

//printf("p1:%d %d %d %d\n",p1[3],p1[2],p1[1],p1[0]);


cont=0;
for(i=0;i<4;i++){ //contador paridad

	if(p1[i]==1){

		cont++;
	}

}

printf("p1:%d\n",cont);
if(cont%2==0){

	datapp[9]=0;
}

else{
	datapp[9]=1;
}

//paridad 2

p2[0]=datapp[0];  //trama paridad 2
p2[1]=datapp[3];
p2[2]=datapp[4];
p2[3]=datapp[7];


cont=0;
for(i=0;i<4;i++){ //contador paridad

	if(p2[i]==1){

		cont++;
	}
}

if(cont%2==0){

	datapp[8]=0;
}

else{
	datapp[8]=1;
}
printf("p2:%d\n",cont);
//paridad 4

p4[0]=datapp[3];  //trama paridad 4
p4[1]=datapp[4];
p4[2]=datapp[5];


cont=0;
for(i=0;i<3;i++){ //contador paridad

	if(p4[i]==1){

		cont++;
	}
}


if(cont%2==0){

	datapp[6]=0;
}

else{
	datapp[6]=1;
}
printf("p4:%d\n",cont);
// paridad 8


p8[0]=datapp[0];   //trama paridad 8
p8[1]=datapp[1];

cont=0;
for(i=0;i<2;i++){ //contador paridad

	if(p8[i]==1){

		cont++;
	}
}

if(cont%2==0){

	datapp[2]=0;
}

else{
	datapp[2]=1;
}
printf("p8:%d\n",cont);


printf("%d %d %d %d %d %d %d %d %d %d\n",datapp[9],datapp[8],datapp[7],datapp[6],datapp[5],datapp[4],datapp[3],datapp[2],datapp[1],datapp[0]);


dato_pp=0;

for(i=0;i<10;i++){


dato_pp+=  (datapp[i])<<i;


}



return dato_pp;
}


int decodificacion(int dato_pp){

char data[5],datapp[10],i=0,cont=0,p1[5],p2[5],p4[4],p8[4],aux=0;
int dato=0;



for(i=0;i<10;i++){


datapp[i]=((1<<i)&dato_pp)>>i;


}

cont=9;
for(i=0;i<5;i++){  //trama paridad 1

	p1[4-i]=datapp[cont];
	cont-=2;
}

cont=0;
for(i=0;i<5;i++){ //contador paridad

	if(p1[i]==1){

		cont++;
	}

}
//printf("p1:%d \n",cont);

if(cont%2==0){

	aux+=0;
}

else{
	aux+=1;
}


//paridad 2

p2[0]=datapp[0];  //trama paridad 2
p2[1]=datapp[3];
p2[2]=datapp[4];
p2[3]=datapp[7];
p2[4]=datapp[8];



cont=0;
for(i=0;i<5;i++){ //contador paridad

	if(p2[i]==1){

		cont++;
	}
}
//printf("p2:%d \n",cont);

if(cont%2==0){

	aux+=0;
}

else{
	aux+=2;
}

//printf("aux:%d\n",aux);
//paridad 4

p4[0]=datapp[3];  //trama paridad 4
p4[1]=datapp[4];
p4[2]=datapp[5];
p4[3]=datapp[6];

cont=0;
for(i=0;i<4;i++){ //contador paridad

	if(p4[i]==1){

		cont++;
	}
}

//printf("p4:%d \n",cont);


if(cont%2==0){

	aux+=0;
}

else{
	aux+=4;
}
//printf("aux:%d\n",aux);
// paridad 8


p8[0]=datapp[0];   //trama paridad 8
p8[1]=datapp[1];
p8[2]=datapp[2];

cont=0;
for(i=0;i<3;i++){ //contador paridad

	if(p8[i]==1){

		cont++;
	}
}
//printf("p8:%d \n",cont);

if(cont%2==0){

	aux+=0;
}

else{
	aux+=8;
}

//printf("aux>>%d\n",aux);
//correcion de errores por medio del metodo de la sumatoria sigma delta


if( (aux>0) && (aux<11) ){

    datapp[-1*(aux-10)]^=1;

}

data[0]=datapp[0];
data[1]=datapp[1];
data[2]=datapp[3];
data[3]=datapp[4];
data[4]=datapp[5];
data[5]=datapp[7];



for(i=0;i<5;i++){

    dato|=(data[i])<<i;


}


return dato;
}
