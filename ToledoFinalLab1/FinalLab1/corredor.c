#include "corredor.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>


eParticipantes* corredor_new()
{

    eParticipantes* newParticipante = (eParticipantes*) malloc(sizeof(eParticipantes));

    if (newParticipante != NULL)
    {
        newParticipante->id_cuatri = 0;
        strcpy(newParticipante->nombre," ");
        strcpy(newParticipante->categoria," ");
        newParticipante->promedio = 0;
        newParticipante->tiempo = 0;

    }

    return newParticipante;

}


eParticipantes* corredor_newParametros(char* idStr,char* nombreStr,char* categoriaStr,char* promedioStr,char* tiempoStr)
{


    eParticipantes* nuevoCorredor = corredor_new();

    if (nuevoCorredor != NULL)
    {

        corredorSetId(nuevoCorredor,atoi(idStr));
        corredorSetNombre(nuevoCorredor,nombreStr);
        corredorSetCategoria(nuevoCorredor,categoriaStr);
        corredorSetPromedio(nuevoCorredor,atof(promedioStr));
        corredorSetTiempo(nuevoCorredor,atof(tiempoStr));

    }

    return nuevoCorredor;
}

int corredorSetId( eParticipantes* corredor, int id)
{

    int todoOk=1;
    if( corredor!=NULL && id >= 0)
    {

        corredor->id_cuatri=id;
        todoOk=0;
    }


    return todoOk;

}




int corredorGetId( eParticipantes* corredor, int* id )
{

    int todoOk=1;

    if( corredor!=NULL && id != NULL)
    {

        *id=corredor->id_cuatri;
        todoOk=0;
    }


    return todoOk;

}



int corredorSetNombre( eParticipantes* corredor, char* nombre)
{


    int todoOk=1;
    if( corredor!=NULL && nombre!=NULL  )
    {

        strcpy(corredor->nombre,nombre);
        todoOk=0;
    }


    return todoOk;

}


int corredorGetNombre( eParticipantes* corredor, char* nombre)
{
    int todoOk=1;

    if(corredor!=NULL && nombre !=NULL){

        strcpy(nombre, corredor->nombre);
        todoOk=0;

    }

    return todoOk;
}


int corredorSetCategoria( eParticipantes* corredor, char* categoria)
{


    int todoOk=1;
    if( corredor!=NULL && categoria!=NULL )
    {

        strcpy(corredor->categoria,categoria);
        todoOk=0;
    }


    return todoOk;

}


int corredorGetCategoria( eParticipantes* corredor, char* categoria )
{
    int todoOk=1;

    if(corredor!=NULL && categoria !=NULL){

        strcpy(categoria, corredor->categoria);
        todoOk=0;

    }

    return todoOk;
}


int corredorSetPromedio( eParticipantes* corredor, float promedio)
{

    int todoOk=1;
    if( corredor!=NULL )
    {

        corredor->promedio=promedio;
        todoOk=0;
    }


    return todoOk;

}






int corredorGetPromedio( eParticipantes* corredor, float* promedio)
{
    int todoOk=1;

    if(corredor!=NULL && promedio !=NULL){

        *promedio = corredor->promedio;
        todoOk=0;

    }

    return todoOk;
}


int corredorSetTiempo( eParticipantes* corredor, float tiempo)
{

    int todoOk=1;
    if( corredor!=NULL && tiempo >= 0)
    {

        corredor->tiempo=tiempo;
        todoOk=0;
    }


    return todoOk;

}



int corredorGetTiempo( eParticipantes* corredor, float* tiempo)
{
    int todoOk=1;

    if(corredor!=NULL && tiempo !=NULL){

        *tiempo=corredor->tiempo;
        todoOk=0;

    }

    return todoOk;
}



void mostrarCorredor (LinkedList* lista, int index)
{
    eParticipantes* pCorredor = (eParticipantes*) corredor_new();
    int id;
    char nombre[128];
    char categoria[20];
    float promedio;
    float tiempo;



    if(lista != NULL && index >=0)
    {
        pCorredor = ll_get(lista, index);

        corredorGetId(pCorredor,&id);
        corredorGetNombre(pCorredor,nombre);
       corredorGetCategoria(pCorredor,categoria);
       corredorGetPromedio(pCorredor,&promedio);
        corredorGetTiempo(pCorredor,&tiempo);




        printf("%2d        %-10s       %-10s       %.2f           %.2f \n",id,nombre,categoria,promedio,tiempo);

    }

}


int mostrarCorredores(LinkedList* pArraylist)
{
    int todoOk = 1;

    eParticipantes* pCorredor;


    if(pArraylist != NULL)
    {

        printf("\n  ID      Nombre         Categoria       Tiempo        Promedio   \n\n");
        for(int i = 0; i < ll_len(pArraylist); i++)
        {
            pCorredor = ll_get(pArraylist, i);
            if(pCorredor != NULL)
            {
                mostrarCorredor(pArraylist, i);
                todoOk = 0;
            }
        }
    }
    else if(todoOk == 1)
    {
        printf("No hay Corredores cargados en la lista\n");
    }

    return todoOk;
}


void* asignarPromedio(void* corredor)//Calcula numeros random y los settea en el campo.
{

   eParticipantes* auxCorredor = NULL;
    float promedio = rand()%120+50;

    if(corredor != NULL)
    {
        auxCorredor = (eParticipantes*) corredor;

        corredorSetPromedio(auxCorredor,promedio);
    }

    return auxCorredor;
}


int OrdenarPosiciones(void* a, void* b){

    int retorno=0;
    float tiempoP1;
    float tiempoP2;


    eParticipantes* p1;
    eParticipantes* p2;


    if(a!=NULL && b!=NULL){

        p1=(eParticipantes*)a; //conversion
        p2=(eParticipantes*)b;

    corredorGetTiempo(p1,&tiempoP1);
    corredorGetTiempo(p2,&tiempoP2);

    }


    if(tiempoP1 > tiempoP2 ){
        retorno=1;

    }else if (tiempoP1 < tiempoP2 ){
        retorno=-1;
    }




    return retorno;
}

