/*
 * スタック
 */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef long ELEM;

#define STACK_SIZE 100

ELEM stack[STACK_SIZE];
int n;

void error(char *s)
{
	fprintf(stderr, s);
	exit(1);
}

void init()
{
	n = 0;
}

void push(ELEM x)
{
	if( n >= STACK_SIZE )
	{
		error("stack overflow\n");
	}
	stack[n++] = x;
}

ELEM pop()
{
	if(n <= 0)
	{
		error("stack underflow\n");
	}
	return stack[--n];
}

int empty()
{
	return n == 0;
}

// main関数
void main()
{
	int c = 0;
	long x = 0,a = 0,b = 0;

	init();
	while( (c = getchar()) != EOF )
	{
		if(isdigit(c))
		{
			ungetc(c, stdin);
			scanf("%ld", &x);
			push(x);
		}
		else
		{
			switch(c)
			{
			case '+':
				b = pop();
				a = pop();
				push( a + b);
				break;
			case '-':
				b = pop();
				a = pop();
				push( a - b);
				break;
			case '*':
				b = pop();
				a = pop();
				push( a * b);
				break;
			case '/':
				b = pop();
				a = pop();
				push( a / b);
				break;
			case '\n':
				if(!empty())
				{
					printf("答えは%ldです\n", pop());
				}
				break;
			case ' ':
			case '\t':
				break;
			default:
				printf("不正な文字がありました\n");
				printf("入力しなおしてください\n");
				while( (c = getchar()) != EOF && c != '\n')
					;
				break;
			}
		}
	}
}