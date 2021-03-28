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

int main() {
  int N, M, Q; cin >> N >> M >> Q;
  vector<ll> W(N), V(N); REP(i, N) cin >> W[i] >> V[i];
  vector<ll> X(M); REP(i, M) cin >> X[i];
  map<ll, vector<ll>> m;
  REP(i, N) {
    m[W[i]].push_back(V[i]);
  }
  for(auto x : m) {
    auto n = x.second;
    sort(all(n));
  }
  REP(i, Q) {
    ll ans = 0; auto copy = m;
    ll L, R; cin >> L >> R; L--; R--;
    // 愚直にできないか？
    vector<ll> p;
    REP(k, M) {
      if(L <= k && k <= R) continue;
      p.push_back(X[k]);
    }
    sort(all(p));
    REP(k, p.size()) {
      ll max_n = 0; ll idx = -1;
      for(auto x : copy) {
        if(p[k] >= x.first) {
          auto e = x.second;
          if(e.size() != 0) {
            if(max_n < e[e.size() - 1]) {
              max_n = e[e.size() - 1]; idx = x.first;
            }
          }
        }
      }
      if(max_n != 0) {
        ans += max_n;
        copy[idx].pop_back();
      }
    }
    cout << ans << endl;
    p.clear();
  }
}