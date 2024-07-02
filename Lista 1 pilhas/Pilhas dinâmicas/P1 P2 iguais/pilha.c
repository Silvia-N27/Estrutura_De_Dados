#include "pilha.h"

void InicializarPilha(Pilha *p){
    p->topo=NULL;
}

int Tamanho(Pilha *p){
    PONT var=p->topo;
    int tam=0;
    while(var!=NULL){
        tam++;
        var=var->prox;
    }
    return tam;
}

bool PilhaVazia(Pilha *p){
    return (p->topo == NULL);
}

void ImprimirPilha(Pilha *p){
    PONT var=p->topo;
    printf("\n\n*************PILHA******************\n\n");
    while(var!=NULL){
        printf("\t %d \n",var->r.chave);
        var=var->prox;
    }
}

bool PUSH(Pilha *p, Registro r){
    PONT NovaPilha=(PONT)malloc(sizeof(Elemento));
    if (NovaPilha == NULL){
        return false;
    }
    NovaPilha->r=r;
    NovaPilha->prox=p->topo;
    p->topo=NovaPilha;
    return true;
}

bool POP(Pilha *p, Registro *r){
    if(p->topo==NULL)
        return false;
    *r=p->topo->r;
    PONT limpar=p->topo;
    p->topo=p->topo->prox;
    free(limpar);
    return true;
}

void ReinicializarPilha(Pilha *p){
    PONT limpar;
    PONT pos=p->topo;
    while(pos!=NULL){
        limpar=pos;
        pos=pos->prox;
        free(limpar);
    }
    p->topo=NULL;
}

void TransferirPilha(Pilha *P1, Pilha *P2) {
    Registro r;
    while (!PilhaVazia(P1)) {
        POP(P1, &r);
        PUSH(P2, r);
    }
}

bool CompararPilhas(Pilha *P1, Pilha *P2) {
    return (Tamanho(P1) == Tamanho(P2));
}

void InverterPilha(Pilha *P) {
    Pilha aux1, aux2;
    Registro r;

    InicializarPilha(&aux1);
    InicializarPilha(&aux2);

    while (!PilhaVazia(P)) {
        POP(P, &r);
        PUSH(&aux1, r);
    }

    while (!PilhaVazia(&aux1)) {
        POP(&aux1, &r);
        PUSH(&aux2, r);
    }

    while (!PilhaVazia(&aux2)) {
        POP(&aux2, &r);
        PUSH(P, r);
    }
}

bool PilhasIguais(Pilha *P1, Pilha *P2) {
    Pilha aux1, aux2;
    Registro r1, r2;
    bool iguais = true;

    InicializarPilha(&aux1);
    InicializarPilha(&aux2);

    if (Tamanho(P1) != Tamanho(P2)) {
        return false;
    }

    while (!PilhaVazia(P1)) {
        POP(P1, &r1);
        POP(P2, &r2);
        PUSH(&aux1, r1);
        PUSH(&aux2, r2);
    }


    while (!PilhaVazia(&aux1)) {
        POP(&aux1, &r1);
        POP(&aux2, &r2);
        if (r1.chave != r2.chave) {
            iguais = false;
            break;
        }
        PUSH(P1, r1);
        PUSH(P2, r2);
    }

    while (!PilhaVazia(&aux1)) {
        POP(&aux1, &r1);
        POP(&aux2, &r2);
        PUSH(P1, r1);
        PUSH(P2, r2);
    }

    return iguais;
}