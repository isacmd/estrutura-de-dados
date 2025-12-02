/*
    Isabella Nunes de Oliveira | Prática 01 - Lista Sequencial
*/
#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

void cria_lista_vazia(Lista *l) {
    if (!l) return;
    l->n = 0;
}

int lista_vazia(Lista *l) {
    if (!l) return 1; 
    return l->n == 0;
}

int lista_cheia(Lista *l) {
    if (!l) return 0;
    return l->n == MAX;
}

int tamanho_lista(Lista *l) {
    if (!l) return 0;
    return l->n;
}

int obter_valor(Lista *l, int pos, int *valor) {
    if (!l || pos < 1 || pos > l->n || !valor) return 0;
    *valor = l->vetor[pos - 1];
    return 1;
}

int alterar_valor(Lista *l, int pos, int valor) {
    if (!l || pos < 1 || pos > l->n) return 0;
    l->vetor[pos - 1] = valor;
    return 1;
}

int inserir_posicao(Lista *l, int pos, int valor) {
    if (!l || pos < 1 || pos > l->n + 1) return 0; 
    if (lista_cheia(l)) return 0;
    for (int i = l->n - 1; i >= pos - 1; --i) {
        l->vetor[i + 1] = l->vetor[i];
    }
    l->vetor[pos - 1] = valor;
    l->n++;
    return 1;
}

int remover_posicao(Lista *l, int pos, int *valor) {
    if (!l || pos < 1 || pos > l->n) return 0;
    if (valor) *valor = l->vetor[pos - 1];
    for (int i = pos - 1; i < l->n - 1; ++i) {
        l->vetor[i] = l->vetor[i + 1];
    }
    l->n--;
    return 1;
}

// Função auxiliar para imprimir a lista
void imprimir_lista(Lista *l) {
    if (!l) return;
    printf("[ ");
    for (int i = 0; i < l->n; ++i) {
        printf("%d ", l->vetor[i]);
    }
    printf("]\n");
}


