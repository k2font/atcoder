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

int H, W;
vector<vector<bool>> p; // 赤色で塗られているかどうか

int main() {
  cin >> H >> W;
  int Q; cin >> Q;
  p.resize(H, vector<bool>(W, false));
  UnionFind uf(H * W);
  REP(i, Q) {
    int t; cin >> t;
    if(t == 1) {
      int r, c; cin >> r >> c; r--; c--;
      p[r][c] = true;
      for(int i = 0 ; i < 4; ++i) {
        int X = r + dx[i]; int Y = c + dy[i];
        if(X < 0 || X >= H) continue;
        if(Y < 0 || Y >= W) continue;
        if(p[X][Y] == true) uf.merge(W * X + Y, W * r + c);
      }
    } else if(t == 2) {
      int ra, ca, rb, cb; cin >> ra >> ca >> rb >> cb;
      ra--; ca--; rb--; cb--;
      if(uf.issame(W * ra + ca, W * rb + cb) && p[ra][ca] == true && p[rb][cb] == true) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
}