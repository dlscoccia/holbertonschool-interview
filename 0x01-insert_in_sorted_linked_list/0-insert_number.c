#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: start of pointer
 * @number: new node
 * Return: address of the new element or NULL if it failed
 */


listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	/*Start of the list*/
	current = *head;

	/*Allocate memory*/
	new = malloc(sizeof(listint_t));

	/*Validate the  new node isn't null*/
	if (new)
	{
		/*store number in the structure*/
		new->n = number;
		new->next = NULL;

		/*Search the position the number in the list*/
		if (*head == NULL || (*head)->n > new->n)
		{
			/*The number is in the first position*/
			new->next = *head;
			*head = new;
		}
		else
		{
			/*Compare and search the postion number*/
			while (current->next && current->next->n < new->n)
			{
				current = current->next;
			}

			/*Add conection of the new node with the list*/
			new->next = current->next;
			current->next = new;
		}
		return (new);
	}
	return (NULL);

}
