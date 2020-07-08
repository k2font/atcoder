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
      int tmp;
      cin >> tmp;
      A[i].push_back(tmp);
    }
  }

  vector<int> m(100);
  REP(i, 100) m[i] = 0;
  REP(i, K) {
    REP(k, d[i]) {
      m[A[i][k]]++;
    }
  }

  int cnt = 0;
  REP(i, N + 1) {
    if(i == 0) continue;
    if(m[i] == 0) cnt++;
  }

  cout << cnt << endl;
}