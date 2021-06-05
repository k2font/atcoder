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

vector<vector<ll>> tree;
vector<ll> tmp;
void dfs(ll n, ll parent) {
  for(int i = 0; i < tree[n].size(); ++i) {
    if(parent == tree[n][i]) continue;
    tmp[tree[n][i]] += tmp[n]; dfs(tree[n][i], n);
  }
}

int main() {
  ll N, Q; cin >> N >> Q;
  tree.resize(N);
  REP(i, N - 1) {
    ll a, b; cin >> a >> b; --a; --b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  tmp.resize(N, 0);
  REP(i, Q) {
    ll p, x; cin >> p >> x;
    p--;
    tmp[p] += x;
  }
  dfs(0, -1);
  REP(i, N) {
    cout << tmp[i] << endl;
  }
}