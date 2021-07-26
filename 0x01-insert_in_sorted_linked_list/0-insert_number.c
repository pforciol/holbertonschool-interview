#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 *
 * @head: the head of the sorted linked list.
 * @number: the number to add into the linked list.
 *
 * Return: the address of the new node, of NULL if it failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *tmp = *head;

	new = malloc(sizeof(listint_t));
	if (new)
	{
		new->n = number;

		if (!*head)
		{
			*head = new;
		}
		else
		{
			if (number < tmp->n)
			{
				new->next = tmp;
				*head = new;
			}
			else
			{
				while (tmp->next && number > tmp->next->n)
					tmp = tmp->next;

				new->next = tmp->next;
				tmp->next = new;
			}
		}

		return (new);
	}

	return (NULL);
}
