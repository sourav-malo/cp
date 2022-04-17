#include <bits/stdc++.h>
using namespace std;

int printSubsequencesCountOfSumK(int idx, int arr[], int n, int k, int sum) {
  if(idx == n) {
    return k == sum ? 1 : 0; 
  }

  // pick
  sum += arr[idx];
  int l = printSubsequencesCountOfSumK(idx + 1, arr, n, k, sum);
  // not pick
  sum -= arr[idx];
  int r = printSubsequencesCountOfSumK(idx + 1, arr, n, k, sum);

  return l + r;
}

int main() {
  // ONLINE JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  
  int n, k;
  cin >> n >> k;
  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];
  cout << printSubsequencesCountOfSumK(0, arr, n, k, 0);

  return 0;
}