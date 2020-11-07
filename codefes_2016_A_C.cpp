#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
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
  string s; cin >> s;
  ll K; cin >> K; ll tmp = 0; bool flag = false;
  REP(i, s.size()) {
    if(s[i] != 'a' && tmp + ('z' - s[i] + 1) <= K) {
      tmp += ('z' - s[i] + 1);
      s[i] = 'a';
    }
  }
  if(s[s.size() - 1] + ((K - tmp) % 26) <= 'z') s[s.size() - 1] += ((K - tmp) % 26);
  else {
    ll a = 'z' - s[s.size() - 1];
    ll b = ((K - tmp) % 26) - a - 1;
    s[s.size() - 1] = ('a' + b);
  }
  cout << s << endl;
}