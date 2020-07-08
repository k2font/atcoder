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
  ll N; cin >> N;
  vector<ll> K(N); REP(i, N - 1) cin >> K[i];
  vector<ll> A(N); REP(i, N) A[i] = 0;

  A[0] = K[0];
  REP(i, N - 1) {
    if(K[i] < A[i]) A[i] = K[i];
    A[i + 1] = K[i];
  }

  REP(i, N) {
    cout << A[i] << " ";
  }
  cout << endl;
}