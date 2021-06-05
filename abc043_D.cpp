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
  string s; cin >> s;
  for(char t = 'a'; t <= 'z'; ++t) {
    REP(i, s.size() - 1) {
      if(s[i] == t) {
        if(s[i] == s[i + 1]) {
          cout << i + 1 << " " << i + 2 << endl;
          return 0;
        } else if(i + 2 < s.size() && s[i] == s[i + 2]) {
          cout << i + 1 << " " << i + 3 << endl;
          return 0;
        }
      }
    }
  }
  cout << -1 << " " << -1 << endl;
}