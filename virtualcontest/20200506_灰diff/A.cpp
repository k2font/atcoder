#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N; cin >> N;
  vector<int> A(N); REP(i, N) cin >> A[i];
  vector<int> B(N); REP(i, N) cin >> B[i];
  vector<int> C(N - 1); REP(i, N - 1) cin >> C[i];

  int ans = 0;
  REP(i, N) {
    ans += B[A[i] - 1];
    if(i != N - 1 && A[i + 1] == A[i] + 1) ans += C[A[i] - 1];
  }

  cout << ans << endl;
}