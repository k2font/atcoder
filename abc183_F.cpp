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
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> par;

  public:
    UnionFind() : _n(0) {}
    UnionFind(int n) : _n(n), par(n, -1) {}

    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
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
    
    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = root(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
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
      a = uf.leader(a); // aの祖先
      b = uf.leader(b); // bの祖先
      if(a != b) { // aとbが同じグループにいなければ...
        uf.merge(a, b); // 2つをマージする
        for(auto tmp: m[b]) m[a][tmp.first] += tmp.second;
      }
    } else if(q == 2) {
      cout << m[uf.leader(a)][b] << endl;
    }
  }
}