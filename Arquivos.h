#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "Dados.h"
#include "Alunos.h"
#include "Livros.h"
#include "Recursos.h"
#include "Menu.h"

void cryptografar(char *mensagem, char *arquivo, FILE *exportar);

void descryptografar(char *mensagem, char *arquivo, FILE *importar);

void exportar_arq(char *mensagem, char *arquivo, cab_recursos *cab, alunos **vet_alunos, int *cad_alunos, livros **vet_livros, int *cad_livros, FILE *exportar);

void importar_arq(char *mensagem, char *arquivo, cab_recursos *cab, alunos **vet_alunos, int *cad_alunos, livros **vet_livros, int *cad_livros, FILE *importar, int *tam_vet_alunos, int *tam_vet_livros);

#endif
