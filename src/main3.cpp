#define _CRT_SECURE_NO_WARNINGS
#define STR 4
#include <stdio.h>
#include <string.h>
#include "task3.h"
#include <time.h>


int main(int argc, char * argv[])
{
	char buf[256];					//������ ������ �� txt
	char out[256] = {0};					//������ ������ �� txt
	if (argc < 2)		
	{
		printf("Wrong format\n");
		return -1;
	}

	FILE *fr = fopen(argv[1], "rt");	//��������� ���� �� ������
	if (!fr)
	{
		printf("Cannot open %s\n", argv[1]);
		return -1;
	}
	printf("Strings from txt:\n\n");
	int i = 0;
	while (!feof(fr))					//������ ���� � ���������� � �����
	{
		fgets(buf, 256, fr);
		printf("%s", buf);

		mixLine(buf, out);		//������������� ��� ����� ������

		printf("New strings\n");			//����� ����� ������
		printf("%s\n", out);

		i++;		
		
	}
	printf("\n\n");
	fclose(fr);							//������� �����
	
	return 0;
}