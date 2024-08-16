#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USUARIOS 100
#define TAM_NOME 50


typedef struct {
    int id;
    char nome[TAM_NOME];
    int idade;
} Usuario;

Usuario bancoDados[MAX_USUARIOS];
int totalUsuarios = 0;
void adicionarUsuario();
void exibirUsuarios();
void buscarUsuario();
void editarUsuario();
void deletarUsuario();


void adicionarUsuario() {
    if (totalUsuarios >= MAX_USUARIOS) {
        printf("Banco de dados cheio! Não é possível adicionar mais usuários.\n");
        return; }

    Usuario novoUsuario;
    novoUsuario.id = totalUsuarios + 1;

    printf("Digite o nome do usuário: ");
    getchar();
    fgets(novoUsuario.nome, TAM_NOME, stdin);
    novoUsuario.nome[strcspn(novoUsuario.nome, "\n")] = '\0';

    printf("Digite a idade do usuário: ");
    scanf("%d", &novoUsuario.idade);

    bancoDados[totalUsuarios] = novoUsuario;
    totalUsuarios++;

    printf("Usuário adicionado com sucesso!\n"); }

void exibirUsuarios() {
    if (totalUsuarios == 0) {
        printf("Nenhum usuário cadastrado.\n");
        return; }

    printf("Lista de Usuários:\n");
    for (int i = 0; i < totalUsuarios; i++) {
        printf("ID: %d, Nome: %s, Idade: %d\n", bancoDados[i].id, bancoDados[i].nome, bancoDados[i].idade); } }

void buscarUsuario() {
    int id;
    printf("Digite o ID do usuário: ");
    scanf("%d", &id);

    for (int i = 0; i < totalUsuarios; i++) {
        if (bancoDados[i].id == id) {
            printf("Usuário encontrado: ID: %d, Nome: %s, Idade: %d\n", bancoDados[i].id, bancoDados[i].nome, bancoDados[i].idade);
            return; } }
    printf("Usuário com ID %d não encontrado.\n", id); }

void editarUsuario() {
    int id;
    printf("Digite o ID do usuário a ser editado: ");
    scanf("%d", &id);

    for (int i = 0; i < totalUsuarios; i++) {
        if (bancoDados[i].id == id) {
            printf("Digite o novo nome do usuário: ");
            getchar();
            fgets(bancoDados[i].nome, TAM_NOME, stdin);
            bancoDados[i].nome[strcspn(bancoDados[i].nome, "\n")] = '\0';

            printf("Digite a nova idade do usuário: ");
            scanf("%d", &bancoDados[i].idade);

            printf("Usuário atualizado com sucesso!\n");
            return; } }
    printf("Usuário com ID %d não encontrado.\n", id); }

void deletarUsuario() {
    int id;
    printf("Digite o ID do usuário a ser deletado: ");
    scanf("%d", &id);

    for (int i = 0; i < totalUsuarios; i++) {
        if (bancoDados[i].id == id) {
            for (int j = i; j < totalUsuarios - 1; j++) {
                bancoDados[j] = bancoDados[j + 1]; }
            totalUsuarios--;
            printf("Usuário deletado com sucesso!\n");
            return; } }
    printf("Usuário com ID %d não encontrado.\n", id); }

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
    return 0; }
