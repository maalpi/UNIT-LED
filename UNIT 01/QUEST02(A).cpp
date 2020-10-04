#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

void inserir(int elemento);
void remover(int elemento);
void inserir_inic(int elemento);
int buscar(int elemento);
int obter(int indice);
int tamanho();
void imprimir();
void apagar();

int main(void) {
  for (int i = 0;i < 8;i++){
    inserir(i);
  }
  imprimir();
  inserir_inic(20);
  imprimir();
  inserir(20);
  imprimir();
  system("pause");
  return 0;
}

void inserir(int elemento){
  int cont_inserir = 0;
  if (pos < MAX){
    if (buscar(elemento) == 0){
      	printf("Elemento ja presente na lista.\n");
    }
    else{
	    l[pos++] = elemento;
    }
  }
  else {
	printf("Não foi possível inserir %d. Lista cheia.\n",elemento);
  }
}

void inserir_inic(int elemento){
  
  if (pos < MAX){
    for(int i = MAX; i > -1;i--){
      l[i + 1] = l[i];
    }
    l[0] = elemento;
    pos++;
  }else{
    printf("Não foi possível inserir %d. Lista cheia.\n",elemento);
}
}

int buscar(int elemento){
  for (int i = 0 ; i < pos ; i++){
	if (l[i] == elemento)
  	return i;
  }
  return -1;
}

void remover(int elemento){
int p = buscar(elemento);
 
  if (p == -1)
	return;
 
  for (int i = p ; i < pos -1; i++)
	l[i] = l[i+1];
  pos--;
}

int obter(int indice){
  if (indice < 0 || indice >= pos) {
	printf("Indice %d fora dos limites da Lista.\n", indice);
	exit(1);
  }
  return l[indice];
}

int tamanho(){
  return pos;
}

void imprimir(){
  for (int i = 0 ; i < pos ; i++)
	printf("%d ",l[i]);
  printf("\n");
}

void apagar(){
  pos = 0;
}

