#include <bits/stdc++.h>
using namespace std;

bool printOneSubsequenceOfSumK(int idx, int arr[], int n, int k, vector <int> &v, int sum) {
  if(idx == n) {
    if(k == sum) {
      for(auto it : v) cout << it << ' ';
      cout << endl;
      return true;
    }
    return false; 
  }

  // pick
  sum += arr[idx];
  v.push_back(arr[idx]);
  if(printOneSubsequenceOfSumK(idx + 1, arr, n, k, v, sum)) {
    return true;
  }
  // not pick
  sum -= arr[idx];
  v.pop_back();
  if(printOneSubsequenceOfSumK(idx + 1, arr, n, k, v, sum)) {
    return true;
  }

  return false;
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
  printOneSubsequenceOfSumK(0, arr, n, k, v, 0);

  return 0;
}