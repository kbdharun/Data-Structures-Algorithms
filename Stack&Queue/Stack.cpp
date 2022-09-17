/*C++ Program to demonstrate Stack operation*/
#include<iostream>
using namespace std;
class Stack1{
	int size;
	int *a;
	int top;
	public:
		Stack1(){ //Constructor
			cout<<"Enter size of array:";cin>>size;
			top=-1;
			a= new int[size];
		}
		bool push(int ele){
			if (top==size-1){
					cout<<"Stack overflow."<<endl;
					return false;
				}
				a[++top] = ele;
				return true;
	}
			
		bool pop(int dataout){
			if(top ==-1){
				cout<<"Stack Underflow"<<endl;
				return false;
			}
			dataout = a[top--];
			return true;
	}
		bool stackTop(int dataout){
			if (top==-1)
				return false;
			dataout= a[top];
			return true;
	}
		bool isFull(){
			if (top==size-1)
				return true;
			else
				return false;
	}
		bool isEmpty(){
			if (top==-1)
				return true;
			else
				return false;
	}
};

int main()
{
	Stack1 s1; //Creating object
	int n;
	cout<<"\t\t\tOperations\n"<<"\nChoices:\n1. Push\n2. Pop\n3. StackTop Value\n4. isFull\n5.isEmpty\n6.Exit\n"<<endl;
	cout<<"Enter your choice:";cin>>n;
	bool status=true;
	do{	
	switch(n)
	{
		case 1:
			int ele;
			cout<<"Enter elements to push:";cin>>ele;
			if (s1.push(ele))
				cout<<"Element has been pushed successfully."<<endl;
			break;
		case 2:
			int data;
			if (s1.pop(data))
				cout<<"The element "<<data<<" has been removed."<<endl;
			break;
		case 3:
			if (s1.stackTop(data))
				cout<<"stackTop element is"<<data<<endl;
			else
				cout<<"Stack is empty!"<<endl;			
			break;
		case 4:
			if (s1.isFull())
				cout<<"Stack is full!"<<endl;
			else
				cout<<"Stack isn't full!"<<endl;
			break;
		case 5:
			if (s1.isEmpty())
				cout<<"Stack is Empty!"<<endl;
			else
				cout<<"Stack isn't empty!"<<endl;
			break;
		case 6:
			status = false;
			break;
		default:
			cout<<"Invalid input, Please try again"<<endl;
	}
 }while(status);
	return 0;
}
