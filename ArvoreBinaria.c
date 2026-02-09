#include "ArvoreBinaria.h" //inclui os Protótipos

// Local functions (Prototipo da funcao)
void libera_NO(struct NO* no);
struct NO* remove_atual(struct NO* atual);

// TAD ABO - Arvore Binaria Ordenada

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int insere_ArvBin(ArvBin* raiz, int valor, Elem_ld *el)
{
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->cpf = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    novo->no_cor = el;
    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->cpf){
                free(novo);
                return 0;//elemento já existe
            }

            if(valor > atual->cpf)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->cpf)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 é o nó anterior a r na ordem e-r-d
    // no1 é o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}
// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->cpf){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->cpf)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->cpf){
            return 1;
        }
        if(valor > atual->cpf)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

void preOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("cpf: %d\n",(*raiz)->cpf);          // cpf é Int
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%09d\n",(*raiz)->cpf);          // cpf é Int
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}


void posOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("cpf: %d\n",(*raiz)->cpf);          // cpf é Int
    }
}

// Funcoes Adicionais de Arvore

void Procura_preOrdem_ArvBin(ArvBin *raiz, int valor, int *achou)
{
    if(raiz == NULL)
        return;
    if (*achou)
        return;
    if(*raiz != NULL)
    {
        if (valor == (*raiz)->cpf)
        {
            printf("Achou: %d! \n",(*raiz)->cpf);   // cpf é Int
            *achou=1;
        }
        Procura_preOrdem_ArvBin(&((*raiz)->esq),valor,achou);
        Procura_preOrdem_ArvBin(&((*raiz)->dir),valor,achou);
    }
}

void Exibe_emOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;

    if(*raiz != NULL)
    {
        printf("Atual: %d - Vai para Esquerda \n",(*raiz)->cpf);   // cpf é Int
        Exibe_emOrdem_ArvBin(&((*raiz)->esq));
        printf("Dado : %d \n",(*raiz)->cpf);
        printf("Atual: %d - Vai para Direita \n",(*raiz)->cpf);    // cpf é Int
        Exibe_emOrdem_ArvBin(&((*raiz)->dir));
        printf("Feito(%d) \n",(*raiz)->cpf);                       // cpf é Int
    }
    else
        printf("NULL\n");

}


// Funções novas

// Função para achar o primeiro elemento. Note que utilizo a lógica do exercício para retornar o ponteiro para o elemento da LDED, assim apenas percorrendo a árvore binária (mais rápido)

Elem_ld *acha_primeiro_elemento(ArvBin *raiz)
{
    if(raiz == NULL) {return NULL;}//erro
    if(*raiz == NULL) {return NULL;} //erro árvore vazia
    NodoArvBin *ant = (*raiz); // auxiliares
    NodoArvBin *atual = ((*raiz)->esq);
    {
        while (atual != NULL) // achar o elemento mais a esquerda
        {   
        ant = atual;
        atual = atual->esq;
        }
    }
    return ant->no_cor; // devolve o elemento mais a esquerda
}

// Função para achar o último elemento. Note que utilizo a lógica do exercício para retornar o ponteiro para o elemento da LDED, assim apenas percorrendo a árvore binária (mais rápido)

Elem_ld *acha_ultimo_elemento(ArvBin *raiz)
{
    if(raiz == NULL) {return NULL;}//erro
    if(*raiz == NULL) {return NULL;} //erro arvore vazia
    NodoArvBin *ant = (*raiz);// auxiliares
    NodoArvBin *atual = ((*raiz)->dir);
    {
        while (atual != NULL) // achar o elemento mais a direita
        {   
        ant = atual;
        atual = atual->dir;
        }
    }
    return ant->no_cor; // devolve o elemento mais a direita
}

// Função para imprimir a árvore binária no arquivo, parecida com a função original de impressão
void emOrdem_ArvBin_linha(ArvBin *raiz, FILE *f)
{
    if(raiz == NULL)
        return;
    if(f == NULL)
        return;

    if(*raiz != NULL){
        emOrdem_ArvBin_linha(&((*raiz)->esq), f);
        fprintf(f, "%09d\n",(*raiz)->cpf);          // cpf é Int
        emOrdem_ArvBin_linha(&((*raiz)->dir), f);
    }
}
