#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

Usuario bancoDados[MAX_USUARIOS];
int totalUsuarios = 0;

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
