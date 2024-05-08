#include "headerMain.h"

float troco = 0.0;
int activeLoja = 0;
static struct gastos allGastos  = {0,0,0,0};
struct gastos* gastosPointer = &allGastos;

struct quantidadeProdutos* LojaPointer;

//come�a o sistema, setando o troco, mostrando a mensagem de bem-vindo
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int *trocoPointer = &troco;
    setTroco(trocoPointer);
    welcome();
    inicializeSystem();
    return 0;
}
//inicializa o sistema, mostrando o menu principal e chamando o redirecionamento
void inicializeSystem() {

    showPayQuantity(gastosPointer);
    mainMenu();
    redirectUser();
}

//redireciona o usuario para a funcao correspondente
void redirectUser()
{
    int entrada = 0;
    scanf("%d", &entrada);

    switch(entrada)
    {
        case 1:
            //chama material de limpeza
            getLimpeza();
            break;
        case 2:
            //chama Venda de alimentos
            getAlimentos();
            break;
        case 3:
            //chama Padaria
            getPadaria();
            break;
        case 4:
            //chama pagamento
            chamarPagamento();
            break;
        case 5:
            //chama abrir caixa
            resetTroco();
            main();
            break;
        case 6:
            //chama mostrar faturamento diario
            terminarFaturamento();
            break;
        default:
            //avisa que o valor eh invalido e redireciona para o menu
            printf("Escreva um valor valido.");
            main();
            break;
    }
}

//recebe os produtos por um punteiro de Limpeza
void getLimpeza() {
    LojaPointer = getPointerListaProdutoLimpeza();
    activeLoja = 1;
    showStore(LojaPointer);
}
//recebe os produtos por um punteiro de Limpeza
void getAlimentos() {
    LojaPointer = getPointerListaProdutoAlimentos();
    activeLoja = 2;
    showStore(LojaPointer);
}
//recebe os produtos por um punteiro de Limpeza
void getPadaria() {
    LojaPointer = getPointerListaProdutoPadarias();
    activeLoja = 3;
    showStore(LojaPointer);
}
//chama a printagem da loja, enviando o ponteiro da loja escolhida
void showStore() {
    printStore(LojaPointer);
    redirectStore();
}
//chama o gerenciador do input do usuario, e usa sua resposta para redirecionar o usuario
void redirectStore() {
    int inputAnswer = 0;
    inputAnswer = manageInput(LojaPointer);

    if(inputAnswer == 0) {
        inicializeSystem();
    }
    else if(inputAnswer < 0) {
        showStore();
    }
    else {
        insertPrecoInGastos(inputAnswer);
    }
}
//inserta o preco do produto selecionado pelo manageInput na variavel gastos
void insertPrecoInGastos(float preco) {
    if(activeLoja == 1) {
        allGastos.gastosLimpeza += preco;
    }
    else if(activeLoja == 2) {
        allGastos.gastosAlimentos += preco;
    }
    else if(activeLoja == 3) {
        allGastos.gastosPadaria += preco;
    }
    else {
        printf("\n Nenhuma loja aparentemente ativa. Valor ser� somente inserido dentro dos gastos totais. \n");
    }
    allGastos.gastosTotais += preco;
    showStore();
}


void chamarPagamento() {
}

void terminarFaturamento() {
}

// mostra os atuais gastos do usuario
void showPayQuantity()
{
    system("cls | clear");
    printf("--/--/--/--/--/--/");
    printf("\n");
    printf("Valor da Limpeza a pagar: %0.2f", allGastos.gastosLimpeza);
    printf("\n");
    printf("Valor de Alimentos a pagar: %0.2f", allGastos.gastosAlimentos);
    printf("\n");
    printf("Valor da Padaria a pagar: %0.2f", allGastos.gastosPadaria);
    printf("\n");
    printf("Valor a pagar: %0.2f", allGastos.gastosTotais);
    printf("\n");
    printf("--/--/--/--/--/--/");
    printf("\n \n");
}
