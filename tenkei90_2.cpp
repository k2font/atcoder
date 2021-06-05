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
  vector<string> ans;
  for(int bit = 0; bit < (1 << N); ++bit) {
    string t = "";
    for(int i = 0; i < N; ++i) {
      if(bit & (1 << i)) t += '(';
      else t += ')';
    }
    int tmp = 0; bool f = true;
    REP(k, N) {
      if(t[k] == '(') tmp++;
      else tmp--;
      if(tmp < 0) f = false;
    }
    if(tmp != 0) f = false;
    if(f == true) ans.push_back(t);
  }
  sort(all(ans));
  REP(i, ans.size()) cout << ans[i] << endl;
}