#include "pilha.h"

void InicializarPilha(Pilha *p){
    p->topo = NULL;
}

int Tamanho(Pilha *p){
    PONT var = p->topo;
    int tam = 0;
    while (var != NULL){
        tam++;
        var = var->prox;
    }
    return tam;
}

bool PilhaVazia(Pilha *p){
    return (p->topo == NULL);
}

void ImprimirPilha(Pilha *p){
    PONT var = p->topo;
    printf("\n\n*************PILHA******************\n\n");
    while (var != NULL){
        printf("\t %c \n", var->r.chave);
        var = var->prox;
    }
}

bool PUSH(Pilha *p, Registro r){
    PONT NovaPilha = (PONT)malloc(sizeof(Elemento));
    if (NovaPilha == NULL){
        return false;
    }
    NovaPilha->r = r;
    NovaPilha->prox = p->topo;
    p->topo = NovaPilha;
    return true;
}

bool POP(Pilha *p, Registro *r){
    if (p->topo == NULL)
        return false;
    *r = p->topo->r;
    PONT limpar = p->topo;
    p->topo = p->topo->prox;
    free(limpar);
    return true;
}

void ReinicializarPilha(Pilha *p){
    PONT limpar;
    PONT pos = p->topo;
    while (pos != NULL){
        limpar = pos;
        pos = pos->prox;
        free(limpar);
    }
    p->topo = NULL;
}

bool Palindromo(const char* str) {
    Pilha pilha;
    InicializarPilha(&pilha);
    Registro r;

    for (const char* ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr != ' ' && *ptr != '.') {
            r.chave = tolower(*ptr);
            PUSH(&pilha, r);
        }
    }

    for (const char* ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr != ' ' && *ptr != '.') {
            if (PilhaVazia(&pilha)) {
                return false;
            }
            POP(&pilha, &r);
            if (tolower(*ptr) != r.chave) {
                return false;
            }
        }
    }

    return PilhaVazia(&pilha);
}