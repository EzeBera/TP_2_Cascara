#include "funciones.h"
#include "stdio.h"


char *validarNombre();
int obtenerEspacioLibre(EPersona lista[]){
int resultado= -1;
short int i;

for(i=0;i<20;i++){


    if(lista[i].estado==0){

        resultado = i;
        break;
    }


}
return resultado;

}

int buscarPorDni(EPersona lista[], int dni){

int i;
int resultado=-1;


for(i=0;i<20;i++){


    if(lista[i].dni==dni){

        resultado = i;
        break;
    }

}
return resultado;

}


int borrarPersona(int dni, EPersona personas[]){
printf("/nIngrese el dni a borrar /n");
VariablesACero( personas,buscarPorDni(personas, dni));




}


void VariablesACero(EPersona lista[], int i){

        strcpy(lista[i].nombre, "\0");
        lista[i].dni = 0;
        lista[i].edad = 0;
        lista[i].estado = 0;


}


void InicializarVariables(EPersona lista[]){
short int i;

for(i=0;i<20;i++){

VariablesACero(lista,i);
}}


void darDeAlta(EPersona lista[])
{
    int x, i, enc = 0;
    long int auxDni;
    char auxNombre[50];

   int posicion = obtenerEspacioLibre(lista);

    if(posicion != -1)
    {
        printf("  INGRESE DATOS: \n");

        printf("\n  Ingrese DNI entre 1000000, 90000000 : ");
        auxDni = validarInt(10000000, 99999999);

        for(x = 0; x < 20; x++)
        {
            if(auxDni == lista[x].dni)
            {
                enc = 1;
                break;
            }
        }

        if(!enc)
		{
            lista[posicion].dni = auxDni;

strcpy(auxNombre,validarNombre());


            strcpy(lista[posicion].nombre, auxNombre);

            printf("\n  Ingrese edad: ");
            lista[posicion].edad = validarInt(1, 99);

            lista[posicion].estado = 1;

		}

		else
		{
			printf("\n  El DNI ingresado ya existe, ingrese otro.  \n\n");
			system("pause");
			system("cls");
		}


    }

    else
    {
        printf("\n  no hay mas espacio \n\n\n");
        system("pause");
    }

}
int validarInt(int min, int max){


 int lectura;
    scanf("%d",&lectura);

    while(lectura > max || lectura < min )
    {
        printf("\n El numero debe ser entre 0 y 20");
        scanf("%d", &lectura);
    }

return lectura;


}

char *validarNombre(){
    int x;
    char *ADC=(char*)malloc(sizeof(char)*50);
 char auxNombre[50];
		    printf("\n  Ingrese nombre: ");
		    fflush(stdin);
            gets(auxNombre);

            while(strlen(auxNombre) > 49)
            {
                printf("\n  ERROR, puede ingresar hasta 49 caracteres: ");
                fflush(stdin);
                gets(auxNombre);
            }

            strlwr(auxNombre);

            for( x = 0; x < 50; x++)
            {

                    auxNombre [x] = toupper(auxNombre[x]);

            }
strcpy(ADC, auxNombre);
return ADC;

}


void ordenarNombres(EPersona lista[],int total){
EPersona aux;
int i,j;
for(i=0;i<total-1;i++){
        for(j=i;j<total;j++){

   if(strcmp(lista[i].nombre,lista[j].nombre)){

        aux=lista[i];
        lista[i]=lista[j];
        lista[j]=aux;
    }
}}
}

void mostrarGente(EPersona gente[], int total){
int i;
for(i=0;i<total;i++){
    printf("dni %d nombre %s edad %d \n", gente[i].dni, gente[i].nombre, gente[i].edad);



}


}


void mostrarGrafico(int hasta18,int de19a35,int mayorDe35){
    int i, flag=0, mayor;

    if(hasta18 >= de19a35 && hasta18 >= mayorDe35){
        mayor = hasta18;
    }else{
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else{
        mayor = mayorDe35;
        }
    }

    for(i=mayor; i>0; i--){
        if(i<10){
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= hasta18){
            printf("*");
        }
        if(i<= de19a35){
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d", hasta18, de19a35, mayorDe35);





}
