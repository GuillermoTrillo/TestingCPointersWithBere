#ifndef G
#define G
typedef struct produto {
    int codigo;
    char nome[50];
    float preco;
    int estoque;
} PROD;
extern struct quantidadeProdutos {

    int referencia;
    PROD produto[30];
};


#endif
