/*
 * �A�����X�g
 */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// ���X�g�̍\��
struct CELL{
	struct CELL *next;
	int value;
} header;

// �폜����
enum DELETE_TYPE{
	FRONT = 0,	//�擪�폜
	REAR,		//�����폜
	SPECIFIC	//����̒l�̍폜
};

// �}��
bool Insert(int value)
{
	CELL *newVal, *now, *prev;
	// �V�v�f����
	if( (newVal = (CELL*)malloc(sizeof(CELL))) == NULL )
	{
		puts("memory error!");
		return false;
	}
	newVal->value = value;

	// �����ړ�
	now = header.next;
	prev = &header;
	while( now != NULL )
	{
		prev = now;
		now = now->next;
	}

	// �l�̑��
	newVal->next  = now;
	newVal->value = value;
	prev->next = newVal;
	return true;
}

// �폜
bool Delete(int value, DELETE_TYPE _type)
{
	switch(_type)
	{
	case FRONT:
		{
			if(&header == NULL)
			{
				printf("list is empty\n");
				return false;
			}

			CELL temp = header;
			header = *temp.next;
			free(&temp);
		}
	case REAR:
		{

		}
	case SPECIFIC:
		{

		}
	default:
		break;
	}
}

void main()
{
	Insert(5);
	Insert(4);
	Insert(3);
	Delete(0, FRONT);
	return;
}