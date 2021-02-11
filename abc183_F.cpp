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

// UnionFindを示す構造体
// 2020/11/10: 連結成分の個数を出力するよう修正した
struct UnionFind {
  private:
    ll _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<ll> par, w;

  public:
    UnionFind() : _n(0) {}
    UnionFind(ll n) : _n(n), par(n, -1), w(n, 0) {}

    ll root(ll x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
    
    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }
    
    bool merge(ll x, ll y) {
        x = root(x); y = root(y);
        if (x == y) {
          ++w[x];
          return false;
        }
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        w[x] += w[y];
        ++w[x];
        return true;
    }
    
		// 頂点の数
    ll size(ll x) {
        return -par[root(x)];
    }

		// 辺の数
		int wei(int x) {
        return w[root(x)];
    }
    
    std::vector<std::vector<ll>> groups() {
        std::vector<ll> leader_buf(_n), group_size(_n);
        for (ll i = 0; i < _n; i++) {
            leader_buf[i] = root(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<ll>> result(_n);
        for (ll i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (ll i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<ll>& v) { return v.empty(); }),
            result.end());
        return result;
    }
};

int main() {
  int N, Q; cin >> N >> Q;
  vector<ll> C(N); REP(i, N) cin >> C[i];
  UnionFind uf(N);
  vector<map<int, int>> m(N);
  REP(i, N) {
    C[i]--;
    m[i][C[i]] = 1;
  }
  REP(i, Q) {
    int q, a, b; cin >> q >> a >> b;
    a--; b--;
    if(q == 1) {
      if(uf.issame(a, b)) continue;
      int A = uf.root(a); // aの祖先
      int B = uf.root(b); // bの祖先
      uf.merge(A, B);

      if(uf.root(B) == B) swap(A, B);

      for(auto x : m[B]) m[A][x.first] += x.second;
    } else if(q == 2) {
      if(m[uf.root(a)].count(b)) cout << m[uf.root(a)][b] << endl;
      else cout << 0 << endl;
    }
  }
}