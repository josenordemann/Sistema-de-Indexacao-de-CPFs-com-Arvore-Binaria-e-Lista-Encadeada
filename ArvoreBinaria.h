//  Arquivo ArvBinaria.h
//  TAD: ProjArvoreBinaria-V2
#include <stdio.h>
#include <stdlib.h>
#include "LDED.h"

#ifndef FALSO
#define FALSO      0
#define VERDADEIRO 1
#endif

#ifndef OK
#define OK         1
#define ERRO       0
#endif


//Definição do tipo Arvore
struct NO{
    int cpf;
    struct NO *esq;
    struct NO *dir;
    Elem_ld *no_cor; // no correspondente da arvore binaria
};

typedef struct NO NodoArvBin;
typedef struct NO *ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, int valor, Elem_ld *el);
int remove_ArvBin(ArvBin *raiz, int valor);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, int valor);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);

// Funções Adicionais
void Procura_preOrdem_ArvBin(ArvBin *raiz, int valor, int *achou);
void Exibe_emOrdem_ArvBin(ArvBin *raiz);

// Funções novas
Elem_ld *acha_primeiro_elemento(ArvBin *raiz);
Elem_ld *acha_ultimo_elemento(ArvBin *raiz);
void emOrdem_ArvBin_linha(ArvBin *raiz, FILE *f);
