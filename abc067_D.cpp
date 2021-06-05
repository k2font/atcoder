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

vector<vector<ll>> d;
vector<vector<ll>> tree;
void dfs(ll x, ll y, ll z, ll w) {
  d[w][x] = z;
  REP(i, tree[x].size()) {
    if(tree[x][i] == y) continue;
    dfs(tree[x][i], x, z + 1, w);
  }
}

int main() {
  int N; cin >> N;
  int c1 = 0; int c2 = 0;
  vector<ll> a(N - 1), b(N - 1); REP(i, N - 1) cin >> a[i] >> b[i];
  tree.resize(N); d.resize(2, vector<ll>(1000010, 0));
  REP(i, N - 1) {
    --a[i]; --b[i];
    tree[a[i]].push_back(b[i]);
    tree[b[i]].push_back(a[i]);
  }
  dfs(0, -1, 0, 0);
  dfs(N - 1, -1, 0, 1);
  REP(i, N) {
    if(d[0][i] <= d[1][i]) {
      c1++;
    } else {
      c2++;
    }
  }

  if(c1 > c2) cout << "Fennec" << endl;
  else cout << "Snuke" << endl;
}