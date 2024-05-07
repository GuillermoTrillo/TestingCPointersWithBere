#include "genericHeader.h"

static struct quantidadeProdutos produtosLimpeza = {
    9,
    {
        {11,"Detergente", 1.99, 20},
        {12, "Sabao em Po (1kg)", 8.99, 20},
        {13, "Esponja (sem estoque)", 1.5, 20},
        {14, "Amaciante (1Lt)", 15, 20},
        {15, "Bucha de Pia (kit c/3)", 4.99, 20},
        {16, "Desinfetante (1Lt)", 7.99, 20},
        {17, "Sabão em Barra(Un)", 1, 20},
        {18, "Limpa Vidros", 6.5, 20},
        {19, "Sabao Liquido", 11, 20}
    }
};

 static * getPointerListaProdutoLimpeza() {
    struct produto* pointer = &produtosLimpeza;
    return pointer;
}
