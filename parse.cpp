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
void push(node * &tail, node * &first, int &counter, char input, int value, int size) {
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

//opens file and fills up the deck
void parse(node * tail_deck, node * first_deck, int counter_deck, int size_deck) { 
  std::ifstream in; 
  in.open("deck2"); //opens the file
  std::string garbageline; //holds the first line so it can be ignored
  char s; //placeholders for values
  int n;
  if(in.fail()) {
    std::cout << "Cannot open the file." << std::endl;
    return; 
  }
  else {
    std::getline(in, garbageline); //ignores the first line
    for(int i=0;i<size_deck;i++) { //reads the file line by line and fills up the array with the data
      in >> s;
      in >> n;
      push(tail_deck, first_deck, counter_deck, s, n, size_deck); //uses push to fill up the deck
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
  int size_deck = 30; 
  int size_hand = 5;
  char suits[size_deck];
  int numbers[size_deck];

  //initialize queue
  node * first_deck = new node; //constantly holds the first node of the deck
  node * head_deck = first_deck; //is the head of the deck
  node * tail_deck = first_deck; //is used for the next availible spot to put nodes
  int counter_deck = 0; //counter for queue to see how many elements are in the queue

  node * first_hand = new node; //constantly holds the first node of the deck
  node * head_hand = first_hand; //is the head of the deck
  node * tail_hand = first_hand; //is used for the next availible spot to put nodes
  int counter_hand = 0; //counter for queue to see how many elements are in the queue
  
  parse(tail_deck, first_deck, counter_deck, size_deck); //fills up the deck
  print(head_deck, tail_deck, size_deck);
}
