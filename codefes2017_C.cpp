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

int N;
int cnt;
void dfs(vector<int> _A, vector<int> _ans, int i) {
  if(i == N) {
    int tmp = 1;
    REP(j, N) {
      tmp = tmp * _ans[j];
    }
    if(tmp % 2 == 0) cnt++;
    return;
  }

  for(int k = -1; k <= 1; ++k) {
    _ans.push_back(_A[i] + k);
    dfs(_A, _ans, i + 1);
    _ans.pop_back();
  }
}

int main() {
  cin >> N;
  vector<int> A(N); REP(i, N) cin >> A[i];
  vector<int> ans;
  cnt = 0;
  dfs(A, ans, 0);
  cout << cnt << endl;
}