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
  vector<ll> A(N);
  REP(i, N) {
    ll a, b;
    cin >> a >> b;
    A[a] = b;
  }
  int ans = N;

  vector<vector<ll>> tmp(N, vector<ll>(2));
  REP(i, N) {
    REP(k, 2) {
      tmp[i][k] = 0;
    }
  }

  for(auto m : A) {
    if() {

    }
  }

  REP(i, N) {
    if(X[i - 1] + L[i - 1] > X[i] - L[i] && i != 0) tmp[i][0] = 1;
    if(X[i + 1] - L[i + 1] < X[i] + L[i] && i != N - 1) tmp[i][1] = 1;
    // cout << tmp[i][0] << " " << tmp[i][1] << endl;
  }

  REP(i, N) {
    if(tmp[i][0] == 1 && tmp[i][1] == 1) ans--;
  }

  REP(i, N - 1) {
    if(tmp[i][0] == 0 && tmp[i][1] == 1 && (tmp[i + 1][0] == 1 && tmp[i + 1][1] == 0)) ans--;
  }

  cout << ans << endl;
}