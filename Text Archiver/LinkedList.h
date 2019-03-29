#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	char* data;
	char* id;
	struct Node *next;
};


void add(Node* node, char* data, char* id);
Node* createNode(char* data, char* id);
void deleteNode(Node** head, char* id);
char* createId();
void freeLinkedList(Node** head);
