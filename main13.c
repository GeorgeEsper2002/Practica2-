//
// Created by Usuario on 17/5/2024.
//

/*
 * Ejercicio 13 pacientes
 * En la guardia de un hospital ingresan pacientes todos los días durante una semana, y de cada
uno se tiene: número de documento, cobertura (O: Obra social - P: Prepaga), edad. A su vez, se
los clasifica según la prioridad de atención:
    Rojo: Atención inmediata - pacientes críticos.
    Naranja: Atención en menos de 10 minutos - pacientes graves o emergentes.
    Amarillo: Atención en un máximo de 60 minutos - urgencias comunes.
    Verde: Atención en menos de 120 minutos - urgencias menores.
    Azul: Demora máxima de 240 minutos - problemas no urgentes.
    Los datos se leen en orden de día (1 a 7), pero no se sabe cuántos pacientes ingresan cada día.
    Proponer un fin de datos conveniente para los datos de un día, y desarrollar un algoritmo para
    ingresar y procesar los datos, el que debería mostrar los siguientes resultados:
    Por día:
     El promedio de edades de los pacientes que ingresaron.
     Mostrar si ingresaron con cobertura por obra social, prepaga o iguales cantidades.
     x. La cantidad de pacientes por cada clasificación en atención. / Proporción sobre el
    total
    Con respecto a la semana completa:
     El número de documento, sexo y edad de la persona de mayor edad que haya
    ingresado.
     La cantidad total de pacientes ingresados.
    o ¿Qué día ingresaron más pacientes críticos o graves?
 */

#include <stdio.h>
#include <ctype.h>
#define T 1000
#define C 7
#define D 5

struct persona{
    int nroDoc;
    char cobertura;
    int edad;
    char prioridad;
};

struct prioridades
{
    char prioridad;
    float proporcional;
    int cantidad;
};
void ingresarDatos(struct persona pacientes[T][C]);
void procesoDatosDia(struct persona pacientes[T][C],int promedioEdadDia[C],char mayorCobertura[C],struct prioridades categorias[C][D]);
void procesoDatosSemana(struct persona pacientes[T][C]);
void salidaDatosDia(int promedioEdadDia[C], char mayorCobertura[C],struct prioridades categorias[C][D]);
void salidaDatosSemana(struct persona pacientes[T][C]);

void funcionA(struct persona pacientes[T][C],int promedioEdadDia[C]);
void funcionB(struct persona pacientes[T][C],char mayorCobertura[C]);
void funcionC(struct persona pacientes [T][C],struct prioridades categorias[C][D]);



int main(){

    struct persona pacientes[T][C];
    struct persona mayorEdad;
    struct prioridades categorias[C][D];
    int promedioEdadDia[C];
    char mayorCobertura[C]; // Llena el arreglo con P u O, si cantidad de p==o se llena con N
    printf("Programa Control Guardia Hospital\n");
    ingresarDatos(pacientes);
    procesoDatosDia(pacientes,promedioEdadDia,mayorCobertura,categorias);
    procesoDatosSemana(pacientes);
    salidaDatosDia(promedioEdadDia,mayorCobertura,categorias);
    salidaDatosSemana(pacientes);
    return 0;
}



void ingresarDatos(struct persona pacientes[T][C])
{
    int nroDoc,edad,j=0;
    char cob,prioridad;
    printf("Funcion Ingreso datos\n");
    for(int i=0;i<7;i++)
    {
        do
        {   if(nroDoc!=0)
            {
                do
                {
                    printf("Ingresa tu numero de documento:");
                    scanf(" %d",&nroDoc);

                }while(nroDoc<0);

                do
                {
                    printf("Ingresa tu cobertura O:Obrasocial P:Prepaga");
                    scanf(" %c",&cob);
                    cob= toupper(cob);

                }while(cob!='O' && cob!='P');

                do
                {
                    printf("Ingresa tu prioridad:");
                    scanf(" %c",&prioridad);
                    prioridad= toupper(prioridad);
                }while(prioridad!='R'&& prioridad!='N' && prioridad !='A' && prioridad!='V' && prioridad!='Z');

                do
                {
                    printf("Ingresa tu edad:");
                    scanf(" %d",&edad);

                }while(edad<0);
                pacientes[j][i].nroDoc=nroDoc;
                pacientes[j][i].cobertura=cob;
                pacientes[j][i].edad=edad;
                pacientes[j][i].prioridad=prioridad;
                j++;
            }// fin del if
            else
            {
                pacientes[j][i].nroDoc=nroDoc;//pone un 0 al final de los documentos
            }

        }while(nroDoc!=0);// sale del do while cuando no hay mas pacientes
    }// fin de for, cambio de dia
    return;
}


void procesoDatosDia(struct persona pacientes[T][C],int promedioEdadDia[C],char mayorCobertura[C],struct prioridades categorias[C][D])
{
        funcionA(pacientes, promedioEdadDia);
        funcionB(pacientes, mayorCobertura);
        funcionC(pacientes, categorias);

    return;
}
void procesoDatosSemana(struct persona pacientes[T][C])
{

}

void salidaDatosDia(int promedioEdadDia[C], char mayorCobertura[C], struct prioridades categorias[C][D])
{

}
void salidaDatosSemana(struct persona pacientes[T][C])
{

}

void funcionA(struct persona pacientes[T][C], int promedioEdadDia[C]){
    int j;
    int suma=0;
    printf("Funcion A promedio edad dia\n");
    for(int i=0;i<1000;i++)// iterar el arreglo struct
    {   j=0;
        while(pacientes[i][j].nroDoc!=0 && j<C)
        {
            suma+=pacientes[i][j].edad;
            j++;
        }
        promedioEdadDia[i]=suma/(j-1);
        suma=0;
    }



}

// Funcion que recopila por dia que cantidad de pacientes con X cobertura aparecieron
void funcionB(struct persona pacientes[T][C],char mayorCobertura[C])
{
    int totalObraSocial;
    int totalPrepaga;
    for(int i=0;i<C;i++)
    {   totalPrepaga=0;
        totalObraSocial=0;
        for(int j=0;j<T;j++)
        {
            if (pacientes[j][i].cobertura=='O')
            {
                totalObraSocial+=1;
            }
            else if(pacientes[j][i].cobertura=='P')
            {
                totalPrepaga+=1;
            }
        }
        if(totalObraSocial>totalPrepaga)
        {
            mayorCobertura[i]='O';
        }
        else if(totalObraSocial<totalPrepaga){
            mayorCobertura[i]='P';
        }
        else{
            mayorCobertura[i]='=';
        }
    }
   


}
// Funcion que calcula el proporcional de prioridades de atencion
/*
 *  Rojo: Atención inmediata - pacientes críticos.
    Naranja: Atención en menos de 10 minutos - pacientes graves o emergentes.
    Amarillo: Atención en un máximo de 60 minutos - urgencias comunes.
    Verde: Atención en menos de 120 minutos - urgencias menores.
    Azul: Demora máxima de 240 minutos - problemas no urgentes.
 */
void funcionC(struct persona pacientes [T][C],struct prioridades categorias[C][D])
{
    int cantidadPacientes;
    int j;
    int r=0/*Rojo*/,n=0/*Naranja*/,a=0/*Amarillo*/,v=0/*Verde*/,z=0/*Azul*/;
    for(int i=0;i<C;i++)//itera de 1 a 7
    {
        j=0;
        cantidadPacientes=0;
        while(pacientes[j][i].nroDoc!=0 && j<T)// itera hasta que encuentre un 0
        {
            cantidadPacientes++;
            j++;
        }

    }
    categorias[0][0].prioridad='R';
    categorias[1][1].prioridad='N';
    categorias[2][2].prioridad='A';
    categorias[3][3].prioridad='V';
    categorias[4][4].prioridad='Z';
    for(int i=0;i<C;i++)
    {
            for(int g=0;g<T;g++)
            {
                switch (pacientes[g][i].prioridad) 
                {
                    case 'R':
                        categorias[i][0].;
                        break;
                    case 'N':
                        n++;
                        break;
                    case 'A':
                        a++;
                        break;
                    case 'V':
                        v++;
                        break;
                    case 'Z':
                        z++;
                        break;
                }
            }
    }

    for (int i = 0; i < C; i++) 
    {
        for(int k=0;k<5;k++)
        {
            
        }    
    }
    
    
}