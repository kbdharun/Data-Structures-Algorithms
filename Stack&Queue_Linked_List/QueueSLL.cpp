#include<iostream>
using namespace std;

struct node{
	int data;
	node* link;
};

struct Head{
	int count;
	node* front;
	node* rear;
};

Head* createQueue(){
	Head* head = new Head;
	head->count = 0;
	head->front = NULL;
	head->rear = NULL;
	return head;
}

node* createNode(Head* head, int dataIn){
	node* temp = new node;
	temp->data = dataIn;
	temp->link = NULL;
	return temp;
}

bool queueFull(Head* head){
	node* temp = new node;
	if(temp==NULL)
		return false;
	else
		return true;
	delete temp;
}

bool emptyQueue(Head* head){
	if(head->count ==0)
		return true;
	else
		return false;
}

bool enqueue(Head* head, int data){
	if(queueFull(head))
		return false;
	node* temp = createNode(head,data);
	if(emptyQueue)
		head->front = temp;
	else
		head->rear->link =temp;
	head->rear = temp;
	head->count++;
	return true;
}

bool dequeue(Head* head, int &dataOut){
	if(emptyQueue(head))
		return false;
	dataOut = head->front->data;
	if(head->count ==1)
		head->rear = NULL;
	head->front = head->front->link;
	head->count--;
	return true;
}

bool queueFront(Head* head, int &dataOut){
	if(emptyQueue(head))
		return false;
	dataOut = head->front->data;
	return true;
}

bool queueRear(Head* head, int &dataOut){
	if(emptyQueue(head))
		return false;
	dataOut = head->rear->data;
	return true;
}

int queueCount(Head* head){
	return head->count;}

void destroyQueue(Head* head){
	while(head->count!=0){
		int dataOut;
		dequeue(head, dataOut);
	}
	delete head;
}

int main(){
	Head* head = createQueue();
	cout << "1. Enqueue \n2. Dequeue \n3. Queue Front \n4. Queue Rear \n5. Queue count \n6. Destroy queue \n7. Exit" << endl;
	int ch;
	do{
	cout << "Enter your choice: "; cin >> ch;
	switch(ch){
		case 1:
			int data;
			cout << "Enter element to enqueue: "; cin >> data;
			enqueue(head, data);
			break;

		case 2:
			if (!dequeue(head, data))
				cout << "Element cannot be removed" << endl;
			else
				cout<<data<< " dequeued successfully!" << endl;
			break;
		case 3:
			if(queueFront(head, data))
				cout << "QueueFront element: " << data << endl;
			else
				cout << "QueueFront not present" << endl;
			break;
		case 4:
			if(queueRear(head,data))
				cout << "QueueRear element: " << data << endl;
			else
				cout << "QueueRear not present" << endl;
			break;	
		case 5:
			queueCount(head);
			break;
		case 6:
			destroyQueue(head);
			break;
		case 7:
			break;
		default:
			cout << "Invalid choice. " << endl;

	}
	}while(ch!=7 && ch!=6);
}
