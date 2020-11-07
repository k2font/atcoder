#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
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

struct UnionFind {
  vector<int> par;
  
  UnionFind(int n) : par(n, -1) { }

  int root(int x) {
      if (par[x] < 0) return x;
      else return par[x] = root(par[x]);
  }
  
  bool issame(int x, int y) {
      return root(x) == root(y);
  }
  
  bool merge(int x, int y) {
      x = root(x); y = root(y);
      if (x == y) return false;
      if (par[x] > par[y]) swap(x, y); // merge technique
      par[x] += par[y];
      par[y] = x;
      return true;
  }
  
  int size(int x) {
      return -par[root(x)];
  }
};

int main() {
  ll N, M; cin >> N >> M;
  vector<ll> A(M), B(M);
  REP(i, M) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
  }
  UnionFind uf(N);
  REP(i, M) {
    uf.merge(A[i], B[i]);
  }
  ll ans = 0;
  REP(i, N) {
    ll res = uf.size(i);
    if(ans < res) ans = res;
  }
  cout << ans << endl;
}