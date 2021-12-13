#include "header.h"

void InitAccount(FILE* fp)
{
	int id;
	char name[NAME_LEN];
	int money;
	head = (bank*)malloc(sizeof(bank));
	tail = (bank*)malloc(sizeof(bank));
	head->next = tail;
	tail->next = tail;

	while (fscanf(fp, "%d %s %d", &id, name, &money) == 3) {
		WriteAccount(id, name, money);
	}
}


void WriteAccount(int id, char* name, int money)
{
	bank* t;
	t = (bank*)malloc(sizeof(bank));
	t->id = id;
	strcpy(t->name, name);
	t->money = money;

	t->next = head->next;
	head->next = t;
}


void MakeAccount(FILE* fp)
{
	int id;
	char name[NAME_LEN];
	int money;
	bank* t;
	t = (bank*)malloc(sizeof(bank));

	printf("\n*********���� ����*********\n");
	printf("���¹�ȣ : ");
	scanf("%d", &id);
	printf("�� �� �� : ");
	scanf("%s", name);
	printf("�� �� �� : ");
	scanf("%d", &money);

	t->id = id;
	strcpy(t->name, name);
	t->money = money;

	t->next = head->next;
	head->next = t;

	BubbleSort(t);
	SaveAccount(fp);
}


void Deposit(FILE* fp)
{
	int id;
	int money;
	bank* t;
	printf("���¹�ȣ : ");
	scanf("%d", &id);
	printf("�� �� �� : ");
	scanf("%d", &money);

	for (t = head->next; t != tail; t = t->next)
	{
		if (t->id == id)
		{
			t->money += money;
			SaveAccount(fp);
			return;
		}
	}
	printf("���� ���¹�ȣ�Դϴ�.\n");

}

void WithDraw(FILE* fp)
{
	int id;
	int money;
	bank* t;
	printf("���¹�ȣ : ");
	scanf("%d", &id);
	printf("�� �� �� : ");
	scanf("%d", &money);

	for (t = head->next; t != tail; t = t->next)
	{
		if (t->id == id)
		{
			if (t->money < money)
			{
				printf("��ݾ��� �ܾ��� �ʰ��� �� �����ϴ�.\n");
				return;
			}
			else {
				t->money -= money;
			}
			SaveAccount(fp);
			return;
		}
	}
	printf("���� ���¹�ȣ�Դϴ�.\n");
}

void ReadAccount(void)
{
	int id;
	bank* t;

	printf("���¹�ȣ : ");
	scanf("%d", &id);

	for (t = head->next; t != tail; t = t->next)
	{
		if (t->id == id) {
			printf("\n*********�ܾ� ��ȸ*********\n");
			printf("���¹�ȣ : %d\n", t->id);
			printf("�� �� �� : %s��\n", t->name);
			printf("��    �� : %d��\n\n", t->money);
			return;
		}
	}
	printf("���� ���¹�ȣ�Դϴ�.\n");
}

int GetBankLength(bank* t) {
	int count = 0;
	bank* cur = t;

	while (cur != tail->next)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

void SwapBankData(bank* node1, bank* node2)
{
	int temp;
	temp = node1->id;
	node1->id = node2->id;
	node2->id = temp;
}

void BubbleSort(bank* t) {
	 bank* cur = t;

	int size = GetBankLength(t);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (cur->id < cur->next->id) {
				SwapBankData(cur, cur->next);
			}
			cur = cur->next;
		}
		cur = t->next;
	}
}

void SaveAccount(FILE* fp)

{
	bank* t;
	rewind(fp);//�����͸� ó������ ������

	for (t = head->next; t != tail; t = t->next)
	{
		fprintf(fp, "%d %s %d\n", t->id, t->name, t->money);
	}
}

