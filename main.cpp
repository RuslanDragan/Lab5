#include <iostream>
#include <cstring>
using namespace std;

// Визначаємо нескінченність як дуже велике число
#define INF 9999999

// Кількість вершин у графі
#define V 8

// Матриця суміжності для Варіанту
// 0 - відстань до себе, INF - відсутність ребра, числа - вага ребра
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
  int no_edge; // лічильник ребер

  // Масив для відстеження обраних вершин
  // selected буде true, якщо вершина вже включена в МКД
  bool selected[V];

  // Спочатку всі false
  memset(selected, false, sizeof(selected));

  // Починаємо з 0 ребер
  no_edge = 0;

  selected[0] = true;

  int x; // номер рядка (вершина з)
  int y; // номер стовпця (вершина в)

  cout << "Edge" << " : " << "Weight";
  cout << endl;

  int total_weight = 0; // Змінна для підрахунку загальної ваги

  // Цикл працює, поки кількість ребер менша за V - 1
  while (no_edge < V - 1) {

    int min = INF;
    x = 0;
    y = 0;

    // Для кожної вершини, яка вже в дереві (selected[i] == true)
    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        // Шукаємо сусідню вершину, якої ще немає в дереві (selected[j] == false)
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) { // якщо вершина не обрана і є ребро
            // Якщо це ребро менше за поточний мінімум
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

    total_weight += G[x][y]; // Додаємо вагу до суми
    selected[y] = true;      // Позначаємо вершину як додану
    no_edge++;
  }

  cout << endl << "Total Cost (Min Weight): " << total_weight << endl;

  return 0;
}