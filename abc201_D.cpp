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

int H, W;
vector<vector<ll>> memo(2501, vector<ll>(2501, 0));
vector<vector<ll>> visited(2501, vector<ll>(2501, 0));
vector<vector<ll>> r;
ll dfs(ll x, ll y) {
  if(x == H - 1 && y == W - 1) return 0;
  if(visited[x][y] == 1) return memo[x][y];
  visited[x][y] = 1;
  ll res = -1000100100;
  if(x + 1 < H) res = max(res, r[x + 1][y] - dfs(x + 1, y));
  if(y + 1 < W) res = max(res, r[x][y + 1] - dfs(x, y + 1));
  return memo[x][y] = res;
}

int main() {
  cin >> H >> W;
  vector<string> A; A.resize(H); REP(i, H) cin >> A[i];
  r.resize(H, vector<ll>(W, 0));
  REP(i, H) {
    REP(k, W) {
      if(A[i][k] == '+') r[i][k] = 1;
      if(A[i][k] == '-') r[i][k] = -1;
    }
  }

  ll res = dfs(0, 0);
  if(res == 0) cout << "Draw" << endl;
  if(res > 0) cout << "Takahashi" << endl;
  if(res < 0) cout << "Aoki" << endl;
}