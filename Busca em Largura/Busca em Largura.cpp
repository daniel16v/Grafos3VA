// Autor: Daniel Vaz de Oliveira

#include<stdio.h>


int a[20][20], q[20], visitado[20], n, i, j, f = 0, r = -1;

void bfs(int v) {
	for(i = 1; i <= n; i++)
		if(a[v][i] && !visitado[i])
			q[++r] = i;
	if(f <= r) {
		visitado[q[f]] = 1;
		bfs(q[f++]);
	}
}

int main() {
	int v;
	printf("\n Insira o numero de vertices:");
	scanf("%d", &n);
	
	for(i=1; i <= n; i++) {
		q[i] = 0;
		visitado[i] = 0;
	}
	
	printf("\n Insira os dados do grafo em forma de matriz:\n");
	for(i=1; i<=n; i++) {
		for(j=1;j<=n;j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	printf("\n Insira o vertice inicial:");
	scanf("%d", &v);
	bfs(v);
	printf("\n O no que e acessivel e:\n");
	
	for(i=1; i <= n; i++) {
		if(visitado[i])
			printf("%d\t", i);
		else {
			printf("\n Bfs nao e possivel. Nem todos os nos sao acesiveis");
			break;
		}
	}
}