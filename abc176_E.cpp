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

int main() {
  int H, W; cin >> H >> W;
  int M; cin >> M;
  vector<int> h(M), w(M);
  REP(i, M) {
    cin >> h[i] >> w[i];
    h[i]--; w[i]--;
  }
  vector<ll> x(H, 0), y(W, 0);
  REP(i, M) {
    x[h[i]]++; y[w[i]]++;
  }
  ll ans = 0;
  ll max_x = *max_element(all(x));
  ll max_y = *max_element(all(y));
  vector<ll> p, q;
  REP(i, H) if(x[i] == max_x) p.push_back(i);
  REP(i, W) if(y[i] == max_y) q.push_back(i);
  ans = max_x + max_y;
  bool flag = false; ll cnt = 0;
  REP(i, M) {
    if(binary_search(all(p), h[i]) && binary_search(all(q), w[i])) {
      cnt++;
    }
  }
  if(p.size() * q.size() == cnt) cout << ans - 1 << endl;
  else cout << ans << endl;
}