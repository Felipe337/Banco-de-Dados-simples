#ifndef FUNC_H
#define FUNC_H

#define MAX_USUARIOS 100
#define TAM_NOME 50

typedef struct {
    int id;
    char nome[TAM_NOME];
    int idade;
} Usuario;

extern Usuario bancoDados[MAX_USUARIOS];
extern int totalUsuarios;

void adicionarUsuario();
void exibirUsuarios();
void buscarUsuario();
void editarUsuario();
void deletarUsuario();

#endif
