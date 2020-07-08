#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
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

vector<int> buf;
vector<int> tmp = {100, 101, 102, 103, 104, 105};

int main() {
  int X; cin >> X;

  // DPで解く
  int dp[X + 1000];
  dp[0] = 1;
  dp[1] = 0;
  int a[6] = {100, 101, 102, 103, 104, 105};

  for(int i = 0; i < 6; ++i) {
    for(int k = 0; k < X; ++k) {
      if(dp[k] == 1) dp[k + a[i]] = 1;
    }
  }

  cout << dp[X] << endl;
}