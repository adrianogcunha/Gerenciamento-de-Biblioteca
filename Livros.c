#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Dados.h"
#include "Alunos.h"

//===================================================================
//Inserir Livros

void aumentar_cadastro_livros(livros ***vet_livros, int *tam_vet_livros){
	(*tam_vet_livros) = (*tam_vet_livros) + 100;

	*vet_livros = realloc((*vet_livros), sizeof((*tam_vet_livros) * sizeof(livros *)));
}

void cadastrar_livro(livros **vet_livros, int *cad_livros, int *tam_vet_livros) {
	char aux_nome[50];
   char aux_categoria[50];
   int aux_ano_publi;

	puts("Digite o nome do Livro:");
	__fpurge(stdin);
	fgets(aux_nome, 50, stdin);
	strtok(aux_nome, "\n");
   puts("Digite qual é a categoria do Livro (EM LETRA MAIÚSCULA):");
	__fpurge(stdin);
	fgets(aux_categoria, 50, stdin);
	strtok(aux_categoria, "\n");
   puts("Digite o ano do Livro:");
	scanf("%d", &aux_ano_publi);


	++(*cad_livros);
	if((*cad_livros) == (*tam_vet_livros)){
		aumentar_cadastro_livros(&vet_livros, tam_vet_livros);
	}

	vet_livros[(*cad_livros)] = (livros *)(malloc(sizeof(livros))); //Alocando dinamicamente espaço para uma struct dentro do vetor de ponteiro
	vet_livros[(*cad_livros)]->id = (*cad_livros);
	strcpy(vet_livros[(*cad_livros)]->nome, aux_nome);
   strcpy(vet_livros[(*cad_livros)]->categoria, aux_categoria);
   vet_livros[(*cad_livros)]->ano_publi = aux_ano_publi;
	vet_livros[(*cad_livros)]->status = -1; //DISPONIVEL
	puts("\nLivro cadastrado com sucesso!\n");
}

//===================================================================
//Remover Livro

void remover_livro(livros **vet_livros, int *cad_livros){
	int id;
	puts("Qual o ID do Livro que deseja remover?");
	scanf("%d", &id);
   if(vet_livros[id] != NULL && id <= (*cad_livros)){
   	if(vet_livros[id]->status == -1){
   		free(vet_livros[id]);
   		vet_livros[id] = NULL;
         printf("\nID: %d Removido com Sucesso!\n\n", id);
   	}else{
   		puts("\nO Livro está emprestado, logo, não pode ser removido!\n");
   	}
   }else{
      puts("\nEsse ID não está cadastrado, logo não é possivel remove-lo\n");
   }
}

//===================================================================
//Listar cadastros

void listar_livros(alunos **vet_alunos, livros **vet_livros, int *cad_livros) {
	int aux = -1;
	for(int i = 0; i <= (*cad_livros); ++i){
		if(vet_livros[i] != NULL){
			puts("==========================================");
			printf("ID: %d\n", vet_livros[i]->id);
			printf("Nome: %s\n", vet_livros[i]->nome);
			printf("Ano de Publicação: %d\n", vet_livros[i]->ano_publi);
         printf("Categorio: %s\n", vet_livros[i]->categoria);
			printf("\n");
         //status
         if(vet_livros[i]->status == -1){
            puts("Status: DISPONIVEL");
         }else{
            printf("Status: EMPRESTADO\n O livro está emprestado ao aluno de matricula: %s\n", vet_alunos[vet_livros[i]->status]->matricula);
         }
		}else{
			++aux;
		}
	}
	puts("==========================================");
	printf("\n");

	if ((*cad_livros) == -1) {
		puts("Não há nenhum livro cadastrado!");
		printf("\n");
	}else if(((*cad_livros) > -1) && (aux == (*cad_livros))) {
		puts("Não há nenhum livro cadastrado!");
		printf("\n");
	}
}

//===================================================================
//Buscar cadastro

void buscar_livro_id(alunos **vet_alunos, livros **vet_livros, int *cad_livros){
	system("clear");
	int id;
	puts("Qual o ID do aluno buscado?");
	scanf("%d", &id);
   if((vet_livros[id] != NULL) && (id <= (*cad_livros))){
      puts("==========================================");
      printf("ID: %d\n", vet_livros[id]->id);
      printf("Nome: %s\n", vet_livros[id]->nome);
      printf("Ano de Publicação: %d\n", vet_livros[id]->ano_publi);
      printf("Categorio: %s\n", vet_livros[id]->categoria);
		printf("\n");
      //status
      if(vet_livros[id]->status == -1){
         puts("Status: DISPONIVEL");
      }else{
         printf("Status: EMPRESTADO\n O livro está emprestado ao aluno de matricula: %s\n", vet_alunos[vet_livros[id]->status]->matricula);
      }
      puts("==========================================");
   }else{
		printf("\n");
		puts("Livro não encontrado!");
	}
}

void buscar_livro_categoria(alunos **vet_alunos, livros **vet_livros, int *cad_livros){
	system("clear");
   char categoria[50];
	int aux = -1;
   puts("Qual a categoria que deseja buscar? (EM LETRA MAIUSCULA)");
   scanf("%s", categoria);

   for(int i = 0; i <= (*cad_livros); ++i){
      if((vet_livros[i] != NULL) && (strcmp(categoria, vet_livros[i]->categoria) == 0)) {
         puts("==========================================");
         printf("ID: %d\n", vet_livros[i]->id);
         printf("Nome: %s\n", vet_livros[i]->nome);
         printf("Ano de Publicação: %d\n", vet_livros[i]->ano_publi);
         printf("Categorio: %s\n", vet_livros[i]->categoria);
			printf("\n");
         //status
         if(vet_livros[i]->status == -1){
            puts("Status: DISPONIVEL");
         }else{
            printf("Status: EMPRESTADO\n O livro está emprestado ao aluno de matricula: %s\n", vet_alunos[vet_livros[i]->status]->matricula);
         }
         puts("==========================================");
      }else{
         ++aux;
      }
	}

	printf("\n");

	if ((*cad_livros) == -1) {
		puts("Não há nenhum livro cadastrado!");
	}else if(((*cad_livros) > -1) && (aux == (*cad_livros))) {
		puts("Não há livros dessa categoria!");
	}

}

void buscar_livro(alunos **vet_alunos, livros **vet_livros, int *cad_livros){
   int opt;
   puts("[1] - Buscar Libro por ID;");
   puts("[2] - Buscar Livro por Categorio;");
   puts("Escolha uma opcao:");
   scanf("%d", &opt);

   switch (opt) {
      case 1:
         buscar_livro_id(vet_alunos, vet_livros, cad_livros);
         break;
      case 2:
         buscar_livro_categoria(vet_alunos, vet_livros, cad_livros);
         break;
   }
}

//===================================================================
//Emprestimo Livro

void emprestar_livro(livros **vet_livros, alunos **vet_alunos, int *cad_livros, int *cad_alunos){
	system("clear");
   int id_livro;
   int id_aluno;
   puts("Qual é o ID do livro que deseja emprestar?");
   scanf("%d", &id_livro);
   puts("Qual é o ID do aluno que deseja pegar o livro emprestado?");
   scanf("%d", &id_aluno);
   //verificar se aluno e livro existe

   if((vet_alunos[id_aluno] == NULL) || (id_aluno > (*cad_alunos))){
      puts("Esse aluno não está cadastrado");
      return;
   }if((vet_livros[id_livro] == NULL) || (id_livro > (*cad_livros))){
      puts("Esse livro não está cadastrado");
      return;
   }else{
      if(vet_livros[id_livro]->status >= 0){
         puts("Esse livro já está emprestado");
      }else{
         vet_livros[id_livro]->status = vet_alunos[id_aluno]->id;
         ++vet_alunos[id_aluno]->pendencia;
			printf("\n");
			puts("Livro foi Emprestado com Sucesso!!");
      }
   }
}

void devolver_livro(livros **vet_livros, alunos **vet_alunos, int *cad_livros){
	system("clear");
   int id_livro;
   //int id_aluno;
   puts("Qual é o ID do livro que deseja devolver?");
   scanf("%d", &id_livro);

   if((vet_livros[id_livro] == NULL) || (id_livro > (*cad_livros))){
      puts("Esse livro não está cadastrado");
      return;
   }else{
      if(vet_livros[id_livro]->status == -1){
         puts("Esse livro não está emprestado");
      }else{
         --vet_alunos[vet_livros[id_livro]->status]->pendencia;
         vet_livros[id_livro]->status = -1;
			printf("\n");
			puts("Livro foi Devolvido com Sucesso!!");
      }
   }
}

void emprestimo_livro(livros **vet_livros, alunos **vet_alunos, int *cad_livros, int *cad_alunos){
   int opt;
   puts("[1] - Pegar Emprestado;");
   puts("[2] - Devolver Livro;");
	puts("[3] - Voltar;");
   puts("Escolha uma opcao:");
   scanf("%d", &opt);

   switch (opt) {
      case 1:
         emprestar_livro(vet_livros, vet_alunos, cad_livros, cad_alunos);
         break;
      case 2:
         devolver_livro(vet_livros, vet_alunos, cad_livros);
         break;
		case 3:
			return;
   }
}
