#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "task2.h"
#include <time.h>

void delay(int ms)
{
	int c = clock() + ms;
	while (clock() < c);
}

void screenClear()
{
	for (int i = 0; i < 25; i++)
	{
		printf("\n");
	}
}

int main()
{
	char arr[N][M];
	char (*a)[M] = arr;
	while(1)
	{
		clearMatrix(a); //���������� ���������� �������(�������) ���������

		fillMatrix(a);	//���������� �������� ������ ��������� ������� �����������

		setMatrix(a);	//����������� ��������� � ������ ������� �������
		screenClear();
		printMatrix(a); //������ �������

		delay(2500);
		
	}

	 
	return 0;
}