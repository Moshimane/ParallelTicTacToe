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

//create nodes to be inserted into the graph
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


//Inserts nodes into the graph using the adjacency list analogy
void TicTac::insertNode(Graph* G, char b1[3][3], char b2[3][3],int x, char ch){
  Node* newNode1 = createNode(b1);
  Node* newNode2 = createNode(b2);
  newNode2->player = ch;
  Node* curr = G->vertList[x].verticeslist;

  //Insert node at the head
  if(G->vertList[x].verticeslist == NULL){
    G->vertList[x].verticeslist = newNode2;
  }
  else{
    //insert at the end of the list
      while(curr->next!=NULL){
        curr = curr->next;
      }
      curr->next = newNode2;
  }
}

//Add the head to new pointer
void  TicTac::addRoot(Graph* G, char b[3][3], int x,char ch){
  Node* newNode = createNode(b);
  newNode->player = ch;
  G->vertList[x].verticeslist = newNode;

}

//Fill the matrixes
void TicTac::fillMatrix(Graph* G,char m[3][3],int level){

  char matrix[3][3];
  char ch;
  if(G->vertList[level].verticeslist->player=='X'){
    ch = 'O';
  }else{
    ch = 'X';
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      matrix[i][j] = m[i][j];
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(matrix[i][j]!='X'&& matrix[i][j]!='O'){
        matrix[i][j] = G->vertList[level].verticeslist->player;
        insertNode(G,m,matrix,level,ch);
        matrix[i][j] = '*';
      }
    }
  }
}

void TicTac::BFS(Graph* G,char m[3][3]){

  //cout <<"I'm BFS"<<endl;
  Node* start = G->vertList[0].verticeslist;
  bool check = false;
  int c=0;
  int z=0;
  while(start!=NULL&&z==0){
    //cout <<"I'm still BFS"<<endl;
    for(int i=3;i<3;i++){
      for(int j=0;j<3;j++){
        if(m[i][j]!=start->board[i][j]){
          check = true;
          break;
        }
      }
      if(check==true){
        start = start->next;
        break;
      }
      else{
        if(i==2){
          z++;
          cout << "Found it"<<endl;
          for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
              cout <<start->board[i][j] <<" ";
            }
            cout<<endl;
          }
        }
      }
    }
    if(z==0&&start==NULL){
      c++;
      start = G->vertList[c].verticeslist;
    }
  }

}

/*void TicTac::DepthFirstSearch(Graph *G){
  Node* start = G->vertList[0].verticeslist;
  while()
}*/
