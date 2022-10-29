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
};

list* create(list* dll)
{
	dll = new list();
	dll->count = 0;
	dll->head = NULL;
	dll->rear = NULL;
	return dll;
	cout<<"Created..."<<endl;
}

bool searchList(list* dll,node* &pPre,node* &pLoc/*,node* &pSuc*/,int target)
{
	pLoc = dll->head;
	//pSuc = dll->head;
	while(pLoc != NULL && target > pLoc->data)
	{
		pPre = pLoc;
		pLoc = pLoc->fore;
		//pSuc = pLoc->fore;
	}
	if(pLoc != NULL && target == pLoc->data)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void insertDLL(list* dll,int dataIn,node* &pPre/*,node* &pSuc*/)
{
	node* n = new node();
	n->data = dataIn;
	node* pSuc;
	if(pPre == NULL)
	{
		n->back = NULL;
		n->fore = dll->head;
		dll->head = n;
		if(dll->rear == NULL)
		{
			dll->rear = n;
		}
	}
	else
	{
		pSuc = pPre->fore;
		n->fore = pSuc;
		n->back = pPre;
		pPre->fore = n;
		pSuc = n->fore;
	}
	if(pSuc == NULL)
	{
		dll->rear = n;
	}
	else
	{
		pSuc->back = n;
	}
	dll->count ++;
}

void deleteDLL(list* dll,node* &pPre,node* &pLoc,node* &pSuc)
{
	if(pLoc == NULL)
	{
		return;
	}
	if(pLoc->fore != NULL)
	{
		pSuc = pLoc->fore;
	}
	if(pLoc->back != NULL)
	{
		pPre = pLoc->back;
		pPre->fore = pLoc->fore;
	}
	else
	{
		dll->head = pLoc->fore;
	}
	if(pSuc != NULL)
	{
		pSuc->back = pPre/*Loc->fore*/;
	}
	else
	{
		dll->rear = pLoc->back;
	}
	delete pLoc;
	dll->count--;
}

bool emptyDLL(list* dll)
{
	if(dll->count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int countDLL(list* dll)
{
	return dll->count;
}

void displayHeadToRear(list* dll)
{
	node* walker = new node();
	walker = dll->head;
	cout<<endl<<"Head to Rear : ";
	while(walker != NULL)
	{
		cout<<walker->data<<" ";
		walker = walker->fore;
	}
	cout<<endl;
}

void displayRearToHead(list* dll)
{
	node* walker = new node();
	walker = dll->rear;
	cout<<endl<<"Rear to Head : ";
	while(walker != NULL)
	{
		cout<<walker->data<<" ";
		walker = walker->back;
	}
	cout<<endl;
}

void destroyDLL(list* &dll)
{
	while(!dll->head)
	{
		dll->head = dll->head->fore;
	}
	dll->head = NULL;
	dll->rear = NULL;
	dll->count = 0;
}

int searchDLLFromHead(list* dll,int target)
{
	node* pLoc = dll->head;
	int pos = 1;
	while(pLoc != NULL && target > pLoc->data)
	{
		pos += 1;
		pLoc = pLoc->fore;
	}
	if(!pLoc)
	{
		return -1;
	}
	else
	{
		if(target == pLoc->data)
		{
			return pos;
		}
		else
		{
			return -1;
		}
	}
}

int searchDLLFromRear(list* dll,int target)
{
	node* pLoc = dll->rear;
	int pos = 1;
	while(pLoc != NULL && target < pLoc->data)
	{
		pos += 1;
		pLoc = pLoc->back;
	}
	if(!pLoc)
	{
		return -1;
	}
	else
	{
		if(target == pLoc->data)
		{
			return pos;
		}
		else
		{
			return -1;
		}
	}
}

int main()
{
	int ch,key,y;
	list* dll;
	dll = create(dll);
	bool x;
	ch = 1;
	node *pPre,*pLoc,*pSuc;
	do{
		cout<<endl<<"1.Insert 2.Delete 3.SearchFromHead  4.SearchFromRear 5.EmptyList 6.CountDLL 7.DisplayFromHead 8.DisplayFromRear 9.DestroyList 0.Exit"<<endl;
		cout<<endl<<"Enter your choice : ";cin>>ch;
		switch(ch)
		{
			case 0:
				cout<<endl<<"Good Bye..  :)"<<endl;
				break;
			case 1:
				pPre = NULL;
				pLoc = NULL;
				pSuc = NULL;
				cout<<endl<<"Enter element to insert : ";cin>>key;
				x = searchList(dll,pPre,pLoc,/*pSuc,*/key);
				cout<<endl<<"Search : "<<x<<endl;
				//cout<<endl<<pPre<<" "<<pLoc<<" "<<pSuc<<endl;
				if(!x)
				{
					insertDLL(dll,key,pPre/*,pSuc*/);
				}
				else
				{
					cout<<endl<<"Element already exist in the DLL..."<<endl;
				}
				break;
			case 2:
				pPre = NULL;
				pLoc = NULL;
				pSuc = NULL;
				cout<<endl<<"Enter element to delete : ";cin>>key;
				x = searchList(dll,pPre,pLoc/*,pSuc*/,key);
				if(x)
				{
					deleteDLL(dll,pPre,pLoc,pSuc);
				}
				else
				{
					cout<<endl<<"Element not found in the DLL..."<<endl;
				}
				break;
			case 3:
				cout<<endl<<"Enter element to search from head : ";cin>>key;
				y = searchDLLFromHead(dll,key);
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
				y = searchDLLFromRear(dll,key);
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
				if(emptyDLL(dll))
				{
					cout<<endl<<"List is empty..."<<endl;
				}
				else
				{
					cout<<endl<<"List isn't empty..."<<endl;
				}
				break;
			case 6:
				cout<<endl<<"Number of elements in list : "<<countDLL(dll)<<endl;
				break;
			case 7:
				displayHeadToRear(dll);
				break;
			case 8:
				displayRearToHead(dll);
				break;
			case 9:
				destroyDLL(dll);
				break;
			default:
				cout<<endl<<"Invalid Choice : "<<endl;
		}
	}while(ch != 0);
	return 0;
}
