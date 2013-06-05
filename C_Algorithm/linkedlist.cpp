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
} *header;

// 削除方式
enum DELETE_TYPE{
	FRONT = 0,	//先頭削除
	REAR,
	SPECIFIC	//特定の値の削除
};

// 挿入
bool Insert(int value)
{
	// リストが空の場合はヘッダに追加
	if( header == NULL )
	{
		header = (CELL*)calloc(1, sizeof(CELL));
		header->value = value;
		return true;
	}
	// 末尾に代入
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

// 削除
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