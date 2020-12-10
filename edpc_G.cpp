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

ll N, M;
vector<vector<ll>> tree;
vector<int> dp; vector<bool> res;
int f(int _x) { // xからスタートしたときの最長経路f(x)
  if(res[_x] == 1) return dp[_x];
  res[_x] = 1; int a = 0;
  for(int i = 0; i < tree[_x].size(); ++i) {
    a = max(a, f(tree[_x][i]) + 1);
  }
  // cout << a << endl;
  dp[_x] = a;
  return dp[_x];
}

int main() {
  cin >> N >> M;
  tree.resize(N); dp.resize(N); res.resize(N, 0);
  REP(i, M) {
    ll x, y; cin >> x >> y; --x; --y;
    tree[x].push_back(y);
  }
  int ans = 0;
  REP(i, N) f(i);
  REP(i, N) {
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}