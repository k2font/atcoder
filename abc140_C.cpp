#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}

int main() {
  int N; cin >> N;
  vector<int> B(N - 1); REP(i, N - 1) cin >> B[i];
  vector<int> A(N); REP(i, N) A[i] = 0;

  for(int i = N - 2; i >= 0; --i) {
    if(i == N - 2) {
      A[i + 1] = B[i];
      A[i] = B[i];
      continue;
    }

    if(B[i + 1] >= B[i]) {
      A[i + 1] = B[i];
      A[i] = B[i];
    } else {
      A[i] = B[i];
    }
  }
/*
  REP(i, N) {
    cout << A[i] << endl;
  } */

  ll a = accumulate(all(A), 0LL);
  cout << a << endl;
}