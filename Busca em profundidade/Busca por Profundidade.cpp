//Autor Daniel Vaz de Oliveira
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int a[20][20],reach[20],n;
void dfs(int v) {
	int i;
	reach[v]=1;
	for (i=1;i<=n;i++)
	  if(a[v][i] && !reach[i]) {
		printf("\n %d->%d",v,i);
		dfs(i);
	}
}
int main() {
	int i,j,count=0;
	system("cls");
	printf("\n Insira o numero de vertices:");
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		reach[i]=0;
		for (j=1;j<=n;j++)
		   a[i][j]=0;
	}
	printf("\n Insira a matriz de adjacencia:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);
	dfs(1);
	printf("\n");
	for (i=1;i<=n;i++) {
		if(reach[i])
		   count++;
	}
	if(count==n)
	  printf("\n O grafo e conectado"); else
	  printf("\n O grafo nao e conectado");
	  
	  getch();
}