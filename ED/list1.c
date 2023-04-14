#include <stdio.h>

void unknown(int lista[], int s, int e){

    int a;

    if (s + 1 < e - 1){
        unknown(lista, s + 1, e - 1);

        a = lista[s];
        lista[s] = lista[e];
        lista[e] = a;
    }
}

int main() {

 
    int lista[] = {1 ,2 ,3 ,4 ,5 };

    printf("Lista original: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", lista[i]);
    }

    unknown(lista, 1, 3);


    printf("\nLista invertida: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", lista[i]);
    }

    return 0;
}
