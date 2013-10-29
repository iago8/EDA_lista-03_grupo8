
//Implementa��o de uma pilha de uma  Lista encadeada
 
   //Estrutura dos n�s
   struct no {
	int conteudo;
	struct no *prox;
   };
//Usando typedef para no virar No
 typedef struct no No;

//Estrutura da pilha 
	struct pi{
	  No *primeiro;       //Ponteiro do tipo estrutura No
	};
	
	typedef struct pi pilha;
  
// Iniciar a pilha criando uma cabe�a, com o topo apontado para ela
   
pilha *iniciar(){
	pilha *p;
	p=(pilha*) malloc(sizeof(pilha));
	p->primeiro = 0; //inicializa com zero elementos 
	return p;        //retorna ponteiro
}

//Fun�ao para verificar se a pilha est� vazia
int vazia (pilha *p)
{
    if(!p->primeiro){
    	printf("\nPilha vazia\n");
    	return 0;
    }
}

//Fun��o para inserir no come�o da lista

No* inicio(No *l, int valor){
	
	No *p;
	p= (No*) malloc(sizeof(No)); //Novo n�
	p->conteudo = valor;
	p->prox = l;
	return p; //Retorna o topo da lista
}

//Fun�ao para retirar do come�o da lista
No* retirar(No *l){
	No *p; 
	p=l->prox;
	free(l);
	return p;
}

//Fun��o para empilhar
void empilhar(pilha *p, int valor){
  p->primeiro = inicio(p->primeiro,valor);
}

//Fun�ao para desempilhar
int desempilhar (pilha *p){
	int  valor;
	if (vazia(p)) {
		 printf("\nPilha vazia\n");
		 exit(1); //sai da execu��o
	}
	valor = p->primeiro->conteudo;
	p->primeiro = retirar(p->primeiro);
	return valor;
}

//Fun��o para mostrar os elementos da pilha 

void mostrar (pilha *p){
	No *q;  //Nova variavel para armazenar
	for (q=p->primeiro; q!=NULL; q=q->prox){  //Varre os n�s com um contador que vai do primeiro n� at� achar um n� cujo proximo seja nulo
	  printf("%4d\n",q->conteudo);	  //Mostra o valor armazenado em conteudo de cada n�
	}
	
}

//Func�o que libera a pilha 
void liberar(pilha *p){
	No *q = p->primeiro; //armazena o end do primeiro elemento
		while (q!=NULL) {  //Enquanto ele n�o for nulo
		No *t = q->prox;  //Outra variavel assime o valor do endere�o do proximo n�
		free(q);          //Libera o topo atual
		q = t;           //Transforma o proximo no topo
		}
   free(p);  //libera a pilha
}

