#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void mostrarPersonas(char *ArreDeNombres[]);
int BuscaNombrePorPalabra(char *buscar,char *ArreDeNombres[]);
void BuscarNombrePorID(int num, char *ArreDeNombres[]);
int main(){

int num,numopc;
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

printf("Si desea buscar por ID ingrese 1 si desea buscar por palabra ingrese 2 \n");
scanf("%d",&numopc);
if (numopc==1)
{
printf("Ingrese un numero de 0 a 5: \n");
scanf("%d",&num);
BuscarNombrePorID(num,arreglosNombres);
}else{
    printf("Ingrese la palabra a buscar \n");
    scanf("%s",buscar);
    int indice=BuscaNombrePorPalabra(buscar,arreglosNombres);
    if (indice==-1)
    {
        printf("No se encontro el nombre \n");
    }else{
        printf("El nombre encontrado es : \n %s", arreglosNombres[indice]);
    }
}

    return 0;
}

void mostrarPersonas(char  *ArreDeNombres[]){

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n",ArreDeNombres[i]);
    }
}


int BuscaNombrePorPalabra(char *buscar, char *ArreDeNombres[]) {
    for (int i = 0; i < 5; i++) {
        
        if (strstr(ArreDeNombres[i], buscar) != NULL) {
            return i; 
        }
    }
    return -1;
}
void BuscarNombrePorID(int num, char *ArreDeNombres[]){

    if (num<0 || num>4)
    {
        printf("No se encontro el valor buscado\n");
    }else{
        printf("El nombre ubicado en esa posicion es  %s \n", ArreDeNombres[num]);
    }
    
}
