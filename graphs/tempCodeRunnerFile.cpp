#include <bits/stdc++.h>
using namespace std;

#define N 100005

vector <bool> vis;
vector <int> adj[N];

vector <int> bfs(int s) {
  queue <int> q;
  vector <int> x;
  q.push(s);
  vis[s] = 1;

  while(!q.empty()) {
    int f = q.front();
    q.pop();

    for(auto i : adj[f]) {
      if(!vis[i]) {
        vis[i] = 1;
        q.push(i);
        x.push_back(i);
      }
    }
  }

  return x;
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
      vector <int> x = bfs(i);
      for(auto i : x) {
        cout << i << ' ';
      }
      cout << '\n';
    }
  }

  return 0;
}