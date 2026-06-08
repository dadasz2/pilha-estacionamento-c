#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Estrutura do veículo.

    Cada veículo possui:
    - placa
    - modelo
    - proprietário
    - ponteiro para o próximo veículo
*/

typedef struct Veiculo{

    char placa[15];
    char modelo[50];
    char proprietario[50];

    struct Veiculo *prox;

}Veiculo;

/*
    Ponteiro que guarda o topo da pilha.
    No início ele é vazio.
*/

Veiculo *topo = NULL;

/*
    Função para estacionar um veículo.

    Cria um novo nó e coloca ele no topo da pilha.
*/

void push(char placa[], char modelo[], char proprietario[]){

    Veiculo *novo = (Veiculo*) malloc(sizeof(Veiculo));

    if(novo == NULL){
        printf("Erro ao alocar memoria!\n");
        return;
    }

    strcpy(novo->placa, placa);
    strcpy(novo->modelo, modelo);
    strcpy(novo->proprietario, proprietario);

    // O novo veículo aponta para o antigo topo
    novo->prox = topo;

    // Agora ele passa a ser o topo
    topo = novo;

    printf("\nVeiculo estacionado com sucesso!\n");
}

/*
    Função para retirar um veículo.

    Remove o carro que está no topo.
*/

void pop(){

    if(topo == NULL){
        printf("\nNao ha veiculos estacionados.\n");
        return;
    }

    Veiculo *aux = topo;

    printf("\nVeiculo retirado:\n");
    printf("Placa: %s\n", aux->placa);
    printf("Modelo: %s\n", aux->modelo);
    printf("Proprietario: %s\n", aux->proprietario);

    topo = topo->prox;

    free(aux);
}

/*
    Mostra todos os veículos.

    Percorre a pilha do começo até o fim.
*/

void listar(){

    if(topo == NULL){
        printf("\nEstacionamento vazio.\n");
        return;
    }

    Veiculo *aux = topo;

    printf("\n====== VEICULOS ESTACIONADOS ======\n");

    while(aux != NULL){

        printf("\nPlaca: %s\n", aux->placa);
        printf("Modelo: %s\n", aux->modelo);
        printf("Proprietario: %s\n", aux->proprietario);

        aux = aux->prox;
    }

    printf("\n==================================\n");
}

/*
    Mostra apenas o veículo
    que está na saída.
*/

void mostrarTopo(){

    if(topo == NULL){
        printf("\nEstacionamento vazio.\n");
        return;
    }

    printf("\nVeiculo na saida:\n");
    printf("Placa: %s\n", topo->placa);
    printf("Modelo: %s\n", topo->modelo);
    printf("Proprietario: %s\n", topo->proprietario);
}

/*
    Salva os dados no arquivo.

    Foi utilizado um arquivo texto simples.
*/

void salvarArquivo(){

    FILE *arquivo;

    arquivo = fopen("estacionamento.txt", "w");

    if(arquivo == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    /*
        Conta quantos veículos existem.
    */

    int qtd = 0;

    Veiculo *aux = topo;

    while(aux != NULL){
        qtd++;
        aux = aux->prox;
    }

    if(qtd == 0){
        fclose(arquivo);
        return;
    }

    /*
        Vetor auxiliar para salvar
        na ordem correta.
    */

    Veiculo *vet[qtd];

    aux = topo;

    int i = qtd - 1;

    while(aux != NULL){

        vet[i] = aux;

        aux = aux->prox;

        i--;
    }

    for(i = 0; i < qtd; i++){

        fprintf(arquivo,
                "%s;%s;%s\n",
                vet[i]->placa,
                vet[i]->modelo,
                vet[i]->proprietario);
    }

    fclose(arquivo);
}

/*
    Carrega os veículos que estavam
    salvos no arquivo.
*/

void carregarArquivo(){

    FILE *arquivo;

    arquivo = fopen("estacionamento.txt", "r");

    // Caso seja a primeira execução
    if(arquivo == NULL)
        return;

    char linha[200];

    while(fgets(linha, sizeof(linha), arquivo)){

        linha[strcspn(linha,"\n")] = '\0';

        char *placa = strtok(linha,";");
        char *modelo = strtok(NULL,";");
        char *proprietario = strtok(NULL,";");

        if(placa != NULL &&
           modelo != NULL &&
           proprietario != NULL){

            push(placa, modelo, proprietario);
        }
    }

    fclose(arquivo);
}

/*
    Libera toda memória utilizada.
*/

void liberarMemoria(){

    Veiculo *aux;

    while(topo != NULL){

        aux = topo;

        topo = topo->prox;

        free(aux);
    }
}

/*
    Programa principal.
*/

int main(){

    // Carrega os dados salvos
    carregarArquivo();

    int opcao;

    char placa[15];
    char modelo[50];
    char proprietario[50];

    do{

        printf("\n");
        printf("=================================\n");
        printf("     SISTEMA DE ESTACIONAMENTO\n");
        printf("=================================\n");
        printf("1 - Estacionar veiculo\n");
        printf("2 - Retirar veiculo\n");
        printf("3 - Listar veiculos\n");
        printf("4 - Mostrar veiculo da saida\n");
        printf("5 - Salvar dados\n");
        printf("6 - Sair\n");
        printf("Opcao: ");

        scanf("%d",&opcao);

        getchar();

        switch(opcao){

            case 1:

                printf("Placa: ");
                fgets(placa,sizeof(placa),stdin);
                placa[strcspn(placa,"\n")] = '\0';

                printf("Modelo: ");
                fgets(modelo,sizeof(modelo),stdin);
                modelo[strcspn(modelo,"\n")] = '\0';

                printf("Proprietario: ");
                fgets(proprietario,sizeof(proprietario),stdin);
                proprietario[strcspn(proprietario,"\n")] = '\0';

                push(placa, modelo, proprietario);

                break;

            case 2:

                pop();

                break;

            case 3:

                listar();

                break;

            case 4:

                mostrarTopo();

                break;

            case 5:

                salvarArquivo();

                printf("\nDados salvos!\n");

                break;

            case 6:

                // Salva antes de fechar
                salvarArquivo();

                // Libera a memória
                liberarMemoria();

                printf("\nPrograma encerrado.\n");

                break;

            default:

                printf("\nOpcao invalida!\n");
        }

    }while(opcao != 6);

    return 0;
}