#ifndef DADOS_H
#define DADOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <locale.h>

//! Utilizados na função cadastrar_recursos(), na qual tem a função de facilitar o cadastro dos recursos
#define A "SALA"
#define B "COMPUTADOR"
#define C "ARMÁRIO"

//! Foi Utilizado um vetor de ponteiros que apontam para uma struct como estrutura de dados na seção de alunos, pois é mais vantajoso na hora de realizar busca por ID devido ao ID ser gerado automaticamente;
typedef struct alunos{
	int id;
	int pendencia; //0 = Não   >= 1
	char nome[50];
	char matricula[50];
}alunos;

//! Foi Utilizado um vetor de ponteiros que apontam para uma struct como estrutura de dados na seção de livros, pois é mais vantajoso na hora de realizar busca por ID devido ao ID ser gerado automaticamente;
typedef struct livros{
	int id;
	int status; //-1 = Não Emprestado   >= 0 = Emprestado
   int ano_publi;
	char nome[50];
   char categoria[50];
}livros;

//! Foi Utilizado lista encadeada como estrutura de dados na seção dos recursos, pois como o ID é definido pelo usuário, não há vantagem na busca, logo a lista encadeada tem uma vantagem nesse caso, pois não deixa um ponteiro apontando para NULL quando a struct é removida;
typedef struct recursos{
   int id; //inserir
   int id_aluno_emp;
   int status; // 0 = Disponivel e 1 = Ocupado
   char tipo[50]; //inserir
   struct recursos *prox;
}recursos;

typedef struct cab_recursos{// inicio livros
   recursos *inicio;
}cab_recursos;

#endif
