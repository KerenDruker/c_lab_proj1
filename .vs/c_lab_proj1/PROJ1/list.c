#include <stdio.h>
#include <stdlib.h>
#include "list.h"


node *cerateNode(int newData)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = newData;
	newNode->next = NULL;
	return newNode;
}


void addNodeAtStart(LinkedList *list, int newData)
{
	node *newNode = cerateNode(newData);
	newNode->next = list->head;
	list->head = newNode;
}

void addNodeAtEnd(LinkedList *list, int newData)
{
	node *newNode = cerateNode(newData);
	//empty list
	if (list->head == NULL) {
		list->head = newNode;
		return;
	}
	node* currNode = list->head;
	while (currNode->next != NULL) {
		currNode = currNode->next;
	}
	currNode->next = newNode;
}

node *findNode(LinkedList *list, int data)
{
	node *currNode = list->head;
	while (currNode != NULL) {
		if (currNode->data == data) {
			return currNode;
		}
		currNode = currNode->next;
	}
	return NULL;
}

void addNodeIAfterJ(LinkedList *list, int i, int j)
{
	node *nodeI = cerateNode(i);

	struct Node* nodeJ = findNode(list->head, j);
	if (nodeJ == NULL)
	{
		printf("Error: Element j not found.\n");
		exit(1);
	}
	
	nodeI->next = nodeJ->next;
	nodeJ->next = nodeI;
	return;
}

void printIndexNodeI(LinkedList *list, int I)
{
	int index = 0;
	node *currNode = list->head;
	while (currNode != NULL) {
		if (currNode->data == I) {
			printf("%d", index);
			return;
		}
		currNode = currNode->next;
		index += 1;
	}
	printf("%d", -1);
}

// maybe too long and to similar to find node.
void deleteIndex(LinkedList *list, int index)
{
	node *currNode = list->head;
	node *prevNode = NULL;
	int i = 0;
	while (currNode != NULL && i < index){
		prevNode = currNode;
		currNode = currNode->next;
		i++;
	}
	if (currNode == NULL) {
		printf("Error: Index too large.\n");
		exit(1);
	}
	if (prevNode == NULL) {
		list->head = currNode->next;
	}
	else {
		prevNode->next = currNode->next;
	}
	free(currNode);
}

void printList(LinkedList *list)
{
	printf("[");
	node * currNode = list->head;
	while (currNode != NULL) {
		printf("%d", currNode->data);
		if (currNode->next != NULL) {
			printf(", ");
		}
		currNode = currNode->next;
	}
	printf("]");
}

void freeList(LinkedList *list)
{
	node *temp;
	while (list->head != NULL)
	{
		temp = list->head;
		list->head = list->head->next;
		free(temp);
	}
}

void exitProgram(LinkedList *list) {
	freeList(list->head);
	exit(0);
}

int main()
{

}