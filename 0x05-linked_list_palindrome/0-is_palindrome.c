#include "lists.h"
/**
* add_nodeint - adds a node at the begging of list
* @head: pointer to h
* @n: int value
* Return: pointer to new node
**/

listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new_node = NULL;

new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->next = *head;
*head = new_node;

return (new_node);
}


/**
* is_palindrome - determine if a linked lists is palindrome
* @head: pointer to h
* Return: 1 if it is palindrome - 0 if it not
**/
int is_palindrome(listint_t **head) {
listint_t *current = NULL, *current_fast, *len;
int lenght = 0, i = 0;
current_fast = *head;
len = *head;

while (len != NULL) {
lenght++;
len = len->next;
}

while (i < lenght / 2) {
add_nodeint(&current, current_fast->n);
current_fast = current_fast->next;
i++;
}

while (current_fast != NULL && current != NULL) {
if (current->n != current_fast->n){
free_listint(current);
return 0;
}
current = current->next;
current_fast = current_fast->next;
}
free_listint(current);
return 1;
}
