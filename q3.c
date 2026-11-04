// rows = sensors
// columns = hourly readings 

// input number of sensors
// input the number of hourly readings 
//make a 2d array for it

//             input function:
// store the readings in that array

//             sensor function: (must be called individually fro each sensor)
// sum of all reading =
// avg (2dp) =
// highest = 
// lowest =
// (rtitical) number of readings >= 40 =
// (warning) number of readings between 35 and 39 (inclusive)
// longest streak of temperature >= 35

//              report function (must be called individually for each sensor)
// print all statistics for each sensor

//              highest average function
// return the sensor number with the highest average

//              print function
//print the sensor number with the highest avg and its reading

#include <stdio.h>

int main(void)
{
	int input(int hours, int sensors, float array[][hours]);
	float sensor_analysis(int i, int hours, float array[][hours]);
	int highest_avg(float average[], int sensors);


	int sensors, hours;
	int i;
	int avg_high;
	
	
	printf("Input number of sensors: ");
	scanf("%d", &sensors);
	
	printf("Input number of hours: ");
	scanf("%d", &hours);
	
	float array[sensors][hours];
	float average[sensors];
	
	printf("\n");
	input(hours, sensors, array);
	
	for (i = 0; i < sensors; i++)
	{
		average[i] = sensor_analysis(i, hours, array);		
	}
	
	avg_high = highest_avg(average, sensors);
	
	printf("\n\nHighest average: Sensor %d (%0.2f)", avg_high, average[avg_high - 1]);
    
    return 0;
}


int input(int hours, int sensors, float array[][hours])
{
	int i, j;
	for (i = 0; i < sensors; i++)
	{
		printf("Sensor %d: ", i + 1);
		for  (j = 0; j < hours; j++)
		{
			scanf("%f", &array[i][j]);
		}
		
	}
}


float sensor_analysis(int i, int hours, float array[][hours])
{
	int j;
	float total = 0;
	float avg;
	int high_index = 0;
	int low_index = 0;
	int critical = 0;
	int warning = 0 ;
	int streak_count = 0;
	int streak_high = 0;
	
	for (j = 0; j < hours; j++)
	{
		total += array[i][j];
		
		if (array[i][j] > array[i][high_index])
		{
			high_index = j;
		}
		
		if (array[i][j] < array[i][low_index])
		{
			low_index = j;
		}
		
		if (array[i][j] >= 40)
		{
			critical++;
			streak_count++;
		}
		else if (array[i][j] >= 35 && array[i][j] <= 39)
		{
			warning++;
			streak_count++;
		}
		else
		{
			streak_count = 0;
		}
		
		if (streak_count > streak_high)
		{
			streak_high = streak_count;
		}
	}
	
	avg = total / hours;
	
	printf("\nSensor %d: Total=%0.0f Avg=%0.2f Max=%0.0f Min=%0.0f\n" , i + 1, total, avg, array[i][high_index], array[i][low_index]);
	printf("\t  Critical=%d Warning=%d Longest hot streak=%d", critical, warning, streak_high);
	
	return avg;
}


int highest_avg(float average[], int sensors)
{
	int i;
	int high_index = 0;
	for (i = 0; i < sensors; i++)
	{
		if (average[i] > average[high_index])
		{
			high_index = i;
		}
	}
	return high_index + 1;
}

