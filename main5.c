//
// Created by Usuario on 28/5/2024.
//
/*
 * Ejercicio 5 – Control empleados
    Del reloj de marcación del personal de una empresa se obtienen los siguientes datos: número de
    día, ID del empleado y cantidad de horas extras que trabajó (número entero).
    Estos datos se vuelcan a una planilla donde están ordenados por día. Se sabe que todos los
    días que la empresa abrió hubo algún trabajador que hizo horas extras, y que en un mismo día
    no hubo dos empleados con igual cantidad de horas extras.
    Se requiere procesar esta información para obtener:
    Para cada día:
    ○ El ID del empleado que trabajó la mayor cantidad de horas extras.
    ○ El promedio de horas extras trabajadas (cantidad total de horas extras/cantidad
    total de personas que trabajaron extras).
    Para todo el período en estudio:
    ○ La cantidad de días que se trabajó.

 */
#define T 3
#include <stdio.h>
struct empleado{
    int idEmpleado;
    int dia;// El dia que ingresa el empleado
    int horasTrabajadas;

};
void ingresoDatos(struct empleado empleados[T]);
void procesoDatos(struct empleado empleados[T],int *idMayor, int *diasTrabajados,int *masHoras);
void salidaDatos(int *idMayor,int *masHoras, int *diasTrabajados);


int main()
{   printf("Ejercicio 5\n");
    struct empleado empleados[T];
    int idMayor;
    int masHoras;
    int diasTrabajados;
    ingresoDatos(empleados);
    procesoDatos(empleados,&idMayor,&diasTrabajados,&masHoras);
    salidaDatos(&idMayor,&masHoras,&diasTrabajados);
}

void ingresoDatos(struct empleado empleados[T]){
    int bandera=1,j=0,id,diaTrabajo,horasT,ultimaPosicion;
    printf("Funcion ingreso datos\n");
    while(bandera!=0 && j<T)
    {
        do {
            printf("Ingresa tu id de empleado(entero mayor a 0):");
            scanf(" %d",&id);
        } while (id<0);

        do {
            printf("Ingresa tu dia de trabajo(entero mayor a 0):\n");
            scanf(" %d",&diaTrabajo);
        } while (diaTrabajo<0);
        do {
            printf("Ingresa tus horas extras(entero mayor a 0):\n");
            scanf(" %d",&horasT);
        } while (horasT<0);
        empleados[j].idEmpleado=id;
        empleados[j].dia=diaTrabajo;
        empleados[j].horasTrabajadas=horasT;
        j++;
        if (j < T) {
            do {
                printf("Desea seguir ingresando empleados 1<-SI 0<-NO: ");
                scanf("%d", &bandera);
            } while (bandera != 1 && bandera != 0);
        }
        else {
            bandera = 0; // To ensure we do not ask for more input if the limit is reached
        }
    }

    if (j < T) {
        empleados[j].idEmpleado = 0; // Signal the end of the entered data
    }

}


void procesoDatos(struct empleado empleados[T],int *idMayor,int *diasTrabajados, int *masHoras)
{   printf("Funcion procesoDatos");
    *diasTrabajados=0,*masHoras=0,*idMayor=0;
    int i=0,bandera=1;
    do
    {
        (*diasTrabajados)++;
        if(bandera==1){
            *masHoras=empleados[0].horasTrabajadas;//Asigno el primer valor de horas del arreglo struct p/ poder comparar
            *idMayor=empleados[0].idEmpleado;
            bandera=0;
        }
        if(empleados[i].horasTrabajadas>*masHoras)
        {
            *idMayor=empleados[i].idEmpleado;
            *masHoras=empleados[i].horasTrabajadas;
        }
        i++;
    } while (empleados[i].idEmpleado!=0 && i<T);
}
void salidaDatos(int *idMayor,int *masHoras, int *diasTrabajados)
{
       printf("Funcion salida datos\n");
       printf("LO LOGRASTE RACHIDDDDDDDDDDDDDDDDDDDDDDDDD 8==================>\n");
       printf("El empleado de id %d tuvo la mayor cantidad de horas extras trabajadas %d\n",*idMayor,*masHoras);
       printf("Dias de trabajo:%d",*diasTrabajados);
}