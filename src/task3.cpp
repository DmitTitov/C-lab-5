#include "task3.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char *mixLine(char *instr, char * outstr)	//������������� ��� ����� ������
{
	char * pointers[64] = { 0 };
	int count = 0;  //������� �������� ���������� ����
	int inWord = 0; //���� ��������� �����

	for (int i = 0; instr[i] != '\0';i++)
	{
		if ((instr[i] >= 'A' && instr[i] <= 'Z')
			|| (instr[i] >= 'a' && instr[i] <= 'z')
			|| (instr[i] >= '!' && instr[i] <= '9'))
		{
			if (!inWord) //inWord==0; or inWord!=0;
			{
				inWord = 1;
				pointers[count++] = instr + i; // ��������� , ��� ��� � ����� ������� �� ���������� ����� 
			}

		}
		else
		{
			inWord = 0;
		}
	}
	int count2 = 0;
	for (int i = 0; i <= count - 1; i++)								//��������� �����
	{
		int j = 0;
		int a = strlen(instr) - 1;
		int lenWord = 0;
		int temp = j;
		while ((pointers[i][j] >= 'A' && pointers[i][j] <= 'Z')
			|| (pointers[i][j] >= 'a' && pointers[i][j] <= 'z')
			|| (pointers[i][j] >= '!' && pointers[i][j] <= '9'))  // ������� ����� �����
		{
			lenWord++;
			j++;
		}
		j = temp;
		if (lenWord <= 3)				// ���� ����� ������ ���� ��������, ��  ������ �� ������
		{
			while ((pointers[i][j] >= 'A' && pointers[i][j] <= 'Z')
				|| (pointers[i][j] >= 'a' && pointers[i][j] <= 'z')
				|| (pointers[i][j] >= '!' && pointers[i][j] <= '9'))   // ��� (*(pointers[i]+j))
			{

				*(outstr + count2) = pointers[i][j];
				count2++;
				j++;
			}
		}
		else           //// ���� ����� ������ ���� ��������, ������������ �����, �� �� ������ 1 � ���������
		{
			while ((pointers[i][j] >= 'A' && pointers[i][j] <= 'Z')
				|| (pointers[i][j] >= 'a' && pointers[i][j] <= 'z')
				|| (pointers[i][j] >= '!' && pointers[i][j] <= '9'))   // ��� (*(pointers[i]+j))
			{
				if (j == 0)		//������ �����
				{
					*(outstr + count2) = pointers[i][j];
					count2++;
					j++;
				}

				for (j = 1; j < lenWord - 1;j++)
				{
					*(outstr + count2) = pointers[i][lenWord - j - 1];
					count2++;
				}
				if (j == lenWord - 1)//��������� �����
				{
					*(outstr + count2) = pointers[i][j];
					count2++;
					j++;
				}
			}
		}


		if (i <= count)
		{
			*(outstr + count2) = ' ';
		}
		count2++;
	}
	//*(outstr + count2-	1) = '\n';

	*(outstr + count2 - 1) = '\0';
	return outstr;
}



char *mixChars(char *in, char *out)			//������������� �������� � ����� �����
{
	return out;
}
