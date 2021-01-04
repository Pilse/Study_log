#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char String1[51];
	int pointer = 0;
	int result = 0;
	int d = 1;
	int signal = 0;
	gets(String1);
	int length = strlen(String1);

	for (int i = 0; i <length+1; i++)
	{
		if (String1[i] == '-' || String1[i] == '+' || i==length)
		{
			for (int j = pointer; j < i; j++)
			{
				d = d / 10;
				if(signal==0)
				result = result + (String1[j] * d);
				else if(signal==1)
				result = result - (String1[j] * d);
			}
			pointer = i + 1;
			if (String1[i] == '-')
				signal = 1;
		}
		else
		{
			d = d * 10;
			String1[i] = String1[i] - '0';
		}
		}
	printf("%d", result);
	return 0;
}