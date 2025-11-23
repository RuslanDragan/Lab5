#include <iostream>
#include <cstring>
using namespace std;

#define INF 9999999

#define V 8


int G[V][V] = {
  // 1    2    3    4    5    6    7    8
  {0,   4,   1,   4, INF, INF, INF, INF}, // 1
  {4,   0, INF, INF,   7,   3, INF, INF}, // 2
  {1, INF,   0,   5, INF,   5, INF,   4}, // 3
  {4, INF,   5,   0,   1, INF, INF, INF}, // 4
  {INF, 7, INF,   1,   0, INF,   4, INF}, // 5
  {INF, 3,   5, INF, INF,   0,   6, INF}, // 6
  {INF,INF,INF, INF,   4,   6,   0,   5}, // 7
  {INF,INF,  4, INF, INF, INF,   5,   0}  // 8
};

int main() {
  int no_edge; 


  bool selected[V];


  memset(selected, false, sizeof(selected));


  no_edge = 0;

  selected[0] = true;

  int x; 
  int y; 

  cout << "Edge" << " : " << "Weight";
  cout << endl;

  int total_weight = 0; 


  while (no_edge < V - 1) {

    int min = INF;
    x = 0;
    y = 0;


    for (int i = 0; i < V; i++) {
      if (selected[i]) {

        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) { 

            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }

    cout << x + 1 << " - " << y + 1 << " : " << G[x][y];
    cout << endl;

    total_weight += G[x][y]; 
    selected[y] = true;     
    no_edge++;
  }

  cout << endl << "Total Cost (Min Weight): " << total_weight << endl;

  return 0;
}
