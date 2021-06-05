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

  // oが4つ以上含まれる場合は確実に0
  int cnt = 0; int cnt2 = 0;
  REP(i, S.size()) {
    if(S[i] == 'o') cnt++;
    if(S[i] == '?') cnt2++;
  }
  if(cnt >= 5 || cnt2 == 0) {
    cout << 0 << endl;
    return 0;
  }

  // そうではない場合
  ll ans = 0;
  for(int i = 0; i <= 9999; ++i) {
    vector<int> d(10, 0);
    std::ostringstream sout;
    sout << std::setfill('0') << std::setw(4) << i;
    std::string s = sout.str();

    map<char, int> c;
    c[S[char_to_int(s[0])]]++;
    c[S[char_to_int(s[1])]]++;
    c[S[char_to_int(s[2])]]++;
    c[S[char_to_int(s[3])]]++;

    d[char_to_int(s[0])]++; d[char_to_int(s[1])]++; d[char_to_int(s[2])]++; d[char_to_int(s[3])]++;

    bool f = false;
    REP(k, 10) {
      if(S[k] == 'o') {
        if(d[k] == 0) f = true;
      }
    }
    
    if(f == true) continue;
    if(c['x'] > 0) continue;
    ans++;
  }
  cout << ans << endl;
}