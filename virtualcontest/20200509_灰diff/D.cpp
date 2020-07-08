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
  int N, K; cin >> N >> K;
  vector<int> d(K);
  vector<vector<int>> A(K);
  REP(i, K) {
    cin >> d[i];
    REP(k, d[i]) {
      int a;
      cin >> a;
      A[i].push_back(a);
    }
  }

  vector<int> snuke(N + 1);
  for(int i = 0; i < K; ++i) {
    for(int k = 0; k < d[i]; ++k) {
      snuke[A[i][k]]++;
    }
  }

  int ans = 0;
  for(int i = 1; i <= N; ++i) {
    if(snuke[i] == 0) ans++;
  }
  cout << ans << endl;
}
