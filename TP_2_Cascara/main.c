#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

EPersona personas[20];
InicializarVariables(personas);
int dni;
int contadorPersonas=0;
int main()
{
    char seguir='s';
    int opcion=0;
     int menos; int entre18y35; int mas; int i;

    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
darDeAlta(personas);
contadorPersonas++;

                break;
            case 2:
printf("\nIngrese dni :");
scanf("%d",&dni);
personas[buscarPorDni(personas,dni)].estado=2;
                break;
            case 3:
                ordenarNombres(personas,contadorPersonas);
                mostrarGente(personas,contadorPersonas);
                system("pause");
                break;
            case 4:
                  menos=0;  entre18y35=0;  mas=0;
                for(i=0;i<contadorPersonas;i++){
                    if(personas[i].edad<18){
                    menos++;
                    }else if(personas[i].edad>35){
                    mas++;
                    }else{
                    entre18y35++;
                    }
                }
                mostrarGrafico(menos,entre18y35,mas);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
