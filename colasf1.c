#include <stdio.h>
#include <stdlib.h>

struct piloto {
    char nombre[20];
    int edad;
    char pais[20];
    int experiencia;
    float salario;
};

struct nodo {
    struct piloto datos;
    struct nodo *siguiente;
};

struct cola {
    struct piloto datos_piloto;
    struct nodo *inicio;
    struct nodo *fin;
};

void encolar(struct cola *q, struct piloto p) {
    struct nodo *nuevo_nodo = (struct nodo*)malloc(sizeof(struct nodo));
    nuevo_nodo->datos = p;
    nuevo_nodo->siguiente = NULL;
    
    if (q->inicio == NULL) {
        q->inicio = nuevo_nodo;
    } else {
        q->fin->siguiente = nuevo_nodo;
    }
    
    q->fin = nuevo_nodo;
}

void imprimir_cola(struct cola q) {
    struct nodo *actual = q.inicio;
    
    while (actual != NULL) {
        printf("Nombre: %s\n", actual->datos.nombre);
        printf("Edad: %d\n", actual->datos.edad);
        printf("Pais: %s\n", actual->datos.pais);
        printf("Experiencia: %d años\n", actual->datos.experiencia);
        printf("Salario: $%.2f\n", actual->datos.salario);
        fflush(stdin);
        actual = actual->siguiente;
    }
}

int main() {
    struct cola q = {0};
    struct piloto p1 = {"Lewis Hamilton", 37, "Reino Unido", 15, 40.5};
    struct piloto p2 = {"Max Verstappen", 24, "Países Bajos", 5, 15.5};
    struct piloto p3 = {"Valtteri Bottas", 32, "Finlandia", 8, 10.0};
    struct piloto p4 = {"Sergio Pérez", 31, "México", 11, 8.0};
    struct piloto p5 = {"Charles Leclerc", 24, "Mónaco", 3, 5.5};
    
    // Agregar los pilotos a la cola
    encolar(&q, p1);
    encolar(&q, p2);
    encolar(&q, p3);
    encolar(&q, p4);
    encolar(&q, p5);
    
    // Imprimir la cola
    printf("Cola de pilotos:\n");
    imprimir_cola(q);
    
    return 0;
}
