#include <stdio.h>

// 0 represents an available seat and 1 represents a booked seat
// priority -> middle rows

int main(void)
{
	int rows, seats, total_available, k, consecutive, selected_row, selected_seat;
	int i, j;
	
	do
	{
		printf("Input the total number of rows: ");
		scanf("%d", &rows);
		
	}
	while (rows <= 0);
	
	do
	{
		printf("Input the total number of seats per row: ");
		scanf("%d", &seats);	
	}
	while (seats <= 0);
	
	do
	{
		printf("Input the total number of customers who want to sit together: ");
		scanf("%d", &k);
	}
	while (k <= 0);
	
	int array[rows][seats];
	int available[rows];
	
	
	
	int flag;
	do
	{
		total_available = 0;
		printf("Input current seating arrangement (0 = available, 1 = booked): \n");
		
		for (i = 0; i < rows; i++)
		{	
			available[i] = 0;
		}
		
		flag = 0;
		for (i = 0; i < rows; i++)
		{
			consecutive = 0;
			for (j = 0; j < seats; j++)
			{
				scanf("%d", &array[i][j]);
				
				if (array[i][j] != 0 && array[i][j] != 1)
				{
					flag = 1;
				}
			
				if (array[i][j] == 0)
				{
					available[i]++;
					consecutive++;
				}
				else if (array[i][j] == 1)
				{
					consecutive = 0;	
				}
			
				if (consecutive == k)
				{
					array[i][j - k + 1] = 2;
					consecutive = 0;
				}
			}
			total_available += available[i];
		}	
	}
	while (flag == 1);
		
	printf("\n");
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < seats; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	
	
	
	int row;
	flag = 1;
	i = 1;
	
	int round;
	
	if (rows % 2 == 1) // odd
	{
		row = rows / 2;
		round = 2;
		
		for (j = 0; j < seats; j++)
		{
			if (array[row][j] == 2)
			{
				flag = 0;
				selected_row = row;
				selected_seat = j;
				break;
			}
		}
		
		if (flag != 0)
		{
			do
			{
				if (round == 2)
				{
					row = row - i;
					for (j = 0; j < seats; j++)
					{			
						if (array[row][j] == 2)
						{
							flag = 0;
							selected_row = row;
							selected_seat = j;
							break;
						}
					}
					round = 1;
					i++;
				}
				else if (round == 1)
				{
					row = row + i;
					for (j = 0; j < seats; j++)
					{		
						if (array[row][j] == 2)
						{
							flag = 0;
							selected_row = row;
							selected_seat = j;
							break;
						}
					}
					round = 2;
					i++;
				}
			}	
			while (row != rows - 1 && flag == 1);	
		}
	}
	else // even
	{
		round = 1;
		row = (rows / 2) - 1;
		for (j = 0; j < seats; j++)
		{
			if (array[row][j] == 2)
			{
				flag = 0;
				selected_row = row;
				selected_seat = j;
				break;
			}
		}
		
		if (flag != 0)
		{
			do
			{
				if (round == 2)
				{
					row = row - i;
					for (j = 0; j < seats; j++)
					{			
						if (array[row][j] == 2)
						{
							flag = 0;
							selected_row = row;
							selected_seat = j;
							break;
						}
					}
					round = 1;
					i++;
				}
				else if (round == 1)
				{
					row = row + i;
					for (j = 0; j < seats; j++)
					{		
						if (array[row][j] == 2)
						{
							flag = 0;
							selected_row = row;
							selected_seat = j;
							break;
						}
					}
					round = 2;
					i++;
				}
			}	
			while (row != rows - 1 && flag == 1);
		}
	}
	
	printf("\nFree seets per row: ");
	for (i = 0; i < rows; i++)
	{
		printf("%d ", available[i]);
	}
	printf("\n\n");
	
	if (flag == 1)
	{
		printf("Sorry, no desired seats available\n");
	}
	else
	{
		printf("Group of %d seated in Row %d, Seats %d to %d", k, selected_row, selected_seat, selected_seat + k - 1);
	}
	
	//print the grid ////////////////////////////////////////////////////////////////////     TODO       ///////////////////////////////////////////////////////
	for (i = 0; i < k; i++)
	{
		array[selected_row][selected_seat + i] = 1;
	}
	
	printf("\n   \t");
	for (i = 0; i < seats; i++)
	{
		printf("%d ", i);
	}
	
	printf("\n");
	
	for (i = 0; i < rows; i++)
	{
		printf("r%d \t", i);
		for (j = 0; j < seats; j++)
		{
			if (array[i][j] == 1)
			{
				printf("x ");
			}
			else
			{
				printf("_ ");
			}
		}
		printf("\n");
	}
	return 0;
}


