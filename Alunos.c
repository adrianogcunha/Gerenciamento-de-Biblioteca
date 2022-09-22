#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Dados.h"

//===================================================================
//Inserir alunos

void aumentar_cadastro_aluno(alunos ***vet_alunos, int *tam_vet_alunos){
	(*tam_vet_alunos) = (*tam_vet_alunos) + 100;

	*vet_alunos = realloc((*vet_alunos), sizeof((*tam_vet_alunos) * sizeof(alunos *)));
}

void cadastrar_aluno(alunos **vet_alunos, int *cad_alunos, int *tam_vet_alunos) {
	char aux_nome[50];
	char aux_matricula[50];

	puts("Digite o nome do aluno:");
	__fpurge(stdin);
	fgets(aux_nome, 50, stdin);
	strtok(aux_nome, "\n");
	puts("Digite a matricula do aluno:");
	__fpurge(stdin);
	fgets(aux_matricula, 50, stdin);
	strtok(aux_matricula, "\n");

	for (int i = 0; i <= (*cad_alunos); ++i) {
		if((vet_alunos[i] != NULL) && (strcmp(aux_matricula, vet_alunos[i]->matricula) == 0)) {
			puts("\nAluno já foi cadastrado!\n");
			return;
		}
	}

	++(*cad_alunos);
	if((*cad_alunos) == (*tam_vet_alunos)){
		aumentar_cadastro_aluno(&vet_alunos, tam_vet_alunos);
	}
	vet_alunos[(*cad_alunos)] = (alunos *)(malloc(sizeof(alunos)));
	vet_alunos[(*cad_alunos)]->id = (*cad_alunos);
	strcpy(vet_alunos[(*cad_alunos)]->nome, aux_nome);
	strcpy(vet_alunos[(*cad_alunos)]->matricula, aux_matricula);
	vet_alunos[(*cad_alunos)]->pendencia = 0;
	puts("\nAluno cadastrado com sucesso!\n");
}

//===================================================================
//Listar cadastros

void listar_alunos(alunos **vet_alunos, int *cad_alunos) {
	int aux = -1;
	for(int i = 0; i <= (*cad_alunos); ++i){
		if(vet_alunos[i] != NULL){
			puts("==========================================");
			printf("ID: %d\n", vet_alunos[i]->id);
			printf("Nome: %s\n", vet_alunos[i]->nome);
			printf("Matricula: %s\n", vet_alunos[i]->matricula);
		}else{
			++aux;
		}
	}
	puts("==========================================");
	printf("\n");

	if ((*cad_alunos) == -1) {
		puts("Não há nenhum aluno cadastrado!");
		printf("\n");
	}else if(((*cad_alunos) > -1) && (aux == (*cad_alunos))) {
		puts("Não há nenhum aluno cadastrado!");
		printf("\n");
	}
}

//===================================================================
//Remover aluno

void remover_aluno(alunos **vet_alunos, int *cad_alunos){
	int id;
	puts("Qual o ID do aluno que deseja remover?");
	scanf("%d", &id);
   if(vet_alunos[id] != NULL && id <= (*cad_alunos)){
   	if(vet_alunos[id]->pendencia == 0){
   		free(vet_alunos[id]);
   		vet_alunos[id] = NULL;
			printf("\nID: %d Removido com Sucesso!\n\n", id);
   	}else{
   		puts("\nO aluno tem alguma pendencia com a biblioteca, logo não pode ser removido!\n");
   	}
   }else{
      puts("\nEsse ID não está cadastrado, logo não é possivel remove-lo!\n");
   }
}

//===================================================================
//Buscar cadastro

void buscar_aluno(alunos **vet_alunos, int *cad_alunos){
	int id;
	puts("Qual o ID do aluno buscado?");
	scanf("%d", &id);
	if((vet_alunos[id] != NULL) && (id <= (*cad_alunos))){
		puts("==========================================");
		printf("ID: %d\n", vet_alunos[id]->id);
		printf("Nome: %s\n", vet_alunos[id]->nome);
		printf("Matricula: %s\n", vet_alunos[id]->matricula);
		puts("==========================================");
	}else{
		puts("\nAluno não encontrado!\n");
	}
}
