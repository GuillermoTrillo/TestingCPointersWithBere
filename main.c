#include "headerMain.h"

float troco = 0.0;
int main()
{
    //struct quantidadeProdutos* padariaPointer = getPointerListaProdutoPadarias();
    int *trocoPointer = &troco;
    setarTroco(trocoPointer);

    //menuPrincipal();
    return 0;
}
