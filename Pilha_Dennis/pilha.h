
//Implementação de uma pilha de uma  Lista encadeada
 
   //Estrutura dos nós
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
  
// Iniciar a pilha criando uma cabeça, com o topo apontado para ela
   
pilha *iniciar(){
	pilha *p;
	p=(pilha*) malloc(sizeof(pilha));
	p->primeiro = 0; //inicializa com zero elementos 
	return p;        //retorna ponteiro
}

//Funçao para verificar se a pilha está vazia
int vazia (pilha *p)
{
    if(!p->primeiro){
    	printf("\nPilha vazia\n");
    	return 0;
    }
}

//Função para inserir no começo da lista

No* inicio(No *l, int valor){
	
	No *p;
	p= (No*) malloc(sizeof(No)); //Novo nó
	p->conteudo = valor;
	p->prox = l;
	return p; //Retorna o topo da lista
}

//Funçao para retirar do começo da lista
No* retirar(No *l){
	No *p; 
	p=l->prox;
	free(l);
	return p;
}

//Função para empilhar
void empilhar(pilha *p, int valor){
  p->primeiro = inicio(p->primeiro,valor);
}

//Funçao para desempilhar
int desempilhar (pilha *p){
	int  valor;
	if (vazia(p)) {
		 printf("\nPilha vazia\n");
		 exit(1); //sai da execução
	}
	valor = p->primeiro->conteudo;
	p->primeiro = retirar(p->primeiro);
	return valor;
}

//Função para mostrar os elementos da pilha 

void mostrar (pilha *p){
	No *q;  //Nova variavel para armazenar
	for (q=p->primeiro; q!=NULL; q=q->prox){  //Varre os nós com um contador que vai do primeiro nó até achar um nó cujo proximo seja nulo
	  printf("%4d\n",q->conteudo);	  //Mostra o valor armazenado em conteudo de cada nó
	}
	
}

//Funcão que libera a pilha 
void liberar(pilha *p){
	No *q = p->primeiro; //armazena o end do primeiro elemento
		while (q!=NULL) {  //Enquanto ele não for nulo
		No *t = q->prox;  //Outra variavel assime o valor do endereço do proximo nó
		free(q);          //Libera o topo atual
		q = t;           //Transforma o proximo no topo
		}
   free(p);  //libera a pilha
}

