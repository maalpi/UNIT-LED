
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNODE{
  char nome[100];
  int notaA,notaB;
  float media;
  struct sNODE *prox;
}lista;

struct sNODE *ini = NULL, *fim = NULL;

void inserir_ord(int notaA, int notaB, char *nome);
void remover(char *nome);
lista *buscar(char *nome);

int obter(lista *node);
int tamanho();
void imprimir();
void apagar();
void ordenar();

int main(){
    inserir_ord(30,58,"mateus");
    imprimir();
    inserir_ord(30,18,"pedro");
    buscar("mateus");
    imprimir();
    inserir_ord(30,100,"joao");
    inserir_ord(30,56,"fabio");
    imprimir();
    remover("fabio");
    imprimir();
    system("pause");
  return 0;
}

void inserir_ord(int notaA, int notaB, char *nome){
  lista *novo = (lista*) malloc(sizeof(lista));
  lista *ant = NULL,*aux = ini;
  int iMEDIA=(notaA+notaB)/2;
  novo->notaA = notaA;
  novo->notaB = notaB;
  novo->media = ((notaA+notaB)/2);
  strcpy(novo->nome, nome);
  novo->prox = NULL;
  
  while (aux && iMEDIA < aux->media){
      ant = aux;
      aux = aux->prox; 
  }
  if (!ini){
	ini = fim = novo;
  }else if (aux == ini){
    novo->prox = ini;
	  ini = novo;
  }
  else if(!aux){
    fim->prox=novo;
    fim = novo;
  }
  else{
    ant->prox=novo;
    novo->prox=aux;
  }
}


lista *buscar(char *nome){
  lista *aux = ini;

  while (aux){
	if ((strcmp(nome,aux->nome)==0))
  	    return aux;
	aux = aux->prox;
  }

  return NULL;
}

void remover(char *nome){
  lista *aux = ini, *ant = NULL;

  while (aux){
	if ((strcmp(nome,aux->nome)==0)){
  	    if (aux == ini)
    	        ini = ini->prox;
  	    else if(aux == fim){
    	        ant->prox = NULL;
    	        fim = ant;
  	    } else
    	        ant->prox = aux->prox;
 	 
  	    free(aux);
  	    return;
	}
    
	ant = aux;
	aux = aux->prox;
  }
}

void apagar(){
  lista *aux = ini, *ant;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  ini = fim = NULL;
}

int obter(lista *node){
  if (!node){
	printf("Erro ao obter dado. Ponteiro invalido.");
	exit(0);
  }
 
  return node->media;
}

int tamanho(){
  lista *aux = ini;
  int tam = 0;
 
  while (aux){
	tam++;
	aux = aux->prox;
  }
 
  return tam;
}

void imprimir(){
  lista *aux = ini;
 
  printf("\n");
  while (aux){
  printf("Aluno: %s ", aux->nome);
	printf("Media: %.2lf ", aux->media);
  printf("\n");
	aux = aux->prox;
  }
  printf("\n");
}
