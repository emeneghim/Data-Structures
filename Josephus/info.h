typedef struct nodo {
      int num;
      char plv;
      struct nodo *prox;
} bloco, *pbloco; // bloco/nodo/elemento da lista

typedef struct lista {
      bloco *inicio;
      bloco *final;
      int dimensao;  
} *plista, **pplista; // descritor da lista