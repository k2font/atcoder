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

int main() {
  int N, D; cin >> N >> D;
  vector<vector<int>> X(N, vector<int>(D));
  REP(i, N) {
    REP(k, D) {
      cin >> X[i][k];
    }
  }

  int cnt = 0;
  double ans = 0;
  REP(m, N) {
    REP(i, N) {
      if(m >= i) continue;
      REP(k, D) {
        ans += pow(X[m][k] - X[i][k], 2);
      }
      // cout << m << " " << i << " " << sqrt(ans) << endl;
      if(sqrt(ans) == floor(sqrt(ans))) cnt++;
      ans = 0;
    }
  }

  cout << cnt << endl;
}