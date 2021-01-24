#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
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

// 1-indexed
template <typename T=int>
struct BIT {
    const int n;
    vector<T> v;
 
    BIT(int n): n(n), v(n+1,0) {}
 
    void add(int i, int x) {
        ++i;
        while (i <= n) {
            v[i] += x;
            i += i & -i;
        }
    }
    T sum(int i) {
        ++i;
        T ret = 0;
        while (i > 0) {
            ret += v[i];
            i -= i & -i;
        }
        return ret;
    }
    T sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
};

int main() {
  ll N, Q; cin >> N >> Q;
  vector<ll> c(N); REP(i, N) cin >> c[i];
  vector<ll> l(Q), r(Q); REP(i, Q) cin >> l[i] >> r[i];
  BIT<ll> bit(N + 1);
  vector<pair<pair<ll, ll>, ll>> p(Q);
  REP(i, Q) {
    --r[i]; --l[i];
    p[i] = make_pair(make_pair(r[i], l[i]), i);
  }
  sort(all(p));

  vector<ll> m(N + 1, -1);
  vector<ll> ans(Q);
  int k = 0;
  for(int i = 0; i < Q; ++i) {
    while(k <= p[i].first.first) {
      if(m[c[k]] != -1) {
        bit.add(m[c[k]], -1);
      }
      m[c[k]] = k;
      bit.add(k, 1);
      ++k;
    }
    ans[p[i].second] = bit.sum(p[i].first.second, p[i].first.first);
  }
  for(int i = 0; i < Q; ++i) cout << ans[i] << endl;
}