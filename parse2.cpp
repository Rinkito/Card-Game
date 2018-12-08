#include <iostream>
#include <iomanip>
#include <fstream>
#include <thread>
#include <chrono>
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
    if(counter == size-1) { //checks to see if the tail reaches hand size
      tail->next = first;
      tail->suit = input; 
      tail->number = value;
      tail = tail->next; //sets tail back to the first spot in the hand
      counter++;
    }
    else{
      if(counter == size) {
          counter = 0;
      }
      tail->suit = input; 
      tail->number = value;
      tail->next = new node; 
      tail = tail->next;
      counter++;
    }
}

void push_stack(node* &tail, node* &first, int &counter, char input, int value)
{  
    if(counter == 0) { //checks to see if the tail reaches hand size
      tail->suit = input; 
      tail->number = value;    
      tail->next = new node;
      //tail = tail->next; //sets tail back to the first spot in the hand
      counter++;
    }
    else{
      tail = tail->next;
      tail->suit = input; 
      tail->number = value;
      tail->next = new node; 
      //tail = tail->next;
      counter++;
    }
}

node pop_deck(node array[], int & head) {
  node temp = array[head];
  head++;
  return temp; //return the node that was the head
}

void pop_hand(node * &head, node * &first) {
  /*if(head->next == NULL) {
    head = first;
  }
  else {*/
    head = head->next;
  //}
}

void pop_stack(node* &tail,node* &head,int sort_counter){
     if (isEmpty(sort_counter)) //check if empty list
    {
        std::cout << "Empty" << std::endl;
        return;

    }
    else if(head == tail) //identical case to queue, if there is 1 node left
    {
        delete head;
        head = tail = NULL;
    }
    node* temp = tail; //now we have a temporary node set equal to the current tail
    tail = head; //because temp is now at tail, we can change tail to equal head (back to beginning of list)
    while (tail->next != temp) //this will iterate through the linked list until just before the current temp
    { //which temp is now in previous tail's pos, or at last of list
        tail = tail->next; // set tail equal to the node before the last of the list for future pop
    }
    tail->next = NULL; // unlink the very last node because temp is already that node
    delete temp; // now delete temp since we had stored in the data char
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
	std::cout << "| "; 
  for(int i=0;i<size;i++) { 
    std::cout << head->suit << head->number << " | ";
    head = head->next;
  }
  std::cout << std::endl;
}

void load(std::string a) //Loading animation
{
	std::string dot[] = {".", ". .", ". . ."};
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			std::cout << a << dot[i] << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			system("clear");
		}
	}
}


int main() {
  int choice;
  int choice2; 
  int size_deck = 30; //max deck size 
  int left = 30; //used for the game later to count how many cards are in the deck
  int size_hand = 5;
  int actions = 5; //amount of cards left in hand basically
  int turn = 1; // number of turns 
  int size_output = 10;
  
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
	//node* head = new node;
	node* headA = NULL;
	node* tailA = new node;
    //    node* topA = new node;	

	node* headB = NULL;
	node* tailB = new node;
    //    node* topB = new node;	

	node* headC = NULL;
	node* tailC = new node;
    //    node* topC = new node;        

        //initialize these for later use
        tailA->number = 0;
        tailB->number = 0;
        tailC->number = 0;

	// 5 sorting stack nodes initialize
	node* headO1 = NULL;
	node* tailO1 = new node;
    //    node* topO1 = new node;
	node* headO2 = NULL;
	node* tailO2 = new node;
    //    node* topO2 = new node;
	node* headO3 = NULL;
	node* tailO3 = new node;
    //    node* topO3 = new node;
	node* headO4 = NULL;
	node* tailO4 = new node;
    //    node* topO4 = new node;	
	node* headO5 = NULL;
	node* tailO5 = new node;
    //    node* topO5 = new node;
	int counter_sort = 0;
	int iA,iB,iC; //suit A,B,C counters for sort full

  //sort algorithm - determines which stack user wants to put card in and will only allow user to put in card numbers
  //1 less than current value at top of respective sorting stacks
 
  load("Drawing");
  for(int i=0; i<5; i++) {
    push(tail_hand, first_hand, counter_hand, size_hand, deck[head_deck].suit, deck[head_deck].number);
    pop_deck(deck, head_deck);
    left--;
  }
  bool game_end = false;
	while(game_end == false)
	{ 
		print(head_hand, actions, first_hand);
		// initial cards if possible will go to output stack
		if(tail_hand->suit == 'A' && tail_hand->number == 1){
			push(tailA,headA,iA,size_output,tail_hand->suit,tail_hand->number);
		}
		else if(tail_hand->suit == 'B' && tail_hand->number == 1){
			push(tailB,headB,iB,size_output,tail_hand->suit,tail_hand->number);
		}
		else if(tail_hand->suit == 'C' && tail_hand->number == 1){
			push(tailC,headC,iC,size_output,tail_hand->suit,tail_hand->number);
		}
		// if there's already cards in output stack and hand fits (1 value more + same suit)
		else if(tail_hand->suit == 'A' && tail_hand->number == (tailA->number)+1){
			push(tailA,headA,iA,size_output,tail_hand->suit,tail_hand->number);
		}
		else if(tail_hand->suit == 'B' && tail_hand->number == (tailB->number)+1){
			push(tailB,headB,iB,size_output,tail_hand->suit,tail_hand->number);
		}
		else if(tail_hand->suit == 'C' && tail_hand->number == (tailC->number)+1){
			push(tailC,headC,iC,size_output,tail_hand->suit,tail_hand->number);
		}
		else // sorting stack pushes
		{
			if(tailO1->number == 0){ //if sort stack is empty
				push(tailO1,headO1,counter_sort,size_output,tail_hand->suit,tail_hand->number);
			}
			else if(tail_hand->number = (tailO1->number)-1){ // otherwise make sure value is 1 less than what is currently on sort stack
				push(tailO1,headO1,counter_sort,size_output,tail_hand->suit,tail_hand->number);
			}
			else if(tailO2->number == 0){
				push(tailO2,headO2,counter_sort,size_output,tail_hand->suit,tail_hand->number);
			}
			else if(tail_hand->number = (tailO2->number)-1){
				push(tailO2,headO2,counter_sort,size_output,tail_hand->suit,tail_hand->number);
			}
			else if(tailO3->number == 0){
				push(tailO3,headO3,counter_sort,size_output,tail_hand->suit,tail_hand->number);
			}
			else if(tail_hand->number = (tailO3->number)-1){
				push(tailO2,headO2,counter_sort,size_output,tail_hand->suit,tail_hand->number);
			}
			else if(tailO4->number == 0){
				push(tailO4,headO4,counter_sort,size_output,tail_hand->suit,tail_hand->number);
			}
			else if(tail_hand->number = (tailO4->number)-1){
				push(tailO4,headO4,counter_sort,size_output,tail_hand->suit,tail_hand->number);
			}
			else if(tailO5->number == 0){
				push(tailO5,headO5,counter_sort,size_output,tail_hand->suit,tail_hand->number);
			}
			else if(tail_hand->number = (tailO5->number)-1){
				push(tailO5,headO5,counter_sort,size_output,tail_hand->suit,tail_hand->number);
			}
		}
		while(true) {
			
			
		      if(left == 0) //if the deck is empty and the hand is empty
              {
				game_end = true;
              }
			}
		}
}

