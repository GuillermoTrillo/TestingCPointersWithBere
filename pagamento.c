#include "genericHeader.h"

static int saldoIsSet = 0;

static void resetTroco() {
    saldoIsSet = 0;
}
static void setTroco(float *trocoPointer) {

    float cashBalance = 0.0;

    if(saldoIsSet == 1){
        return;
    }

    printf("Informe o saldo do caixa:\n");
    scanf("%f", &cashBalance);

    if(cashBalance > 0) {
        saldoIsSet = 1;
        *trocoPointer = cashBalance;
        return;
    }
    else {
        printf("Valor inválido! Tente de novo!");
        sleep(1);
        system("cls");
        setTroco(trocoPointer);
    }

}
