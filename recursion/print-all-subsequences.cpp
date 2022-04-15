#include <bits/stdc++.h>
using namespace std;

void printAllSubsequences(int idx, int arr[], int n, vector <int> &v) {
  if(idx >= n) {
    for(auto it: v) cout << it << ' ';
    cout << endl;
    return;
  }

  v.push_back(arr[idx]);
  printAllSubsequences(idx + 1, arr, n, v);
  v.pop_back();
  printAllSubsequences(idx + 1, arr, n, v);
}

int main() {
  // ONLINE JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];
  vector <int> v;
  printAllSubsequences(0, arr, n, v);
  return 0;
}