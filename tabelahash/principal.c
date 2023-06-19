#include <stdio.h>
#include <stdlib.h>
#include "listas_encadeadas.h"


int funcao_hash(int matricula){
	return matricula %11;

}
int main(int argc, char *argv[]) {
	Lista ** v;
	char *s;
	size_t n=0;
	int op=0;
	int matricula,i;
	v=(Lista **)malloc(22*sizeof(Lista *));
	s=(char *)malloc(200*sizeof(char));

	for(i=0;i<22;i++){
		v[i]=criaLista();
	}
	while(op!=-1){
		printf("(-1)-Sair;(1)-Adicionar Elemento;(2)-Exibir Elementos;(3)-Pesquisar elemento\n");
		scanf("%d",&op);
		if(op==-1){
			printf("Saindo\n");
			
		}else if(op==1){
		    printf("Digite o email\n");
			scanf("%s",s);
			printf("Digite a matricula\n");
			scanf("%d",&matricula);
            
			insereFinalLista(&v[funcao_hash(matricula)],matricula,s);
		    s=NULL;
		    s=(char *)malloc(200*sizeof(char));
		}else if(op==2){
			for(i=0;i<22;i++){
				exibeLista(&v[i]);
			}
		}else if(op==3){
			printf("Digite a matricula a ser pesquisada\n");
			scanf("%d",&matricula);
			Lista *aux=pesquisa(&v[funcao_hash(matricula)],matricula);
			if(aux!=NULL){
				printf("Elemento encontrado!! Matricula: %d ; Email: %s\n",matricula,aux->email);
			}
			else{
				printf("Elemento não encontrado!! Matricula: %d não foi cadastrada.\n",matricula);

			}
		}else{
			printf("Opcao invalida!!!\n");
		}
	}

}