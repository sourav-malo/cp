#include <bits/stdc++.h>
using namespace std;

bool hasCycleBfs(vector <int> g[], int s, vector <bool> &vis) {
  queue <pair <int, int>> q;
  q.push({ s, -1 });
  vis[s] = 1;

  while(!q.empty()) {
    int node = q.front().first;
    int par = q.front().second;
    q.pop();

    for(auto it : g[node]) {
      if(!vis[it]) {
        vis[it] = 1;
        q.push({ it, node });
      } else if(it != par) {
        return true;
      }
    }
  }

  return false;
}

bool isCycle(vector <int> g[], int n) {
  vector <bool> vis(n + 1, 0);
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      if(hasCycleBfs(g, i, vis)) return true;
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

  cout << isCycle(g, n);

  return 0;
}