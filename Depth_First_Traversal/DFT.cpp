// Graph Traversal-DFS

#include <iostream>
using namespace std;
struct ga;
struct gv // Graph Vertex
{
  char data;
  bool instack, processed;
  ga *firstarc;
  gv *nextvertex;
};

struct ga // Graph Arc
{
  gv *content;
  ga *nextarc;
};

struct node // Node for stack
{
  gv *vertex;
  node *link;
};

class stack // Stack for DFT
{
private:
  node *top;

public:
  int count;
  stack() : count(0) { top = NULL; }
  void push(gv *v)
  {
    node *temp = new node;
    temp->vertex = v;
    temp->link = NULL;
    if (top == NULL)
      top = temp;
    else
    {
      temp->link = top;
      top = temp;
    }
    count++;
  }

  node *Topstack()
  {
    return top;
  }

  gv *pop()
  {
    node *temp = top;
    gv *v = temp->vertex;
    top = top->link;
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
  graph() : count(0) { first = NULL; }
  void insertvertex(char x)
  {
    gv *temp = new gv;
    temp->data = x;
    temp->instack = temp->processed = false;
    temp->firstarc = NULL;
    temp->nextvertex = NULL;
    // Insertion

    if (first == NULL)
      first = temp;
    else
    {
      gv *t = first;
      while (t->nextvertex != NULL)
        t = t->nextvertex;
      t->nextvertex = temp;
    }
    count++;
    cout << "Vertex inserted!!" << endl;
  }

  bool insertarc(char x, char y)
  {
    gv *xtemp = NULL, *ytemp = NULL;
    gv *xt = first, *yt = first;
    while (xt != NULL && xt->data != x)
      xt = xt->nextvertex;
    while (yt != NULL && yt->data != y)
      yt = yt->nextvertex;
    if (xt == NULL || yt == NULL) // Vertex not found
      return false;
    else
    {
      xtemp = xt;
      ytemp = yt;
    }
    // Insertion at x arc
    ga *xarc = new ga;
    xarc->content = ytemp;
    xarc->nextarc = NULL;
    if (xtemp->firstarc == NULL)
      xtemp->firstarc = xarc;
    else
    {
      ga *xa = xtemp->firstarc;
      while (xa->nextarc != NULL)
        xa = xa->nextarc;
      xa->nextarc = xarc;
    }

    // Insertion at y arc

    ga *yarc = new ga;
    yarc->content = xtemp;
    yarc->nextarc = NULL;

    if (ytemp->firstarc == NULL)
      ytemp->firstarc = yarc;
    else
    {
      ga *ya = ytemp->firstarc;
      while (ya->nextarc != NULL)
        ya = ya->nextarc;
      ya->nextarc = yarc;
    }
  };

  void dfs()
  {
    stack s;
    int visitedvertex = 0;
    gv *vertex = first;
    s.push(vertex);
    vertex->processed = true;
    vertex->instack = true;
    visitedvertex++;
    cout << vertex->data << "\t";
    while (count != visitedvertex)
    {
      ga *arc = s.Topstack()->vertex->firstarc;
      while (arc != NULL && arc->content->processed == true)
      {
        arc = arc->nextarc;
      }
      if (arc != NULL)
      {
        s.push(arc->content);
        arc->content->processed = true;
        arc->content->instack = true;
        visitedvertex++;
        cout << arc->content->data << "\t";
      }
      else
      {
        vertex = s.pop();
        vertex->instack = false;
        if (s.Topstack() == NULL)
        {
          vertex = first->nextvertex;
          while (vertex != NULL && vertex->processed == true)
            vertex = vertex->nextvertex;
          if (vertex != NULL)
          {
            s.push(vertex);
            vertex->processed = true;
            vertex->instack = true;
            visitedvertex++;
            cout << vertex->data << "\t";
          }
        }
      }
    }
    cout << "\n";
  }
};
int main()
{
  graph g;
  int ch;
  char x, y;
  do
  {
    cout << "\n1-Insert Vertex, 2-Insert Edge, 3-Depth first search,0-Exit\n";
    cout << "Enter choice: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
      cout << "Enter character to insert: ";
      cin >> x;
      g.insertvertex(x);
      break;
    
    case 2:
      cout << "Enter characters to add edge: ";
      cin >> x >> y;
      if (g.insertarc(x, y))
        cout << "Edge inserted between " << x << " and " << y << "." << endl;
      else
        cout << "Either one or both vertices not present in graph.\n";
      break;

    case 3:
      g.dfs();
      break;

    case 0:
      break;

    default:
      cout << "Invalid choice!";
    }

  } while (ch != 0);
}
