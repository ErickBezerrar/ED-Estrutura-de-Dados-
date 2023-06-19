#include <stdio.h>
#include <stdlib.h>

struct arv {
    char info;
    struct arv *esq;
    struct arv *dir;
};
typedef struct arv Arv;

int arvoreEstaVazia(Arv *a)
{
    return a == NULL;
}

int maior(int a, int b)
{
    return (a > b) ? a : b;
}

int alturaArvore(Arv *a)
{
    if (arvoreEstaVazia(a))
        return 0;
    else
        return 1 + maior(alturaArvore(a->esq), alturaArvore(a->dir));
}

Arv *liberaArvore(Arv *a)
{
    if (!arvoreEstaVazia(a)) {
        liberaArvore(a->esq);
        liberaArvore(a->dir);
        free(a);
    }
    return NULL;
}

int buscaBinaria(Arv *a, char c)
{
    if (arvoreEstaVazia(a)) {
        return 0;
    } else {
        if (a->info == c) {
            return 1;
        } else {
            if (a->info > c) {
                return buscaBinaria(a->esq, c);
            } else {
                return buscaBinaria(a->dir, c);
            }
        }
    }
}

int pertence(Arv *a, char c)
{
    if (arvoreEstaVazia(a)) {
        return 0;
    } else {
        if (a->info == c) {
            return 1;
        } else {
            if (pertence(a->esq, c)) {
                return 1;
            } else {
                return pertence(a->dir, c);
            }
        }
    }
}

Arv *criaArvoreVazia(void)
{
    return NULL;
}

Arv *criaArvore(char c, Arv *subArvEsq, Arv *subArvDir)
{
    Arv *a;
    a = (Arv *)malloc(sizeof(Arv));
    a->info = c;
    a->esq = subArvEsq;
    a->dir = subArvDir;
    return a;
}

void imprimirArvore(Arv *a)
{
    if (!arvoreEstaVazia(a)) {
        printf("(");
        printf("%c ", a->info);
        imprimirArvore(a->esq);
        imprimirArvore(a->dir);
        printf(")");
    }
}

int busca_arvore(char x, Arv *pt)
{
    if (pt == NULL) {
        return 0;
    } else if (x == pt->info) {
        return 1;
    } else if (x < pt->info) {
        if (pt->esq == NULL) {
            return 2;
        } else {
            pt = pt->esq;
            return busca_arvore(x, pt);
        }
    } else {
        if (pt->dir == NULL) {
            return 3;
        } else {
            pt = pt->dir;
            return busca_arvore(x, pt);
        }
    }
}

void insercao_Arvore(char x, Arv **pt)
{
    int f = busca_arvore(x, *pt);
    if (f == 1) {
        printf("Inserção inválida");
    } else {
        Arv *novo;
        novo = criaArvore(x, criaArvoreVazia(), criaArvoreVazia());
        novo->esq = NULL;
        novo->dir = NULL;
        if (f == 0) {
            *pt = novo;
        } else {
            if (f == 2) {
                (*pt)->esq = novo;
            } else {
                (*pt)->dir = novo;
            }
        }
    }
}

int main()
{
    char c;
    Arv *a, *a1, *a2, *a3, *a4, *a5;
    a1 = criaArvore('f', criaArvoreVazia(), criaArvoreVazia());
    a2 = criaArvore('d', criaArvoreVazia(), a1);
    a3 = criaArvore('m', criaArvoreVazia(), criaArvoreVazia());
    a4 = criaArvore('x', criaArvoreVazia(), criaArvoreVazia());
    a5 = criaArvore('p', a3, a4);
    a = criaArvore('j', a2, a5);
    imprimirArvore(a);
    printf("\nAltura da Árvore: %d\n", alturaArvore(a));
    printf("Digite o caractere a ser procurado: ");
    scanf(" %c", &c);
    if (pertence(a, c)) {
        printf("Encontrei o caractere '%c' na árvore!\n", c);
    } else {
        printf("Não encontrei o caractere '%c' na árvore!\n", c);
    }

    liberaArvore(a);
    return 0;
}
