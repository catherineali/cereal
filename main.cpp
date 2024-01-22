#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
#define MAXN 100005

ifstream fin("cereal.in");
ofstream fout("cereal.out");

int n, m, cnt, f[MAXN], s[MAXN], used[MAXN], ans[MAXN];

int main() {
  fin >> n >> m;
  for (int i = 0; i < n; i++)
    fin >> f[i] >> s[i];
  for (int i = n - 1; i >= 0; i--) {
    int j = i, pos = f[i];
    while (1) {
      if (!used[pos]) {
        used[pos] = j, cnt++;
        break;
      } else if (used[pos] < j)
        break;
      else {
        int k = used[pos];
        used[pos] = j;
        if (pos == s[k])
          break;
        j = k, pos = s[k];
      }
    }
    ans[i] = cnt;
  }
  for (int i = 0; i < n; i++)
    fout << ans[i] << endl;
}