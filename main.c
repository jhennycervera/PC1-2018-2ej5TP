/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Jhenny Cervera Vargas(20182841)
 *
 * Created on 14 de abril de 2020, 16:48
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void ImprimirRep(double promEstadistica1, double porcEstadistica2, double promEstadistica3){
   printf("Resultados:\n");
   printf("Promedio de edades que prefieren los canales de 50 en adelante: %.2lf anhos\n", promEstadistica1);
   printf("Porcentaje de hombre menores de 12 años que ve mas de 3 horas de tv: %.1lf%%\n", porcEstadistica2);
   printf("Promedio de tiempo que ven la TV las mujeres entre 35 y 50 anhos: %.1lf horas\n", promEstadistica3);
   
}

void fPrefierenCanalesMayorA50(int canal,int anhos, int*sumaEdad, int*contPreferenciaCanal){
    if(canal>50){
        (*sumaEdad)+=anhos;
       (*contPreferenciaCanal)++;
    }
}
int fHombresVenTvMasTresHoras(int anhos,int tiempo){
    if(tiempo>3) return 1;
    return 0;
}

void fMujeresVenTvEntre35y50anhos( int *SumtiempoEstd3,int*contEstadis3,int anhos, int tiempo){
    if(anhos>35 && anhos<50){
        (*SumtiempoEstd3)+=tiempo;
        (*contEstadis3)++;
    }
}
int main(int argc, char** argv) {
    double promEstadistica1,porcEstadistica2,promEstadistica3;
    int sexo, canal, horai, horaf, anhos, sumaEdad=0, contPreferenciaCanal=0, contPersonas=0;
    int tiempo, contEstadist2=0, SumtiempoEstd3=0, contEstadis3=0;
    while(1){
        scanf("%d %d %d %d %d",  &sexo,  &anhos,&canal, &horai, &horaf);
        if(sexo== -1 && anhos==-1 && canal==-1 && horai==-1 && horaf==-1) break;
        
        tiempo=horaf-horai;
        fPrefierenCanalesMayorA50(canal,anhos,&sumaEdad, &contPreferenciaCanal);
        if(sexo==0) contEstadist2+=fHombresVenTvMasTresHoras(anhos,tiempo);
        if(sexo==1) fMujeresVenTvEntre35y50anhos(&SumtiempoEstd3,&contEstadis3,anhos,tiempo);
        contPersonas++;
    }
    promEstadistica1=(double)sumaEdad/contPreferenciaCanal;
    porcEstadistica2=contEstadist2*100/(double)contPersonas;
    promEstadistica3=SumtiempoEstd3/(double)contEstadis3;
    ImprimirRep( promEstadistica1,porcEstadistica2,promEstadistica3);
    
    
    return (EXIT_SUCCESS);
}

