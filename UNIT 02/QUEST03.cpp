#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sLISTA{
  struct sNODE *ini, *fim;
};

typedef struct sLISTA LISTA;
typedef struct sNODE NODE;

void inicializar(LISTA *lst);
void apagar(LISTA *lst);

void inserir_ord(LISTA *lst, int dado);
void remover(LISTA *lst, int dado);
struct sNODE *buscar(LISTA *lst, int dado);

int obter(struct sNODE *node);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);


int main(){
  LISTA lst;
  inicializar(&lst);

  inserir_ord(&lst, 100);
  inserir_ord(&lst, 200);
  inserir_ord(&lst, 300);
  imprimir(&lst);

  remover(&lst, 200);
  imprimir(&lst);
  apagar(&lst);
  imprimir(&lst);
  
  return 0;
}

void inicializar(LISTA* lst){
  lst->ini = lst->fim = NULL;
}

void apagar(LISTA* lst){
  NODE *aux = lst->ini, *ant;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  lst->ini = lst->fim = NULL;
}

void inserir_ord(LISTA *lst, int dado){
  NODE *novo = (NODE*) malloc(sizeof(NODE));
  NODE *ant = NULL;
  NODE *aux = lst->ini;
  int dados = dado;
  novo->dado = dado;
  novo->prox = NULL;
  
  while (aux && dados > aux->dado){
      ant = aux;
      aux = aux->prox; 
  }
  if (!lst->ini){
	lst->ini = lst->fim = novo;
  }else if (aux == lst->ini){
    novo->prox = lst->ini;
	  lst->ini = novo;
  }
  else if(!aux){
    lst->fim->prox=novo;
    lst->fim = novo;
  }
  else{
    ant->prox=novo;
    novo->prox=aux;
  }
}

NODE *buscar(LISTA *lst,int dado){
   NODE *aux = lst->ini;

  while (aux){
	if (dado == aux->dado)
  	    return aux;
	aux = aux->prox;
  }

  return NULL;
}

void remover(LISTA *lst, int dado){
  NODE *aux = lst->ini, *ant = NULL;

  while (aux){
	if (dado == aux->dado){
  	    if (aux == lst->ini)
    	        lst->ini = lst->ini->prox;
  	    else if(aux == lst->fim){
    	        ant->prox = NULL;
    	        lst->fim = ant;
  	    } else
    	        ant->prox = aux->prox;
 	 
  	    free(aux);
  	    return;
	}
    
	ant = aux;
	aux = aux->prox;
  }
}

int obter(NODE *node){
  if (!node){
	printf("Erro ao obter dado. Ponteiro invalido.");
	exit(0);
  }
 
  return node->dado;
}

int tamanho(LISTA *lst){
  NODE *aux = lst->ini;
  int tam = 0;
 
  while (aux){
	tam++;
	aux = aux->prox;
  }
 
  return tam;
}

void imprimir(LISTA *lst){
  NODE *aux = lst->ini;
 
  printf("[ ");
  while (aux){
	printf("%d ", aux->dado);
	aux = aux->prox;
  }
  printf("]\n");
}
