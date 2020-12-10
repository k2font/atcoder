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
  string s = to_string(N); int k = s.size();
  int ans = 10000; int tmp = 0;
  REP(i, k) {
    tmp += char_to_int(s[i]);
  }
  if(tmp % 3 == 0) {
    cout << 0 << endl;
    return 0;
  }
  for(int bit = 1; bit < (1 << k); ++bit) {
    int res = 0;
    for(int i = 0; i < k; ++i) {
      if(bit & (1 << i)) {
        res += char_to_int(s[i]);
      }
    }
    if(res % 3 == 0) {
      ans = min(ans, k - __builtin_popcount(bit));
    }
  }
  if(ans != 10000) cout << ans << endl;
  else cout << -1 << endl;
}