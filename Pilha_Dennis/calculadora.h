//Funcoes para calculo da expressão postFix

//Aqui temos funcoes para o calculo das expressoes postFix 

#include "pilha.h"


//Estrutura da calculadora
struct calc {
	char final[21];  //saída dos dados
	pilha* p; 
};

//Funçao para criar a calculadora
calc* criar(char *expressao){
	
calc* c = (calc*) malloc(sizeof(calc));
strcpy(c->final,expressao);
c->p = cria(); //Inicia lista vazia
return c;
}

//Função que identifica os operandos
void operando (calc* c, int valor){

empilhar(c->p,valor);
mostrar(c->final,valor);  //Mostra topo da pilha
}

//Função que identifica os operadores
void operador (calc* c, char op){
int v1, v2, v;
//desempilha operandos
if (vazia(c->p))
v2 = 0;
else
v2 = desempilhar(c->p);
if (vazia(c->p))
v1 = 0;
else
v1 = desempilhar(c->p);

//Lendo as opções
switch (op) {
case '+': v = v1+v2; break;
case '-': v = v1-v2; break;
case '*': v = v1*v2; break;
case '/': v = v1/v2; break;
}
//Empilhar resultado
empilhar(c->p,v);
//Mostra topo da pilha
mostrar(c->f,v);
}

//Função que libera a estrutura da calculadora
void libCalc(calc* c)
{
	liberar(c->p);
	free(c);
}
