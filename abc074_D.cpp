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

const int INF = pow(10, 9) + 7;

int main() {
  int N; cin >> N;
  vector<vector<ll>> A(N, vector<ll>(N));
  REP(i, N) {
    REP(k, N) {
      cin >> A[i][k];
    }
  }
  // -1かどうかの判定
  // ワーシャルフロイドした結果、与えられた行列と結果が変化すれば矛盾があるということ
  vector<vector<ll>> d(N, vector<ll>(N)); // 隣接リストではなく隣接行列を作成することに注意
  d = A;
  // ワーシャルフロイド法
  for (int k = 0; k < N; k++){       // 経由する頂点
    for (int i = 0; i < N; i++) {    // 始点
      for (int j = 0; j < N; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  REP(i, N) {
    REP(k, N) {
      if(d[i][k] != A[i][k]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  // 最短距離を求めるパート
  vector<vector<bool>> d_n(N, vector<bool>(N, false)); // trueなら辺を採用しない
  REP(i, N) {
    REP(k, N) {
      REP(m, N) {
        if(A[i][k] + A[i][m] == A[k][m] && d[i][k] != 0 && d[i][m] != 0) d_n[k][m] = true;
      }
    }
  }
  ll ans = 0;
  REP(i, N) {
    for(int k = i + 1; k < N; ++k) {
      if(d_n[i][k] == false) {
        ans += A[i][k];
      }
    }
  }
  cout << ans << endl;
}