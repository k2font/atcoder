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
  string S, T; cin >> S >> T;
  bool f = false;
  for(int i = S.size() - 1; i >= 0; --i) {
    for(int k = i; k < i + T.size(); ++k) {
      if(!(S[k] == T[k - i] || '?' == S[k])) {
        break;
      }
      if(k == i + T.size() - 1) {
        for(int m = i; m < i + T.size(); ++m) {
          if(S[m] == '?') S[m] = T[m - i];
        }
        f = true;
      }
    }
    if(f) break;
  }
  REP(i, S.size()) if(S[i] == '?') S[i] = 'a'; // 後処理
  if(f) cout << S << endl;
  else cout << "UNRESTORABLE" << endl;
}