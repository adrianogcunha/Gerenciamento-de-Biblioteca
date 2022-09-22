#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Dados.h"
#include "Alunos.h"
#include "Livros.h"
#include "Recursos.h"

void menu_aluno(alunos **vet_alunos, int *cad_alunos, int *tam_vet_alunos){
	int opt;
	for(;;){
		system("clear");
		puts("============================================");
		puts("                 SECAO ALUNO                ");
		puts("============================================");
		puts("[1] - Cadastrar Aluno;");
		puts("[2] - Remover Aluno;");
		puts("[3] - Listar Alunos;");
		puts("[4] - Buscar Aluno;");
		puts("[5] - Voltar ao Menu Inicial;");
		puts("Digite a opção desejada:");
		scanf("%d", &opt);

		switch (opt) {
			case 1:
				system("clear");
				cadastrar_aluno(vet_alunos, cad_alunos, tam_vet_alunos);
				puts("Pressione ENTER para continuar...");
				__fpurge(stdin);
				getchar();
				__fpurge(stdin);
				break;
			case 2:
				system("clear");
				remover_aluno(vet_alunos, cad_alunos);
				puts("Pressione ENTER para continuar...");
				__fpurge(stdin);
				getchar();
				__fpurge(stdin);
				break;
			case 3:
				system("clear");
				listar_alunos(vet_alunos, cad_alunos);
				puts("Pressione ENTER para continuar...");
				__fpurge(stdin);
				getchar();
				__fpurge(stdin);
				break;
			case 4:
				system("clear");
				buscar_aluno(vet_alunos, cad_alunos);
				puts("Pressione ENTER para continuar...");
				__fpurge(stdin);
				getchar();
				__fpurge(stdin);
				break;
			case 5:
				return;
		}
	}
}

void menu_livros(alunos **vet_alunos, livros **vet_livros, int *cad_livros, int *cad_alunos, int *tam_vet_livros){
	int opt;
	for(;;){
		system("clear");
		puts("============================================");
		puts("                SECAO LIVROS                ");
		puts("============================================");
		puts("[1] - Cadastrar Livro;");
		puts("[2] - Remover Livro;");
		puts("[3] - Listar Livro;");
		puts("[4] - Buscar Livro;");
      puts("[5] - Emprestar/Devolver Livro;");
		puts("[6] - Voltar ao Menu Inicial;");
		puts("Digite a opção desejada:");
		scanf("%d", &opt);

		switch (opt) {
			case 1:
				system("clear");
			   cadastrar_livro(vet_livros, cad_livros, tam_vet_livros);
				puts("Pressione ENTER para continuar...");
				__fpurge(stdin);
				getchar();
				__fpurge(stdin);
				break;
			case 2:
				system("clear");
				remover_livro(vet_livros, cad_livros);
				puts("Pressione ENTER para continuar...");
				__fpurge(stdin);
				getchar();
				__fpurge(stdin);
				break;
			case 3:
				system("clear");
				listar_livros(vet_alunos, vet_livros, cad_livros);
				puts("Pressione ENTER para continuar...");
				__fpurge(stdin);
				getchar();
				__fpurge(stdin);
				break;
			case 4:
				system("clear");
				buscar_livro(vet_alunos, vet_livros, cad_livros);
				puts("Pressione ENTER para continuar...");
				__fpurge(stdin);
				getchar();
				__fpurge(stdin);
				break;
			case 5:
            system("clear");
            emprestimo_livro(vet_livros, vet_alunos, cad_livros, cad_alunos);
				puts("Pressione ENTER para continuar...");
				__fpurge(stdin);
				getchar();
				__fpurge(stdin);
            break;
         case 6:
            return;
		}
	}
}

void menu_recursos(cab_recursos *cab, alunos **vet_alunos, int *cad_alunos){
	int opt;
	for(;;){
		system("clear");
		puts("============================================");
		puts("                SECAO RECURSO               ");
		puts("============================================");
		puts("[1] - Cadastrar Recurso;");
		puts("[2] - Remover Recurso;");
		puts("[3] - Listar Recurso;");
		puts("[4] - Buscar Recurso;");
      puts("[5] - Emprestar/Devolver Recurso;");
		puts("[6] - Voltar ao Menu Inicial;");
		puts("Digite a opção desejada:");
		scanf("%d", &opt);

		switch (opt) {
			case 1:
				system("clear");
				cadastrar_recurso(cab);
				puts("Pressione ENTER para continuar...");
				__fpurge(stdin);
				getchar();
				__fpurge(stdin);
				break;
			case 2:
				system("clear");
				remover_recurso(cab);
				puts("Pressione ENTER para continuar...");
				__fpurge(stdin);
				getchar();
				__fpurge(stdin);
				break;
			case 3:
				system("clear");
				listar_recurso(cab, vet_alunos);
				puts("Pressione ENTER para continuar...");
				__fpurge(stdin);
				getchar();
				__fpurge(stdin);
				break;
			case 4:
				system("clear");
				buscar_recurso(cab, vet_alunos);
				puts("Pressione ENTER para continuar...");
				__fpurge(stdin);
				getchar();
				__fpurge(stdin);
				break;
			case 5:
            system("clear");
				emprestimo_recurso(cab, vet_alunos, cad_alunos);
				puts("Pressione ENTER para continuar...");
				__fpurge(stdin);
				getchar();
				__fpurge(stdin);
            break;
         case 6:
            return;
		}
	}
}
