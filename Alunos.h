#ifndef ALUNOS_H
#define ALUNOS_H

#include "dados.h"

///Função utilizada para aumentar o vetor de ponteiros.

///O vetor começa com 100 posições, e quando atinge seu limite, essa função é chamada, para acrescentar mais 100 posições.

/// @param vet_alunos Vetor de ponteiros;
/// @param tam_vet_alunos Tamanho do vetor de ponteiros;
/// @note Ela é utilizada dentro da funçao cadastrar_aluno().
/// @warning Essa função é essencial para manter o codigo funcionando, pois sem ela, o codigo teria um limite de cadastrados;
void aumentar_cadastro_aluno(alunos ***vet_alunos, int *tam_vet_alunos);

///Função utilizada para cadastrar novos alunos.

/// @param vet_alunos Vetor de ponteiros;
/// @param tam_vet_alunos Tamanho do vetor de ponteiros;
/// @param cad_alunos Contador de alunos cadastrados;
void cadastrar_aluno(alunos **vet_alunos, int *cad_alunos, int *tam_vet_alunos);

///Função utilizada para listar todos os alunos cadastrados.

/// @param vet_alunos Vetor de ponteiros;
/// @param cad_alunos Contador de alunos cadastrados;
void listar_alunos(alunos **vet_alunos, int *cad_alunos);

///Função utilizada para remover um aluno através de seu ID.

/// @param vet_alunos Vetor de ponteiros;
/// @param cad_alunos Contador de alunos cadastrados;
void remover_aluno(alunos **vet_alunos, int *cad_alunos);

///Função utilizada para buscar um aluno através de seu ID.

/// @param vet_alunos Vetor de ponteiros;
/// @param cad_alunos Contador de alunos cadastrados;
void buscar_aluno(alunos **vet_alunos, int *cad_alunos);

#endif
