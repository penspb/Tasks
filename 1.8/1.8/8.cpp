#include<stdio.h>

int main()
{
	int sizeOfArray;
	scanf("%d", &sizeOfArray);
	float *someArray = new float[sizeOfArray];
	int quantity0 = 0;
	for (int i = 0; i < sizeOfArray; i++)
	{
		scanf("%f", &someArray[i]);
		if (someArray[i] == 0)
		{
			quantity0++;
		}
	}
	printf("%d", quantity0);
	return 0;
}