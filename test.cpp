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
  int C1 = 0; int C2 = 0;
  REP(i, S.size() - 1) {
    if(S[i] == 'B' && S[i + 1] == 'B') {
      S[i] = 'A'; S[i + 1] = 'A'; C2++;
    }
  }
  REP(i, S.size() - 2) {
    if(S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'A') {
      S[i + 1] = 'A'; C2++;
    }
  }
  REP(i, S.size()) {
    if(S[i] == 'A') C1++;
  }
  cout << C1 << " " << C2 << endl;
}