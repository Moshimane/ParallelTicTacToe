#include <iostream>
#include "tictac.h"
#include "tictac.cpp"

using namespace std;

int main(){
  TicTac T;

	struct Graph *G = T.createGraph(362881);

  char m1[3][3] = {{'*','*','*'},{'*','*','*'},{'*','*','*'}};
  T.addRoot(G,m1,0,'O');

  int r=0;
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


	cout<<"Vertices I can access \n";
	//for(int i = 0; i < 2; i++)
	{
    int i=5000;
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
