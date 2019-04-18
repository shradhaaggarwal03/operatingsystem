#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int i,opt;
struct Memory
{
	int M_ID,size,left,once_used;
};

struct Process
{
	int length,got_memory;
};

void First_Fit(struct Memory M[5],struct Process P[4])
{
	if(opt==1)
	printf("      Inside first_fit  With Fixed_Length");
	else
	printf("      Inside first_fit  With Variable_Length");

	int i,j;
	int n=4,m=5;
	//n is number of processes and m is memory spaces
		for(i=0;i<n;i++)//loop for picking process
		{
			for(j=0;j<m;j++)//loop for seeking the best first memory
			{
				if(M[j].left>=P[i].length && P[i].got_memory==0 && M[j].once_used==0)
				{
					M[j].left-=P[i].length;         //calculating left memory
					printf("\n\nMemory NO        : %d",j+1);
					printf("\nProcess NO       : %d",i+1);
					printf("\nProcess Size     : %d",P[i].length);
					printf("\nOriginal Space   : %d",M[j].size);
					printf("\nSpace Occupied   : %d",P[i].length);
					printf("\nSpace Left       : %d",M[j].left);
					P[i].got_memory=1;
					if(opt==1)
					M[j].once_used=1;
				}
			}
			if(P[i].got_memory==0)
			{
				//printf("\nNo Memory Available for Process: %d\n",i+1);
			}
     	}
}

void Best_Fit(struct Memory M[5],struct Process P[4])
{
	if(opt==1)
	printf("      Inside Best_Fit  With Fixed_Length");
	else
	printf("      Inside Best_Fit  With Variable_Length");

	int i,j,temp_j;
	int n=4,m=5;

		for(i=0;i<n;i++)//loop for picking process
		{
			int min=999;
			for(j=0;j<m;j++)//loop for seeking the best first memory
			{
				if(M[j].left>=P[i].length && M[j].left<min && P[i].got_memory==0 && M[j].once_used==0)//checking for the best memory
				{
					min=M[j].left;
					temp_j=j;
				}
			}

			if(M[temp_j].left>=P[i].length && P[i].got_memory==0 && M[temp_j].once_used==0)
				{
					M[temp_j].left-=P[i].length;         //calculating left memory
					printf("\n\nMemory NO        : %d",temp_j+1);
					printf("\nProcess NO       : %d",i+1);
					printf("\nProcess Size     : %d",P[i].length);
					printf("\nOriginal Space   : %d",M[temp_j].size);
					printf("\nSpace Occupied   : %d",P[i].length);
					printf("\nSpace Left       : %d",M[temp_j].left);
					P[i].got_memory=1;
					if(opt==1)
					M[temp_j].once_used=1;
				}
     	}
}

void Worst_Fit(struct Memory M[5],struct Process P[4])
{
	if(opt==1)
	printf("      Inside Worst_Fit  With Fixed_Length");
	else
	printf("      Inside Worst_Fit  With Variable_Length");

	int i,j,temp_j;
	int n=4,m=5;

		for(i=0;i<n;i++)//loop for picking process
		{
			int max=0;
			for(j=0;j<m;j++)//loop for seeking the best first memory
			{
				if(M[j].left>=P[i].length && M[j].left>max && P[i].got_memory==0 && M[j].once_used==0)//checking for the best memory
				{
					max=M[j].left;
					temp_j=j;
				}
			}

			if(M[temp_j].left>=P[i].length && P[i].got_memory==0 && M[temp_j].once_used==0)
				{
					M[temp_j].left-=P[i].length;         //calculating left memory
					printf("\n\nMemory NO        : %d",temp_j+1);
					printf("\nProcess NO       : %d",i+1);
					printf("\nProcess Size     : %d",P[i].length);
					printf("\nOriginal Space   : %d",M[temp_j].size);
					printf("\nSpace Occupied   : %d",P[i].length);
					printf("\nSpace Left       : %d",M[temp_j].left);
					P[i].got_memory=1;
					if(opt==1)
					M[temp_j].once_used=1;
				}
     	}
}

int main()
{
	//initalizing all the value
	struct Memory M[5];
	M[0].size=100;
	M[1].size=500;
	M[2].size=200;
	M[3].size=300;
	M[4].size=600;

	struct Process P[4];
	P[0].length=212;
	P[1].length=417;
	P[2].length=112;
	P[3].length=426;

	for(i=0;i<5;i++)//initalizing memory
	{
		M[i].left=M[i].size;
		M[i].once_used=0;
	}

	for(i=0;i<4;i++)//initalizing processes
	{
		P[i].got_memory=0;
	}

	int choice;
	printf("Select The Option");
	printf("\nPress 1: For First_Fit");
	printf("\nPress 2: For Best_Fit");
	printf("\nPress 3: For Worst_Fit\n");
	scanf("%d",&choice);

	system("cls");
	printf("Select The Partioning Method");
	printf("\nPress 1: For Fixed_Length");
	printf("\nPress 2: For Variable_Length\n");
	scanf("%d",&opt);

	system("cls");
	switch(choice)
	{
		case 1:
			First_Fit(M,P);
			break;

		case 2:
			Best_Fit(M,P);
			break;

		case 3:
			Worst_Fit(M,P);
			break;
	}
}
