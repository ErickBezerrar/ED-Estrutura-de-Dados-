typedef struct Lista{
	int    id;
	char * nome;
	struct Lista *prox;
}Lista;

Lista * criaLista();
void exibeLista(Lista **lista);
void insereFinalLista(Lista **lista,int id,char *s);
void destruirLista(Lista **lista);
Lista * pesquisa(Lista **lista,int id);