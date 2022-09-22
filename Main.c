
#include "Dados.h"
#include "Alunos.h"
#include "Livros.h"
#include "Recursos.h"
#include "Menu.h"
#include "Arquivos.h"


int main() {

	setlocale(LC_ALL,"Portuguese");

//DECLARAR VETOR ALUNOS
	int cad_alunos = -1;
	int tam_vet_alunos = 100;

	alunos **vet_alunos = (alunos **)(malloc((tam_vet_alunos) * sizeof(alunos *)));

//DECLARAR VETOR LIVROS
   int cad_livros = -1;
   int tam_vet_livros = 100;

   livros **vet_livros = (livros **)(malloc((tam_vet_livros) * sizeof(livros *)));

//DECLARAR RECURSOS
	cab_recursos *cab = (cab_recursos *)malloc(sizeof(cab_recursos)); //Perguntar professor
   cab->inicio = NULL;

	int opt;
	int i;
	int j;

//===================================

	char mensagem[1000];

	char arquivo[] = "armazenamento.txt";

	FILE *exportar;
	FILE *importar;

	importar_arq(mensagem, arquivo, cab, vet_alunos, &cad_alunos, vet_livros, &cad_livros, importar, &tam_vet_alunos, &tam_vet_livros);

	for(;;){
		system("clear");
		puts("============================================");
		puts("                MENU INICIAL                ");
		puts("============================================");
		puts("[1] - Seção Alunos");
		puts("[2] - Seção Livros");
		puts("[3] - Seção Recursos");
		puts("[4] - Sair");
		puts("Digite a opção desejada:");
		scanf("%d", &opt);

		switch (opt) {
			case 1:
				menu_aluno(vet_alunos, &cad_alunos, &tam_vet_alunos);
				break;
			case 2:
            menu_livros(vet_alunos, vet_livros, &cad_livros, &cad_alunos, &tam_vet_livros);
            break;
			case 3:
				menu_recursos(cab, vet_alunos, &cad_alunos);
				break;
			case 4:
				exportar_arq(mensagem, arquivo, cab, vet_alunos, &cad_alunos, vet_livros, &cad_livros, exportar);

				//Dando free
				for (i = 0; i <= cad_alunos; i++) {
					if (vet_alunos[i] != NULL) {
						free(vet_alunos[i]);
					}else{
						continue;
					}
				}
				for (j = 0; j <= cad_livros; j++) {
					if (vet_livros[i] != NULL) {
						free(vet_livros[i]);
					}else{
						continue;
					}
				}
				free(vet_alunos);
				free(vet_livros);
				return 0;
		}
	}
   return 0;
}

//gcc Alunos.c Livros.c Recursos.c Menu.c Main.c Arquivos.c
//./a.out
