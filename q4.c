#include <stdio.h>

int main(void)
{
	// prototypes
	int getValidDays();
	float calculateDailySales(int dayNumber);
	int findHighestSalesDay(float daily_sales[], int numberOfDays);
	void displayBarChart(float dailySales[], int numberOfDays);

	// variables
	int days;
	int i;
	int high_day;
	float total_sales = 0;
	
	days = getValidDays();
	
	float daily_sales[days];
	
	for (i =  0; i < days; i++)
	{
		daily_sales[i] = calculateDailySales(i);	
		total_sales += daily_sales[i];
	}
	
	high_day = findHighestSalesDay(daily_sales, days); 

	printf("===== FESTIVAL SUMMARY =====\n");
	printf("Total festival sales: %0.2f\n", total_sales);
	printf("Day with highest sales: %d\n", high_day);
	printf("Highest daily sales: %0.2f\n", daily_sales[high_day - 1]);
	
	displayBarChart(daily_sales, days);
}

int getValidDays()
{
	int days;
	do
	{
		printf("Number of days: ");
		scanf("%d", &days);
	}
	while (days < 1 || days > 7);
	
	return days;
}

float calculateDailySales(int dayNumber)
{
	int orders, flag;
	int i;
	
	do
	{
		printf("Day %d - Number of orders: ", dayNumber + 1);
		scanf("%d", &orders);
		
	}
	while (orders < 0);
	
	float amounts[orders];
	float total = 0;
	float avg = 0;
	int high_index = 0;
	
	do
	{
		flag = 0;
		
		printf("Order amounts: ");
		
		for (i = 0; i < orders; i++)
		{
			scanf("%f", &amounts[i]);
			
			if (amounts[i] <= 0)
			{
				flag = 1;
			}
		}	
	}
	while(flag == 1);
	
	for (i = 0; i < orders; i++)
	{
		total += amounts[i];
		
		if (amounts[i] > amounts[high_index])
		{
			high_index = i;
		}
	}
	
	if (orders > 0)
	{
		avg = total / orders;	
	}
	printf("\n=====Day %d=====\n", dayNumber + 1);
	printf("Total Sales: Rs. %0.2f\n", total);
	printf("Average order: Rs. %0.2f\n", avg);
	printf("Highest order: Rs. %0.2f\n\n", (orders > 0) ? amounts[high_index] : 0);
	
	return total;
}

int findHighestSalesDay(float daily_sales[], int numberOfDays)
{
	int high_index = 0;
	int i;
	for (i = 0; i < numberOfDays; i++)
	{
		if (daily_sales[i] > daily_sales[high_index])
		{
			high_index = i;
		}
	}
	return high_index + 1;
}

void displayBarChart(float dailySales[], int numberOfDays)
{
	int stars;
	int i, j;
	
	printf("\n===== DAILY SALES BAR CHART =====\n");
	for (i = 0; i < numberOfDays; i++)
	{
		printf("Day %d: ", i + 1);
		stars = dailySales[i] / 100.0;
		
		for (j = 0; j < stars; j++)
		{
			printf("*");
		}
		printf(" (Rs. %0.2f)\n", dailySales[i]);
	}
}
