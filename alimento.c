#include "genericHeader.h"

static struct quantidadeProdutos produtosAlimentos = {
    9,
    {
        {21, "Cafe", 19.99, 20},
        {22, "Leite (cx)", 5.90, 20},
        {23, "Arroz (1kg)", 4.5, 20},
        {24, "Feijao", 8, 20},
        {25, "Acucar (1kg)", 5, 20},
        {26, "Sal", 2, 20},
        {27, "Farinha de Trigo (1kg)", 5, 20},
        {28, "Azeite", 15, 20},
        {29, "Farinha (1kg)", 3.5, 20}
    }
};

 static * getPointerListaProdutoAlimentos() {
    struct produto* pointer = &produtosAlimentos;
    return pointer;
}
