/*
 * Programa para ler uma expressao aritmetica em notacao postfix, e 
 fornecer o resultado da expressao.
* Disciplina: Estrutura de Dados e Algoritmos - 193704
 * Professor: Nilton Correia da Silva
 * Turma: B
 * Tarefa: Trabalho Pratico (Pilhas)
 * Grupo: 8
 * Data de Termino: 29/10/2013
 * Integrantes:
 * -> Dennis Lúcio Merli Rodrigues - 13/0044130
 * --> GitHub: https://github.com/neneds
 * -> Iago Mendes Leite
 * --> GitHub: https://github.com/iago8
 * -> Ricardo Gonçalves Teixeira
 * --> GitHub: https://github.com/ricardogtx
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculadora.h"

main ()
{
	
char c;
int valor,op;
calc *calculadora;
//Cria uma estrutura calculadora
calculadora = criar("%.4d\n"); //Expressão final será em formato de inteiros

do {
       
    printf("\nDigite a expressao\n");
	scanf(" %c",&c);
	if (c=='+' || c=='-' || c=='*' || c=='/') {
	  operador(calculadora,c);
	}
	//devolve caractere lido e tenta ler número 
	else {
	  ungetc(c,stdin);
	  if (scanf("%d",&valor) == 1)
	  operando(calculadora,valor);
	}
	printf("\nDeseja calcular outra expressao? 1-Sim 2-Nao\n\n");
	scanf("%d",&op);
	} while (op!=2);
	free(calculadora);
	printf("\nFim do programa!\n");
	return 0;
}
