
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
	char expressao[25];
	
	printf("\n\nPrograma para calcular valor de expressao PostFix\n\n\n");
	printf("\nDigite a expressao:\n\n");
	scanf("%c",&expressao);
	printf("\nO valor da expressao:\n\n");
	printf("%4d\n\n",AvaliaPostFix(expressao));
	printf("\nFim do programa!\n");
	return 0;
}
