#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_node - insert a node into a linked list
 * @head: pointer to list
 * @number: data of the node
 * Return: addrres to new node or NULL if it fails
 */


listint_t *insert_node(listint_t **head, int number)
{

listint_t *new_node;
listint_t *auxiliar;
auxiliar = *head;
new_node = malloc(sizeof(listint_t));

if (new_node != NULL) {
new_node->n = number;
new_node->next = NULL;

if (auxiliar == NULL || auxiliar->n > new_node->n){
new_node->next = *head;
*head = new_node;
}
else
{
while (auxiliar->next != NULL && auxiliar->next->n < new_node->n)
{
auxiliar = auxiliar->next;
}
new_node->next = auxiliar->next;
auxiliar->next = new_node;
}
return (new_node);
}
return (NULL);
}
