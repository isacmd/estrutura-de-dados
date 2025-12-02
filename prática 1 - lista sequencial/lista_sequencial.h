/*
    Isabella Nunes de Oliveira | Prática 01 - Lista Sequencial
    - Cabeçalho com definições e protótipos
*/
#define MAX 100

typedef struct ListaSeq {
    int vetor[MAX];
    int n; 
} Lista;

void cria_lista_vazia(Lista *l);
int lista_vazia(Lista *l);
int lista_cheia(Lista *l);
int tamanho_lista(Lista *l);
int obter_valor(Lista *l, int pos, int *valor);
int alterar_valor(Lista *l, int pos, int valor);
int inserir_posicao(Lista *l, int pos, int valor);
int remover_posicao(Lista *l, int pos, int *valor);
void imprimir_lista(Lista *l);