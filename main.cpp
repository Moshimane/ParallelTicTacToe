#include <iostream>
#include "tictac.h"
#include "tictac.cpp"
#include <vector>

using namespace std;

void Player(TicTac T,Graph* G,char game[3][3]){
  cout<<"Game state is: "<<endl;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cout <<game[i][j] <<" ";
    }
    cout<<endl;
  }
  int x,y;
  cin>>x>>y;
//  while(x<0&&x>2&&y<0&&y>2){
  cout<<"Invalid input, enter again :"<<endl;
    //  cin>>x>>y;
//  }
  /*while(game[x][y]=='X'&&game[x][y]=='O'){
    cout<<"Space Already Played, enter again :"<<endl;
    cin>>x>>y;
  }*/
  game[x][y] = 'O';
  T.BFS(G,game);
}

int main(){
  cout <<"Joy\n";
  TicTac T;
  //vector<Node> v;

  char m1[3][3] = {{'*','*','*'},{'*','*','*'},{'*','*','*'}};

  struct Graph *G = T.createGraph(10);
  T.addRoot(G,m1/*topofstack*/,0,'X');
  T.fillMatrix(G,G->vertList[0].verticeslist->board,0);
    //Node* curr;
  //T.currentBestMove(G);
  /*while(G->vertList[0].verticeslist!=NULL){
    curr = G->vertList[0].verticeslist;
    while(curr->next->next!=NULL){
      curr = curr->next;
    }
    Node* temp = curr;
    curr = curr->next;
    temp->next = curr->next;*/
  //  G->vertList[0].verticeslist=NULL;

  cout << G->vertList[0].verticeslist->board[0][0]<<endl;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      m1[i][j] = G->vertList[0].verticeslist->next->board[i][j];
    }
  }
  G->vertList[0].verticeslist=NULL;
  G = T.createGraph(9);
  T.addRoot(G,m1/*topofstack*/,0,'X');
  T.fillMatrix(G,G->vertList[0].verticeslist->board,0);
  /*int r=0;
  for(int i=0;i<362881;){
    if(i==0){
      T.fillMatrix(G,G->vertList[i].verticeslist->board,i);
      i++;
    }
    else{
      Node* curr = G->vertList[r].verticeslist;

      if(curr->next!=NULL){
        curr = curr->next;
      }
      while(curr!=NULL){
        if(G->vertList[r].verticeslist->player=='X'){
          T.addRoot(G,curr->board,i,'O');
        }
        else{
            T.addRoot(G,curr->board,i,'X');
        }
        T.fillMatrix(G,curr->board,i);
        i++;
        curr = curr->next;
      }
      r++;
    }
  }

  Player(T,G,G->vertList[0].verticeslist->next->board);
*/

	cout<<"Vertices I can access \n";
	//for(int i = 0; i < 2; i++)
	{
    int i=0;
		while(G->vertList[i].verticeslist != NULL)
		{
      for(int j=0;j<3;j++){
        for(int z=0;z<3;z++){
          cout<<G->vertList[i].verticeslist->board[j][z]<<" ";
        }
        cout << endl;
      }
      G->vertList[i].verticeslist = G->vertList[i].verticeslist->next;
			cout <<"Next One"<<endl;
		}
	}
}
