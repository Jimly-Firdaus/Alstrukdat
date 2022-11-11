#include "queuelinked.h"
#include <stdio.h>
#include "charmachine.h"
char currentChar;
boolean EOP;

int main()
{

	Queue q_s, q_m, q_id;
	CreateQueue(&q_s);
	CreateQueue(&q_m);
	CreateQueue(&q_id);
	int N = 0;
	START();
	boolean switchSides = false;
	while (!EOP)
	{
		if (currentChar == ',')
		{
			switchSides = true;
			for (int i = 1; i <= N; i++)
			{
				enqueue(&q_id, i);
			}
		}
		if (!switchSides)
		{
			if (currentChar == 'B')
			{
				enqueue(&q_m, 0);
			}
			if (currentChar == 'K')
			{
				enqueue(&q_m, 1);
			}
			N++;
		}
		else
		{
			if (currentChar == 'B')
			{
				enqueue(&q_s, 0);
			}
			if (currentChar == 'K')
			{
				enqueue(&q_s, 1);
			}
		}
		ADV();
	}
	int id, trash1, trash2;
	int first_id = HEAD(q_m);
	int i = 0;
	while (!isEmpty(q_s) && i < length(q_id))
	{
		if (HEAD(q_s) == HEAD(q_m))
		{
			dequeue(&q_s, &trash1);
			dequeue(&q_m, &trash2);
			dequeue(&q_id, &id);
			if (trash1 == 0)
			{
				printf("%d -> bulat\n", id);
			}
			else
			{
				printf("%d -> kotak\n", id);
			}
			i = 0;
		}
		else
		{
			i++;
			dequeue(&q_m, &trash2);
			dequeue(&q_id, &id);
			enqueue(&q_m, trash2);
			enqueue(&q_id, id);
		}
	}

	printf("%d\n", length(q_m));

	return 0;
}