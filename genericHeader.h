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
extern struct gastos {
    float gastosPadaria;
    float gastosAlimentos;
    float gastosLimpeza;
    float gastosTotais;
};
static void mostrarAPagar();

#endif
