#include <iostream>
#include <cstring>
using namespace std;

// Âèçíà÷àºìî íåñê³í÷åíí³ñòü ÿê äóæå âåëèêå ÷èñëî
#define INF 9999999

// Ê³ëüê³ñòü âåðøèí ó ãðàô³
#define V 8

// Ìàòðèöÿ ñóì³æíîñò³ äëÿ Âàð³àíòó
// 0 - â³äñòàíü äî ñåáå, INF - â³äñóòí³ñòü ðåáðà, ÷èñëà - âàãà ðåáðà
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
  int no_edge; // ë³÷èëüíèê ðåáåð

  // Ìàñèâ äëÿ â³äñòåæåííÿ îáðàíèõ âåðøèí
  // selected áóäå true, ÿêùî âåðøèíà âæå âêëþ÷åíà â ÌÊÄ
  bool selected[V];

  // Ñïî÷àòêó âñ³ false
  memset(selected, false, sizeof(selected));

  // Ïî÷èíàºìî ç 0 ðåáåð
  no_edge = 0;

  selected[0] = true;

  int x; // íîìåð ðÿäêà (âåðøèíà ç)
  int y; // íîìåð ñòîâïöÿ (âåðøèíà â)

  cout << "Edge" << " : " << "Weight";
  cout << endl;

  int total_weight = 0; // Çì³ííà äëÿ ï³äðàõóíêó çàãàëüíî¿ âàãè

  // Öèêë ïðàöþº, ïîêè ê³ëüê³ñòü ðåáåð ìåíøà çà V - 1
  while (no_edge < V - 1) {

    int min = INF;
    x = 0;
    y = 0;

    // Äëÿ êîæíî¿ âåðøèíè, ÿêà âæå â äåðåâ³ (selected[i] == true)
    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        // Øóêàºìî ñóñ³äíþ âåðøèíó, ÿêî¿ ùå íåìàº â äåðåâ³ (selected[j] == false)
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) { // ÿêùî âåðøèíà íå îáðàíà ³ º ðåáðî
            // ßêùî öå ðåáðî ìåíøå çà ïîòî÷íèé ì³í³ìóì
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

    total_weight += G[x][y]; // Äîäàºìî âàãó äî ñóìè
    selected[y] = true;      // Ïîçíà÷àºìî âåðøèíó ÿê äîäàíó
    no_edge++;
  }

  cout << endl << "Total Cost (Min Weight): " << total_weight << endl;

  return 0;
}
