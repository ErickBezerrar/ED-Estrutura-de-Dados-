//how to print a array in C?


#include <stdio.h>
#include <stdlib.h>

int main(){

    int i;
    char nomes_estudantes[1000] = {'p', 'a', 'z', 'a'};
    int idades_estudantes[] = {15,9.80,13,51,1231,312321,3123};
    float nota_estudantes[1000] = {3,21,312,31,3,123,1,3,123,12,31,23,123,1,312,3,123,12,312,3,12,4125,3455654,64,7,7,86,9,9,89,8,67,5,756,45,64,53,4,423,4,32,324,23,4};

    printf("%c", nomes_estudantes[1]);
    
    for(i = 0; i < 1000; i++ ){
        printf("%2f", nota_estudantes[i]);
    }
    
    
    return 0;
}


