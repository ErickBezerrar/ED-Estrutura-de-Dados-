#include <stdio.h>
#include <stdlib.h>
#include "listas_encadeadas.h"


int funcao_hash(int id){
	return id %11;

}
int main(int argc, char *argv[]) {
	Lista ** v;
	char *s;
	size_t n=0;
	int op=0;
	int id,i;
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
			
		}

        else if(op==1){
		    printf("Digite algum nome que você deseja guardar\n");
			scanf("%s",s);
			printf("Digite a ID\n");
			scanf("%d",&id);
            
			insereFinalLista(&v[funcao_hash(id)],id,s);
		    s=NULL;
		    s=(char *)malloc(200*sizeof(char));

		}

        else if(op==2){
			for(i=0;i<22;i++){
				exibeLista(&v[i]);
			}
		}

        else if(op==3){

			printf("Digite o id a ser pesquisado\n");
			scanf("%d",&id);

			Lista *aux=pesquisa(&v[funcao_hash(id)],id);
            
			if(aux!=NULL){
				printf("Elemento encontrado!! id: %d ; nome: %s\n",id,aux->nome);
			}else{
				printf("Elemento não encontrado!! id: %d não foi cadastrada.\n",id);

			}
		}else{
			printf("Opção inválida!!!\n");
		}
	}

}