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
  string S; cin >> S;
  ll ans = 0; int cnt = 0;
  REP(i, S.size() - 1) {
    if(S[i] == '2' && S[i + 1] == '5') {
      cnt++;
    }
    else if(S[i] == '5' && S[i + 1] == '2') {
      // スルー
    } else {
      int res = 0;
      while(true) {
        if(cnt == 0) break;
        res += cnt;
        cnt--;
      }
      ans += res;
      cnt = 0;
    }

    if(i == S.size() - 2) {
      int res = 0;
      while(true) {
        if(cnt == 0) break;
        res += cnt;
        cnt--;
      }
      ans += res;
    }
  }
  cout << ans << endl;
}