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
void push(node* &tail, node* &first, int &counter, int size, char input, int value) {
  if(counter == size) { //if the queue reaches the max size
    counter == 0; //reset the counter
    tail->suit = input;
    tail->number = value;
    tail->next = first; //set the next pointer back to the beginning of the queue
    tail = tail->next;
  }
  else {
    tail->suit = input;
    tail->number = value;
    tail->next = new node;
    tail = tail->next;
    counter++;
  }
} 

void push_hand(node* &tail, node* &first, int &counter, char input, int value)
{
	if(counter == 5) // hand only holds max 5 cards
	{
		cout << "Hand is full!" << endl;
	}
	node* temp = new node; 
    temp->suit = input; 
    temp->number = value;
    temp->next = NULL; 
    
    if (first_h == NULL) 
    {
        first_h = tail = temp;
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

void push_sort(node* &tail, node* &first, int &counter, char input, int value)
{
	node* temp = new node; 
    temp->suit = input; 
    temp->number = value;
    temp->next = NULL; 
    if (first_h == NULL) 
    {
        first_h = tail = temp;
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
void parse(node * tail_deck, node * first_deck, int counter_deck, int size_deck, char values, int numbers) { 
  std::ifstream in; 
  in.open("deck2"); //opens the file
  std::string garbageline; //holds the first line so it can be ignored
  if(in.fail()) {
    std::cout << "Cannot open the file." << std::endl;
    return; 
  }
  else {
    std::getline(in, garbageline); //ignores the first line
    for(int i=0;i<size_deck;i++) { //reads the file line by line and fills up the array with the data
      in >> s;
      in >> n;
      push(tail_deck, first_deck, counter_deck, size_deck, values, numbers); //uses push to fill up the deck
    }
  }
}

//prints out the array 
void print(node * head, node * tail, int counter) {
  for(int i=0;i<counter;i++) { 
    std::cout << head->suit << " " << head->number;
    std::cout << std::endl;
    head = head->next;
  }
}

int main() {
  int choice;
  int size_deck = 30; 
  int size_hand = 5;
  //char suits[size_deck];
  //int numbers[size_deck];
  int turn = 1; // number of turns passed
  char s; //placeholders for values
  int n;
  //initialize deck
  node * first_deck = new node; //constantly holds the first node of the deck
  node * head_deck = first_deck; //is the head of the deck
  node * tail_deck = first_deck; //is used for the next availible spot to put nodes
  int counter_deck = 0; //counter for queue to see how many elements are in the queue
  parse(tail_deck, first_deck, counter_deck, size_deck, s, n); //fills up the deck

  //initialize hand
  //node * first_hand = new node; //already have new node as temp in function
  node * head_hand = first_hand;
  node * tail_hand = first_hand; 
  int counter_hand = 0; 
  
  //3 sorting stack nodes initialize
	node* headA = NULL;
	node* tailA = head;
	
	node* headB = NULL;
	node* tailB = head;
	
	node* headC = NULL;
	node* tailC = head;
	int counter_sort = 0;
	int iA,iB,iC; //suit A,B,C counters for sort full
	 
	cout << "Drawing..." << endl;
	for (int i = 0; i < 5; i++) //first time starting - draw 5 cards into hand as queue
	{
		push_hand(tail_hand,head_hand,counter_hand,/*pop [node]->suit?, pop [node]->number?*/)
	}
  
  cout << "Enter 1, 2, 3 to place onto the respective sorting stacks ";
  cout << "or 4 to place first card in hand back into bottom of deck." << endl;
  
	while(bool game_end == false)
	{
		cout << "TURN " << turn << endl;
		if(choice == 1)
		{  
			if(iA == 10) // 10 values per suit
			{
				cout << "Stack A is full!" << endl;
				//return; redo the push
			}
			else if(tail_hand->suit == 'B' || tail_hand->suit == 'C')
			{
				cout << "Wrong card type" << endl;
				//return; redo the push
			}
			else if(tail_hand->number != (tailA->number)+1)
			{
				cout << "Not sorted correctly!" << endl;
				//return; redo push
			}
			iA++;
			push_sort(tailA,headA,counter_sort,tail_hand->suit, tail_hand->number);
			//pop
		}
		else if (choice == 2)
		{
			if(iB == 10) // 10 values per suit
			{
				cout << "Stack B is full!" << endl;
				//return; redo the push
			}
			else if(tail_hand->suit == 'A' || tail_hand->suit == 'C')
			{
				cout << "Wrong card type" << endl;
				//return; redo the push
			}
			else if(tail_hand->number != (tailB->number)+1)
			{
				cout << "Not sorted correctly!" << endl;
				//return; redo push
			}
			iB++;
			push_sort(tailB,headB,counter_sort,tail_hand->suit, tail_hand->number);
			//pop
		}
		else if (choice == 3)
		{
			if(iC == 10) //10 values per suit
			{
				cout << "Stack A is full!" << endl;
				//return; redo the push
			}
			else if(tail_hand->suit == 'B' || tail_hand->suit == 'A')
			{
				cout << "Wrong card type" << endl;
				//return; redo the push
			}
			else if(tail_hand->number != (tailC->number)+1)
			{
				cout << "Not sorted correctly!" << endl;
				//return; redo push
			}
			iC++;
			push_sort(tailC,headC,counter_sort,tail_hand->suit,tail_hand->number);
			//pop
		}
		else if (choice == 4)
		{
			push(tail_deck, first_deck, counter_deck, size_deck,tail_hand->suit, tail_hand->number); // suit and number comes from hand on all of these
			//pop hand that was sent to deck
			//push from deck back into hand
		}
		
		turn++;
		
		game_end == true; //end game	
	}
  
  print(head_deck, tail_deck, size_deck);
}
