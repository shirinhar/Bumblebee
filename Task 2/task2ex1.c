#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main ()
{
	
	printf("Enter number of input: ");
	int size;
	scanf("%d",&size);
	int str[size];

	for (int l; l< size; l++)
	{
		printf("Enter number: ");
		scanf("%d",&str[l]);
	}

	bool swap = false;

	int i, j;
	while(1)
	{
		swap = false;
		for (j = 0; j < size-1 ; j++)
		{
			if(str[j]>str[j+1])
			{
				int y = str[j+1];
				str[j+1] = str[j];
				str[j] = y;
				swap = true;
			}
		}

		if (swap == false){
			break;
		}

	}

	for (i = 0; i< size;i++)
	{
		printf("%d, ", str[i]);
	}

	return 0;
}
