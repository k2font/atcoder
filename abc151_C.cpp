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
int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int main() {
  int N, M; cin >> N >> M;
  vector<int> p(M); vector<string> S(M);
  REP(i, M) cin >> p[i] >> S[i];
  vector<vector<int>> tmp(N, vector<int>(2));
  REP(i, N) {
    tmp[i][0] = 0;
    tmp[i][1] = 0;
  }
  REP(i, M) {
    if(tmp[p[i] - 1][1] == 0 && S[i] == "WA") {
      tmp[p[i] - 1][0]++;
    }
    if(S[i] == "AC") {
      tmp[p[i] - 1][1] = 1;
    }
  }
  ll ans = 0;
  ll res = 0;
  REP(i, N) {
    if(tmp[i][1] == 1) {
      ans++;
      res += tmp[i][0];
    }
  }
  cout << ans << " " << res << endl;
}