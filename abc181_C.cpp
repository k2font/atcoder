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
  vector<P> z(N);
  REP(i, N) {
    ll x, y; cin >> x >> y;
    z[i] = P(x, y);
  }
  sort(all(z));
  string ans = "No";
  for(int i = 0; i < N; ++i) {
    for(int k = i + 1; k < N; ++k) {
      for(int m = k + 1; m < N; ++m) {
        double d1 = 0; double d2 = 1;
        if(z[k].first - z[i].first != 0 && z[m].first - z[i].first != 0) {
          d1 = (double)(z[k].second - z[i].second) / (double)(z[k].first - z[i].first);
          d2 = (double)(z[m].second - z[i].second) / (double)(z[m].first - z[i].first);
        } else if(z[k].first - z[i].first == 0 && z[m].first - z[i].first == 0) {
          ans = "Yes";
        } else {
          continue;
        }
        // cout << "d: " << d1 << " " << d2 << endl;
        if(d1 == d2) {
          ans = "Yes";
          // cout << "d: " << d1 << " " << d2 << " i: " << i << " k: " << k << " m: " << m << endl;
        }
      }
    }
  }
  cout << ans << endl;
}