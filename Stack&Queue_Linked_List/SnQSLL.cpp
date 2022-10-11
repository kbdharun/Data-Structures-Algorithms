#include<iostream>
using namespace std;

struct node{
	int data;
	node* link;
};

struct Head{
	int count;
	node* first;
};

Head* createStack(){
	Head* head = new Head;
	head->count = 0;
	head->first = NULL;
	return head;
}

node* createNode(int dataIn){
	node* temp = new node;
	temp->data = dataIn;
	temp->link = NULL;
	return temp;
}

bool emptyStack(Head* head){
	if(head->count ==0)
		return true;
	else
		return false;
}

void pushStack(Head* head, int dataIn){
	// Insert at beginning
	node* temp = createNode(dataIn);
	temp->link = head->first;
	head->first = temp;
	head->count++;
}

bool popStack(Head* head, int &dataOut){
	if(emptyStack(head))
		return false;
	else{
		dataOut = head->first->data;
		head->first = head->first->link;
		head->count--;
		return true;
	}
}

bool stackTop(Head* head, int &dataOut){
	if(emptyStack(head))
		return false;
	else{
		dataOut = head->first->data;
		return true;
	}
}

void destroyStack(Head* head){
	int dataOut;
	while(!emptyStack(head))
		popStack(head, dataOut);
	delete head;
}

void display(Head* head){
	node* temp = head->first;
	cout << "Stack elements: ";
	while(temp!=NULL){
		cout << temp->data << " ";
		temp = temp->link;
	}
	cout << endl;
}

int main(){
	Head* head = createStack();
	cout << "1. Push Element \n2. Pop Element \n3. Stack Top \n4. Stack Empty \n5. Destroy Stack \n6. Display Stack \n7. Exit" << endl;
	int ch;
	do{
	cout << "Enter your choice: "; cin >> ch;
	switch(ch){
		case 1:
			int data;
			cout << "Enter element to insert: "; cin >> data;
			pushStack(head, data);
			break;

		case 2:
			if (!popStack(head, data))
				cout << "Element cannot be removed" << endl;
			else
				cout<<data<< " popped successfully!" << endl;
			break;
		case 3:
			if(stackTop(head, data))
				cout << "StackTop element: " << data << endl;
			else
				cout << "StackTop not present" << endl;
			break;
		case 4:
			if(emptyStack(head))
				cout << "Stack is Empty" << endl;
			else
				cout << "Stack is NOT empty" << endl;
			break;	
		case 5:
			destroyStack(head);
			break;
		case 6:
			display(head);
			break;
		case 7:
			break;
		default:
			cout << "Invalid choice. " << endl;

	}
	}while(ch!=7 && ch!=5);
}
