#ifndef RECURSOS_H
#define RECURSOS_H

#include "Dados.h"
#include "Alunos.h"

void cadastrar_recurso(cab_recursos *cab);

void buscar_recurso(cab_recursos *cab, alunos **vet_alunos);

void listar_recurso(cab_recursos *cab, alunos **vet_alunos);

void remover_recurso(cab_recursos *cab);

void emprestar_recurso(cab_recursos *cab, alunos **vet_alunos, int *cad_alunos);

void devolver_recurso(cab_recursos *cab, alunos **vet_alunos);

void emprestimo_recurso(cab_recursos *cab, alunos **vet_alunos, int *cad_alunos);


#endif
