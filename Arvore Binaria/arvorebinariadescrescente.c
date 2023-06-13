#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserirNo(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserirNo(raiz->direita, valor);
    }

    return raiz;
}

void listarEmOrdemDecrescente(No* raiz) {
    if (raiz != NULL) {
        listarEmOrdemDecrescente(raiz->direita);
        printf("%d ", raiz->valor);
        listarEmOrdemDecrescente(raiz->esquerda);
    }
}

int main() {
    No* raiz = criarNo(4);
    inserirNo(raiz, 2);
    inserirNo(raiz, 6);
    inserirNo(raiz, 1);
    inserirNo(raiz, 3);
    inserirNo(raiz, 5);
    inserirNo(raiz, 7);

    printf("Valores dos nos em ordem decrescente: ");
    listarEmOrdemDecrescente(raiz);
    printf("\n");

    return 0;
}
