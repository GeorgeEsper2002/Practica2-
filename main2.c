//
// Created by Usuario on 23/4/2024.
//
/*Ejercicio 2 – Central telefónica
    Una central telefónica registra la duración de cada llamada, expresada en segundos.
    A partir de esta información se quiere convertir la duración de cada llamada a horas, minutos y
    segundos.
    Luego, al finalizar el ingreso de datos y el proceso de conversión, determinar:
    ●
    La cantidad de llamadas que superaron los 10 minutos.
    ●
    El promedio de duración de las llamadas (en segundos).
    ●
    La mínima duración de llamada (en segundos).
    No se sabe cuántas llamadas se han registrado, proponer un fin de datos.
 */


//SIN ARREGLOS
/*float llamadaTelefonica;
    int horas;
    int totalHoras=0;
    float totalLlamadas=0;
    int cantidadllamadas=0;
    int llamadas10min=0;
    int minutos;
    float segundos;
    float llamadaMinima;
    printf("Ejercicio 2\n");
    printf("Ingrese la duracion de tiempo de la llamada (en minutos):");
    scanf(" %d",&llamadaTelefonica);
    while(llamadaTelefonica!=0)
    {
        segundos=llamadaTelefonica;
        horas=((int)llamadaTelefonica/3600);
        totalHoras+=horas;
        minutos=llamadaTelefonica/60;
        if(minutos>10)
        {
            llamadas10min++;
        }
        if(llamadaMinima<segundos)
        {
            llamadaMinima=segundos;
        }
        totalLlamadas+=(float)minutos;
        cantidadllamadas++;
        printf("Ingresa otra llamada telefonica(EN SEGUNDOS):");
        scanf("%f",&llamadaTelefonica);
    }
    printf("La cantidad de llamadas menores a 10 min:%d\n",llamadas10min);
    printf("La llamada minima:%.2f\n",llamadaMinima);
    printf("El promedio de llamadas en segundos es:%.2f",(float)totalLlamadas/(float)cantidadllamadas);
    */
#include <stdio.h>
#include <math.h>
void ingresoDatos(int llamadas[1000]);
void procesoDatos(int llamadas[1000],int llamadasConvertidas[1000][3],int *llamada10min,int *llamadaMenor);
void SalidaDatos(int llamadasConvertidas[1000][3]);

int main()
{   printf("EJERCICIO 2 - CONVERSION DE LLAMADAS.");
    int llamadas[1000];
    int llamadaMenor;
    int llamada10min;
    int llamadasConvertidas[1000][3];
    ingresoDatos(llamadas);
    procesoDatos(llamadas, llamadasConvertidas, &llamada10min, &llamadaMenor);
    SalidaDatos(llamadasConvertidas);
    return 0;
}


void ingresoDatos(int llamadas[1000])
{
    int llamada;
    printf("Funcion Ingreso Datos:\n");
    for (int i = 0; i < 1000; ++i)
    {
        do
        {
            printf("Ingresa la duracion de la llamada %d",i+1);
            scanf(" %lf",&llamada);
        } while (llamada<=0.0);
        llamadas[i]=llamada;
    }
}

void procesoDatos(int llamadas[1000],int llamadasConvertidas[1000][3],int *llamada10min,int *llamadaMenor)
{
    printf("Funcion Proceso Datos:\n");
    for (int i = 0; i < 1000; ++i) // horas
    {
        llamadasConvertidas[i][0]= llamadas[i];//Segundos
        llamadasConvertidas[i][1]=floor(llamadas[i]/60);//Minutos
        llamadasConvertidas[i][2]=floor(llamadas[i]/3600);//Horas
    }

    for(int j=0;)
    {

    }
}