//Autor: Daniel Vaz de Oliveira
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int i,j,k,a,b,u,v,n,ne=1;
int min,mincust=0,cust[9][9],parent[9];
int find(int);
int uni(int,int);



int main()
{
	system("cls"); //limpa tela
	printf("\n\tImplementando o algoritmo\n");
	printf("\nInsira o numero de vertices:");
	scanf("%d",&n);
	printf("\nInsira a matriz de adjacencia de custo:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cust[i][j]);
			if(cust[i][j]==0)
				cust[i][j]=999;
		}
	}
	printf("As arestas da arvore de extensao de custo minimo sao:\n");
	while(ne < n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cust[i][j] < min)
				{
					min=cust[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("%d aresta (%d,%d) =%d\n",ne++,a,b,min);
			mincust +=min;
		}
		cust[a][b]=cust[b][a]=999;
	}
	printf("\n\tCusto minimo = %d\n",mincust);
	getch();
}
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}