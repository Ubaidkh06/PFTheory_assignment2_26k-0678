#include <stdio.h>

// num1 and num2 are amicable pair if (sum of divisors of num1) = (num2) and vise versa

// num1 and num2 must be differeent (num1 != num2)

// both numbers must be <= n 

int main(void)
{
	int n;
	int i;
	int sum_divisors(int number);
	int sum1, sum2;
	int count = 0;
	
	printf("Input number n: ");
	scanf("%d", &n);
    
    for (i = 1; i <= n; i++)
    {
    	sum1 = sum_divisors(i);
    	sum2 = sum_divisors(sum1);
    	
    	if (sum2 == i && i != sum1 && sum1 > i)
    	{
    		printf("(%d, %d)\n", i, sum1);
			count++;
		}
	}
	printf("Total pairs: %d\n", count);
	return 0;
}

int sum_divisors(int number)
{
	int j;
	int sum = 0;
	
	for (j = 1; j < number; j++)
	{
		if (number % j == 0)
    	{
    		sum += j;
		}
	}
	return sum;
}
