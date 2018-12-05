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
    counter == 0; //reset the counter
    array[counter].suit = input;
    array[counter].number = value;
    array[counter].next = NULL; //set the next pointer back to the beginning of the queue
  }
  else {
    array[counter].suit = input;
    array[counter].number = value;
    array[counter].next = new node;
    counter++;
  }
}

void push(node* &tail, node* &first, int &counter, char input, int value)
{
	node* temp = new node; 
    temp->suit = input; 
    temp->number = value;
    temp->next = NULL; 
    if (first == NULL) 
    {
        first = tail = temp;
        tail->next = NULL;
        counter++;
    }
    else //otherwise, we push in from tail
    {
        tail->next = temp;
        tail = temp;
        counter++;
    }
}

//opens file and fills up the deck
void parse(node array[], int & deck_counter) { 
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
      push_deck(array, deck_counter, s, n); //uses push to fill up the deck
    }
  }
}

//prints out the array 
void print(node deck[], int counter) {
  for(int i=0;i<counter;i++) { 
    std::cout << deck[i].suit << " " << deck[i].number;
    std::cout << std::endl;
    //head = head->next;
  }
}

int main() {
  int choice;
  int size_deck = 30; 
  int size_hand = 5;
  int turn = 1; // number of turns 
  
  node deck[size_deck]; //ring buffer array for deck
  
  /*initialize deck
  node * first_deck = new node; //constantly holds the first node of the deck
  node * head_deck = first_deck; //is the head of the deck
  node * tail_deck = first_deck; //is used for the next availible spot to put nodes
  */
  
  int counter_deck = 0; //counter for queue to see how many elements are in the queue
  parse(deck, counter_deck); //fills up the deck
  //std::cout << counter_deck << std::endl;

  //initialize hand
  node * first_hand = new node; //already have new node as temp in function
  node * head_hand = first_hand;
  node * tail_hand = first_hand; 
  int counter_hand = 0; 
  
  //3 sorting stack nodes initialize
	node* head = new node;
	node* headA = NULL;
	node* tailA = head;
	
	node* headB = NULL;
	node* tailB = head;
	
	node* headC = NULL;
	node* tailC = head;
	int counter_sort = 0;
	int iA,iB,iC; //suit A,B,C counters for sort full
	 
	std::cout << "Drawing..." << std::endl;
	for (int i = 0; i < 5; i++) //first time starting - draw 5 cards into hand as queue
	{
		push(tail_hand,head_hand,counter_hand,tail_hand->suit,tail_hand->number);
	}
  
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
	}
  
  print(deck, counter_deck);
}
