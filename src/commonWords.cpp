/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31

int spacecheck(char *str1, int i)
{
	for (i = i; str1[i] != '\0'; i++)
	{
		if ((int)str1[i] != 32)
		{
			return i;
		}
	}
	return -1;
}
int nextword(char *str, int j)
{
	for (j = j; str[j] != '\0'; j++)
	{
		if ((int)str[j] == 32 && (int)str[j + 1] != 32)
		{
			return j;
		}
	}
	return -1;
}
char ** commonWords(char *str1, char *str2) {
	int i = 0, j = 0, k = 0, p = 0, temp;
	char **res;
	res = (char **)malloc(sizeof(char)*SIZE);
	if (str1&&str2)
	{
		while (str1)
		{

			res[p] = (char *)malloc(sizeof(char)*k);
			i = spacecheck(str1, i);
			if (i == -1)
			{
				return NULL;
			}
			temp = i;
			for (j = 0; str2[j] != '\0'; j++)
			{

				if (str2[j] == str1[i] && str1[i] != 32 && str1[i] != '\0')
				{
					res[p] = (char *)realloc(res[p], sizeof(char)*k + 1);
					res[p][k] = str1[i];
					i++; k++;
				}
				else if (((int)str2[j] == 32 && str1[i] == '\0') || ((int)str1[i] == 32 && (int)str2[j] == 32))
				{
					res[p][k] = '\0';
					p++;
					k = 0;
					break;
				}
				else
				{
					res[p] = (char *)realloc(res[p], sizeof(char)* 0);
					j = nextword(str2, j + 1);

					i = temp;
					k = 0;
					if (j == -1)
					{
						break;
					}

				}
			}
			if (str2[j] == '\0' && (int)str1[i] == 32 || str2[j] == '\0'&&str1[i] == '\0')
			{
				res[p][k] = '\0';
				p++;
				k = 0;
			}
			i = nextword(str1, i) + 1;
			j = 0;
			if (i == 0)
			{
				break;
			}
		}
		if (p == 0)
		{
			return NULL;
		}
		res[p] = '\0';
		return res;
	}
	else
	{
		return NULL;
	}
}