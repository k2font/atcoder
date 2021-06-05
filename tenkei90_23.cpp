#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1}; 
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
  int H, W; cin >> H >> W; int N = H * W;
  vector<string> C(H); REP(i, H) cin >> C[i];
  int ans = 0;
  for(int bit = 0; bit < (1 << N); ++bit) {
    int sum = 0;
    vector<vector<int>> tmp(H, vector<int>(W, 0));
    for(int i = 0; i < N; ++i) {
      if(bit & (1 << i)) {
        // すべての場合においてx座標とy座標の特定
        int cnt = 0;
        REP(k, H) {
          REP(m, W) {
            if(cnt == i) {
              tmp[k][m] = 1;
            }
            cnt++;
          }
        }
      }
    }

    // フラグが立ったマスの周辺8マスにフラグがあるかを確認する
    bool f = false;
    REP(i, H) {
      REP(k, W) {
        if(tmp[i][k] == 0) continue;
        if(C[i][k] == '#') f = true;
        for(int m = 0; m < 8; ++m) {
          int x = i + dx[m]; int y = k + dy[m];
          if(x < 0 || x >= H) continue;
          if(y < 0 || y >= W) continue;
          if(C[x][y] == '#') continue;
          if(tmp[x][y] == 1) f = true;
        }
      }
    }

    // なければans++
    if(f == false) ans++;
    // あればcontinue
  }
  cout << ans << endl;
}