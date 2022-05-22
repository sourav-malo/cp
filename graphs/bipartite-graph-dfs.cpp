#include <bits/stdc++.h>
using namespace std;

bool checkBipartiteDfs(int s, int par, vector <int> g[], vector <int> &colors) {
  colors[s] = 1 - colors[par];
  for(auto it : g[s]) {
    if(colors[it] == -1) {
      checkBipartiteDfs(it, s, g, colors);
    } else if(colors[it] == colors[s]) {
      return false;
    }
  } 

  return true;
}

bool isBipartite(int n, vector <int> g[]) {
  vector <int> colors(n + 1, -1);
  for(int i = 1; i <= n; i++) {
    if(colors[i] == -1) {
      if(!checkBipartiteDfs(i, 0, g, colors)) {
        return false;
      }
    }
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

  if(isBipartite(n, g)) {
    cout << "Yes";
  } else {
    cout << "No";
  }

  return 0;
}