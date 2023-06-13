#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore binária
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Função para criar um novo nó da árvore
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir um nó na árvore
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

// Função para listar os valores dos nós em ordem crescente
void listarEmOrdem(No* raiz) {
    if (raiz != NULL) {
        listarEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        listarEmOrdem(raiz->direita);
    }
}

// Função principal
int main() {
    // Criando uma árvore de exemplo
    No* raiz = criarNo(4);
    inserirNo(raiz, 2);
    inserirNo(raiz, 6);
    inserirNo(raiz, 1);
    inserirNo(raiz, 3);
    inserirNo(raiz, 5);
    inserirNo(raiz, 7);

    // Listando os valores dos nós em ordem crescente
    printf("Valores dos nos em ordem crescente: ");
    listarEmOrdem(raiz);
    printf("\n");

    return 0;
}
