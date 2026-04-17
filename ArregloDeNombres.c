#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void mostrarPersonas(char *ArreDeNombres[]);
void BuscarNombre(int num, char *ArreDeNombres[]);
int main(){
int num;
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
printf("Ingrese un numero de 0 a 5: \n");
scanf("%d",&num);
BuscarNombre(num,arreglosNombres);
    return 0;
}

void mostrarPersonas(char  *ArreDeNombres[]){

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n",ArreDeNombres[i]);
    }

}
void BuscarNombre(int num, char *ArreDeNombres[]){

    if (num<0 || num>4)
    {
        printf("No se encontro el valor buscado\n");
    }else{
        printf("El nombre ubicado en esa posicion es  %s \n", ArreDeNombres[num]);
    }
    

}