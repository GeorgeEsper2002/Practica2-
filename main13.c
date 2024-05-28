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
    char sexo;
    char cobertura;
    int edad;
    char prioridad;
};

struct prioridades
{
    float proporcional;
    int cantidad;
};
void ingresarDatos(struct persona pacientes[T][C]);
void procesoDatosDia(struct persona pacientes[T][C],int promedioEdadDia[C],char mayorCobertura[C],struct prioridades categorias[C][D]);
void procesoDatosSemana(struct persona pacientes[T][C],struct persona mayorEdad,int *totalPacientes,int *masCriticos,int *masGraves,int *ganador);
void salidaDatosDia(int promedioEdadDia[C], char mayorCobertura[C],struct prioridades categorias[C][D]);
void salidaDatosSemana(struct persona pacientes[T][C]);

void funcionA(struct persona pacientes[T][C],int promedioEdadDia[C]);
void funcionB(struct persona pacientes[T][C],char mayorCobertura[C]);
void funcionC(struct persona pacientes [T][C],struct prioridades categorias[C][D]);
void funcionD(struct persona pacientes[T][C],struct persona mayorEdad,int *totalPacientes);
void funcionE(struct persona pacientes[T][C],int *masCriticos,int *masGraves,int *ganador);


int main(){

    struct persona pacientes[T][C];
    struct persona mayorEdad;
    struct prioridades categorias[C][D];
    int promedioEdadDia[C];
    int ganador;
    int totalPacientes;
    int masCriticos;
    int masGraves;
    char mayorCobertura[C]; // Llena el arreglo con P u O, si cantidad de p==o se llena con N
    printf("Programa Control Guardia Hospital\n");
    ingresarDatos(pacientes);
    procesoDatosDia(pacientes,promedioEdadDia,mayorCobertura,categorias);
    procesoDatosSemana(pacientes,mayorEdad,&totalPacientes,&masCriticos,&masGraves,&ganador);
    salidaDatosDia(promedioEdadDia,mayorCobertura,categorias);
    salidaDatosSemana(pacientes);
    return 0;
}



void ingresarDatos(struct persona pacientes[T][C]){
    int nroDoc,edad,j=0;
    char cob,prioridad,sexo;
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
                    printf("Ingresa tu Sexo M/F:");
                    scanf(" %c",&sexo);
                    sexo= toupper(sexo);

                }while(sexo!='M'&& sexo!='F');


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
                pacientes[j][i].sexo=sexo;
                pacientes[j][i].cobertura=cob;
                pacientes[j][i].edad=edad;
                pacientes[j][i].prioridad=prioridad;
                j++;
            }// fin del if
            else
            {
                pacientes[j][i].nroDoc=nroDoc;//pone un 0 al final de los documentos
            }

        }while(pacientes[j][i].nroDoc!=0 && j<T);// sale del do while cuando no hay mas pacientes
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
void procesoDatosSemana(struct persona pacientes[T][C],struct persona mayorEdad,int *totalPacientes,int *masCriticos,int *masGraves,int *ganador)
{
    funcionD(pacientes,mayorEdad,totalPacientes);
    funcionE(pacientes,masCriticos,masGraves,ganador);
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
                totalObraSocial++;
            }
            else if(pacientes[j][i].cobertura=='P')
            {
                totalPrepaga++;
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
void funcionC(struct persona pacientes[T][C],struct prioridades categorias[C][D]){
    int cantidadPacientes=0;
    int j,g,n;
    int r=0/*Rojo*//*Naranja*/,a=0/*Amarillo*/,v=0/*Verde*/,z=0/*Azul*/;
    //Creo un acumulador para poder sacar los proporcionales
    for(int i=0;i<C;i++)
    {
        n=0;
        do{
            cantidadPacientes++;
            n++;
        } while (pacientes[n][i].nroDoc!=0 && n<T);
    }
    // Inicializo los acumuladores de pacientes atendidos en cada categoria
    for(int k=0;k<C;k++)
    {
        for(int h=0;h<D;h++)
        {
            categorias[k][h].cantidad=0;
        }
    }
  // Sumo los acumuladores de pacientes atendidos dependiendo la categoria de urgencia
    for(int i=0;i<C;i++)
    {       g=0;
            do
            {
                switch (pacientes[g][i].prioridad) 
                {
                    case 'R':
                        categorias[i][0].cantidad++;
                        break;
                    case 'N':
                        categorias[i][1].cantidad++;
                        break;
                    case 'A':
                        categorias[i][2].cantidad++;
                        break;
                    case 'V':
                        categorias[i][3].cantidad++;
                        break;
                    case 'Z':
                        categorias[i][4].cantidad++;
                        break;
                }
                g++;
            }while(pacientes[g][i].nroDoc!=0 && g<T);
    }
//Calcula los proporcionales
    for(int i=0;i<C;i++)
    {
        for(int x=0;x<D;x++)
        {
            categorias[i][x].proporcional=((float)categorias[i][x].cantidad/(float)cantidadPacientes);
        }
    }

}
// Funcion que busca la persona de mayor edad ingresada
void funcionD(struct persona pacientes[T][C],struct persona mayorEdad,int *totalPacientes){
    int j;
    *totalPacientes=0;
    mayorEdad.edad=1;
    for(int i=0;i<C;i++)
    {   j=0;
        do
        {
            if(pacientes[j][i].nroDoc!=0)
            {
                if(pacientes[j][i].edad>mayorEdad.edad)// compara las edades de todos los pacientes cargados
                {
                    mayorEdad.nroDoc=pacientes[j][i].nroDoc;
                    mayorEdad.edad=pacientes[j][i].edad;
                    mayorEdad.nroDoc=pacientes[j][i].nroDoc;
                    mayorEdad.sexo=pacientes[j][i].sexo;
                    mayorEdad.cobertura=pacientes[j][i].cobertura;
                    mayorEdad.prioridad=pacientes[j][i].prioridad;


                }
                *totalPacientes++;
            }
            j++;
        } while (pacientes[j][i].nroDoc!=0 && j<T);

    }


}
// Funcion que compara todos los dias quienes ingresaron en mayor cantidad si criticos o graves.
void funcionE(struct persona pacientes[T][C],int *masCriticos,int *masGraves, int *ganador)
{   int j;
    *masGraves=0;
    *masCriticos=0;
    for(int i=0;i<C;i++)
    {   j=0;
        do
        {
            if(pacientes[j][i].nroDoc!=0)
            {
                switch (pacientes[j][i].prioridad)
                {
                    case 'R':
                        *masCriticos++;
                        break;
                    case 'N':
                        *masGraves++;
                        break;
                }
            }
            j++;
        } while (pacientes[j][i].nroDoc!=0 && j<T);

    }

    if(*masCriticos>*masGraves){
        *ganador=1;
    }
    else if(*masCriticos<*masGraves){
        *ganador=2;
    }
    else
    {
        *ganador=0;
    }

}






