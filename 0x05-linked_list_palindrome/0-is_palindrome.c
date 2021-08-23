#include "lists.h"

/**
 * is_palindrome - checks if a linked list is a palindrome
 *
 * @head: the head address of the linked list
 *
 * Return: 1 if it's a palindrome, 0 else
 */

int is_palindrome(listint_t **head)
{
	listint_t *lst = *head;
	int val[2048], i = 0, j = 0;

	if (*head)
	{
		while (lst)
		{
			val[i] = lst->n;
			lst = lst->next;
			i++;
		}

		while (j < i / 2)
		{
			if (val[j] == val[i - j - 1])
				j++;
			else
				return (0);
		}
	}

	return (1);
}
