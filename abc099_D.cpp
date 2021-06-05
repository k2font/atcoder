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
template <class T> T up(T a, T div) { return (a + div - 1) / div; }

int main() {
  // O(N^2 * C)
  int N, C; cin >> N >> C;
  vector<vector<ll>> D(C, vector<ll>(C));
  REP(i, C) {
    REP(k, C) {
      cin >> D[i][k];
    }
  }
  vector<vector<ll>> c(N, vector<ll>(N));
  REP(i, N) {
    REP(k, N) {
      cin >> c[i][k]; c[i][k]--;
    }
  }

  vector<vector<ll>> pre(3, vector<ll>(30, 0));
  REP(col, C) {
    REP(i, N) {
      REP(k, N) {
        pre[(i + k) % 3][col] += D[c[i][k]][col];
      }
    }
  }
  // 色で全探索
  ll ans = 100100100100100;
  REP(c0, C) {
    REP(c1, C) {
      REP(c2, C) {
        // 色が同じではまずい
        if(c0 == c1) continue;
        if(c0 == c2) continue;
        if(c1 == c2) continue;

        // 指定した色を割り当てて、色を変更する
        chmin(ans, pre[0][c0] + pre[1][c1] + pre[2][c2]);
      }
    }
  }

  cout << ans << endl;
}