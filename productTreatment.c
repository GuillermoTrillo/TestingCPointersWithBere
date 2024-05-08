#include "genericHeader.h"

static struct quantidadeProdutos* lojaPointer;
static int cycle = 0;

static int updateEstoque(int quantity) {
    if(quantity <= 0) {
        return -1;
    }
    else if(quantity > (lojaPointer->produto+cycle)->estoque) {
        return 0;
    }
    else {
        (lojaPointer->produto+cycle)->estoque -= quantity;
        return quantity;
    }
}

static int takeQuantity(){
    int quantity = 0;
    printf("Insira a quantidade de unidades: ");
    scanf("%d", &quantity);
    return updateEstoque(quantity);
}
static  int bruh() {
    int produtoCode = 0;
    int quantity = 0;

    scanf("%d", &produtoCode);

    for(int i = 0; i < lojaPointer->referencia; i++) {
        if(produtoCode == (lojaPointer->produto+i)->codigo) {
            cycle = i;
            quantity = takeQuantity(i);
            break;
        }
    }
    return quantity;
}
//gerencia que o codigo correspondente passe o preco correspondente
static float manageInput(struct quantidadeProdutos* activePointer) {
    int quantity = 0;
    cycle = -1;
    lojaPointer = activePointer;

    quantity = bruh();

    if(cycle == -1) {
        return 0;
    }
    else if(quantity == 0) {
        printf("Esse valor é inválido, pois supera a quantidade de estoque atual.");
        sleep(1);
        return -1;
    }
    else if(quantity < 0) {
        printf("Insira um valor valido.");
        sleep(1);
        return -1;
    }
    else {
        return quantity * (lojaPointer->produto+cycle)->preco;
    }

}
