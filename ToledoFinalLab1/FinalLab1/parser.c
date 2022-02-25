#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "corredor.h"


int parser(FILE* pFile, LinkedList* lista)
{
    int todoOk = 1;
    eParticipantes* pCorredor;
    char id[200];
    char nombre[200];

    char categoria[200];
    char promedio[200];
    char tiempo[200];




    if(pFile != NULL && lista != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, categoria,tiempo, promedio);
        do
        {
            if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, categoria,tiempo, promedio) == 5)
            {
                pCorredor = corredor_newParametros(id, nombre, categoria,tiempo, promedio);

                if(pCorredor != NULL)//osea si pudo cargar
                {
                    ll_add(lista, pCorredor);
                    todoOk = 0;
                }
            }
            else
            {
                break;
            }

        }
        while(feof(pFile) == 0);
    }

    return todoOk;
}


int loadFromText(LinkedList* lista)
{
    int todoOk = 1;
    char path[128];

    printf("Ingrese el Nombre del archivo (enduro)(sin extension): ");
    fflush(stdin);
    scanf("%s",path);

    strcat(path,".csv");



    FILE* f = fopen(path,"r");

    if(f != NULL)
    {
        if(!parser(f,lista))
        {
            todoOk = 0;
            printf("Se cargaron los datos\n");
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    fclose(f);

    return todoOk;
}


int saveAsText(char* path , LinkedList* lista)
{


	int todoOk = 1;

	FILE* pFile;
	int auxId;
	char auxNombre[31];
	char auxCategoria[31];
	float auxPromedio;
	float auxTiempo;
	eParticipantes* auxMoto;

	if(lista != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			todoOk = 0;
			fprintf(pFile, "id,nombre,categoria,tiempo,promedio\n");
			for(int i = 0; i < ll_len(lista); i++)
			{
				auxMoto = (eParticipantes*) ll_get(lista, i);
				if(!corredorGetId(auxMoto,&auxId) &&
				   !corredorGetNombre(auxMoto,auxNombre) &&
                   !corredorGetCategoria(auxMoto,auxCategoria) &&
				   !corredorGetPromedio(auxMoto,&auxPromedio)&&
                    !corredorGetTiempo(auxMoto,&auxTiempo)

                    )

				{
					fprintf(pFile, "%d,%s,%s,%.2f,%.2f\n", auxId, auxNombre,auxCategoria,auxTiempo,auxPromedio);
				}
			}
			fclose(pFile);
			printf("Se guardaron los datos en el archivo\n");
		}
	}

    return todoOk;
}

