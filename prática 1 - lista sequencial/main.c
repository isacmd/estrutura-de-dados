#include <stdio.h>
#include "lista_sequencial.h"

int main(void) {
    Lista lista;
    cria_lista_vazia(&lista);

    printf("Lista criada. Ela está vazia? %s\n", lista_vazia(&lista) ? "Sim" : "Não");

    // inserir alguns elementos
    inserir_posicao(&lista, 1, 10);
    inserir_posicao(&lista, 2, 20);
    inserir_posicao(&lista, 3, 30);
    inserir_posicao(&lista, 2, 15); // insere no meio

    printf("Lista após as inserções: "); imprimir_lista(&lista);
    printf("Tamanho: %d\n", tamanho_lista(&lista));

    int val;
    if (obter_valor(&lista, 2, &val)) printf("Valor da posição 2: %d\n", val);
    alterar_valor(&lista, 2, 25);
    printf("Depois de alterar o valor da posição 2 para 25: "); imprimir_lista(&lista);

    if (remover_posicao(&lista, 3, &val)) printf("Posição 3 removida (valor %d): ", val);
    imprimir_lista(&lista);

    printf("A listá está vazia? %s\n", lista_vazia(&lista) ? "sim" : "nao");
    printf("A lista está cheia? %s\n", lista_cheia(&lista) ? "sim" : "nao");

    inserir_posicao(&lista, tamanho_lista(&lista) + 1, 99);
    printf("Depois de inserir 99 no final: "); imprimir_lista(&lista);

    int ok = inserir_posicao(&lista, 0, 1); // pos invalida
    printf("Inserir posição 0 (esperado 0): %d\n", ok);
    ok = inserir_posicao(&lista, 1000, 1); // pos invalida
    printf("Inserir posição 1000 (esperado 0): %d\n", ok);

    return 0;
}
