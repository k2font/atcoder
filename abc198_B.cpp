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

bool kaibun(string str){
  bool f = true;
  for(int i = 0; i < str.size(); ++i) {
    if(str[i] != str[str.size() - (i + 1)]) f = false;
  }
  if(f) return true;
  else return false;
}

int main() {
  string N; cin >> N;
  string ans = "No";
  string tmp = N;
  for(int i = 0; i < 11; ++i) {
    if(kaibun(tmp)) ans = "Yes";
    tmp = "0" + tmp;
    if(kaibun(tmp)) ans = "Yes";
  }
  cout << ans << endl;
}