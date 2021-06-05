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
  vector<ll> a(N); REP(i, N) cin >> a[i];
  vector<vector<ll>> res(210);
  int c = min(10, N);
  for(int bit = 0; bit < (1 << c); ++bit) {
    ll sum = 0;
    vector<ll> tmp;
    for(int i = 0; i < c; ++i) {
      if(bit & (1 << i)) {
        sum += a[i]; tmp.push_back(i + 1);
      }
    }

    if(res[sum % 200].size() != 0) {
      cout << "Yes" << endl;
      cout << res[sum % 200].size() << " ";
      REP(i, res[sum % 200].size()) {
        cout << res[sum % 200][i] << " ";
      }
      cout << endl;
      cout << tmp.size() << " ";
      REP(i, tmp.size()) {
        cout << tmp[i] << " ";
      }
      cout << endl;
      return 0;
    }

    REP(i, tmp.size()) {
      res[sum % 200].push_back(tmp[i]);
    }
  }
  cout << "No" << endl;
}