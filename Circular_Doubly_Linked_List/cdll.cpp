#include <iostream>

using namespace std;

struct node
{
	int data;
	node* fore;
	node* back;
};

struct list
{
	int count;
	node* head;
	node* rear;
}*cdll;

void createCDLL()
{
	cdll = new list();
	cdll->count = 0;
	cdll->head = NULL;
	cdll->rear = NULL;
	cout<<"CDLL Created ..."<<endl;
}

bool emptyCDLL()
{
	if(cdll->count == 0)
	{
		cout<<"Empty .. "<<endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool fullCDLL()
{
	node* n = new node();
	if(n == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int countCDLL()
{
	return cdll->count;
}

int searchCDLLFromHead(int target)
{
	node* pLoc = cdll->head;
	int pos = 1;
	if(emptyCDLL())
	{
		return -1;
	}
	if(target == pLoc->data)
	{
		return pos;
	}
	pLoc = pLoc->fore;
	pos ++;
	while(pLoc != cdll->head && target > pLoc->data)
	{
		pos++;
		pLoc = pLoc->fore;
	}
	if(target == pLoc->data)
	{
		return pos;
	}
	else
	{
		return -1;
	}
}

int searchCDLLFromRear(int target)
{
	node* pLoc = cdll->rear;
	int pos = 1;
	if(emptyCDLL())
	{
		return -1;
	}
	if(target == pLoc->data)
	{
		return pos;
	}
	pLoc = pLoc->back;
	pos ++;
	while(pLoc != cdll->head && target < pLoc->data)
	{
		pos++;
		pLoc = pLoc->back;
	}
	if(target == pLoc->data)
	{
		return pos;
	}
	else
	{
		return -1;
	}
}

void insertCDLL(int dataIn,node* &pPre,node* &pLoc)
{
	node* n = new node();
	n->data = dataIn;
	if(pPre == NULL)
	{
		if(cdll->count==0)
		{
			cdll->head = n;
			cdll->rear = n;
			cout<<"\nStep if if.. "<<endl;
		}
		else
		{
			cdll->head->back = n;
			cdll->rear->fore = n;
			cout<<"Step if else .. "<<endl;
		}
		n->back = cdll->rear;
		n->fore = cdll->head;
		cdll->head = n;
		cout<<"Step if .. "<<endl;
	}
	else
	{
		n->fore = pLoc;
		n->back = pPre;
		pPre->fore = n;
		if(pLoc == cdll->head)
		{
			cdll->rear = n;
		}
		pLoc->back = n;
		cout<<"Step else .. "<<endl;
	}
	cout<<"Inserted : "<<dataIn<<endl;
	cdll->count ++;
}

void deleteCDLL(int dataIn,node* &pPre,node* &pLoc)
{
	if(cdll->count == 1)
	{
		cdll->head = cdll->rear = NULL;
	}
	else
	{
		if(pPre != NULL)
		{
			pPre->fore = pLoc->fore;
			pLoc->fore->back = pPre;
			if(pLoc == cdll->rear)
			{
				cdll->rear = pPre;
			}
		}
		else
		{
			cdll->head = pLoc->fore;
			pLoc->fore->back = pLoc->back;
			cdll->rear = pLoc->fore;
		}
	}
	delete pLoc;
	cdll->count --;
	cout<<"Deleted : "<<dataIn<<endl;
}

bool searchList(node* &pPre,node* &pLoc,int target)
{
	pPre = NULL;
	pLoc = cdll->head;
	if(emptyCDLL())
	{
		cout<<"pPre : "<<pPre<<endl;
		return false;
	}
	if(pLoc->data == target)
	{
		return true;
	}
	if(target < pLoc->data)
	{
		return false;
	}
	pPre = pLoc;
	pLoc = pLoc->fore;
	while(pLoc != cdll->head && target > pLoc->data)
	{
		pPre = pLoc;
		pLoc = pLoc->fore;
	}
	if(pLoc == cdll->head)
	{
		return false;
	}
	else
	{
		if(target == pLoc->data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void displayCDLLHeadToRear()
{
	node* n = cdll->head;
	cout<<"Head to Rear : ";
	if(n != NULL)
	{
		cout<<n->data<<" ";
		n = n->fore;
	}
	while(n != cdll->head)
	{
		cout<<n->data<<" ";
		n = n->fore;
	}
	cout<<endl;
}

void displayCDLLRearToHead()
{
	node* n = cdll->rear;
	cout<<"Rear to Head : ";
	if(n != NULL)
	{
		cout<<n->data<<" ";
		n = n->back;
	}
	while(n != cdll->head)
	{
		cout<<n->data<<" ";
		n = n->back;
	}
	cout<<n->data<<" ";
	cout<<endl;
}

void destroyCDLL()
{
	node* t = cdll->head;
	node* t1 = NULL;
	if(cdll->count != 0)
	{
		t1 = t;
		t = t->fore;
		delete t1;
	}
	while(t != cdll->head)
	{
		t1 = t;
		t = t->fore;
		delete t1;
	}
	cdll->count = 0;
	cdll->head = cdll->rear = NULL;
}

int main()
{
	int ch,key,y;
	createCDLL();
	bool x;
	ch = 1;
	node *pPre,*pLoc;
	do{
		cout<<endl<<"1.Insert 2.Delete 3.SearchFromHead  4.SearchFromRear 5.EmptyList 6.CountCDLL 7.DisplayFromHead 8.DisplayFromRear 9.DestroyCDLList 0.Exit"<<endl;
		cout<<endl<<"Enter your choice : ";cin>>ch;
		switch(ch)
		{
			case 0:
				cout<<endl<<"Good Bye..  :)"<<endl;
				break;
			case 1:
				pPre = NULL;
				pLoc = NULL;
				cout<<endl<<"Enter element to insert : ";cin>>key;
				x = searchList(pPre,pLoc,key);
				if(!x)
				{
					insertCDLL(key,pPre,pLoc);
				}
				else
				{
					cout<<endl<<"Element already exist in the DLL..."<<endl;
				}
				break;
			case 2:
				pPre = NULL;
				pLoc = NULL;
				cout<<endl<<"Enter element to delete : ";cin>>key;
				x = searchList(pPre,pLoc,key);
				if(x)
				{
					deleteCDLL(key,pPre,pLoc);
				}
				else
				{
					cout<<endl<<"Element not found in the DLL..."<<endl;
				}
				break;
			case 3:
				cout<<endl<<"Enter element to search from head : ";cin>>key;
				y = searchCDLLFromHead(key);
				if(y != -1)
				{
					cout<<endl<<"Element found at position "<<y<<" from the head.."<<endl;
				}
				else
				{
					cout<<endl<<"Element not found..."<<endl;
				}
				break;
			case 4:
				cout<<endl<<"Enter element to search from rear : ";cin>>key;
				y = searchCDLLFromRear(key);
				if(y != -1)
				{
					cout<<endl<<"Element found at position "<<y<<" from the rear.."<<endl;
				}
				else
				{
					cout<<endl<<"Element not found..."<<endl;
				}
				break;
			case 5:
				if(emptyCDLL())
				{
					cout<<endl<<"List is empty..."<<endl;
				}
				else
				{
					cout<<endl<<"List isn't empty..."<<endl;
				}
				break;
			case 6:
				cout<<endl<<"Number of elements in list : "<<countCDLL()<<endl;
				break;
			case 7:
				displayCDLLHeadToRear();
				break;
			case 8:
				displayCDLLRearToHead();
				break;
			case 9:
				destroyCDLL();
				break;
			default:
				cout<<endl<<"Invalid Choice : "<<endl;
		}
	}while(ch != 0);
	return 0;
}
