#include<stdio.h>
#include<stdlib.h>
int a[9][9];
void printBoard();
void mkmove(int si,int sj,int di,int dj);
void startGame();
int main()
{
	int ch,i,j;
	//Board initialisation
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(i<3 && j<3)
				a[i][j]=-1;
			else if(i<3 && j>5)
				a[i][j]=-1;
			else if(i>5 && j<3)
				a[i][j]=-1;
			else if(i>5 && j>5)
				a[i][j]=-1;
			else
				a[i][j]=0;
			a[4][4]=1;
		}
	}
	printf("1.Start\n");
	printf("2.Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			startGame();
			break;
		case 2:
			exit(1);
			break;
		default:
			break;
	}
}
void startGame()
{
	int si,sj,di,dj;
	while(1)
	{
		system("cls");
		printBoard();
		printf("enter the source position and destination position:\n");
		scanf("%d%d%d%d",&si,&sj,&di,&dj);
		mkmove(si,sj,di,dj);
		system("cls");
	}
}
void printBoard()
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(a[i][j]==-1)
				printf(" 	  ");
			if(a[i][j]==1)
				printf("-	  ");
			else
				printf("%d	  ",a[i][j]);
		}
		printf("\n\n");
	}
}
void mkmove(int si,int sj,int di,int dj)
{
	if(a[si][sj]==0)
	{
		if(a[di][dj]==1)
		{
			if(a[(si+di)/2][(sj+dj)/2]==0)
			{
				if((si-di)==0)
				{
					if((dj-sj)==2 || (dj-sj)==-2)
					{
						a[di][dj]=a[si][sj];
						a[si][sj]=1;
						a[(si+di)/2][(sj+dj)/2]=1;
					}
				}
				else if((sj-dj)==0)
				{
					if((di-si)==2 || (di-si)==-2)
					{
						a[di][dj]=a[si][sj];
						a[si][sj]=1;
						a[(si+di)/2][(sj+dj)/2]=1;
					}
				}
				else
				{
					printf("INVALID MOVE!");
				}
			}
		}
	}
}
