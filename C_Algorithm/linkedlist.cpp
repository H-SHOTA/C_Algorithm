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
} *header;

// �폜����
enum DELETE_TYPE{
	FRONT = 0,	//�擪�폜
	REAR,
	SPECIFIC	//����̒l�̍폜
};

// �}��
bool Insert(int value)
{
	// ���X�g����̏ꍇ�̓w�b�_�ɒǉ�
	if( header == NULL )
	{
		header = (CELL*)calloc(1, sizeof(CELL));
		header->value = value;
		return true;
	}
	// �����ɑ��
	CELL *pos = header, *prev;
	while( pos != NULL )
	{
		prev = pos;
		pos = pos->next;
	}
	prev->next = (CELL*)calloc(1, sizeof(CELL));
	prev->next->value = value;
	return true;
}

// �폜
bool Delete(int value, DELETE_TYPE _type)
{
	if(&header == NULL)
	{
		printf("list is empty\n");
		return false;
	}
	
	switch(_type)
	{
	case FRONT:
		{
			CELL* p = header;
			header = p->next;
			free(p);
		}
		break;
	case REAR:
		{
			CELL *pos = header, *prev = NULL;
			while( pos->next != NULL )
			{
				prev = pos;
				pos = pos->next;
			}
			prev->next = pos->next;
			free(pos);
		}
		break;
	case SPECIFIC:
		{
			CELL *pos = header, *prev = NULL;
			while( pos->next != NULL )
			{
				if(pos->value == value)
				{
					break;
				}
				prev = pos;
				pos = pos->next;
			}
			if( prev != NULL )
			{
				prev->next = pos->next;
				free(pos);
			}
			else
			{
				CELL* p = header;
				header = p->next;
				free(p);
			}
		}
		break;
	default:
		break;
	}
}