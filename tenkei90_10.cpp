#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
char inverse_char(char c) {
  if(isupper(c)) return tolower(c);
  else return toupper(c);
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
struct edge {
  ll to, cost;
};

int main() {
  int N; cin >> N;
  vector<int> C(N), P(N); REP(i, N) cin >> C[i] >> P[i];
  int Q; cin >> Q;
  vector<int> L(Q), R(Q);
  REP(i, Q) {
    cin >> L[i] >> R[i];
  }
  vector<ll> rui1(N + 1, 0), rui2(N + 1, 0);
  REP(i, N) {
    if(C[i] == 1) {
      rui1[i + 1] = rui1[i] + P[i];
      rui2[i + 1] = rui2[i];
    } else {
      rui2[i + 1] = rui2[i] + P[i];
      rui1[i + 1] = rui1[i];
    }
  }
  REP(i, Q) {
    cout << rui1[R[i]] - rui1[L[i] - 1] << " " << rui2[R[i]] - rui2[L[i] - 1] << endl;
  }
}