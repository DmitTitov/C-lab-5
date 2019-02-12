#include "task2.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void clearMatrix(char(*arr)[M])	//���������� ���������� �������(�������) ���������
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = ' ';
			if (j == M - 1)
			{
				arr[i][j] = '\0';
			}
		}
	}
}
void fillMatrix(char(*arr)[M])	//���������� �������� ������ ��������� ������� �����������
{
	srand(time(NULL));
	for (int i = 0; i < N/2; i++)
	{
		for (int j = 0; j < M/2; j++)
		{
			int a = rand() % 2;
			if (a == 0)
				arr[i][j] = '*'; // *
			if (a == 1)
				arr[i][j] = ' '; // ������
			if(j==0)
				arr[i][j] = ' ';
		}
	}

}
void setMatrix(char(*arr)[M])	//����������� ��������� � ������ ������� �������
{
	//3 ��������+
	for (int i = 0; i < N / 2; i++)
	{
		for (int j = (M / 2); j < M - 1; j++)
		{
			arr[i][j] = arr[i][M - j - 1];
		}
	}
	//4 ��������+
	for (int i = (N/2); i < N; i++)
	{
		for (int j = (M/2); j < M-1; j++)
		{
			arr[i][j] = arr[N-i-1][M-j-1];
		}
	}

	
	//2 ��������
	for (int i = N/2; i < N; i++)
	{
		for (int j = 1; j < M/2; j++)
		{
		arr[i][j] = arr[i][M - j - 1];
		}
	}
}
void printMatrix(char(*arr)[M])	//������ �������
{
	for (int i = 0; i < N; i++)
	{
		printf("      %s       \n", arr[i]);
	}
}