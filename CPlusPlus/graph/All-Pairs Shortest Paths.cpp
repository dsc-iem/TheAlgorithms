#include<iostream>
#include<iomanip>
#define NODE 7
#define INF 999
using namespace std;
//Cost matrix of the graph
/**
 * 0 3 6 ∞ ∞ ∞ ∞
 * 3 0 2 1 ∞ ∞ ∞
 * 6 2 0 1 4 2 ∞
 * ∞ 1 1 0 2 ∞ 4
 * ∞ ∞ 4 2 0 2 1
 * ∞ ∞ 2 ∞ 2 0 1
 * ∞ ∞ ∞ 4 1 1 0
**/
int costMat[NODE][NODE] = {
   {0, 3, 6, INF, INF, INF, INF},
   {3, 0, 2, 1, INF, INF, INF},
   {6, 2, 0, 1, 4, 2, INF},
   {INF, 1, 1, 0, 2, INF, 4},
   {INF, INF, 4, 2, 0, 2, 1},
   {INF, INF, 2, INF, 2, 0, 1},
   {INF, INF, INF, 4, 1, 1, 0}
};
void floydWarshal(){
   int cost[NODE][NODE]; //defind to store shortest distance from any node to any node
   for(int i = 0; i<NODE; i++)
      for(int j = 0; j<NODE; j++)
         cost[i][j] = costMat[i][j]; //copy costMatrix to new matrix
         for(int k = 0; k<NODE; k++){
            for(int i = 0; i<NODE; i++)
               for(int j = 0; j<NODE; j++)
                  if(cost[i][k]+cost[k][j] < cost[i][j])
                     cost[i][j] = cost[i][k]+cost[k][j];
   }
   cout << "The matrix:" << endl;
   for(int i = 0; i<NODE; i++){
      for(int j = 0; j<NODE; j++)
         cout << setw(3) << cost[i][j];
      cout << endl;
   }
}
int main(){
   floydWarshal();
}

