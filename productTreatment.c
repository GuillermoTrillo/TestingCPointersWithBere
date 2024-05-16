#include "genericHeader.h"

static struct quantidadeProdutos* lojaPointer;
static int produtoIndex = 0;
//atualiza o estoque do item, e devolve se a quantidade pedida eh valida
static int updateEstoque(int quantity) {

    if(quantity <= 0) {
        return -1;
    }
    else if(quantity > (lojaPointer->produto+produtoIndex)->estoque) {
        return 0;
    }
    else {
        (lojaPointer->produto+produtoIndex)->estoque -= quantity;
        return quantity;
    }

}

//vai receber a quantidade
static int takeQuantity(){
    int quantity = 0;
    printf("Insira a quantidade de unidades: ");
    scanf("%d", &quantity);
    return updateEstoque(quantity);
}

//encontra o produto definido pelo usuario
static  int findProduct() {
    int produtoCode = 0;
    int quantity = 0;

    scanf("%d", &produtoCode);

    for(int i = 0; i < lojaPointer->referencia; i++) {
        if(produtoCode == (lojaPointer->produto+i)->codigo) {
            produtoIndex = i;
            quantity = takeQuantity(i);
            break;
        }
    }
    return quantity;
}

//gerencia que o codigo correspondente passe a resposta correspondente
static float treatQuantityResponse() {

    float quantity = findProduct();

    if(produtoIndex == -1) {
        return -1;
    }

    if(quantity == 0) {
        return 0;
    }
    else if(quantity < 0) {
        printf("Insira um valor valido.");
        sleep(2);
        return -1;
    }
    else {
        return quantity * (lojaPointer->produto+produtoIndex)->preco;
    }
}

static float defineDefaultVariables(struct quantidadeProdutos* activePointer) {
    produtoIndex = -1;
    lojaPointer = activePointer;
    return treatQuantityResponse();
}
