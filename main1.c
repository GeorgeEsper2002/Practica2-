/*
 * Ejercicio 1 – Socios Clubes
    Luego de recabar datos de los socios en cada uno de los 17 clubes más importantes de la ciudad
    se quiere determinar, para cada una de ellos, entre los censados mayores de edad (tienen 18
    años o más) quienes son más numerosos, los que son temporales (código 1) o los que son
    permanentes (código 2).
    Para resolver esto se dispone, por cada socio de cada uno de los clubes, su código de asociado
    (1 para temporal, 2 para permanente) y edad. Ver ejemplo.
    Un código de asociado 0 (cero) indica que no hay más datos de ese club.
    Valide el código entre 0, 1 y 2; no permita otros valores.
    Validar la edad que no sea negativa y reconfirme si es mayor a 100.
 */
/* SIN ARREGLOS
 * int main()
{
    int cantidadPermanentes=0;
    int cantidadTemporales=0;
    char confirmacion;
    int codigoAsociado;
    int grupoMayor;
    int edad;
    for(int i=1;i<=3;i++)
    {   do
        {
            printf("Ingresa tu codigo de asociado(0 para finalizar):\n");
            scanf(" %d",&codigoAsociado);
        }while(!(codigoAsociado>=0 && codigoAsociado<=2));
        while(codigoAsociado!=0)
        {   printf("Estoy en el 2do while.");
            if(codigoAsociado==1)
            {
                printf("Ingresa tu edad:\n");
                scanf(" %d",&edad);

                if(edad>=100)
                {   do
                    {
                        printf("Estas seguro que deseas ingresar %d como edad [S/N]:\n", edad);
                        scanf(" %c", &confirmacion);
                        confirmacion= toupper(confirmacion);
                        if (confirmacion == 'S') {
                            edad = edad;
                        } else {
                            do{
                                printf("Reingresa la edad:\n");
                                scanf(" %d", &edad);//meter do while
                            } while (edad<0);
                        }
                    }while(confirmacion!='S'&& confirmacion!='N');
                    cantidadTemporales++;
                }
                else if(edad>18)
                {
                    cantidadTemporales++;
                }
                else if(edad<0)
                {   //Itera hasta que se ingrese un numero positivo
                    do{
                        printf("Has ingresado un numero negativo!!!\n");
                        printf("Reingresa tu edad:");
                        scanf(" %d",&edad);//meter do while
                    }while(edad<0);
                    cantidadTemporales++;
                }


            }
            else if(codigoAsociado==2)
            {
                printf("Ingresa tu edad:");
                scanf(" %d",&edad);
                if(edad<0)
                {
                    do{
                        printf("Has ingresado un numero negativo!!!\n");
                        printf("Reingresa tu edad:");
                        scanf(" %d",&edad);//meter do while
                    }while(edad<0);

                }
                if(edad>=100)
                {
                    do
                    {
                        printf("Estas seguro que deseas ingresar %d como edad [S/N]:\n", edad);
                        scanf(" %c", &confirmacion);
                        confirmacion= toupper(confirmacion);
                        if (confirmacion == 'S') {
                            edad = edad;
                        } else {
                            do
                            {
                                printf("Reingresa la edad:\n");
                                scanf(" %d", &edad);//meter do while
                            } while (edad<0);
                        }
                    }while(confirmacion!='S'&& confirmacion!='N');
                    cantidadPermanentes++;
                }
                if(edad>18)
                {
                    cantidadPermanentes++;
                }

            }
            if(cantidadPermanentes>cantidadTemporales)
            {
                 grupoMayor=cantidadPermanentes;
            }
            else
            {
                grupoMayor=cantidadTemporales;
            }
            do
            {
                printf("Ingresa tu codigo de asociado:");
                scanf(" %d",&codigoAsociado);
            } while (!(codigoAsociado>=0&&codigoAsociado<=2));

        }
        printf("El grupo %d es mas numeroso del club %d\n",grupoMayor,i);
    }



    return 0;
}*/
// Con arreglos
#include <stdio.h>
#include <ctype.h>
#define TotalSocios  1000
#define codigos 2
#define clubes  17

void ingresoDatos(int socios[clubes][TotalSocios][codigos]);
void procesoDatos(int socios[clubes][TotalSocios][codigos],int resultado[17]);
void mostrarDatos(int resultado[17]);
int main()
{
    int socios[clubes][TotalSocios][codigos];
    int resultado[17];
    ingresoDatos(socios);
    procesoDatos(socios,resultado);
    mostrarDatos(resultado);
    return 0;
}



void ingresoDatos(int socios[clubes][TotalSocios][codigos])
{   printf("Funcion Ingreso datos:\n");
    int codigoSocio;
    int codigo;
    int edad;
    char confirmacion;

    for(int i=0;i<clubes;i++)
    {
        for(int j=0;j<TotalSocios;j++)
        {
            do{
                printf("Ingresa la edad del socio %d:\n",j+1);
                scanf(" %d",&edad);
                if(edad>=100)
                {
                    do {
                        printf("Estas seguro de que deseas ingresar esa edad?:\n");
                        scanf(" %c",&confirmacion);
                        if(confirmacion=='N')
                        {
                            printf("ReIngresa tu edad:\n");
                            scanf(" %d",&edad);
                        }
                    } while (confirmacion!='S'&&confirmacion!='N');
                }
            } while(edad>0 && edad<100);
            do
           {
                printf("Ingresa el codigo de socio del club %d:\n",i+1);
                scanf(" %d",&codigoSocio);
           } while (codigoSocio>0 && codigoSocio<2);
            socios[i][j][0]=codigoSocio;
            socios[i][j][1]=edad;

        }
    }

}

void procesoDatos(int socios[clubes][TotalSocios][codigos],int resultado[17])
{   int masTemporales;
    int masPermanentes;
    int ganador;
    printf("Funcion Proceso Datos:\n");
    for(int i=0;i<clubes;i++)
    {
        masTemporales=0;
        masPermanentes=0;
        for(int j=0;j<TotalSocios;j++)
        {
            if(socios[i][j][1]>18 && socios[i][j][0]==1)//Temporal
            {
                masTemporales++;
            }
            else if(socios[i][j][1]>18 && socios[i][j][0]==2)//Permanente
            {
                masPermanentes++;
            }
        }
        if(masTemporales>masPermanentes)
        {
            ganador=1;
            resultado[i]=ganador;
        }
        else if(masPermanentes>masTemporales)
        {
            ganador=2;
            resultado[i]=ganador;
        }


    }
}

void mostrarDatos(int resultados[17]) {
    printf("Funcion Mostrar Datos:\n");
    for (int k=0;k<17;k++)
    {
       printf("Mas numeroso -> Club:%d/Categoria:%d",k+1,resultados[k]);
    }



}