#define NAME_LEN 20

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)


typedef struct bank {//�������� ����ü
	char* name[NAME_LEN]; //������
	int id;//���¹�ȣ
	int money;//�ܾ�
	struct bank* next;//�ڱ� ���� ����ü ������
}bank;


bank* head, * tail;//����� ó���� ��

void InitAccount(FILE* fp);//����� ó���� ���� �޸� �Ҵ��ϰ�, ���Ͽ��� �Է��� �޵��� �ϴ� �Լ�
void MakeAccount(FILE* fp);//���¸� �����ϴ� �Լ�
int GetBankLength(bank* t);//����ü�� ���̸� �����ִ� �Լ�
void BubbleSort(bank* t);//�������� �Լ�
void Deposit(FILE* fp);//�Ա� �Լ�
void WithDraw(FILE* fp);//��� �Լ�
void SaveAccount(FILE* fp);//������ ������ �����ϴ� �Լ�
void SwapBankData(bank* node1, bank* node2);//����ü�� ���� �ٲ��ִ� �Լ�
void ReadAccount(void);//���¸� ��ȸ�ϴ� �Լ�
void WriteAccount(int id, char* name, int money);//�ؽ�Ʈ ���Ͽ��� �Է��� �޴� �Լ�