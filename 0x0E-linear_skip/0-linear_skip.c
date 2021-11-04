#include "search.h"

/**
 * linear_skip - linear search algorithm in a skip list
 *
 * @list: the skip list to search in
 * @value: value to search for
 *
 * Return: the first index where value is located if found, -1 if not found
 **/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *cur, *prev;

	if (!list)
		return (NULL);

	cur = list;
	while (cur->next && cur->n < value)
	{
		prev = cur;
		if (cur->express)
			cur = cur->express;
		else
		{
			while (cur->next)
				cur = cur->next;
		}
		if (cur->next)
			printf("Value checked at index [%lu] = [%i]\n", cur->index, cur->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev->index,
	       cur->index);

	cur = prev;
	while (cur && cur->n < value)
	{
		printf("Value checked at index [%lu] = [%i]\n", cur->index, cur->n);
		if (cur->next)
			cur = cur->next;
		else
			return (NULL);
	}

	if (cur && cur->n == value)
	{
		printf("Value checked at index [%lu] = [%i]\n", cur->index, cur->n);
		return (cur);
	}

	return (NULL);
}
