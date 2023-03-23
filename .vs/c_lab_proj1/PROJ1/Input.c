#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define MAX_LINE_LENGTH 100
#define True 1
#define False 0

int main() {
	char input[MAX_LINE_LENGTH];
	LinkedList *list;
	list->head = NULL;
	while (True)
	{
		printf("Enter a command: ");
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';

		for (int i = 0; i < strlen(input); i++) {
			input[i] = tolower(input[i]);
		}
		
		if (strncmp(input, "add_end", 7) == 0) {
			int data = atoi(input + 8);
			addNodeAtEnd(list->head, data);
		}
		else if (strncmp(input, "add_start", 9) == 0) {
			int data = atoi(input + 10);
			addNodeAtStart(list->head, data);
		}
		/////// ???????
		else if (strncmp(input, "add_after", 9) == 0) {
			char *token = strtok(input + 10, " ");
			int data = atoi(token);
			token = strtok(NULL, " ");
			int after = atoi(token);
			addNodeIAfterJ(list->head, data, after);
		}

		else if (strncmp(input, "index", 5) == 0) {
			int I = atoi(input + 6);
			printIndexNodeI(list->head, I);
		}
		else if (strncmp(input, "del", 3) == 0) {
			int index = atoi(input + 4);
			deleteIndex(list->head, index);
		}
		else if (strncmp(input, "print", 5) == 0) {
			printList(list->head);
		}
		else if (strncmp(input, "exit", 4) == 0) {
			exitProgram(list->head);
			break;
		}
		else {
			printf("Invalid command\n");
		}
	}
	}

