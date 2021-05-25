#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 *
 * Return: Always 0.
 */
int is_palindrome(listint_t **head)
{
  listint_t *start;
  listint_t *end;
  listint_t *tmp = *head;
  int count = 0;

  while (tmp != NULL)
  {
    count++;
    tmp = tmp->next;
  }

  for (int i = 0; i < count / 2; i++)
  {
    end = *head;
    start = *head;

    for (int k = 0; k < i; k++)
    {
      start = start->next;
    }

    for (int j = (count - 1) - i; j > 0; j--)
    {
      end = end->next;
    }

    if (start->n != end->n)
    {
      return 0;
    }
  }
  return 1;
}
