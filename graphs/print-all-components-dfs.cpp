#include <bits/stdc++.h>
using namespace std;

#define N 100005

int vis[N];
vector <int> adj[N];

void dfs(int s, vector <int> &comp) {
  vis[s] = 1;
  comp.push_back(s);
  for(auto i : adj[s]) {
    if(!vis[i]) {
      dfs(i, comp);
    }
  }  
}

int main() {
  // ONLINE JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int n, e;
  cin >> n >> e;
  for(int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      vector <int> comp;
      dfs(i, comp);
      for(auto j : comp) {
        cout << j << ' ';
      }
      cout << endl;
    }
  }

  return 0;
}