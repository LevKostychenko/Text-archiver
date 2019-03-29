#include "LinkedList.h"

Node* createNode(char* data, char* id)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = (char*)malloc(20);
	node->id = (char*)malloc(10);
	*(node->data) = *data;
	*(node->id) = *id;
	node->next = NULL;
	return node;
}



void add(Node* node, char* data, char* id)
{
	if (node == NULL)
	{
		node = createNode(data, id);
	}
	else if (node->next == NULL)
	{
		node->next = createNode(data, id);
	}
	else
	{
		Node* next = node->next;
		node->next = createNode(data, id);
		node->next->next = next;
	}
}

//search and delete node by Id 
void deleteNode(struct Node **head_ref, char* id)
{
	
	Node* temp = *head_ref, *prev;

	if (temp != NULL && *(temp->id) == *id)
	{
		*head_ref = temp->next;   
		free(temp);              
		return;
	}

	while (temp != NULL && *(temp->id) != *id)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) return;

	
	prev->next = temp->next;

	free(temp);
}

char* createId()
{

	static int ID = -1;
	char buffer[20];
	char* convertedId = (char *)malloc(10);
	ID++;

	return  convertedId = itoa(ID, buffer, 10);
}

//free list
void freeLinkedList(Node** head)
{
	Node* current = *head;
	Node* next;
	while (current != NULL) 
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}