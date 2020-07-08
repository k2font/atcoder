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
  vector<ll> P(N); REP(i, N) cin >> P[i];

  int cnt = 1;
  ll min_num = pow(10, 8);
  REP(i, N - 1) {
    if(P[i] < min_num) min_num = P[i];
    if(P[i + 1] <= min_num) cnt++;
  }

  cout << cnt << endl;
}
