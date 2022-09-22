#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dados.h"
#include "Alunos.h"



//==============================================================================
//cadastrar_recurso

void cadastrar_recurso(cab_recursos *cab){
   int aux_id;
   int opt;
   char aux_tipo[50];
   recursos *ponteiro_aux;

   puts("Digite o ID do recurso:");
   scanf("%d", &aux_id);
   puts("Qual é o tipo?");
   puts("[1] - SALA");
   puts("[2] - COMPUTADOR");
   puts("[3] - ARMÁRIO");
   scanf("%d", &opt);

   switch (opt) {
      case 1:
         strcpy(aux_tipo, A);
         break;
      case 2:
         strcpy(aux_tipo, B);
         break;
      case 3:
         strcpy(aux_tipo, C);
         break;
   }

   ponteiro_aux = cab->inicio;
   while(ponteiro_aux != NULL){
      if (ponteiro_aux->id == aux_id) {
         puts("Esse ID já foi cadastrado");
         return;
      }
      ponteiro_aux = ponteiro_aux->prox;
   }

   recursos *novo_recurso = (recursos*)malloc(sizeof(recursos));

   novo_recurso->prox = cab->inicio;
   cab->inicio = novo_recurso;

   novo_recurso->id = aux_id;
   strcpy(novo_recurso->tipo, aux_tipo);
   novo_recurso->status = 0;
   novo_recurso->id_aluno_emp = 0;

	puts("\nRecurso cadastrado com Sucesso!!\n");

   //printf("%d\n", novo_recurso->id);
   //printf("%s", novo_recurso->tipo);
}

//================================================================
//Buscar recurso

void buscar_recurso(cab_recursos *cab, alunos **vet_alunos){
   recursos *ponteiro_aux;
   int aux_id;
   puts("Digite o ID do recurso que deseja buscar:");
   scanf("%d", &aux_id);

   ponteiro_aux = cab->inicio;
   while(ponteiro_aux != NULL){
      if (ponteiro_aux->id == aux_id) {
         puts("==========================================");
         printf("ID: %d\n", ponteiro_aux->id);
         printf("Tipo: %s\n", ponteiro_aux->tipo);
         printf("\n");
         if(ponteiro_aux->status == 0){
            puts("Status: DISPONIVEL");
         }else{
            puts("Status: EMPRESTADO");
            printf("O %s está emprestado para o aluno de matricula: %s\n", ponteiro_aux->tipo, vet_alunos[ponteiro_aux->id_aluno_emp]->matricula);
         }
         puts("==========================================");
         return;
      }
      ponteiro_aux = ponteiro_aux->prox;
   }
   puts("\nO recurso não foi cadastrado!\n");
}

//================================================================
//Lista recurso

void listar_recurso(cab_recursos *cab, alunos **vet_alunos){
   recursos *ponteiro_aux;

   ponteiro_aux = cab->inicio;
   if(ponteiro_aux == NULL){
      puts("\nNão há nenhum recurso cadastrado\n");
   }
   while(ponteiro_aux != NULL){
      puts("==========================================");
      printf("ID: %d\n", ponteiro_aux->id);
      printf("Tipo: %s\n", ponteiro_aux->tipo);
      printf("\n");
      if(ponteiro_aux->status == 0){
         puts("Status: DISPONIVEL");
      }else{
         puts("Status: EMPRESTADO");
         printf("O %s está emprestado para o aluno de matricula: %s\n", ponteiro_aux->tipo, vet_alunos[ponteiro_aux->id_aluno_emp]->matricula);
      }
      puts("==========================================");
      ponteiro_aux = ponteiro_aux->prox;
   }
}

//================================================================
//remover_recurso

void remover_recurso(cab_recursos *cab) {
   int aux_id;
   puts("Digite o ID que deseja remover:");
   scanf("%d", &aux_id);

   recursos *ponteiro_aux = cab->inicio;
   recursos *noARemover = NULL;

   if((cab->inicio != NULL) && (cab->inicio->id == aux_id) && (cab->inicio->status == 0)){ //verifica se é primeiro nó que quero remover
      noARemover = cab->inicio; //Coloco faço uma copia do & do nó que eu quero remover
      cab->inicio = noARemover->prox; //Igualo ao o cab ao proximo nó
	}else if((cab->inicio != NULL) && (cab->inicio->id == aux_id) && (cab->inicio->status != 0)){
		puts("\nO Recurso tem uma pendencia com o sistema, verifique antes de remove-lo!\n");
   }else{
      while((ponteiro_aux != NULL) && (ponteiro_aux->prox != NULL) && (ponteiro_aux->prox->id != aux_id)){
         ponteiro_aux = ponteiro_aux->prox;
      }
      if((ponteiro_aux != NULL) && (ponteiro_aux->prox != NULL) && (ponteiro_aux->prox->id == aux_id) && (ponteiro_aux->prox->status == 0)){
         noARemover = ponteiro_aux->prox;
         ponteiro_aux->prox = noARemover->prox;
      }else if((ponteiro_aux != NULL) && (ponteiro_aux->prox != NULL) && (ponteiro_aux->prox->id == aux_id) && (ponteiro_aux->prox->status != 0)){
         puts("\nO Recurso tem uma pendencia com o sistema, verifique antes de remove-lo!\n");
      }else{
         puts("\nEsse ID não está cadastrado!\n");
      }

   }
   if(noARemover){
      free(noARemover);
      printf("\nID: %d removido com sucesso!\n\n", aux_id);
   }
}

//================================================================
//Emprestar recurso

void emprestar_recurso(cab_recursos *cab, alunos **vet_alunos, int *cad_alunos) {
   system("clear");
	recursos *ponteiro_aux;
	int id_recurso;
   int id_aluno;

   puts("Qual é o ID do recurso que deseja emprestar?");
   scanf("%d", &id_recurso);
   puts("Qual é o ID do aluno que deseja pegar o recurso emprestado?");
   scanf("%d", &id_aluno);

	if((vet_alunos[id_aluno] == NULL) || (id_aluno > (*cad_alunos))){
      puts("\nEsse aluno não está cadastrado\n");
      return;
	}

	ponteiro_aux = cab->inicio;
   while(ponteiro_aux != NULL){
      if (ponteiro_aux->id == id_recurso) {
			if(ponteiro_aux->status == 1){
				puts("\nEsse recurso já está emprestado\n");
				return;
			}if(ponteiro_aux->status == 0){
				++vet_alunos[id_aluno]->pendencia;
				ponteiro_aux->id_aluno_emp = id_aluno;
				ponteiro_aux->status = 1;
				printf("\nO Recurso: %s foi emprestado!\n", ponteiro_aux->tipo);
	         return;
			}
      }
      ponteiro_aux = ponteiro_aux->prox;
   }
	puts("\nEsse recurso não está cadastrado\n");
}

void devolver_recurso(cab_recursos *cab, alunos **vet_alunos){
   system("clear");
	int id_recurso;
	recursos *ponteiro_aux;
   //int id_aluno;
   puts("Qual é o ID do recurso que deseja devolver?");
   scanf("%d", &id_recurso);


	ponteiro_aux = cab->inicio;
   while(ponteiro_aux != NULL){
      if (ponteiro_aux->id == id_recurso) {
			if(ponteiro_aux->status == 0){
				puts("\nEsse recurso já está disponivel!!\n");
				return;
			}if(ponteiro_aux->status == 1){
				--vet_alunos[ponteiro_aux->id_aluno_emp]->pendencia;
				ponteiro_aux->status = 0;
				printf("O Recurso: %s foi devolvido!\n\n", ponteiro_aux->tipo);
	         return;
			}
      }
      ponteiro_aux = ponteiro_aux->prox;
   }
	puts("\nEsse recurso não está cadastrado\n");
}

void emprestimo_recurso(cab_recursos *cab, alunos **vet_alunos, int *cad_alunos){
	int opt;
   puts("[1] - Pegar Emprestado;");
   puts("[2] - Devolver Recurso;");
	puts("[3] - Voltar;");
   puts("Escolha uma opcao:");
   scanf("%d", &opt);

   switch (opt) {
      case 1:
			system("cls");
         emprestar_recurso(cab, vet_alunos, cad_alunos);
         break;
      case 2:
			system("cls");
         devolver_recurso(cab, vet_alunos);
         break;
		case 3:
			return;
   }
}
