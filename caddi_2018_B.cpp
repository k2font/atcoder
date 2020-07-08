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
  ll H, W; cin >> H >> W;
  vector<ll> A(N), B(N); REP(i, N) cin >> A[i] >> B[i];
  int cnt = 0;

  REP(i, N) {
    if(H <= A[i] && W <= B[i]) cnt++;
  }

  cout << cnt << endl;
}