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
  int H, W; cin >> H >> W;
  vector<string> S(H); REP(i, H) cin >> S[i];
  vector<vector<ll>> L(H, vector<ll>(W, 0));
  vector<vector<ll>> R(H, vector<ll>(W, 0));
  vector<vector<ll>> U(H, vector<ll>(W, 0));
  vector<vector<ll>> D(H, vector<ll>(W, 0));

  // L
  REP(i, H) {
    REP(k, W) {
      if(S[i][k] == '#') continue;
      if(k < 1) L[i][k] = 1;
      else L[i][k] = L[i][k - 1] + 1;
    }
  }

  // R
  REP(i, H) {
    for(int k = W - 1; k >= 0; --k) {
      if(S[i][k] == '#') continue;
      if(k >= W - 1) R[i][k] = 1;
      else R[i][k] = R[i][k + 1] + 1;
    }
  }

  // U
  REP(i, H) {
    REP(k, W) {
      if(S[i][k] == '#') continue;
      if(i < 1) U[i][k] = 1;
      else U[i][k] = U[i - 1][k] + 1;
    }
  }

  // D
  for(int i = H - 1; i >= 0; --i) {
    REP(k, W) {
      if(S[i][k] == '#') continue;
      if(i >= H - 1) D[i][k] = 1;
      else D[i][k] = D[i + 1][k] + 1;
    }
  }

  ll ans = 0;
  REP(i, H) {
    REP(k, W) {
      ans = max(ans, L[i][k] + R[i][k] + U[i][k] + D[i][k] - 3); // 自分のマスから始めているため、必ず重複分の3つを引く必要がある
    }
  }
  cout << ans << endl;
}