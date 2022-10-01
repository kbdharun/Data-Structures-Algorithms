#include<iostream>
using namespace std;

struct node{
	int data;
	node *link;
};

node *first = NULL; // points first node
node* createList(){
	node *list = new node;
	list->data=0;
	list->link = NULL;
	return list;
}

void display(){
	node *temp = first;
	while(temp!=NULL){
		cout << temp->data << ", ";
		temp = temp->link;
	}
}

void insertBeg(int dataIn){
	node *pnew = new node;
	pnew->data = dataIn;
	pnew->link = first;
	first = pnew;
}


void insertEnd(int dataIn){
	node *pnew = new node;
	pnew->data = dataIn;
	pnew->link = NULL;

	if (first==NULL)
		first = pnew;
	else{
		node *temp = first;
		while(temp->link!= NULL)
			temp = temp->link;
		temp->link = pnew;
	}
}

void insertAfterPos(int pos, int dataIn){
	int count=1;
	node *temp = first;
	while (temp!=NULL && count < pos)
		temp = temp-> link; count++;
	if (temp==NULL)
		cout << "Invalid position" << endl;
	else{
		node *ptr = new node;
		ptr->data = dataIn;
		ptr->link = temp->link;
		temp->link = ptr;
	}
}

// deletion
void delValue(int dataout){
	node *temp = first;
	node *ppre = NULL;
	while(temp!=NULL && temp->data!=dataout){
		temp = temp->link;
		ppre = temp;
	}

	if (temp!=NULL){
		if (temp == first)
			first = first->link;
		else
			ppre = temp->link;
	}

	else
		cout << "Invalid data" << endl;
}

void delPosition(int pos){
	node *ppre = NULL;
	node *temp = first;
	int count=1;
	while(count != pos && temp!=NULL){
		ppre = temp;
		temp = temp->link;
		count++;
	}

	if (temp!=NULL){
		if(temp==first)
			first = temp->link;
		else
			ppre->link = temp->link;
	}
}

// search
void search(int target){
	int count = 1;
	node *temp = first;
	while(temp!=NULL && temp->data!=target){
		temp = temp->link;
		count++;
	}

	if (temp!=NULL)
	{
		cout << "Element found at position: " << count << endl;
	}
	
	else{
		cout << "Element "<<target<< " not found!" << endl;
	}
}


int main(){
	//cout << createList() << endl;
	insertBeg(5);
	insertBeg(2);
	insertBeg(12);
	insertEnd(20);
	insertAfterPos(1, 200);
	delValue(12);
	delPosition(3);
	display();
	search(2);
	search(5);
}


