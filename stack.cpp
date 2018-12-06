#include "CARDGAME.h"

void stackPush (char suit, int number, node* &wait shead)
{
	
	node* temp = new node;
	if (head == NULL)
	{
		temp -> suit = suit;
		temp -> number = number;
		temp -> next = NULL;
		head = temp;
	}
	
	else
	{
		temp -> suit = suit;
		temp -> number = number;
		temp -> next = head;
		head = temp;
	}
}

void stackPop (node* &head)
{
	if (head == NULL)
	{
		std::cout << "Stack is empty" << std::endl;
		return 0;
	}
	node* temp = new node;
	temp = head;
	head = head -> next;
	temp -> next = NULL;
}
