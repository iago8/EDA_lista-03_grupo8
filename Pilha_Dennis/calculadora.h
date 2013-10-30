//Funcoes para calculo da expressão postFix

//Aqui temos funcoes para o calculo das expressoes postFix 
#include "pilha.h"


//Funçao AvaliaPostFix

int AvaliaPostFix(char expressao[]){

	char c, posicao;
	int op1, op2, valor;
 
 pilha nova;
 nova=iniciar();
 
 for(posicao = 0; (c =expressao[posicao]) != '\0'; posicao++)
    if(c>= '0'&& c <= '9'){
      empilhar(&nova, (int) (c-'\0'));	
    }
    
   else{
	op2 = desempilha(&nova);
	op1 = desempilha(&nova);
	valor = operador(c, op1, op2);
	empilha(&nova, valor);
	} 
 
 return(desempilha(&nova));
 liberar(&nova);
 
}

//Função que identifica os operadores
int operador (int c, int v1,int v2){
	int v;
	//Lendo as opções
	switch (c) {
		case '+': v = v1+v2; break;
		case '-': v = v1-v2; break;
		case '*': v = v1*v2; break;
		case '/': v = v1/v2; break;
		default:{
		  printf("\nArgumento Invalido!\n");
		  exit(1);
		}
		
		
	}
  return (v);
}


