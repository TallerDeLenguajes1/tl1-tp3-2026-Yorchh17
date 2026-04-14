#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*void mostrarPersonas(char ArreDeNombres[]);*/

int main(){

printf("Ingrese 5 nombres de persona: \n");
char * ArreDeNombres[5];
char *buff[100];
for (int i = 0; i < 5; i++)
{
scanf("%s",&buff);
int cantidadCaract=strlen(buff);
ArreDeNombres[i]=(char*)malloc(sizeof(char)*cantidadCaract);
strcpy(ArreDeNombres[i],buff);
}
printf("Muestra por pantalla \n");

mostrarPersonas(&ArreDeNombres);

    return 0;
}

/*void mostrarPersonas(char  ArreDeNombres[]){

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n",ArreDeNombres[i]);
    }
    

}*/