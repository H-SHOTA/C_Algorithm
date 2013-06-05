/*
 * �A�����X�g
 */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

struct CELL{
	struct CELL *next;
	int value;
} header;

bool insert(int value)
{
	CELL *newVal, *now, *prev;
	// �V�v�f����
	if( (newVal = (CELL*)malloc(sizeof(CELL))) == NULL )
	{
		puts("memory error!");
		return false;
	}
	newVal->value = value;

	// �����}��
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

void main()
{
	insert(5);
	insert(4);
	insert(3);
	return;
}