#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: head linked list
 * Return: Always 0.
 */
int is_palindrome(listint_t **head)
{
	listint_t *splitStart = *head;
	listint_t *splitEnd;
	listint_t *tmp = *head;

	if (*head == NULL)
	{
		return (1);
	}

	while (1)
	{
		tmp = tmp->next->next;
		if (tmp == NULL)
		{
			splitEnd = splitStart->next;
			break;
		}
		if (tmp->next == NULL)
		{
			splitEnd = splitStart->next->next;
			break;
		}

		splitStart = splitStart->next;
	}

	splitStart->next = NULL;
	reverse_listint(&splitEnd);
	int result = check(&splitEnd, head, splitStart->n);

	return (result);
}

/**
 * reverse_listint -  Reverse list
 * @head: Head
 * Return:Head
 *
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL;

	while (*head != NULL)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}
	*head = prev;
	return (*head);
}


/**
 * check -  check is palimdrome
 * @compare: compare split linked list
 * @head: head linkedlist
 * @number: number of value to stop
 * Return:Head
 *
 */
int check(listint_t **compare, listint_t **head, int number)
{
	listint_t *compareLinked = *compare;
	listint_t *tmp = *head;

	while (1)
	{
		if (compareLinked->n == tmp->n)
		{
			if (number == compareLinked->n)
			{
				return (1);
			}
		}
		compareLinked = compareLinked->next;
		tmp = tmp->next;
	}
	return (0);
}
