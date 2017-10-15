#ifndef TICTAC_H
#define TICTAC_H

/******************
*Team #pragma(JLA)*
******************/

/************************************************************************
* We are going to use the undirectional graph structure since it's      *
* unneccesary to be using directions as our goal is more focused on just*
* exploration.                                                          *
************************************************************************/
struct Node{
  char board[3][3];
  char player;
  bool marked = false;
//  string outcome = "win";
  //int score =0;
  Node* next;
};

struct listVertices{
  struct Node* verticeslist;
};

struct Graph{
  int num;
  struct listVertices* vertList;
};

class TicTac{
  public:
    Graph* createGraph(int n);
    Node* createNode(char b[3][3]);
    void addRoot(Graph* G, char b[3][3],int x,char ch);
    void fillMatrix(Graph* G,char m[3][3],int level);
    void insertNode(Graph* G, char b1[3][3], char b2[3][3],int x,char ch);
    void MiniMaxAlgorithm(Graph* G,char b3[3][3]);
    void searchByValue(Graph* G,int a);
    //used to determine whether we are supposed to continue pruning the tree or not
    double winPossibility(char b4[3][3]);
    //used to search for all solutions that result in a win
    void DepthFirstSearch(Graph* G);
    void BFS(Graph* G,char m[3][3]);
  private:

};

#endif
