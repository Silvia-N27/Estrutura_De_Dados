typedef int Tipo_Chave;

typedef struct {
    Tipo_Chave chave;
} Registro;

typedef struct Aux_Elemento {
    Registro r;
    struct Aux_Elemento *prox;
    struct Aux_Elemento *ant;
} Elemento;

typedef Elemento* PONT;

typedef struct {
    PONT No;
} Lista;

void InicializarLista(Lista *L);
int RetornarTamanho(Lista *L);
void ImprimirLista(Lista *L);
bool InserirInicio(Lista *L, Registro r);
bool InserirFinal(Lista *L, Registro r);
PONT BuscarChave(Lista *L, Tipo_Chave ch);
bool RemoverInicio(Lista *L);
bool RemoverFinal(Lista *L);
bool RemoverChave(Lista *L, Tipo_Chave ch);
void ReinicializarLista(Lista *L);