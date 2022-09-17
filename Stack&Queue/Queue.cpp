#include<iostream>
using namespace std;

class Queue{
	int size;
	int *a;
	int F;
	int R;

	public:
		Queue(){
			cout << "Enter size: "; cin >> size;
			a = new int[size];
			F = R = -1;
		}
		
		bool enqueue(int ele){
			if(R>=size-1){
				cout << "Overflow" << endl;
				return false;
			}
			if (F==-1)
				F+=1;
			R+=1;
			a[R] = ele;
			return true;
		}

		bool dequeue(int &dataout){
			if (F==-1){
				cout << "Underflow" << endl;
				return false;
			}
			dataout = a[F];
			if (F==R)
				R=F=-1;
			else
				F++;
			return true;
			}

		bool queueFront(int &dataout){
			if (F==-1){
				cout << "Underflow" << endl;
				return false;
			}
			dataout = a[F];
			return true; 
		}

		bool queueRear(int &dataout){
			if (R==-1){
				cout << "Underflow";
				return false;
			}
			dataout = a[R];
			return true;
		}

};

int main(){
	int n;
	Queue q1;
	bool status=true;
	do{
	cout << "Queue operations" << endl;
	cout << "1. Enqueue \n2. Dequeue \n3. Queue Front \n4. Queue Rear \n5. Exit" << endl;

	cout << "Enter choice: "; cin >> n;
	switch(n){
		case 1:
			int ele;
			cout << "Enter element to push: "; cin >> ele;
			if (q1.enqueue(ele))
				cout << "Element successfully pushed." << endl;
			break;
		
		case 2:
			int data;
			if(q1.dequeue(data))
				cout << "The element "<< data << " is removed."<< endl;
			break;

		case 3:
			if (q1.queueFront(data))
				cout << "queueFront element is " << data << endl;
			else
				cout << "queueFront not there" << endl;
			
			break;

		case 4:
			if (q1.queueRear(data))
				cout << "queueRear element is " << data << endl;
			else
				cout << "queueRear not there" << endl;
			
			break;

		case 5:
			status = false;
			break;

		default:
			cout << "Invalid input for choice." << endl;
			break;
	}
	}while(status);

}
