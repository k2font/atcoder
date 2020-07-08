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
  vector<ll> A(N), B(N); REP(i, N) cin >> A[i] >> B[i];
  ll tmp = 0;
  for(ll i = N - 1; i >= 0; --i) {
    A[i] += tmp;
    if(A[i] % B[i] == 0) {
      continue;
    } else {
      ll res = ((A[i]/B[i]) + 1) * B[i] - A[i];
      tmp += res;
    }
  }
  cout << tmp << endl;
}