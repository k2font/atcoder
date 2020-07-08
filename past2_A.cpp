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
  string S, T; cin >> S >> T;
  int s, t;
  bool s_f, t_f;
  if(S[0] == 'B') {
    s = -char_to_int(S[1]);
    s_f = true;
  } else if(S[1] == 'F') {
    s = char_to_int(S[0]);
    s_f = false;
  }

  if(T[0] == 'B') {
    t = -char_to_int(T[1]);
    t_f = true;
  } else {
    t = char_to_int(T[0]);
    t_f = false;
  }

  int ans = 0;
  if(s_f != t_f) cout << abs(s - t) - 1 << endl;
  else cout << abs(s - t) << endl;
  
}
