#include "header.h"

int main()
{
	int input;
	FILE* fp;
	fp = fopen("data.txt", "r+");//�а��� ����
	InitAccount(fp);

	do {
		printf("\n\n�ȳ��ϼ���! ��ö�����Դϴ�! ���Ͻô� ��ȣ�� �Է��ϼ���! \n\n\n");
		printf("�ۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡ�\n");
		printf("��                                                        ��\n");
		printf("��  1)���� ����   2)���� ��ȸ   3)�Ա�   4)���   5)����  ��\n");
		printf("��                                                        ��\n");
		printf("�ۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡ�\n");
		printf("�Է� : ");
		scanf("%d", &input);

		switch (input) {
		case 1:
			MakeAccount(fp);
			break;
		case 2:
			ReadAccount();
			break;
		case 3:
			Deposit(fp);
			break;
		case 4:
			WithDraw(fp);
			break;
		case 5:
			input = 0;
			free(head);//����, �޸� ��ȯ
			free(tail);//����, �޸� ��ȯ
			break;
		default:
			printf("�߸� �Է��ϼ̽��ϴ�. \n");
			return main();
		}
	} while (input != 0);
}



