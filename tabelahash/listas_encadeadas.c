#include <stdio.h>
#include <stdlib.h>
#include "listas_encadeadas.h"

Lista * criaLista(){
	return NULL;
}

void exibeLista(Lista **lista){
    Lista *aux=(*lista);

	while(aux!=NULL){
		printf("%d- %s\n",aux->id,aux->nome);
		aux=aux->prox;
	}
}

void insereFinalLista(Lista **lista,int id,char *s){
	Lista *novo,*aux;

	novo=(Lista *)malloc(sizeof(Lista));
	novo->id=id;
	novo->nome=s;
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

Lista * pesquisa(Lista **lista,int id){
	Lista *aux=*lista;
	
	if(*lista==NULL){
		return NULL;
	}

	else if((*lista)->id==id){
		return aux;
        
	}else{
		Lista *aux2=(*lista)->prox;

		while((aux2!=NULL)&&(aux2->id!=id)){
			aux=aux->prox;
			aux=aux2->prox;
		}

		if(aux2!=NULL){
			return aux2;
		}
	
	}
	return NULL;
}