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

const long long INF = 1LL<<60;

int main() {
  int N, M, R; cin >> N >> M >> R;
  vector<ll> r(R); REP(i, R) cin >> r[i];
  vector<ll> A(M), B(M), C(M); REP(i, M) cin >> A[i] >> B[i] >> C[i];

  // ワーシャルフロイドで全頂点間の距離を求める
  vector<vector<ll>> d(N + 10, vector<ll>(N + 10)); // 隣接リストではなく隣接行列を作成することに注意

  REP(i, N) { // 初期化
    REP(k, N) {
      d[i][k] = INF; // めっちゃ長い距離ですべて初期化する。10^9+7でじゅうぶん。
    }
    d[i][i] = 0; // 自己ループはすべて0にする
  }

  // 行列の特定の辺の経路を1にする
  REP(i, M) {
    A[i]--; B[i]--;
    d[A[i]][B[i]] = C[i];
    d[B[i]][A[i]] = C[i];
  }

  // ワーシャルフロイド法
  for (int k = 0; k < N; k++){       // 経由する頂点
    for (int i = 0; i < N; i++) {    // 始点
      for (int j = 0; j < N; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  // REP(i, N) {
  //   REP(k, N) {
  //     cout << d[i][k] << " ";
  //   }
  //   cout << endl;
  // }

  // Rの並び順を順列全探索
  ll ans = INF;
  sort(all(r));
  do {
    ll tmp = 0;
    REP(i, r.size() - 1) {
      tmp += d[r[i] - 1][r[i + 1] - 1];
    }
    ans = min(ans, tmp);
  } while(next_permutation(all(r)));

  cout << ans << endl;
}