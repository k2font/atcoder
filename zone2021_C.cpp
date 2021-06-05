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
  int N; cin >> N;
  vector<ll> A(N), B(N), C(N), D(N), E(N); REP(i, N) cin >> A[i] >> B[i] >> C[i] >> D[i] >> E[i];
  // パラメータの合計は考えなくていい
  ll a = 0; ll a_max = 0;
  REP(i, N) {
    if(a_max < A[i]) {
      a_max = A[i]; a = i;
    }
  }
  ll b = 0; ll b_max = 0;
  REP(i, N) {
    if(b_max < B[i]) {
      b_max = B[i]; b = i;
    }
  }
  ll c = 0; ll c_max = 0;
  REP(i, N) {
    if(c_max < C[i]) {
      c_max = C[i]; c = i;
    }
  }
  ll d = 0; ll d_max = 0;
  REP(i, N) {
    if(d_max < D[i]) {
      d_max = D[i]; d = i;
    }
  }
  ll e = 0; ll e_max = 0;
  REP(i, N) {
    if(e_max < E[i]) {
      e_max = E[i]; e = i;
    }
  }

  map<ll, ll> m; 
  m[a]++; m[b]++; m[c]++; m[d]++; m[e]++;
  if(m.size() == 1) { // 1のとき
    ll ans = min(E[a], min(D[a], min(C[a], min(A[a], B[a]))));
    cout << ans << endl;
  } else if(m.size() == 2) { // 2のとき
    ll a1 = 0; ll b1 = 0; ll c1 = 0; ll d1 = 0; ll e1 = 0;
    for(auto x : m) {
      a1 = max(a1, A[x.first]);
      b1 = max(b1, B[x.first]);
      c1 = max(c1, C[x.first]);
      d1 = max(d1, D[x.first]);
      e1 = max(e1, E[x.first]);
    }
    ll ans = min(e1, min(d1, min(c1, min(a1, b1))));
    cout << ans << endl;
  } else { // 3以上のとき
    ll ans = 0;
    for(int bit = 0; bit < (1 << m.size()); ++bit) {
      if(__builtin_popcount(bit) != 3) continue;
      vector<int> n(m.size(), 0);
      // 1が3つ立っているか判定
      for(int i = 0; i < m.size(); ++i) {
        if(bit & (1 << i)) n[i]++;
      }
      // もし3つなら、その3つで判定
      ll a1 = 0; ll b1 = 0; ll c1 = 0; ll d1 = 0; ll e1 = 0; int cc = 0;
      // REP(i, m.size()) {
      //    cout << n[i] << endl;
      // }
      // cout << "=====" << endl;
      for(auto x : m) {
        // cout << x.first << endl;
        if(n[cc] >= 1) {
          // cout << x.first << endl;
          a1 = max(a1, A[x.first]);
          b1 = max(b1, B[x.first]);
          c1 = max(c1, C[x.first]);
          d1 = max(d1, D[x.first]);
          e1 = max(e1, E[x.first]);
          // cout << cc << " " << a1 << " " << b1 << " " << c1 << " " << d1 << " " << e1 << " " << m.size() << endl;
        }
        cc++;
      }
      ll res = min(e1, min(d1, min(c1, min(a1, b1))));
      ans = max(ans, res);
      // cout << ans << " " << a1 << endl;
      // cout << "==" << endl;
      n.clear();
    }
    cout << ans << endl;
  }
}