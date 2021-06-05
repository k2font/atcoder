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

ll N, Z, W; 
vector<ll> a; 

vector<vector<ll>> memo(2501, vector<ll>(2));

ll dfs(ll id, ll turn, ll x, ll y) {
  if(id == N) return abs(x - y);

  if(0 <= memo[id][turn]) return memo[id][turn];

  if(turn == 0) {
    ll res = -1;
    // Xさんの手番
    for(int i = id; i < N; ++i) {
      res = max(res, dfs(i + 1, 1 - turn, a[i], y));
    }
    return memo[id][turn] = res;
  } else {
    ll res = 1001001001001001;
    // Yさんの手番
    for(int i = id; i < N; ++i) {
      res = min(res, dfs(i + 1, 1 - turn, x, a[i]));
    }
    return memo[id][turn] = res;
  }
}

int main() {
  cin >> N >> Z >> W;
  a.resize(N); REP(i, N) cin >> a[i];
  REP(i, N) {
    REP(k, 2) {
      memo[i][k] = -1;
    }
  }
  cout << dfs(0, 0, Z, W) << endl; // id枚まで引いた時、turnさんの手番でXさんがx, Yさんがyのカードを持っている時のスコア
}