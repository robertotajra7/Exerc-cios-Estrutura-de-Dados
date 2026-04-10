#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* next;
} No;

void inserirApos (No *lista, int n1, int n2) {
    No *aux = lista;

    while (aux != NULL && aux->valor != n1) {
        aux = aux->next;
    }

    if (aux != NULL) {
    No *new = malloc(sizeof(No));
        if (new) {
        new->valor = n2;

        new->next = aux->next;
        aux->next = new;
        }
    } else {
        printf ("Valor %d nao encontrado na lista.");
    }
}

void inserirNoInicio (No **lista, int num) {
    No *new = (No*) malloc(sizeof(No));
    if (new) {
        new->valor = num;
        new->next = *lista;
        *lista = new;
    }
}   

void imprimirNaLista (No *no) {
    printf ("\nLista: ");
    while (no != NULL) {
        printf ("%d -> ", no->valor);
        no = no->next;
    }
    printf ("NULL\n");
}

int main() {
    No *minhaLista = NULL;

    inserirNoInicio (&minhaLista, 20);
    inserirNoInicio (&minhaLista, 40);
    inserirNoInicio (&minhaLista, 60);

    imprimirNaLista (minhaLista);

    int n1=40, n2=99;
    printf ("\nInserindo %d apos o %d...", n2, n1);
    inserirApos(minhaLista, n1, n2);

    imprimirNaLista (minhaLista);

    return 0;
}



