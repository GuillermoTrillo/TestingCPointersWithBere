#include "genericHeader.h"

static struct quantidadeProdutos produtosPadaria = {
    8,
    {
        {31, "Pao de Forma", 9.5, 20},
        {32, "Pao Integral", 12.5, 20},
        {33, "Pao Frances(Unid)", 1.9, 20},
        {34, "Sonho", 8.5, 20},
        {35, "Biscoito(kg)", 12.5, 20},
        {36, "Pão Doce (Un)", 2.5, 20},
        {37, "Salgado (Un)", 17.5, 20},
        {38, "Torta de Limao", 25, 20}
    }
};

 static * getPointerListaProdutoPadarias() {
    struct produto* pointer = &produtosPadaria;
    return pointer;
}
