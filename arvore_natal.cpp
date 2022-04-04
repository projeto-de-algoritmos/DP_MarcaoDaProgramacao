#include<bits/stdc++.h>
using namespace std;
#define MAX_W 1000
#define MAX_V 1000
#define MAX_ITENS 1000

// pesos e valores
int W[MAX_ITENS];
int V[MAX_ITENS];

// matriz de memoização
int memo[MAX_W][MAX_V];

int knapsack(int i, int w) {
    if (i < 0 || w <= 0) return 0;

    // Caso este estado já tenha sido resolvido
    if (memo[i][w] != -1) return memo[i][w];

    // Caso o item estoure a capacidade da mochila
    // O item não será carregado
    if (W[i] > w) return memo[i][w] = knapsack(i - 1, w);

    // Caso contrário o valor ótimo será o maior valor entre a decisão
    // de não carregar o item e carregar o item
    return memo[i][w] = max(knapsack(i - 1, w),knapsack(i - 1, w - W[i]) + V[i]);
}

int main() {
    // Inicialização da matriz de memoização com -1
	memset(memo, -1, sizeof memo);
	int n=1,p=1,l,aux,aux2,ins = 1;
	scanf("%d",&n);
	while(n!=0){
		n--;
		scanf("%d",&l);
		scanf("%d",&p);
		//if(n==0)break;
		for(int i=0;i<l;i++){
			scanf("%d %d",&aux,&aux2);
			V[i] = aux;
			W[i] = aux2;
		}
		int k = knapsack(l-1,p);
		printf("Galho %d:\n",ins++);
		printf("Numero total de enfeites: %d\n\n",k);
		memset(V, 0, sizeof V);
		memset(W, 0, sizeof W);
		memset(memo, -1, sizeof memo);
	}
}
/*
 * Problema da mochila binaria adaptado.
 * Link: <https://www.beecrowd.com.br/judge/pt/problems/view/2026>
 */
