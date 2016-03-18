/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

void number_to_str(float number, char *str, int afterdecimal){
	int i, temp = 1, j = 0, temp1 = 0;
	while (j != afterdecimal)
	{
		temp = temp * 10;
		temp1 = temp;
		j++;
	}
	j = 0;
	number = number*temp;
	temp = 10;
	while ((int)number / temp != 0)
	{
		temp = temp * 10;
	}
	for (i = 0; temp != 1; i++)
	{
		if (number < 0)
		{
			str[i++] = '-';
			number = number*(-1);
		}
		str[i] = (((int)number) * 10 / temp) % 10 + '0';
		temp = temp / 10;
		if (temp1 == temp)
		{
			i++;
			str[i] = '.';
		}
	}
	str[i] = '\0';

}