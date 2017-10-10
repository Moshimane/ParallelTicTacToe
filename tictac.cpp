#include <iostream>
#include "tictac.h"

using namespace std;

/******************
*Team #pragma(JLA)*
******************/

Graph* TicTac::createGraph(int n){
  struct Graph* List = new Graph;
  List->num = n;

  //declare a list of n verticeslist
  List->vertList = new listVertices[n+1];

  //Assign head of all verticeslist to NULL
  for(int i=0;i<n+1;i++){
    List->vertList[i].verticeslist = NULL;
  }
  return List;
}

Node* TicTac::createNode(char b[3][3]){
  struct Node* newNode = new Node;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      newNode->board[i][j] = b[i][j];
    }
  }
  newNode->next = NULL;
  return newNode;
}

void TicTac::insertNode(Graph* G, char b1[3][3], char b2[3][3],int x){
  Node* newNode1 = createNode(b1);
  Node* newNode2 = createNode(b2);
  Node* curr = G->vertList[x].verticeslist;

  if(G->vertList[x].verticeslist == NULL){
    G->vertList[x].verticeslist = newNode2;
  }
  else{
      while(curr->next!=NULL){
        curr = curr->next;
      }
      curr->next = newNode2;
  }
}

void  TicTac::addRoot(Graph* G, char b[3][3], int x){
  Node* newNode = createNode(b);
  G->vertList[x].verticeslist = newNode;
}


void TicTac::fillMatrix(Graph* G,char m[3][3],char mat[3][3],int i,int j,int level){
  mat[i][j] = 'X';
  insertNode(G,m,mat,level);
  mat[i][j] = '*';
}

char** TicTac::searchByValue(Graph* G, int a){
  Node* node = G->vertList[a-1].verticeslist;
  int i=0;
  while(i!=a){
    node= node->next;
  }
  return node->board;
}
