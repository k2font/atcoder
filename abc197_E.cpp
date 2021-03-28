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
  ll N; cin >> N;
  vector<ll> X(N), C(N);
  REP(i, N) {
    cin >> X[i] >> C[i];
    C[i]--;
  }
  vector<vector<ll>> v(N);
  REP(i, N) {
    v[C[i]].push_back(X[i]);
  }
  REP(i, N) {
    sort(all(v[i]));
  }
  ll ans = 0;
  REP(i, N) {
    ll tmp = 0; ll res = 0;
    if(i == 0) {
      REP(k, v[i].size()) {
        ans += abs(tmp - v[i][k]);
        tmp = v[i][k];
        if(k == v[i].size() - 1) res = tmp;
      }
    } else {
      
    }
  }
  cout << ans << endl;
}