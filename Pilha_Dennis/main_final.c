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
 * -> Dennis L�cio Merli Rodrigues - 13/0044130
 * --> GitHub: https://github.com/neneds
 * -> Iago Mendes Leite
 * --> GitHub: https://github.com/iago8
 * -> Ricardo Gon�alves Teixeira
 * --> GitHub: https://github.com/ricardogtx
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculadora.h"

main ()
{
	
char c;
int valor;
calc *calculadora;

calculadora = criar("%.4d\n"); //Express�o final ser� em formato de inteiros

do {
       
    printf("\Digite a expressao\n");
	scanf(" %c",&c);
	if (c=='+' || c=='-' || c=='*' || c=='/') {
	operador(calculadora,c);
	}
	/* devolve caractere lido e tenta ler n�mero */
	else {
	ungetc(c,stdin);
	if (scanf("%d",&valor) == 1)
	operando(calculadora,valor);
	}
	} while (c!='q');
	liberar(calculadora);
	return 0;
}
