#include "genericHeader.h"

static int saldoEstaSetado = 0;

static void setarTroco(float *trocoPointer) {

    float saldoCaixa = 0.0;

    if(saldoEstaSetado == 1){
        return;
    }

    printf("Informe o saldo do caixa:\n");
    scanf("%f", &saldoCaixa);

    if(saldoCaixa > 0) {
        saldoEstaSetado = 1;
        *trocoPointer = saldoCaixa;
        return;
    }
    else {
        printf("Valor inválido! Tente de novo!");
        sleep(1);
        system("cls");
        setarTroco(trocoPointer);
    }

}
