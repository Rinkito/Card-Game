#include <iostream>
#include <iomanip>
#include <fstream>

struct node {
  char suit;
  int number;
  node * next;
};

//checks to see if empty
bool isEmpty(int counter) {
  if(counter == 0) { 
    return true;
  }
  return false;
}

//push function
void push_deck(node array[], int & counter, char input, int value) {
  if(counter == 30) { //if the queue reaches the max size
    counter = 0; //reset the counter
    array[counter].suit = input;
    array[counter].number = value;
    array[counter].next = NULL; //set the next pointer back to the beginning of the queue
    counter++;
  }
  else {
    array[counter].suit = input;
    array[counter].number = value;
    array[counter].next = new node;
    counter++;
  }
}

void push(node* &tail, node* &first, int &counter, int size, char input, int value)
{  
    if(counter == size) { //checks to see if the tail reaches hand size
      counter = 0; //loops tail back around
      tail = first; //sets tail back to the first spot in the hand
      tail->suit = input; 
      tail->number = value;
    }
    else{
      tail->suit = input; 
      tail->number = value;
      tail->next = new node; 
      tail = tail->next;
      counter++;
    }
}

node pop_deck(node array[], int & head) {
  node temp = array[head];
  head++;
  return temp; //return the node that was the head
}

void pop_hand(node * &head, node * &first) {
  if(head->next == NULL) {
    head = first;
  }
  else {
    head = head->next;
  }
}

//opens file and fills up the deck
void parse(node array[], int &tail) { 
  std::ifstream in;
  char s; //placeholders for values
  int n; 
  in.open("deck2"); //opens the file
  std::string garbageline; //holds the first line so it can be ignored
  if(in.fail()) {
    std::cout << "Cannot open the file." << std::endl;
    return; 
  }
  else {
    std::getline(in, garbageline); //ignores the first line
    for(int i=0;i<30;i++) { //reads the file line by line and fills up the array with the data
      in >> s;
      in >> n;
      push_deck(array, tail, s, n); //uses push to fill up the deck
    }
  }
}

//prints out the array 
void print(node deck[], int counter, int size) {
  for(int i=0;i<size;i++) { 
    if(counter == size) {
      counter = 0;
    }
    std::cout << deck[counter].suit << " " << deck[counter].number;
    counter++;
    std::cout << std::endl;
    //head = head->next;
  }
}

//print for hands or anything using linked lists
void print(node * head, int size, node * first) { 
  for(int i=0;i<size;i++) { 
    if(head == NULL) {
      head = first;
    }
    std::cout << head->suit << " " << head->number;
    std::cout << std::endl;
    head = head->next;
  }
}

int main() {
  int choice;
  int size_deck = 30; 
  int size_hand = 5;
  int turn = 1; // number of turns 
  
  //initializes decks
  node deck[size_deck]; //ring buffer array for deck 
  int head_deck = 0; //effective head pointer for the deck
  int tail_deck = 0; //next availible place to put values in the deck
  parse(deck, tail_deck); //fills up the deck
  
  //initialize hand
  node * first_hand = new node; //already have new node as temp in function
  node * head_hand = first_hand; //head of the queue used to pop values
  node * tail_hand = first_hand; //tail of the queue used to store values
  int counter_hand = 0; 
  
  //3 sorting stack nodes initialize
	node* head = new node;
	node* headA = NULL;
	node* tailA = head;
	
	node* headB = NULL;
	node* tailB = head;
	
	node* headC = NULL;
	node* tailC = head;
	// 5 sorting stack nodes initialize
	node* headO1 = NULL;
	node* tailO1 = head;
	node* headO2 = NULL;
	node* tailO2 = head;
	node* headO3 = NULL;
	node* tailO3 = head;
	node* headO4 = NULL;
	node* tailO4 = head;	
	node* headO5 = NULL;
	node* tailO5 = head;
	int counter_sort = 0;
	int iA,iB,iC; //suit A,B,C counters for sort full
	
	std::cout << "Drawing..." << std::endl;
	for (int i = 0; i < 5; i++) //first time starting - draw 5 cards into hand as queue
	{
		push(tail_hand, first_hand, counter_hand, size_hand, deck[head_deck].suit, deck[head_deck].number); 
                pop_deck(deck, head_deck); //makes sure that the card is removed from the deck
	}   
  pop_hand(head_hand, first_hand);
  print(head_hand, size_hand, first_hand); 
  
  //sort algorithm - determines which stack user wants to put card in and will only allow user to put in card numbers
  //1 less than current value at top of respective sorting stacks
  /*
  int sort_choice;
  std::cin >> sort_choice;
  if(sort_choice == 1) // push hand into sorting stack 1
  {
	  if(tailO1->number == 0) // if nothing in stack, set number to 1 higher than input
	  {
		  tailO1->number = (tail_hand->number)+1;
	  }
	  if(tail_hand->number = (tailO1->number)+1) // must be lower value than card currently in stack
	  {  
	  push(tailO1,headO1,counter_sort,size_hand,tail_hand->suit,tail_hand->number);
		}
		else
		{
			std::cout << "Not a valid value to be placed" << std::endl;
			// return back to sort menu?
		}	  
  }
  else if(sort_choice == 2)
  {
	  if(tailO2->number == 0) // if nothing in stack, set number to 1 higher than input
	  {
		  tailO2->number = (tail_hand->number)+1;
	  }
	  if(tail_hand->number = (tailO2->number)+1) // must be lower value than card currently in stack
	  {  
	  push(tailO2,headO2,counter_sort,size_hand,tail_hand->suit,tail_hand->number);
		}
		else
		{
			std::cout << "Not a valid value to be placed" << std::endl;
			// return back to sort menu?
		}	  
  }
  else if(sort_choice == 3)
  {
	  if(tailO3->number == 0) // if nothing in stack, set number to 1 higher than input
	  {
		  tailO3->number = (tail_hand->number)+1;
	  }
	  if(tail_hand->number = (tailO3->number)+1) // must be lower value than card currently in stack
	  {  
	  push(tailO3,headO3,counter_sort,size_hand,tail_hand->suit,tail_hand->number);
		}
		else
		{
			std::cout << "Not a valid value to be placed" << std::endl;
			// return back to sort menu?
		}	  
  }
  else if(sort_choice == 4)
  {
	  if(tailO4->number == 0) // if nothing in stack, set number to 1 higher than input
	  {
		  tailO4->number = (tail_hand->number)+1;
	  }
	  if(tail_hand->number = (tailO4->number)+1) // must be lower value than card currently in stack
	  {  
	  push(tailO4,headO4,counter_sort,size_hand,tail_hand->suit,tail_hand->number);
		}
		else
		{
			std::cout << "Not a valid value to be placed" << std::endl;
			// return back to sort menu?
		}	  
  }
  else if(sort_choice == 5)
  {
	  if(tailO5->number == 0) // if nothing in stack, set number to 1 higher than input
	  {
		  tailO5->number = (tail_hand->number)+1;
	  }
	  if(tail_hand->number = (tailO5->number)+1) // must be lower value than card currently in stack
	  {  
	  push(tailO5,headO5,counter_sort,size_hand,tail_hand->suit,tail_hand->number);
		}
		else
		{
			std::cout << "Not a valid value to be placed" << std::endl;
			// return back to sort menu?
		}	  
  }
  */
  
  /*
  std::cout << "Enter 1, 2, 3 to place onto the respective sorting stacks ";
  std::cout << "or 4 to place first card in hand back into bottom of deck." << std::endl;
  bool game_end = false;
	while(game_end == false)
	{
		std::cout << "TURN " << turn << std::endl;
		if(choice == 1)
		{  
			if(iA == 10) // 10 values per suit
			{
				std::cout << "Stack A is full!" << std::endl;
				//return; redo the push
			}
			else if(tail_hand->suit == 'B' || tail_hand->suit == 'C')
			{
				std::cout << "Wrong card type" << std::endl;
				//return; redo the push
			}
			else if(tail_hand->number != (tailA->number)+1)
			{
				std::cout << "Not sorted correctly!" << std::endl;
				//return; redo push
			}
			iA++;
			push(tailA,headA,counter_sort,tail_hand->suit, tail_hand->number);
			//pop
		}
		else if (choice == 2)
		{
			if(iB == 10) // 10 values per suit
			{
				std::cout << "Stack B is full!" << std::endl;
				//return; redo the push
			}
			else if(tail_hand->suit == 'A' || tail_hand->suit == 'C')
			{
				std::cout << "Wrong card type" << std::endl;
				//return; redo the push
			}
			else if(tail_hand->number != (tailB->number)+1)
			{
				std::cout << "Not sorted correctly!" << std::endl;
				//return; redo push
			}
			iB++;
			push(tailB,headB,counter_sort,tail_hand->suit, tail_hand->number);
			//pop
		}
		else if (choice == 3)
		{
			if(iC == 10) //10 values per suit
			{
				std::cout << "Stack A is full!" << std::endl;
				//return; redo the push
			}
			else if(tail_hand->suit == 'B' || tail_hand->suit == 'A')
			{
				std::cout << "Wrong card type" << std::endl;
				//return; redo the push
			}
			else if(tail_hand->number != (tailC->number)+1)
			{
				std::cout << "Not sorted correctly!" << std::endl;
				//return; redo push
			}
			iC++;
			push(tailC,headC,counter_sort,tail_hand->suit,tail_hand->number);
			//pop
		}
		else if (choice == 4)
		{
			push_deck(deck, counter_deck, tail_hand->suit, tail_hand->number); // suit and number comes from hand on all of these
			//pop hand that was sent to deck
			//push from deck back into hand
		}
		
		turn++;
		if(turn = 100)
		{
		game_end = true; }//end game	
	}*/
  
}
