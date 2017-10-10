#include <iostream>
#include "tictac.h"
#include "tictac.cpp"

using namespace std;

int main(){
  TicTac T;

	struct Graph *G = T.createGraph(10);

  char m1[3][3] = {{'*','*','*'},{'*','*','*'},{'*','*','*'}};
  T.addRoot(G,m1,0);

    for(int a=0;a<1;a++){
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          if(i==0&&j==0&&a!=0){
            T.addRoot(G,T.searchByValue(G,a),a);
          }
          else{
            T.fillMatrix(G,G->vertList[a].verticeslist->board,G->vertList[a].verticeslist->board,i,j,a);
          }
        }
      }
    }


	cout<<"Vertices I can access \n";
	for(int i = 0; i < 1; i++)
	{

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
