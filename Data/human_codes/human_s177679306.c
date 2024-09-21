//#include "pch.h"
#include "stdio.h"
#include "stdlib.h"

int cmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

int main()
{
	int N;
	int A[100000];
	int* B = (int *)malloc(sizeof(int) * 100000);
	int* C = (int *)malloc(sizeof(int) * 100000);
	int* D = (int *)malloc(sizeof(int) * 100000);
	int E[100000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	qsort((void *)A, N, sizeof(int), cmp);
	int nCnt = 1;
	B[0] = A[0];
	C[0] = 1;
	for (int i = 1; i < N; i++)
	{
		if (A[i] != A[i - 1])
		{
			B[nCnt] = A[i];
			C[nCnt] = 1;
			nCnt++;
		}
		else
			C[nCnt - 1]++;
	}

	E[0] = B[0];
	for (int i = 1; i < nCnt; i++)
	{
		E[1] = B[i];
		for (int j = 0; j < nCnt; j++)
			D[j] = C[j];
		D[0]--;
		D[i]--;

		int flag = 1;
		for (int j = 2; j < N; j++)
		{
			E[j] = E[j - 1] ^ E[j - 2];
			int *pt = (int *)bsearch(&E[j], B, nCnt, sizeof(int), cmp);
			if (pt == NULL)
			{
				flag = 0;
				break;
			}
			int nShift = 0;
			while (*(B + nShift) != *pt) nShift++;
			D[nShift]--;
			if (D[nShift] < 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1 && (E[1] ^ E[N - 1] == E[0]))
		{
			printf("Yes");
			return 0;
		}
	}

	printf("No");

	return 0;
}