#include <bits/stdc++.h>
using namespace std;

bool checkCycleDfs(int node, int par, vector <int> g[], vector <bool> &vis) {
  vis[node] = 1;
  for(auto it : g[node]) {
    if(!vis[it]) {
      if(checkCycleDfs(it, node, g, vis)) return true;
    } else if(it != par) {
      return true;
    }
  }

  return false;
}

bool isCycle(int n, vector <int> g[]) {
  vector <bool> vis(n + 1, 0);
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      if(checkCycleDfs(i, -1, g, vis)) return true;
    }
  }

  return false;
}

int main() {
  // ONLINE JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int n, e;
  cin >> n >> e;
  vector <int> g[n + 1];
  for(int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  cout << isCycle(n, g);

  return 0;
}