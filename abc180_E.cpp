#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
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

template<typename T>
struct edge {
    int from, to; // クラスカル法に限って、fromもedgeに含めるといい
    T cost;
};

const int MAXN = 21;
const ll INF = pow(10, 17);
int N;
vector<vector<ll>> dist(MAXN, vector<ll>(MAXN));
/* メモ再帰 */
int dp[(1<<20) + 1][21]; // dpテーブルは余裕をもったサイズにする
ll rec(int bit, int v) {
    // すでに探索済みだったらリターン
    if (dp[bit][v] != -1) return dp[bit][v];

    // 初期値
    if (bit == (1<<v)) {
        return dp[bit][v] = 0;
    }

    // 答えを格納する変数
    ll res = INF;

    // bit の v を除いたもの
    int prev_bit = bit & ~(1<<v);

    // v の手前のノードとして u を全探索
    for (int u = 0; u < N; ++u) {
        if (!(prev_bit & (1<<u))) continue; // u が prev_bit になかったらダメ

        // 再帰的に探索
        if (res > rec(prev_bit, u) + dist[u][v]) {
            res = rec(prev_bit, u) + dist[u][v];
        }
    }

    return dp[bit][v] = res; // メモしながらリターン
}

int main() {
  cin >> N;
  vector<ll> X(N), Y(N), Z(N); REP(i, N) cin >> X[i] >> Y[i] >> Z[i];
  REP(i, N) {
    for(int k = i + 1; k < N; ++k) {
      dist[i][k] = abs(X[k] - X[i]) + abs(Y[k] - Y[i]) + max((ll)0, Z[k] - Z[i]);
      dist[k][i] = abs(X[i] - X[k]) + abs(Y[i] - Y[k]) + max((ll)0, Z[i] - Z[k]);
    }
  }
  for (int bit = 0; bit < (1<<N); ++bit) for (int v = 0; v < N; ++v) dp[bit][v] = -1;
   // 探索
  ll res = INF;
  for (int v = 0; v < N; ++v) {
    if (res > rec((1<<N)-1, v)) {
      res = rec((1<<N)-1, v);
    }
  }
  cout << res << endl;
}