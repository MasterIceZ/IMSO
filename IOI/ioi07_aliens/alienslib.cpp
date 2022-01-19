#include "alienslib.h"
#include <stdio.h>

#define UNINITIALIZED 0
#define INITIALIZED 1
#define INVALID 2

int __X0, __Y0, __XC, __YC;
int __N, __M;
int __call_count = 0;
int __state = UNINITIALIZED;

void get_size_and_start(int &N, int &X0, int &Y0)
{
	if (__state != UNINITIALIZED)	
		__state = INVALID;		
	else
	{
		scanf("%d %d", &__N, &__M);
		scanf("%d %d", &__X0, &__Y0);
		scanf("%d %d", &__XC, &__YC);
		__state = INITIALIZED;
		N = __N;
		X0 = __X0;
		Y0 = __Y0;
	}
}

int examine(int X, int Y)
{
	if (__state != INITIALIZED)
	{
		__state = INVALID;
		return -1;
	}
	else if (__call_count >= 300)
	{
		__state = INVALID;
		return -1;
	}
	else
	{
		__call_count++;
		int x0 = __XC - __M - __M - __M/2;
		int y0 = __YC - __M - __M - __M/2;
		int dx = X - x0;
		int dy = Y - y0;
		
		if (dx < 0 || dy < 0 || dx >= 5*__M || dy >= 5*__M)
			return 0;
		else
		{
			dx = dx / __M;
			dy = dy / __M;
			if ((dx+dy) % 2 == 0)
				return 1;
			else
				return 0;
		}
	}
}

void solution(int X, int Y)
{
	if (__state != INITIALIZED)
	{
		__state = INVALID;
		printf("invalid\n");
	}
	else
	{
		if (X == __XC && Y == __YC)
			printf("correct\n");
		else
			printf("incorrect\n");
		__state = INVALID;
	}
}
