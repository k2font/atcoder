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
  int N, M; cin >> N >> M; vector<int> L(M), R(M); REP(i, M) cin >> L[i] >> R[i];
  // vector<vector<int>> tree(N);
  // REP(i, M) {
  //   int L, R; cin >> L >> R; --L; --R;
  //   tree[L].push_back(R);
  //   tree[R].push_back(L);
  // }
  int ans = 0;
  REP(i, M) {
    REP(k, M) {
      if(L[i] == 1 && R[i] == N) {
        continue;
      } else if(L[i] == 1) {
        if(L[i] < L[k] && L[k] < R[i] && R[i] < R[k]) ans++;
        else if(L[i] < R[k] && R[k] < R[i] && R[i] < L[k]) ans++;
      } else if(R[i] == N) {
        if(L[i] < L[k] && L[k] < R[i] && R[k] < L[i]) ans++;
        else if(L[i] < R[k] && R[k] < R[i] && L[k] < L[i]) ans++;
      } else {
        if(L[i] < L[k] && L[k] < R[i] && (R[k] < L[i] || R[i] < R[k])) ans++;
        else if(L[i] < R[k] && R[k] < R[i] && (L[k] < L[i] || R[i] < L[k])) ans++;
      }
    }
  }
  cout << ans / 2 << endl;
}