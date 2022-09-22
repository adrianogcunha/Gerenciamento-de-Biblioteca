#ifndef LIVROS_H
#define LIVROS_H

#include "Dados.h"
#include "Alunos.h"

void aumentar_cadastro_livros(livros ***vet_livros, int *tam_vet_livros);

void cadastrar_livro(livros **vet_livros, int *cad_livros, int *tam_vet_livros);

void remover_livro(livros **vet_livros, int *cad_livros);

void listar_livros(alunos **vet_alunos, livros **vet_livros, int *cad_livros);

void buscar_livro_id(alunos **vet_alunos, livros **vet_livros, int *cad_livros);

void buscar_livro_categoria(alunos **vet_alunos, livros **vet_livros, int *cad_livros);

void buscar_livro(alunos **vet_alunos, livros **vet_livros, int *cad_livros);

void emprestar_livro(livros **vet_livros, alunos **vet_alunos, int *cad_livros, int *cad_alunos);

void devolver_livro(livros **vet_livros, alunos **vet_alunos, int *cad_livros);

void emprestimo_livro(livros **vet_livros, alunos **vet_alunos, int *cad_livros, int *cad_alunos);

#endif
