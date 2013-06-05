/*
 * 連結リスト
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
	// 新要素生成
	if( (newVal = (CELL*)malloc(sizeof(CELL))) == NULL )
	{
		puts("memory error!");
		return false;
	}
	newVal->value = value;

	// 末尾挿入
	now = header.next;
	prev = &header;
	while( now != NULL )
	{
		prev = now;
		now = now->next;
	}

	// 値の代入
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