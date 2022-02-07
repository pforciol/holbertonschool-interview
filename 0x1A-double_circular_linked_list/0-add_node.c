#include "list.h"

/**
 * add_node_end - adds a node at the end
 * @list: the double circular linked list
 * @str: the string to instert in the node
 * Return: the address of the new insterted node or NULL if failure
 */
List *add_node_end(List **list, char *str)
{
	List *new = NULL, *first = *list, *last = *list;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);

	if (str && !new->str)
	{
		free(new);
		return (NULL);
	}

	while (last && last->next && last->next != first)
		last = last->next;

	if (first)
	{
		new->next = first;
		first->prev = new;
	}

	else
	{
		*list = new;
		new->next = new;
	}

	if (last)
	{
		new->prev = last;
		last->next = new;
	}

	else
		new->prev = new;

	return (new);
}

/**
 * add_node_begin - adds a node at the beginning
 * @list: the double circular linked list
 * @str: the string to instert in the node
 * Return: the address of the new insterted node or NULL if failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new = NULL, *first = *list, *last = *list;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);

	if (str && !new->str)
	{
		free(new);
		return (NULL);
	}

	while (last && last->next && last->next != first)
		last = last->next;

	if (first)
	{
		new->next = first;
		first->prev = new;
	}

	else
		new->next = new;

	if (last)
	{
		new->prev = last;
		last->next = new;
	}

	else
		new->prev = new;

	*list = new;

	return (new);
}
