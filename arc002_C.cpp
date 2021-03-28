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

int numPush(const string &s, const string &L, const string &R) {
  const int n = s.size();
  vector<int> dp(n + 1, n);
  dp[0] = 0; // 0文字目は0個の書き換え方法がある
  dp[1] = 1; // 1文字目は1個の書き換え方法がある
  for(int i = 2; i <= n; ++i) {
    dp[i] = min(dp[i], dp[i - 1] + 1);
    if(s.substr(i - 2, 2) == L || s.substr(i - 2, 2) == R) {
      dp[i] = min(dp[i], dp[i - 2] + 1);
    }
  }
  return dp.back();
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  int N; cin >> N;
  string S; cin >> S;

  const string BUTTON = "ABXY";
  int min_push = N;
  for(auto l1 : BUTTON) {
    for(auto l2 : BUTTON) {
      for(auto r1 : BUTTON) {
        for(auto r2 : BUTTON) {
          string L = string(1, l1) + string(1, l2);
          string R = string(1, r1) + string(1, r2);
          min_push = min(min_push, numPush(S, L, R));
        }
      }
    }
  }
  cout << min_push << endl;
}