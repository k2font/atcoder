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

ll calc(ll left, ll right) {
  ll res = 0;
  if(left >= right) {
    res = (left + 1) * left * 0.5;
    res += (right - 1) * right * 0.5;
  } else {
    res = (left - 1) * left * 0.5;
    res += (right + 1) * right * 0.5;
  }
  return res;
}

int main() {
  string S; cin >> S;
  ll ans, left, right; ans = 0; left = 0; right = 0;
  bool flag = false;
  REP(i, S.size()) {
    if(flag == true) {
      if(S[i] == '<') {
        ans += calc(left, right);
        left = 0;
        right = 0;
      }
    }
    if(S[i] == '<') flag = false;
    if(S[i] == '>') flag = true;
    if(flag == false) left++;
    else if(flag == true) right++;
  }
  ans += calc(left, right);
  cout << ans << endl;
}