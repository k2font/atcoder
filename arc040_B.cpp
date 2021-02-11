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
  int R; cin >> R;
  string S; cin >> S;
  int ans = 0;
  
  int q = 0;
  REP(i, N) {
    if(S[i] == '.') q = i;
  }
  q++;

  int c = 0;
  REP(i, N) {
    if(S[i] == 'o') c++;
  }
  if(c == N) {
    cout << 0 << endl;
    return 0;
  }

  int tmp = q - R;
  if(S == "o") {
    cout << 0 << endl;
    return 0;
  }
  if(tmp < 0) {
    cout << 1 << endl;
    return 0;
  }
  REP(i, N) {
    // そこがまだ塗られていなかったら、インク発射
    if(S[i] == '.') {
      for(int k = i; k < i + R; ++k) {
        if(k >= N) continue;
        if(S[k] == '.') {
          S[k] = 'o';
        }
      }
      ans++;
    }
  }
  cout << ans + tmp << endl;
}