#include<iostream>
using namespace std;
struct node{
	int data;
	node* link;
};

node* createNode(int key){
	node* temp = new node;
	temp->data = key;
	temp->link = NULL;
	return temp;
}

node** createHash(int size){
	node** hashTable = new node*[size]; // CHECK
	for (int i=0; i<size; i++)
		hashTable[i] = NULL;
	return hashTable;
}

void insertToHash(node** hashTable, int size, int key){
	int hashIndex = key%size;
	node* p = createNode(key);
	p->link = hashTable[hashIndex];
	hashTable[hashIndex] = p;
}

void deleteFromHash(node** hashTable, int size, int key){
	int hashIndex = key%size;
	node* delNode = hashTable[hashIndex];
	node* temp = NULL;
	while(delNode != NULL){
		if(delNode->data == key)
		{	if (temp==NULL)
				hashTable[hashIndex] = delNode->link;
			else
				temp->link = delNode->link;
                  break;
                }
		
		temp = delNode;
		delNode = delNode->link;
		//cout << "Given key is not present in hash Table.";
		
	}
	
}

void searchInHash(node** hashTable, int size, int key){
	int hashIndex = key%size;
	node* searchNode = hashTable[hashIndex];
	while(searchNode != NULL){
		if(searchNode->data == key)
			cout << searchNode->data << endl;
		searchNode = searchNode->link;
		//cout << "Search element unavailable in hash table";
	}
}

void display(node** hashTable, int size){
	for(int i=0; i<size; i++){
		node* temp = hashTable[i];
		while(temp!=NULL){
			cout << temp->data << " ";
			temp = temp->link;
		}
	}
}

int main(){
	int size,ele;
	cout << "Enter hash size: "; cin >> size;
	node** H = createHash(size);
	cout << "1. Insert into hash \n2. Delete from hash \n3. Search in hash \n4. Display hash \n5. Exit" << endl;
	
	int choice;
	do{
	cout << "Enter your choice: "; cin >> choice;
	switch(choice){
		case 1:
			cout << "Enter element to insert: "; cin >> ele;
			insertToHash(H, size, ele);
			break;
		case 2:
			cout << "Enter element to delete: "; cin >> ele;
			deleteFromHash(H, size, ele);
			break;
		case 3:
			cout << "Enter element to search: "; cin >> ele;
			searchInHash(H, size, ele);
			break;
		case 4:
			display(H,size);
			break;
		case 5:
			break;
		default:
			cout << "Invalid choice" << endl;
	}
	}while(choice!=5);
}

