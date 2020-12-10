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
  ll H, W, N, M; cin >> H >> W >> N >> M;
  vector<ll> A(N), B(N), C(M), D(M);
  REP(i, N) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
  }
  REP(i, M) {
    cin >> C[i] >> D[i];
    C[i]--; D[i]--;
  }
  vector<vector<int>> r(H, vector<int>(W, 0)); // 0なら真っ黒
  REP(i, N) {
    r[A[i]][B[i]] = 2;
  }
  REP(i, M) {
    r[C[i]][D[i]] = -1;
  }
  // 横方向
  REP(i, H) {
    int p = 0; int q = 0; bool f = false;
    REP(k, W) {
      // 電球にたどり着いたら
      if(r[i][k] == 2) f = true;
      // 壁にたどり着いたら...
      if((r[i][k] == -1) || k == W - 1) {
        // cout << "aaa" << " " << f << endl;
        // 壁の位置を記録する
        if(k != W - 1) q = k - 1;
        else q = k;
        // cout << q << " " << f << endl;
        // 壁の次のマスから、壁の一個手前のマスまで塗る
        if(f) {
          for(int m = p; m <= q; ++m) {
            if(r[i][m] == 0) r[i][m] = 1;
          }
        }
        p = k + 1; f = false;
      }
    }
  }
  // 縦方向
  REP(i, W) {
    int p = 0; int q = 0; bool f = false;
    REP(k, H) {
      // 電球にたどり着いたら
      if(r[k][i] == 2) f = true;
      // 壁にたどり着いたら...
      if((r[k][i] == -1) || k == H - 1) {
        // 壁の位置を記録する
        if(k != H - 1) q = k - 1;
        else q = k;
        // 壁の次のマスから、壁の一個手前のマスまで塗る
        if(f) {
          for(int m = p; m <= q; ++m) {
            if(r[m][i] == 0) r[m][i] = 1;
          }
        }
        p = k + 1; f = false;
      }
    }
  }
  ll ans = 0;
  REP(i, H) {
    REP(k, W) {
      if(r[i][k] == -1) continue;
      if(r[i][k] == 1 || r[i][k] == 2) ans++;
    }
  }
  cout << ans << endl;
}