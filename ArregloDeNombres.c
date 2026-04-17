#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void mostrarPersonas(char *ArreDeNombres[]);
int BuscarNombre(char *buscar,char *ArreDeNombres[]);
int main(){


printf("Ingrese 5 nombres de persona: \n");
char *arreglosNombres[5];
char nombre[100];
char buscar[20];
for (int i = 0; i < 5; i++)
{
    scanf("%s", nombre);
    int cant=strlen(nombre);
    arreglosNombres[i]=malloc(cant+1*(sizeof(char)));
    strcpy(arreglosNombres[i],nombre);
}
mostrarPersonas(arreglosNombres);

printf("Ingrese la palabra a buscar \n");
scanf("%s",buscar);
int indice=BuscarNombre(buscar,arreglosNombres);
if (indice==-1)
{
    printf("No se encontro el nombre \n");
}else{
    printf("El nombre encontrado es : \n %s", arreglosNombres[indice]);
}

    return 0;
}

void mostrarPersonas(char  *ArreDeNombres[]){

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n",ArreDeNombres[i]);
    }
}

int BuscarNombre(char *buscar, char *ArreDeNombres[]) {
    for (int i = 0; i < 5; i++) {
        
        if (strstr(ArreDeNombres[i], buscar) != NULL) {
            return i; 
        }
    }
    return -1;
}

