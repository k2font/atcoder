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
  vector<string> input = {
    "dream",
    "dreamer",
    "erase",
    "eraser"
  };

  reverse(all(S));
  REP(i, input.size()) reverse(all(input[i]));

  int pos = 0;
  string ans = "YES";
  bool flag = false;
  while(true) {
    flag = false;
    for(int i = 0; i < input.size(); ++i) {
      if(input[i] == S.substr(pos, input[i].size())) {
        pos += input[i].size();
        flag = true;
      }
    }
    if(flag == false) {
      ans = "NO";
      break;
    }
    if(pos >= S.size()) break;
  }
  cout << ans << endl;
}