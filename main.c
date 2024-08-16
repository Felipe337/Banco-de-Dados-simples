#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main() {
    int opcao;

    while (1) {
        printf("\nBanco de Dados Simples\n");
        printf("1. Adicionar usuário\n");
        printf("2. Exibir usuários\n");
        printf("3. Buscar usuário por ID\n");
        printf("4. Editar usuário\n");
        printf("5. Deletar usuário\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarUsuario();
                break;
            case 2:
                exibirUsuarios();
                break;
            case 3:
                buscarUsuario();
                break;
            case 4:
                editarUsuario();
                break;
            case 5:
                deletarUsuario();
                break;
            case 6:
                printf("Encerrando o programa.\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n"); } }

    return 0;
}
