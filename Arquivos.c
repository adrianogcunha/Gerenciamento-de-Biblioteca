#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include "Dados.h"
#include "Alunos.h"
#include "Livros.h"
#include "Recursos.h"
#include "Menu.h"

void cryptografar(char *mensagem, char *arquivo, FILE *exportar){
   char x;
   long i;

   FILE *aux;

   exportar = fopen(arquivo, "r");
   aux = fopen("aux.txt", "a");

   while(fgets(mensagem, 1000, exportar) != NULL){
      for(i = 0; mensagem[i] != '\0'; i++){
         x = mensagem[i];
         if(x >= '0' && x <= 'z'){
            x = x + 3;
            if(x > 'z'){
               x = x - 'z' + '0' - 1;
            }
            mensagem[i] = x;
         }
      }
      fputs(mensagem, aux);
   }
   fclose(exportar);
   fclose(aux);

   exportar = fopen(arquivo, "w");
   aux = fopen("aux.txt", "r");

   while(fgets(mensagem, 1000, aux) != NULL)

   fputs(mensagem, exportar);

   fclose(exportar);
   fclose(aux);
   remove("aux.txt");
}

void descryptografar(char *mensagem, char *arquivo, FILE *importar){
   char x;
   long i;

   FILE *aux;

   importar = fopen(arquivo, "r");
   aux = fopen("aux.txt", "a");

   while(fgets(mensagem, 1000, importar) != NULL){
      for(i = 0; mensagem[i] != '\0'; i++){
         x = mensagem[i];
         if(x >= '0' && x <= 'z'){
            x = x - 3;
            if(x < '0'){
               x = x + 'z' - '0' + 1;
            }
            mensagem[i] = x;
         }
         mensagem[i] = x;
      }
      fputs(mensagem, aux);
   }
   fclose(importar);
   fclose(aux);

   importar = fopen(arquivo, "w");
   aux = fopen("aux.txt", "r");

   while(fgets(mensagem, 50, aux) != NULL)

   fputs(mensagem, importar);

   fclose(importar);
   fclose(aux);
   remove("aux.txt");
}

void exportar_arq(char *mensagem, char *arquivo, cab_recursos *cab, alunos **vet_alunos, int *cad_alunos, livros **vet_livros, int *cad_livros, FILE *exportar){

   exportar = fopen(arquivo, "w");

   for(int i = 0; i <= (*cad_alunos); ++i){ //alunos
      if (vet_alunos[i] == NULL) {
         fprintf(exportar, "&\n");
      }else{
         fprintf(exportar, "%d\n", vet_alunos[i]->id); //id
         fprintf(exportar, "%s\n", vet_alunos[i]->nome);//nome
         fprintf(exportar, "%s\n", vet_alunos[i]->matricula);//matricula
         fprintf(exportar, "%d\n", vet_alunos[i]->pendencia);
      }
   }
   fprintf(exportar, "%s\n", "+"); //terminou alunos

   for(int i = 0; i <= (*cad_livros); ++i){ //livros
      if (vet_livros[i] == NULL) {
         fprintf(exportar, "&\n");
      }else{
         fprintf(exportar, "%d\n", vet_livros[i]->id); //id
         fprintf(exportar, "%s\n", vet_livros[i]->nome);//nome
         fprintf(exportar, "%d\n", vet_livros[i]->ano_publi);//ano_publi
         fprintf(exportar, "%s\n", vet_livros[i]->categoria); //categoria
         fprintf(exportar, "%d\n", vet_livros[i]->status); //status
      }
   }

   fprintf(exportar, "%s\n", "-"); //terminou livros

   recursos *ponteiro_aux;

   ponteiro_aux = cab->inicio;

   while(ponteiro_aux != NULL){
      fprintf(exportar, "%d\n", ponteiro_aux->id);
      fprintf(exportar, "%s\n", ponteiro_aux->tipo);
      fprintf(exportar, "%d\n", ponteiro_aux->status);
      fprintf(exportar, "%d\n", ponteiro_aux->id_aluno_emp);

      ponteiro_aux = ponteiro_aux->prox;
   }

   fclose(exportar);
   cryptografar(mensagem, arquivo, exportar);
}

void importar_arq(char *mensagem, char *arquivo, cab_recursos *cab, alunos **vet_alunos, int *cad_alunos, livros **vet_livros, int *cad_livros, FILE *importar, int *tam_vet_alunos, int *tam_vet_livros){
   if (access(arquivo, F_OK) == 0){
      descryptografar(mensagem, arquivo, importar);
      importar = fopen(arquivo, "r");

      char aux;

      fscanf(importar, "%c", &aux);
       while(aux != '+'){
         if((*cad_alunos) == (*tam_vet_alunos)){
      		aumentar_cadastro_aluno(&vet_alunos, tam_vet_alunos);
      	}
         if(aux == '&'){
            ++(*cad_alunos);
            vet_alunos[(*cad_alunos)] = NULL;
            fscanf(importar, "\n");
            fscanf(importar, "%c", &aux);
         }else{
            ++(*cad_alunos);
            vet_alunos[(*cad_alunos)] = (alunos *)(malloc(sizeof(alunos)));
            fseek(importar, -1, SEEK_CUR);
            fscanf(importar, "%d\n", &vet_alunos[(*cad_alunos)]->id); //id
            fscanf(importar, "%[^\n]\n", vet_alunos[(*cad_alunos)]->nome);//nome
            fscanf(importar, "%s\n", vet_alunos[(*cad_alunos)]->matricula);//matricula
            fscanf(importar, "%d\n", &vet_alunos[(*cad_alunos)]->pendencia);
            fscanf(importar, "%c", &aux);
         }
      }
      fscanf(importar, "\n");
      fscanf(importar, "%c", &aux);
      while(aux != '-'){
         ++(*cad_livros);
         if((*cad_livros) == (*tam_vet_livros)){
            aumentar_cadastro_livros(&vet_livros, tam_vet_livros);
         }
         if(aux == '&'){
            vet_livros[(*cad_livros)] = NULL;
            fscanf(importar, "\n");
            fscanf(importar, "%c", &aux);
         }else{
            vet_livros[(*cad_livros)] = (livros *)(malloc(sizeof(livros)));
            fseek(importar, -1, SEEK_CUR);
            fscanf(importar, "%d\n", &vet_livros[(*cad_livros)]->id); //id
            fscanf(importar, "%[^\n]\n", vet_livros[(*cad_livros)]->nome);//nome
            fscanf(importar, "%d\n", &vet_livros[(*cad_livros)]->ano_publi);//ano_publi
            fscanf(importar, "%[^\n]\n", vet_livros[(*cad_livros)]->categoria); //categoria
            fscanf(importar, "%d\n", &vet_livros[(*cad_livros)]->status); //status
            fscanf(importar, "%c", &aux);
         }
      }
      fscanf(importar, "\n");

      recursos *ponteiro_aux;
      ponteiro_aux = cab->inicio;
      char c;

      while(fscanf(importar, "%c", &c) != EOF){
         recursos *novo_recurso = (recursos*)malloc(sizeof(recursos));

         novo_recurso->prox = cab->inicio;
         cab->inicio = novo_recurso;

         fseek(importar, -1, SEEK_CUR);
         fscanf(importar, "%d\n", &novo_recurso->id);//nome
         fscanf(importar, "%s\n", novo_recurso->tipo);
         fscanf(importar, "%d\n", &novo_recurso->status);
         fscanf(importar, "%d\n", &novo_recurso->id_aluno_emp);
      }

      fclose(importar);
   }
}
