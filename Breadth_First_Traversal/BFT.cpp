#include<iostream>
using namespace std;
struct ga;
struct gv //Graph Vertex
{
  char data;
  bool inqueue,processed;
  ga *firstarc;
  gv *nextvertex;
};

struct ga //Graph Arc
{
  gv *content;
  ga *nextarc;
};

struct node //Node for queue
{
  gv *vertex;
  node *link;
};

class queue
{
  private:
    node *front,*rear;
  public:
    int count;
    queue():count(0){front=rear=NULL;
  }
  
  void enqueue(gv *v)
  {
      node *temp=new node;
      temp->vertex=v;
      temp->link=NULL;
  if(front==NULL)
    front=rear=temp;
    else
    {
      rear->link=temp;
      rear=temp;
    }
    count++;
  }
    gv* dequeue()
    {
      node *temp=front;
      gv *v=temp->vertex;
      front=front->link;
      delete temp;
      count--;
      return v;
    }
};

class graph
{ 
private:
  gv *first;
  int count;

public:
  graph():count(0){first=NULL;}
  void insertvertex(char x)

    { 
      gv *temp=new gv;
      temp->data=x;  
      temp->inqueue=temp->processed=false;   
      temp->firstarc=NULL;    
      temp->nextvertex=NULL;
    
    //Insertion
    if(first==NULL)
    first=temp;
    else
    { 
      gv *t=first;
      while(t->nextvertex!=NULL)
        t=t->nextvertex;
        t->nextvertex=temp;
    }
    count++;
    cout<<"Vertex inserted!!"<<endl;
    }

  bool insertarc(char x,char y)
  {
      gv *xtemp=NULL,*ytemp=NULL;
      gv *xt=first,*yt=first;
      while(xt!=NULL&&xt->data!=x)
      xt=xt->nextvertex;
      while(yt!=NULL&&yt->data!=y)
      yt=yt->nextvertex;
      if(xt==NULL||yt==NULL) //Vertex not found
      return false;
  else
      {
        xtemp=xt;
        ytemp=yt;
      }
  //Insertion at x arc
    ga *xarc=new ga;
    xarc->content=ytemp;
    xarc->nextarc=NULL;
    if(xtemp->firstarc==NULL)
        xtemp->firstarc=xarc;
    else
    {
    ga *xa=xtemp->firstarc;
    while(xa->nextarc!=NULL)
      xa=xa->nextarc;
      xa->nextarc=xarc;
    }
  
  //Insertion at y arc
    ga *yarc=new ga;
    yarc->content=xtemp;
    yarc->nextarc=NULL;
    if(ytemp->firstarc==NULL)
      ytemp->firstarc=yarc;
  else
    {
      ga *ya=ytemp->firstarc;
      while(ya->nextarc!=NULL)
      ya=ya->nextarc;
      ya->nextarc=yarc;
    }
  }

  void bfs()
  {
    queue q;
    q.enqueue(first);
    cout<<"Breadth first traversal:-\n";
    while(q.count!=0)
    {
    gv *dequeued=q.dequeue();
    cout<<dequeued->data<<"\t";
    dequeued->inqueue=false;
    dequeued->processed=true;
    ga *arc=dequeued->firstarc;
      while(arc!=NULL)
      {
        if((arc->content->processed!=true)&&(arc->content->inqueue!=true))
        {    
          q.enqueue(arc->content);      
          arc->content->inqueue=true;
        }    
        arc=arc->nextarc;  
      }
    }
  cout<<endl;
  }
};

int main(){
graph g;
int ch;
char x,y;
do{
  cout<<"1-Insert Vertex, 2-Insert Edge, 3-Breadth first search,0-Exit\n";
  cout<<"Enter choice: ";
  cin>>ch;
  switch(ch)
    { 
      case 1:  
        cout<<"Enter character to insert: ";
        cin>>x;
        g.insertvertex(x);
        break;
    
    case 2:
        cout<<"Enter characters to add edge: ";
        cin>>x>>y;
        if(g.insertarc(x,y))
          cout<<"Edge inserted between "<<x<<" and "<<y<<"."<<endl;
        else
          cout<<"Either one or both vertices not present in graph.\n";
        break;
      
    case 3:
        g.bfs();
        break;
      
    case 0:
        break;
      
    default:
      cout<<"Invalid choice!";
    }
  }while(ch);
}
