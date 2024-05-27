//
// Created by Usuario on 14/5/2024.
//
/*
 * Ejercicio 4 – Planta autopartes
Una planta que produce autopartes posee varias máquinas destinadas a la producción de
determinadas piezas. Se dispone de una planilla que, durante la última semana, se ha completado
manualmente. En la misma se anota:
●
●
●
Número de identificación de la máquina (número entero).
Tiempo de funcionamiento semanal (en horas, minutos y segundos).
Cantidad de piezas producidas (número entero).
Se desconoce la cantidad de máquinas que se encuentran trabajando actualmente.
 Se requiere procesar esta información tal que se determine:
●
 El rendimiento de cada máquina (cantidad de piezas/tiempo en segundos).
●
 La cantidad total de piezas producidas en la planta esa semana.
 */
#include <stdio.h>
#define T 1000 // Cantidad de maquinas limite
#define C 5// IdMaquina,TiempoFuncionamiento(segundos),minutos,horas,cantidad piezas producidas

void ingresoDatos(int maquinas[T][C]);
void procesoDatos(int maquinas[T][C],float rendimientos[T][2],int *totalPiezas);
void salidaDatos(float rendimientos[T][2],int *totalPiezas);




int main()
{
    int maquinas[T][C];
    float rendimientos[T][2]={0};// almacena los rendimientos de todas las maquinas
    int totalPiezas;
    ingresoDatos(maquinas);
    procesoDatos(maquinas,rendimientos,&totalPiezas);
    salidaDatos(rendimientos,&totalPiezas);
    return 0;
}

void ingresoDatos(int maquinas[T][C]){
    printf("Funcion Ingreso datos\n");
    maquinas[0][0]=1;
    int idMaquina,tiempoFuncionamiento,piezasProducidas,i=0,horas,minutos;
    do
    {
        if(maquinas[i][0]!=0)
        {
            do
            {
                printf("Ingresa el id de la maquina(0 para salir):\n");
                scanf(" %d",&idMaquina);

            }while(idMaquina<1);

            do {
                printf("Ingresa el tiempo de funcionamiento en Segundos de la maquina %d\n",idMaquina);
                scanf(" %d",&tiempoFuncionamiento);
                printf("Ingresa los minutos de funcionamiento:\n");
                scanf(" %d",&minutos);
                printf("Ingresa las horas de funcionamiento:\n");
                scanf(" %d",&horas);
            } while (tiempoFuncionamiento<1 && minutos<1 && horas<1);
            do {
                printf("Ingresa las piezas producidas de la maquina %d:\n",idMaquina);
                scanf(" %d",&piezasProducidas);
            } while (piezasProducidas<1);
            maquinas[i][0]=idMaquina;
            maquinas[i][1]=tiempoFuncionamiento;
            maquinas[i][2]=minutos;
            maquinas[i][3]=horas;
            maquinas[i][4]=piezasProducidas;
            i++;
        }
        else{
            maquinas[i][0]=0;
        }
    }while(maquinas[i][0]!=0 && i<T);// es por que no se la cantidad de maquinas que van a existir

}

void procesoDatos(int maquinas[T][C],float rendimientos[T][2],int *totalPiezas){
    printf("Funcion proceso datos\n");
    int j=0;
    *totalPiezas=0;
    while(maquinas[j][0]!=0 && j<T)
    {
        rendimientos[j][0]=(float)maquinas[j][0];
        rendimientos[j][1]=(float)maquinas[j][4]/((float)maquinas[j][1]+(float)maquinas[j][2]*60+(float)+(float)maquinas[j][3]/3600);
        *totalPiezas+=maquinas[j][4];
        j++;
    }

}

void salidaDatos(float rendimientos[T][2],int *totalPiezas) {
    printf("FUNCION SALIDA DATOS\n");
    int i;
    i = 0;
    while (rendimientos[i][0] != 0 && i < T) {
        printf("Maquina %d -> Rendimiento %.2f\n", (int) rendimientos[i][0], rendimientos[i][1]);
        i++;
    }
    printf("Piezas producidas %d",*totalPiezas);


}