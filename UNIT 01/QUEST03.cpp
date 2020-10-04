#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const unsigned MAX = 10;

char l[MAX][20];
int pos = 0;

void inserir_ord(char *elemento);
void remover(char *elemento);
int buscar(char *elemento);

int obter(char *indice);
int tamanho();
void imprimir();
void apagar();


int main(void) {
  inserir_ord("mateus");/*inserindo e imprindo dados pra ver se deu certo */
  imprimir();
  inserir_ord("lion");
  imprimir();
  
  obter("ola");/*Funcao obter*/

  printf("%d\n",buscar("mateus")); /*Funcao buscar dando print pra mostrar a posicao*/

  remover("lion");/*removendo*/
  imprimir();
 
  return 0;
}

void inserir_ord(char *elemento){
  int i, p;
  char letra = elemento[0];
  int asc = letra;
  if (pos < MAX) {
	for (i = 0 ; i < pos ; i++){
  	    int run = l[i][0];
        if (run >= asc)
    	        break;
        run = 0;
  }
    
	for (p = pos ; p > i ; p--){
  	    strcpy(l[p],l[p-1]);
    }
  strcpy(l[i], elemento);
	pos ++;
  }
  else {
	  printf("Não foi possível inserir %s. Lista cheia.\n",elemento);
  }
}

int buscar(char *elemento){
  for (int i = 0 ; i < pos ; i++){
	if(strcmp(l[i],elemento)==0){
  	return i;
  }
  }
  return -1;
}

void remover(char *elemento){
  int p = buscar(elemento);
 
  if (p == -1){
	  return;
  }

  for (int i = p ; i < pos -1; i++){
	  strcpy(l[i],l[i+1]);
  }
  pos--;
}

int obter(char *indice){
  int cont = 0;
  for (int i = 0 ; i < pos ; i++){
    if(strcmp(l[i],indice)==0){
      cont++;
    }
  }

  if (cont == 0) {
	  printf("Indice %s nao estar na lista.\n",indice);
  }else{
    printf("%s",indice);
  }
  return 0;
}

int tamanho(){
  return pos;
}

void imprimir(){
  for (int i = 0 ; i < pos ; i++)
	  printf("%s ",l[i]);
    printf("\n");
}

void apagar(){
  pos = 0;
}
