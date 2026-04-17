#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void mostrarPersonas(char *ArreDeNombres[]);

int main(){

printf("Ingrese 5 nombres de persona: \n");
char *arreglosNombres[5];
char nombre[100];

for (int i = 0; i < 5; i++)
{
    scanf("%s", nombre);
    int cant=strlen(nombre);
    arreglosNombres[i]=malloc(cant+1*(sizeof(char)));
    strcpy(arreglosNombres[i],nombre);
}
mostrarPersonas(arreglosNombres);

    return 0;
}

void mostrarPersonas(char  *ArreDeNombres[]){

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n",ArreDeNombres[i]);
    }
    

}