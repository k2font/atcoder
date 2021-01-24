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
  string S; cin >> S;
  string ans = "WA";
  if(S[0] == 'A') {
    int tmp = 0; int a = -1;
    for(int i = 2; i < S.size() - 1; ++i) {
      if(S[i] == 'C') {
        tmp++;
        a = i;
      }
    }
    if(tmp != 1) {
      ans = "WA";
      cout << ans << endl;
      return 0;
    }
    REP(i, S.size()) {
      if(i == 0) continue;
      if(i == a) continue;
      if(isupper(S[i])) {
        ans = "WA";
        cout << ans << endl;
        return 0;
      }
      if(i == S.size() - 1) ans = "AC";
    }
  }
  cout << ans << endl;
}