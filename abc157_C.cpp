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
  vector<int> s(M), c(M); REP(i, M) cin >> s[i] >> c[i];
  int ans = 1000;
  for(int i = 0; i <= 999; ++i) {
    string S = to_string(i); bool flag = false;
    REP(k, M) {
      if(char_to_int(S[s[k] - 1]) != c[k]) {
        flag = true;
        break;
      }
    }
    if(!flag) {
      if(S.size() == N) {
        ans = i;
        break;
      }
    }
  }

  if(ans == 1000) cout << -1 << endl;
  else cout << ans << endl;
}