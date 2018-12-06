#include "CARDGAME.h"

void queuePush (node* &head, node* &tail,  char suit, int number)
{
	node* temp = new node;
	temp -> suit = suit;
	temp -> number = number;
	temp -> next = NULL;
	if (head == NULL)
	{
		head = tail = temp;
		tail -> next = NULL;
	}
	
	else
	{
		tail -> next = temp;
		tail = temp;
		tail -> next = NULL;
	}
}

void queuePop (node* &head, node* &tail)
{
	if (head == NULL)
	{
		std::cout << "Queue is empty" << std::endl;
		return;
	}
	
	node* temp = head;
	head = head -> next;
}
