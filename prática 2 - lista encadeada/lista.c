#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void criarLista(Lista* l) {
    l->inicio = NULL;
    l->tamanho = 0;
}

int listaVazia(Lista* l) {
    return l->tamanho == 0;
}

int obterTamanho(Lista* l) {
    return l->tamanho;
}

int obterElemento(Lista* l, int posicao, int* valor) {
    if (posicao < 1 || posicao > l->tamanho) return 0;

    No* atual = l->inicio;
    for (int i = 1; i < posicao; i++) {
        atual = atual->prox;
    }

    *valor = atual->dado;
    return 1;
}

int modificarElemento(Lista* l, int posicao, int novoValor) {
    if (posicao < 1 || posicao > l->tamanho) return 0;

    No* atual = l->inicio;
    for (int i = 1; i < posicao; i++) {
        atual = atual->prox;
    }

    atual->dado = novoValor;
    return 1;
}

int inserirElemento(Lista* l, int posicao, int valor) {
    if (posicao < 1 || posicao > l->tamanho + 1) return 0;

    No* novo = malloc(sizeof(No));
    if (!novo) return 0;

    novo->dado = valor;

    if (posicao == 1) {
        novo->prox = l->inicio;
        l->inicio = novo;
    } else {
        No* atual = l->inicio;
        for (int i = 1; i < posicao - 1; i++) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }

    l->tamanho++;
    return 1;
}

int removerElemento(Lista* l, int posicao) {
    if (posicao < 1 || posicao > l->tamanho) return 0;

    No* remover;

    if (posicao == 1) {
        remover = l->inicio;
        l->inicio = remover->prox;
    } else {
        No* atual = l->inicio;
        for (int i = 1; i < posicao - 1; i++) {
            atual = atual->prox;
        }
        remover = atual->prox;
        atual->prox = remover->prox;
    }

    free(remover);
    l->tamanho--;
    return 1;
}

void imprimirLista(Lista* l) {
    No* atual = l->inicio;
    printf("[ ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("]\n");
}
