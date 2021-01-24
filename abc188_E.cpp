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

int N, M; 
vector<vector<ll>> tree;
vector<ll> A; 
vector<ll> p; // その地点に到達できる矢印の中で最小値
void dfs(ll i, ll q) {
  // cout << q << endl;
  if(p[i] != pow(10, 9) + 10) {
    if(q >= p[i]) return;
  }
  if(q != -(pow(10, 9) + 10) && q < p[i]) p[i] = q;
  REP(k, tree[i].size()) {
    if(q == -(pow(10, 9) + 10)) dfs(tree[i][k], A[i]);
    else dfs(tree[i][k], min(A[i], p[i]));
  }
}

int main() {
  cin >> N >> M;
  A.resize(N); REP(i, N) cin >> A[i];
  tree.resize(N);
  REP(i, M) {
    ll X, Y; cin >> X >> Y; --X; --Y;
    tree[X].push_back(Y);
  }
  // そこまでのノードでの最小値を保持しておく
  p.resize(N, pow(10, 9) + 10);
  REP(i, N) {
    dfs(i, -(pow(10, 9) + 10));
    // REP(k, N) {
    //   cout << k << " " << p[k] << endl;
    // }
    // cout << endl;
  }
  // (その地点の価格 - そこまでの最小値)の中で最も大きい値が答え
  ll ans = -(pow(10, 9) + 10);
  REP(i, N) {
    // cout << p[i] << endl;
    if(p[i] == pow(10, 9) + 10) continue;
    // cout << A[i] << " " << p[i] << endl;
    ans = max(ans, A[i] - p[i]);
  }
  cout << ans << endl;
}
