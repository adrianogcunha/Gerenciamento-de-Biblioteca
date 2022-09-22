#ifndef MENU_H
#define MENU_H

#include "Dados.h"
#include "Alunos.h"
#include "Livros.h"
#include "Recursos.h"

void menu_aluno(alunos **vet_alunos, int *cad_alunos, int *tam_vet_alunos);

void menu_livros(alunos **vet_alunos, livros **vet_livros, int *cad_livros, int *cad_alunos, int *tam_vet_livros);

void menu_recursos(cab_recursos *cab, alunos **vet_alunos, int *cad_alunos);

#endif
