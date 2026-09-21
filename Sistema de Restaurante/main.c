#include "sistema.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Cadastrar(int totalProdutos, PRODUTO *produto){ //Cria o cadastro dos produtos
    
    for(int i = 0; i < totalProdutos; i++){ //laço para abranger a quantidade informada de produtos
        printf("\n\tProduto número %d:\n", i + 1);

        printf("Nome do produto: ");
        getchar(); //limpar o lixo do teclado
        fgets(produtos[i].nome, sizeof(produto[i].nome), stdin);//função fgets e strcspn para aumentar a dinamicidade e facilidade do código
        produtos[i].nome[strcspn(produto[i].nome, "\n")] = '\0';

        printf("Código do produto: ");
        scanf("%d", &produto[i].codigo);

        printf("Categoria do produto: ");
        getchar();//limpar o lixo do teclado
        fgets(produto[i].categoria, sizeof(produto[i].categoria), stdin);//função fgets e strcspn para aumentar a dinamicidade e facilidade do código
        produto[i].categoria[strcspn(produto[i].categoria, "\n")] = '\0';

        printf("Preço do produto: R$ ");
        scanf("%f", &produto[i].preco);
    }
}

int main(){

    int opcao;
	int totalProdutos;
    Produto *produto = 0;
    
    //escolha de 'do while' para executar o menu ao menos uma vez
    
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
		
		//craição das 'escolhas'
		
		switch (opcao) {
            case 1:
				printf("\n===========CADASTRO DE PRODUTOS=============\n"); //deixar a interface do código mais organizada
				printf("Quantas opções de produto terá no restaurante?\n");
				scanf("%d", &totalProdutos);
				produtos = (PRODUTO *) malloc(totalProdutos * sizeof(PRODUTO));
				Cadastrar(totalProdutos, produto);
            break;
            
			case 2:
            break;
            
			case 3:
            break;
            
			case 4:
            break;
           
			case 5:

				consultar_pedido(pedido);
				
            break;
            
			case 6:
            break;
           
			case 7:
            break;
			
			default:
			printf("Opção inválida.");
			break;
        } 
    }while (opcao != 0); //para o código não ficar em loop...
    return 0;
}
