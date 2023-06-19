typedef struct Lista{
	int    matricula;
	char * email;
	struct Lista *prox;
}Lista;

Lista * criaLista();
void exibeLista(Lista **lista);
void insereFinalLista(Lista **lista,int matricula,char *s);
void destruirLista(Lista **lista);
Lista * pesquisa(Lista **lista,int matricula);