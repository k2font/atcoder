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

int main() {
  int N, M; cin >> N >> M;
  vector<int> K(N);
  vector<vector<int>> A(N);
  REP(i, N) {
    cin >> K[i];
    REP(k, K[i]) {
      int a;
      cin >> a;
      A[i].push_back(a);
    }
  }

  map<int, int> m;
  int cnt = 0;
  REP(i, N) {
    REP(k, K[i]) {
      m[A[i][k]]++;
    }
  }

  for(auto x : m) {
    if(x.second == N) cnt++;
  }

  cout << cnt << endl;
}