#include <iostream>
using namespace std;
struct ga;

struct gv {
  char data;
  bool intree;
  ga *firstarc;
  gv *nextvertex;
};

struct ga {
  gv *destination;
  float weight;
  ga *nextarc;
};

class graph {
private:
  gv *first;
  int count;

public:
  graph() : count(0) { first = NULL; }

  void insertvertex(char x) {
    gv *temp = new gv;
    temp->data = x;
    temp->intree = false;
    temp->firstarc = NULL;
    temp->nextvertex = NULL;
    // Insertion
    if (first == NULL)
      first = temp;
    else {
      gv *t = first;
      while (t->nextvertex != NULL)
        t = t->nextvertex;
      t->nextvertex = temp;
    }
    count++;
    cout << "Vertex inserted!!" << endl;
  };
  bool insertarc(char x, char y, float wt) {
    gv *xtemp = NULL, *ytemp = NULL;
    gv *xt = first, *yt = first;
    while (xt != NULL && xt->data != x)
      xt = xt->nextvertex;
    while (yt != NULL && yt->data != y)
      yt = yt->nextvertex;
    if (xt == NULL || yt == NULL) // Vertex not found
      return false;
    else {
      xtemp = xt;
      ytemp = yt;
    }
    // Insertion at x arc
    ga *xarc = new ga;
    xarc->destination = ytemp;
    xarc->nextarc = NULL;
    xarc->weight = wt;
    if (xtemp->firstarc == NULL)
      xtemp->firstarc = xarc;
    else {
      ga *xa = xtemp->firstarc;
      while (xa->nextarc != NULL)
        xa = xa->nextarc;
      xa->nextarc = xarc;
    }
    // Insertion at y arc
    ga *yarc = new ga;
    yarc->destination = xtemp;
    yarc->weight = wt;
    yarc->nextarc = NULL;
    if (ytemp->firstarc == NULL)
      ytemp->firstarc = yarc;
    else {
      ga *ya = ytemp->firstarc;
      while (ya->nextarc != NULL)
        ya = ya->nextarc;
      ya->nextarc = yarc;
    }
  }; // bool insertarc(char x,char y,float wt)
  void MWSTPrims() {
    if (first == NULL)
      return;
    else {
      int minedge;
      gv *vertex = first;
      gv *source;
      ga *arc = NULL;
      ga *minedgeloc = NULL;
      vertex->intree = true;
      bool treecomplete = false;
      int sum = 0;
      while (!treecomplete) {
        treecomplete = true;
        vertex = first;
        minedge = 9999;
        minedgeloc = NULL;
        while (vertex != NULL) {
          if (vertex->intree) {
            arc = vertex->firstarc;
            while (arc != NULL) {
              if (!(arc->destination->intree)) {
                treecomplete = false;
                if (arc->weight < minedge) {
                  minedge = arc->weight;
                  minedgeloc = arc;
                  source = vertex;
                }
              }
              arc = arc->nextarc;
            }
          }
          vertex = vertex->nextvertex;
        }
        if (minedgeloc != NULL) {
          sum = sum + minedgeloc->weight;
          minedgeloc->destination->intree = true;
          cout << source->data << minedgeloc->destination->data
               << minedgeloc->weight << "\n";
        }
      }
      cout << "\nTotal wt:" << sum;
    }
  }
};

int main() {
  graph g;
  int ch;
  char x, y;
  float wt;
  do {
    cout << "\n1-Insert Vertex, 2-Insert Edge, 3-MWSTPrims,0-Exit\n";
    cout << "Enter choice: ";
    cin >> ch;
    switch (ch) {
    case 1:
      cout << "Enter character to insert: ";
      cin >> x;
      g.insertvertex(x);
      break;
    case 2:
      cout << "Enter characters to add edge: ";
      cin >> x >> y;
      cout << "Weight";
      cin >> wt;
      if (g.insertarc(x, y, wt))
        cout << "Edge inserted between " << x << " and " << y << "." << endl;
      else
        cout << "Either one or both vertices not present in graph.\n";
      break;
    case 3:
      g.MWSTPrims();
      break;
    case 0:
      break;
    default:
      cout << "Invalid choice!";
    }
  } while (ch != 0);
}
