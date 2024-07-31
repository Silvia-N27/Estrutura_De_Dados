#include "arvore_binaria.h"

No* novo_no(int chave) {
    No* novo = (No*) malloc(sizeof(No));
    novo->chave = chave;
    novo->esquerda = novo->direita = NULL;
    return novo;
}

No* inserir(No* raiz, int chave) {
    if (raiz == NULL) {
        return novo_no(chave);
    }
    if (chave < raiz->chave) {
        raiz->esquerda = inserir(raiz->esquerda, chave);
    }
    else if (chave > raiz->chave) {
        raiz->direita = inserir(raiz->direita, chave);
    }
    return raiz;
}

No* busca_chave(No* raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave) {
        return raiz;
    }
    if (chave < raiz->chave) {
        return busca_chave(raiz->esquerda, chave);
    }
    else {
        return busca_chave(raiz->direita, chave);
    }
}

No* minimo(No* raiz) {
    while (raiz && raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

No* maximo(No* raiz) {
    while (raiz && raiz->direita != NULL) {
        raiz = raiz->direita;
    }
    return raiz;
}

No* remover(No* raiz, int chave) {
    if (raiz == NULL) {
        return raiz;
    }
    if (chave < raiz->chave) {
        raiz->esquerda = remover(raiz->esquerda, chave);
    }
    else if (chave > raiz->chave) {
        raiz->direita = remover(raiz->direita, chave);
    }
    else {
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        No* temp = minimo(raiz->direita);
        raiz->chave = temp->chave;
        raiz->direita = remover(raiz->direita, temp->chave);
    }
    return raiz;
}

void pre_ordem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void em_ordem(No* raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->chave);
        em_ordem(raiz->direita);
    }
}

void pos_ordem(No* raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->chave);
    }
}

No* predecessor(No* raiz, int chave) {
    No* atual = busca_chave(raiz, chave);
    No* antecessor = NULL;
    if (atual && atual->esquerda) {
        return maximo(atual->esquerda);
    }
    while (raiz) {
        if (chave > raiz->chave) {
            antecessor = raiz;
            raiz = raiz->direita;
        }
        else if (chave < raiz->chave) {
            raiz = raiz->esquerda;
        }
        else {
            break;
        }
    }
    return antecessor;
}

No* sucessor(No* raiz, int chave) {
    No* atual = busca_chave(raiz, chave);
    No* sucessor = NULL;
    if (atual && atual->direita) {
        return minimo(atual->direita);
    }
    while (raiz) {
        if (chave < raiz->chave) {
            sucessor = raiz;
            raiz = raiz->esquerda;
        }
        else if (chave > raiz->chave) {
            raiz = raiz->direita;
        }
        else {
            break;
        }
    }
    return sucessor;
}