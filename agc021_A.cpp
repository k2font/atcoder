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
  ll N; cin >> N;

  string S = to_string(N);
  int S_size = S.size();

  vector<int> ans;
  ans.push_back(char_to_int(S[0]) - 1);
  REP(i, S_size - 1) {
    ans.push_back(9);
  }

  vector<int> ans2;
  REP(i, S_size) {
    ans2.push_back(char_to_int(S[i]));
  }

  cout << max(accumulate(all(ans), 0LL), accumulate(all(ans2), 0LL)) << endl;
}