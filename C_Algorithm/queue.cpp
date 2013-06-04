/*
 * キュー(リンクバッファ)
 */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


typedef long ELEM;

#define QUEUE_SIZE 100

ELEM queue[QUEUE_SIZE];
int front;
int rear;

#define next(a)(((a) + 1) % QUEUE_SIZE)

void error(char *s)
{
	fprintf(stderr, s);
	exit(1);
}

void init()
{
	front = rear = 0;
}

void enqueue(ELEM x)
{
	if(next(rear) == front)
	{
		error("Queue buffer is full !!\n");
	}
	queue[rear] = x;
	rear = next(rear);
}

ELEM dequeue()
{
	ELEM x;

	if(front == rear)
	{
		error("Queue is Empty !\n");
	}

	x = queue[front];
	front = next(front);
	return x;
}

int empty()
{
	return front == rear;
}

// main関数
void main()
{
	char c, d;
	long x = 0;

	while( (c = getchar()) != EOF )
	{
		getchar();
		switch(c)
		{
		case 'e':
		case 'E':
			while( (d = getchar()) != EOF )
			{
				if(isdigit(d))
				{
					ungetc(d, stdin);
					scanf("%ld", &x);
					break;
				}
			}
			enqueue(x);
			getchar();
			break;
		case 'd':
		case 'D':
			printf("dequeue:%ld\n", dequeue());
			break;
		default:
			break;
		}

	}
}