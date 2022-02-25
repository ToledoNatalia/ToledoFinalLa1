#include "LinkedList.h"



#ifndef CORREDOR_H_INCLUDED
#define CORREDOR_H_INCLUDED

 typedef  struct{

int id_cuatri;
char nombre[20];
char categoria[20];
float promedio;
float tiempo;


}eParticipantes;


#endif // CORREDOR_H_INCLUDED

eParticipantes* corredor_new();
eParticipantes* corredor_newParametros(char* idStr,char* nombreStr,char* categoriaStr,char* promedioStr,char* tiempoStr);
int corredorSetId( eParticipantes* corredor, int id);
int corredorGetId( eParticipantes* corredor, int* id);
int corredorSetNombre( eParticipantes* corredor, char* nombre);
int corredorGetNombre( eParticipantes* corredor, char* nombre);
int corredorSetCategoria(eParticipantes* corredor, char* categoria);
int corredorGetCategoria(eParticipantes* corredor, char* categoria );
int corredorSetPromedio(eParticipantes* corredor, float promedio);
int corredorGetPromedio(eParticipantes* corredor, float* promedio);
int corredorSetTiempo(eParticipantes* corredor, float tiempo);
int corredorGetTiempo(eParticipantes* corredor, float* tiempo);
void mostrarCorredor (LinkedList* lista, int index);
int mostrarCorredores(LinkedList* pArraylist);
void* asignarPromedio(void* corredor);
int OrdenarPosiciones(void* a, void* b);

