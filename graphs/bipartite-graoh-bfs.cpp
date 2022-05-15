#include <bits/stdc++.h>
using namespace std;

bool checkBipartiteBfs(int src, vector <int> g[], vector <int> &color) {
  queue <int> q;
  q.push(src);
  color[src] = 0;
  while(!q.empty()) {
    int par = q.front();
    q.pop();

    for(auto it : g[par]) {
      if(color[it] == -1) {
        color[it] = 1 - color[par];
        q.push(it);
      } else if(color[it] == color[par]) {
        return false;
      }
    }
  }

  return true;
}

bool isBipartite(vector <int> g[], int n) {
  vector <int> color(n + 1, -1);
  for(int i = 1; i <= n; i++) {
    if(color[i] != -1) continue;
    if(!checkBipartiteBfs(i, g, color)) return false;
  }

  return true;
}

int main() {
  // ONLINE JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int n, e;
  cin >> n >> e;
  vector <int> g[n + 1];
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  if(isBipartite(g, n)) {
    cout << "Yes";
  } else {
    cout << "No";
  }

  return 0;
}