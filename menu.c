#include <stdio.h>

int main(){

    int opcao;

    do{
        printf("\n========================================\n");
		printf(" SISTEMA DA HAMBURGUERIA\n");
		printf("========================================\n");
		printf("1 - Cadastrar produto\n");
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
