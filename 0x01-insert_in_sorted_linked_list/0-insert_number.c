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

listint_t *new_node = malloc(sizeof(listint_t));
listint_t *auxiliar;

if (new_node == NULL) {
return (NULL);
}
new_node->n = number;
new_node->next = NULL;
auxiliar = *head;
if (number <= auxiliar->n)
{
new_node->next = *head;
*head = new_node;
return (new_node);
}
while (auxiliar->next != NULL)
{
if (auxiliar->next->n >= number)
{
new_node->next = auxiliar->next;
auxiliar->next = new_node;
return (new_node);
}
auxiliar = auxiliar->next;
}
if (auxiliar->next == NULL)
{
auxiliar->next = new_node;
new_node->next = NULL;
}
return (new_node);
