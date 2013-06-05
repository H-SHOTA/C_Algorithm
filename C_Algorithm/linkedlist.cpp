/*
 * 連結リスト
 */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// リストの構造
struct CELL{
	struct CELL *next;
	int value;
} header;

// 削除方式
enum DELETE_TYPE{
	FRONT = 0,	//先頭削除
	REAR,		//末尾削除
	SPECIFIC	//特定の値の削除
};

// 挿入
bool Insert(int value)
{
	CELL *newVal, *now, *prev;
	// 新要素生成
	if( (newVal = (CELL*)malloc(sizeof(CELL))) == NULL )
	{
		puts("memory error!");
		return false;
	}
	newVal->value = value;

	// 末尾移動
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

// 削除
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