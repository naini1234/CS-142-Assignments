#include<iostream>
using namespace std;

class Node {
	/*class Node to create a pointer
	*that points to next element of the queue and data
	*that has to be stored in the node */
	public:
		int data;
		Node* next;

		Node() {    /*A constructor to initialise the initial values*/
			data = 0;
			next = NULL;
		}
};

class Queue {
	/*
 * Class for Queue data structure.
 * Contains two pointers namely head and tail, which point
 * to the first and the last element of the list.
 * A integer variable named size stores the number of
 * items of the linked list.
 */

	private:
		Node* head;
		Node* tail;
		int n;

	public:
		Queue() {  //constructor Queue to initialise the initial values
			head = NULL;
			tail = NULL;
			n = 0;
		}
                        //member function of the class Queue.
		void inQueue(int x);
		void deQueue();
		void display();
};

void Queue::inQueue(int x) {
/*
 * Inserts a new Node 
 * at the end of the Queue.
 */

	Node* temp = new Node;
	temp->data = x;
	temp->next = NULL;

	if (head == NULL) {         //Steps done when the Queue is empty
		head = temp;
		tail = temp;
		++n;
	} else {
		tail->next = temp; //Steps done when the Queue is not empty.
		tail = temp;
		++n;
	}
}

void Queue::deQueue() {
	/*Remove the node from the beginning in the Queue.*/
	Node* p = head;
	head=p->next;
	delete p;
	--n;
}

void Queue::display() {
	/* 
 * Displays all the elements of the linked list.
 */

	if (head == NULL) {
		cout << "There are no elements in the stack." << endl;
	} else {
		Node* p = head;
		while(p != NULL) {
			cout << p->data <<"->";
			p = p->next;
		}
		cout<<"NULL"<<endl;	}
}

int main() {
	/*main function to check
	*whether the code is correct or not*/
	Queue q1;
	int p=0;
	cout << "Enter five elements to the list: " << endl;
	for (int i=0; i<5; ++i) {
		cin >> p;
		q1.inQueue(p);
	}

	q1.display();
	q1.inQueue(9);
	q1.display();
	q1.deQueue();
	q1.display();

	return 0;
}
