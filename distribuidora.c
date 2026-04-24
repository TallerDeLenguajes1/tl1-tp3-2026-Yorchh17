#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// --- ESTRUCTURAS ---
typedef struct {
    int ProductoID;          //Numerado en ciclo iterativo
    int Cantidad;            //Numerado en ciclo iterativo
    char *TipoProducto;      //Numerado en ciclo iterativo
    int PrecioUnitario;      //Numerado en ciclo iterativo
} Producto;

typedef struct {
    int ClienteID;                 // Numerado en el ciclo iterativo
    char *NombreCliente;           // Ingresado por usuario
    int CantidadProductosAPedir;   // (aleatorio entre 1 y 5)
    Producto *Productos;    //El tamaño de este arreglo depende de la variable
} Cliente;


void cargarClientes(Cliente *clientes, int cantidad, char *tipos[]);
void mostrarTodo(Cliente *clientes, int cantClientes);
float costoTotal(Producto *producto); 

int main() {
    srand(time(NULL));
    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
    int cantClientes;
    Cliente *clientes;

    printf("Ingrese la cantidad de clientes a cargar: ");
    if (scanf("%d", &cantClientes) != 1) return 1;

    // Asignación de memoria para clientes
    clientes = (Cliente *)malloc(cantClientes * sizeof(Cliente));

    // Carga de datos
    cargarClientes(clientes, cantClientes, TiposProductos);

    // Muestra de resultados y cálculos
    mostrarTodo(clientes, cantClientes);

    // libero memoria
    for (int i = 0; i < cantClientes; i++) {
        free(clientes[i].NombreCliente); 
        free(clientes[i].Productos);     
    }
    free(clientes); 

    return 0;
}

float costoTotal(Producto *producto) {
    return (float)(producto->Cantidad * producto->PrecioUnitario);
}

void cargarClientes(Cliente *clientes, int cantidad, char *tipos[]) {
    char buffer[100]; 

    for (int i = 0; i < cantidad; i++) {
        clientes[i].ClienteID = i + 1;

        printf("\n--- Registro Cliente %d ---\n", clientes[i].ClienteID);
        printf("Nombre: ");
        scanf("%s", buffer);

       
        clientes[i].NombreCliente = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(clientes[i].NombreCliente, buffer);

        clientes[i].CantidadProductosAPedir = 1 + rand() % 5;
        
        clientes[i].Productos = (Producto *)malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = 1 + rand() % 10; // 1 a 10
            clientes[i].Productos[j].TipoProducto = tipos[rand() % 5];
            clientes[i].Productos[j].PrecioUnitario = 10 + rand() % 91; 
        }
    }
}


void mostrarTodo(Cliente *clientes, int cantClientes) {
    printf("\n\n==========================================================");
    printf("\n               INFORME DE VENTAS TOTALES                  ");
    printf("\n==========================================================\n");

    for (int i = 0; i < cantClientes; i++) {
        float totalAcumuladoCliente = 0; 

        printf("\nCLIENTE: %s (ID: %d)", clientes[i].NombreCliente, clientes[i].ClienteID);
        printf("\nProductos pedidos: %d", clientes[i].CantidadProductosAPedir);
        printf("\n----------------------------------------------------------\n");
        printf("%s   %s   %s       %s\n", "Producto", "Cant.", "P. Unitario", "Subtotal");

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            float subtotal = costoTotal(&clientes[i].Productos[j]);
            totalAcumuladoCliente += subtotal;

            printf("%s   %d      $%d                $%.2f\n", 
                clientes[i].Productos[j].TipoProducto, 
                clientes[i].Productos[j].Cantidad, 
                clientes[i].Productos[j].PrecioUnitario,
                subtotal);
        }

        printf("----------------------------------------------------------");
        printf("\nTOTAL A PAGAR POR CLIENTE: $%.2f\n", totalAcumuladoCliente);
        printf("==========================================================\n");
    }
}