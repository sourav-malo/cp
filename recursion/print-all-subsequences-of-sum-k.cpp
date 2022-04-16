#include <bits/stdc++.h>
using namespace std;

void printAllSubsequencesOfSumK(int idx, int arr[], int n, int k, vector <int> &v, int sum) {
  if(idx == n) {
    if(k == sum) {
      for(auto it : v) cout << it << ' ';
      cout << endl;
    }
    return;
  }

  // pick
  v.push_back(arr[idx]);
  sum += arr[idx];
  printAllSubsequencesOfSumK(idx + 1, arr, n, k, v, sum);
  // not pick
  v.pop_back();
  sum -= arr[idx];
  printAllSubsequencesOfSumK(idx + 1, arr, n, k, v, sum);
}

int main() {
  // ONLINE JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  
  int n, k;
  cin >> n >> k;
  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];
  vector <int> v;
  printAllSubsequencesOfSumK(0, arr, n, k, v, 0);

  return 0;
}