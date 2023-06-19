#include <stdio.h>
#include <stdlib.h>
#include "listas_encadeadas.h"
Lista * criaLista(){
	return NULL;
}

void exibeLista(Lista **lista){
    Lista *aux=(*lista);
	while(aux!=NULL){
		printf("%d- %s\n",aux->matricula,aux->email);
		aux=aux->prox;
	}
}
void insereFinalLista(Lista **lista,int matricula,char *s){
	Lista *novo,*aux;
	novo=(Lista *)malloc(sizeof(Lista));
	novo->matricula=matricula;
	novo->email=s;
	novo->prox=NULL;
	if((*lista)==NULL){
		(*lista)=novo;
	}else{
		aux=*lista;
		while(aux->prox!=NULL){
			aux=aux->prox;
		}
		aux->prox=novo;
	}
}

void destruirLista(Lista **lista){
	Lista *aux;
	while(*lista!=NULL){
		aux=*lista;
		*lista=(*lista)->prox;
		free(aux);
	}
}

Lista * pesquisa(Lista **lista,int matricula){

	Lista *aux=*lista;
	
	if(*lista==NULL){
		return NULL;
	}
	else if((*lista)->matricula==matricula){
		return aux;
	}else{
		Lista *aux2=(*lista)->prox;
		while((aux2!=NULL)&&(aux2->matricula!=matricula)){
			aux=aux->prox;
			aux=aux2->prox;
		}
		if(aux2!=NULL){
			return aux2;
		}
	
	}
	return NULL;
}