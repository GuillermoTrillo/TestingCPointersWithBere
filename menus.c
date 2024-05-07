#include "genericHeader.h"

static void menuPrincipal()
{
    printf("-- MENU PRINCIPAL --");
    printf("\n");
    printf("1. Materiais de Limpeza");
    printf("\n");
    printf("2. Alimentos");
    printf("\n");
    printf("3. Padaria");
    printf("\n");
    printf("4. Pagamento");
    printf("\n");
    printf("5. Abertura de caixa");
    printf("\n");
    printf("6. Fechamento de caixa");
    printf("\n");
    printf("-- FIM MENU PRINCIPAL --");
    printf("\n");
}


 static void printPadaria(struct quantidadeProdutos* storePointer) {
    printf("Codigo /// Nome do produto /// Preco /// quantidade em estoque \n");
     for(int i = 0; i < storePointer->referencia; i++) {
        printf("%d", (storePointer->produto+i)->codigo);
        printf(" /// ");
        printf("%s", (storePointer->produto+i)->nome);
        printf(" /// ");
        printf("%0.2f", (storePointer->produto+i)->preco);
        printf("\n");
        printf("%d", (storePointer->produto+i)->estoque);
        printf("\n");
     }

}
