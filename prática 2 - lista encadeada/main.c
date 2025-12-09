#include <stdio.h>
#include "lista.h"

int main() {
    Lista l;
    criarLista(&l);

    printf("A lista está vazia? %d\n", listaVazia(&l));

    printf("\nInserindo elementos: \n");
    inserirElemento(&l, 1, 10);   //início
    inserirElemento(&l, 2, 20);   //final
    inserirElemento(&l, 2, 15);   //meio
    imprimirLista(&l);         

    printf("\nTamanho: %d\n", obterTamanho(&l));

    printf("\nObtendo elemento da posição 2:\n");
    int valor;
    if (obterElemento(&l, 2, &valor))
        printf("Valor = %d\n", valor);

    printf("\nModificando elemento da posição 3 para 99 \n");
    modificarElemento(&l, 3, 99);
    imprimirLista(&l);          

    printf("\nRemovendo posição 1... \n");
    removerElemento(&l, 1);
    imprimirLista(&l);         

    printf("\nRemovendo posição 2...\n");
    removerElemento(&l, 2);
    imprimirLista(&l);         

    printf("\nInserindo elemento novamente...\n");
    inserirElemento(&l, 2, 50);
    inserirElemento(&l, 1, 5);
    imprimirLista(&l);        

    return 0;
}