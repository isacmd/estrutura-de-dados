#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct Lista {
    No* inicio;
    int tamanho;
} Lista;

void criarLista(Lista* l);
int listaVazia(Lista* l);
int obterTamanho(Lista* l);
int obterElemento(Lista* l, int posicao, int* valor);
int modificarElemento(Lista* l, int posicao, int novoValor);
int inserirElemento(Lista* l, int posicao, int valor);
int removerElemento(Lista* l, int posicao);
void imprimirLista(Lista* l);

#endif