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
  int N, M; cin >> N;
  vector<vector<int>> A(N, vector<int>(N));
  REP(i, N) {
    REP(k, N) {
      cin >> A[i][k];
    }
  }
  cin >> M;
  vector<int> X(M), Y(M);
  REP(i, M) {
    cin >> X[i] >> Y[i]; --X[i]; --Y[i];
  }

  // 走者の並び順
  vector<int> v(N); REP(i, N) v[i] = i;
  sort(all(v)); // 必ずソートすること
  int ans = 2e9;
  do {
    // その並びは不可能かどうか検索する
    bool f = false;
    for(int i = 0; i < v.size() - 1; ++i) {
      REP(k, M) {
        if((X[k] == v[i] && Y[k] == v[i + 1]) || (X[k] == v[i + 1] && Y[k] == v[i])) f = true;
      }
    }
    if(f) continue;

    // もしOKならゴールするまでの時間を計算する
    int res = 0;
    REP(i, N) {
      res += A[v[i]][i];
    }
    ans = min(ans, res);
  } while(next_permutation(all(v)));
  if(ans == 2e9) cout << -1 << endl;
  else cout << ans << endl;
}