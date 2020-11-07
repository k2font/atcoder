#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<int, int>;
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
struct edge {
  ll to, cost;
};

int N, M;
vector<vector<ll>> d;
vector<ll> a, b, c;

void warshall_floyd(int n) {
  for (int k = 0; k < n; k++){       // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
      for (int j = 0; j < n; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

const ll INF = pow(10, 9) + 7;

int main() {
  cin >> N >> M;
  d.resize(N + 10, vector<ll>(N + 10)); a.resize(M); b.resize(M); c.resize(M);
  REP(i, N) { // 初期化
    REP(k, N) {
      d[i][k] = INF; // めっちゃ長い距離ですべて初期化する
    }
    d[i][i] = 0; // 自己ループはすべて0にする
  }
  REP(i, M) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
    d[a[i]][b[i]] = c[i]; d[b[i]][a[i]] = c[i];
  }
  warshall_floyd(N);
  int ans = 0;
  for(int i = 0; i < M; ++i) { // 存在する辺の本数。すべての辺に対して試行する。
    bool f = false;
    for(int p = 0; p < N; ++p) {
      for(int q = 0; q < N; ++q) { // ... というのを全部の頂点間で試して、もし1つでも条件を満たすものがあれば、この辺は使用される
        if(d[p][q] == d[p][a[i]] + c[i] + d[b[i]][q]) f = true;
      }
    }
    if(f == false) ans++;
  }
  cout << ans << endl;
}