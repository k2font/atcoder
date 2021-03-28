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
  int N, P; cin >> N >> P;
  string S; cin >> S;
  ll ans = 0;
  if(P == 2 || P == 5) {
    ll tmp = 0;
    REP(i, N) {
      if((S[N - i - 1] - '0') % P == 0) {
        tmp += N - i;
      }
    }
    ans = tmp;
  } else {
    map<ll, ll> m;
    ll tmp = 0;
    ll ten = 1; m[tmp]++;
    REP(i, N) {
      tmp = (tmp + (S[N - i - 1] - '0') * ten) % P;
      m[tmp]++;
      ten = (ten * 10) % P;
    }
    for(auto x : m) {
      ans += x.second * (x.second - 1) / 2.0;
    }
  }
  cout << ans << endl; 
}