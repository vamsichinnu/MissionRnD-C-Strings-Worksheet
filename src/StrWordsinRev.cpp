/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void reverse(char *input, int i, int j)
{
	while (i < j)
	{
		input[i] = input[i] + input[j];
		input[j] = input[i] - input[j];
		input[i] = input[i] - input[j];
		i++;
		j--;
	}
}
void str_words_in_rev(char *input, int len){
	int i = 0, j = len - 1, k, p = 0;
	reverse(input, i, j);
	for (k = 0; input[k] != '\0'; k++)
	{
		if ((input[k + 1] == ' ') || (input[k + 1] == '\0'))
		{
			reverse(input, p, k);
			p = k + 2;

		}
	}
}
