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
  int T; cin >> T;
  REP(i, T) {
    int N; cin >> N;
    string S; cin >> S;
    vector<ll> ans(N, 0); int tmp = 1;
    REP(k, N) {
      if(k == 0) {
        ans[k] = tmp;
      } else {
        if(S[k - 1] < S[k]) {
          ++tmp; ans[k] = tmp;
        } else {
          tmp = 1; ans[k] = tmp;
        }
      }
    }
    cout << "Case #" << i + 1 << ": ";
    REP(k, N) {
      cout << ans[k];
      if(k != N - 1) cout << " ";
    }
    cout << endl;
  }
}