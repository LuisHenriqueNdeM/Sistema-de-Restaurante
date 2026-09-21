#include <stdio.h>
#include <stdlib.h>

typedef struct{
char nome[30];
int codigo;
char categoria[20];
float preco;
} Produto;

void Cadastrar(int totalProdutos, Produto *produtos){
    
    for(int i = 0; i < totalProdutos; i++){
        printf("\nProduto número %d:", i+1);
        
        printf("\nNome do produto: ");
        scanf("%[^\n]", produtos[i].nome);
        
        printf("\nCódigo do produto:");
        scanf("%d", &produtos[i].codigo);
        
        printf("\nCategoria do produto:");
        scanf("%[^\n]", produtos[i].categoria);
        
        printf("\nPreço do produto:");
        scanf("%f", &produtos[i].preco);
    }
}

int main(){

    int opcao;
	int totalProdutos;
    Produto *produtos = 0;
    do{
        printf("\n========================================\n");
		printf(" SISTEMA DO RESTAURANTE\n");
		printf("========================================\n");
		printf("1 - Cadastrar produtos\n");
		printf("2 - Listar cardápio\n");
		printf("3 - Cadastrar pedidos\n");
		printf("4 - Calcular pedido\n");
		printf("5 - Consultar pedido\n");
		printf("6 - Alteração/Cancelamento\n");
		printf("7 - Fechamento de conta\n");
		printf("0 - Sair\n");
		printf("========================================\n");
		printf("Escolha uma opção: ");
		scanf("%d", &opcao);
		switch (opcao) {
            case 1:
				printf("\n===========CADASTRO DE PRODUTOS=============\n");
				printf("Quantas opções de produto terá no restaurante?\n");
				scanf("%d", &totalProdutos);
				produtos = (Produto *) malloc(totalProdutos * sizeof(Produto));
				Cadastrar(totalProdutos, produtos);
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
        } 
    }while (opcao != 0);
    return 0;
}
