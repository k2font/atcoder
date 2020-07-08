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
  string S; cin >> S;
  int N; cin >> N;
  vector<string> ans;
  for(int i = 0; i < S.size(); ++i) {
    for(int k = 0; k < S.size(); ++k) {
      string tmp = char_to_string(S[i]) + char_to_string(S[k]);
      ans.push_back(tmp);
    }
  }

  sort(all(ans));

  cout << ans[N - 1] << endl;
}