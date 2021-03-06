
#include <stdio.h>

int main()
{
	
	int pro, res;	
	printf("\n\t\tBANKER'S ALGORITHM\n");

	printf("\n\tEnter the number of processes :");	
	scanf("%d", &pro);
	printf("\n\tEnter the number of resources :");	
	scanf("%d", &res);

	
	int alloc[pro][res];	
	int max[pro][res];		
	int avail[res];		
	int work[res];			
	int needMat[pro][res];		

	
	void safeSequence(int alloc[pro][res], int max[pro][res], int avail[res], int needMat[pro][res])
	{
		
		int include[pro];	
		int safe[pro];		

		for(int i = 0; i < pro; i++)
		{
			include[i] = 0;	
			safe[i] = 0;		
		}
		
		for(int i = 0; i < res; i++)
		{	
			work[i] = avail[i];
		}

		int safeNum = 0;	
		int k, i, flag, j, m;

		for(k = 0; k < 3; k++)	
		{
			for(i = 0; i < pro; i++)	
			{
				if(include[i] == 0)	
				{
					flag = 0;	
					
					for(j = 0; j < res; j++)	
					{
						if(needMat[i][j] > work[j])	
						{
							flag = 1;
							break;
						}
					}
					
					if(flag == 0)	
					{
						safe[safeNum] = i;	
						safeNum += 1;		
						
						for(m = 0; m < res; m++)
						{
							work[m] += alloc[i][m];	
						}
						
						include[i] = 1;	
					}
				}
			} 
		}


		printf("\n\t=================================\n");

		printf("\n\tAllocation Matrix\n\t");

		for(int i = 0; i < pro; i++)
		{
			for(int j = 0; j < res; j++)
			{
				printf("%d\t", alloc[i][j]);

			}
			
			printf("\n\t");
		}

		printf("\n\t=================================\n");
		
		printf("\n\tMAX Matrix\n\t");

		for(int i = 0; i < pro; i++)
		{
			for(int j = 0; j < res; j++)
			{
				printf("%d\t", max[i][j]);

			}
			
			printf("\n\t");
		}
		
		printf("\n\t=================================\n");
		
		printf("\n\tNeed Matrix\n\t");

		for(int i = 0; i < pro; i++)
		{
			for(int j = 0; j < res; j++)
			{
				printf("%d\t", needMat[i][j]);

			}
			
			printf("\n\t");
		}
		
		printf("\n\t=================================\n");
		
		printf("\n\tAvailable Resources\n\t");

		for(int i = 0; i < res; i++)
		{
			printf("%d\t", avail[i]);
		}
		

		// Printing the safe sequence

		printf("\n\n\t=================================\n");
		printf("\n\n\tFollowing is the SAFE Sequence\n\t");
		int x;
		for (x = 0; x < pro - 1; x++)
		{
		 	printf(" P%d ->", safe[x]);   
		}
		printf(" P%d ", safe[x]);
		printf("\n\n\t=================================\n");
		printf("\n");	
		
	}
	


	void newAlloc()
	{
		int num;
		printf("\n\tEnter the process no. :");	
		scanf("%d", &num);
		
		int request[res];
		printf("\n\tEnter the Allocation Resources for process no. %d", num);	
		
		for(int i = 0; i < res; i++)
		{
			printf("\n\tEnter resource no. %d :", (i+1));	
			scanf("%d", &request[i]);
		}
		
		
		// Checking conditions for the receiver algorithm
		int flag = 0;
		
		// Is Request(i) < Need(i)
		for(int i = 0; i < res; i++)
		{
			if(needMat[num][i] >= request[i])
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		
		// Is Request(i) < Available
		if(flag == 1)
		{
			for(int i = 0; i < res; i++)
			{
				if(avail[i] >= request[i])
					flag = 1;
				else
				{
					flag = 0;
					break;
				}
					
			}
		}
		
	
		if(flag == 1)
		{
			printf("\n\tThe requested resources by process no. %d can be allocated instantly", num);
			printf("\n\tThe safe sequence is changed accordingly\n\n");
			
		
			for(int i = 0; i < res; i++)
			{
				avail[i] -= request[i];
				alloc[num][i] += request[i];
				needMat[num][i] -= request[i];
			}
			
			safeSequence(alloc, max, avail, needMat);	
		}
		
		if(flag == 0)
		{
			printf("\n\tThe requested resources cannot be allocated to process no. %d\n", num);
		}
		
	}
	


	printf("\n\tEnter values of Allocation Matrix :");

	for(int i = 0; i < pro; i++)
	{
		printf("\n\tEnter the resources for process no. %d : ", (i+1));
		
		for(int j = 0; j < res; j++)
		{
			printf("\n\tEnter the resource no. %d :", (j+1));
			scanf("%d", &alloc[i][j]);
		}
	}
	
	printf("\n\tEnter values of MAX Matrix :");

	for(int i = 0; i < pro; i++)
	{
		printf("\n\tEnter the resources for process no. %d : ", (i+1));
		
		for(int j = 0; j < res; j++)
		{
			printf("\n\tEnter the resource no. %d :", (j+1));
			scanf("%d", &max[i][j]);
		}
	}
	
	printf("\n\tEnter the Initial %d Available Resources :", res);

	for(int i = 0; i < res; i++)
	{
		printf("\n\tEnter value no. %d :", (i+1));
		scanf("%d", &avail[i]);
	}
	
	for(int i = 0; i < pro; i++)
	{
		for(int j = 0; j < res; j++)
			needMat[i][j] = max[i][j] - alloc[i][j];
	}
	
	

	
	safeSequence(alloc, max, avail, needMat);
	

	
	printf("\n\n\tDo you want to change the allocated resources of an existing process?\n\t1. Yes \n\t2. No \n\tOption = ");
	int option;
	scanf("%d", &option);
	
	if (option == 1)
		newAlloc();
	else
		return 0;

}