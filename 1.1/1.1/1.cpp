#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	float result, squaredk, k;
	scanf("%f", &k);
	squaredk = k * k;
	result = (squaredk + k) * (squaredk + 1) + 1;
	printf("%0.2f", result);
	return 0;
}