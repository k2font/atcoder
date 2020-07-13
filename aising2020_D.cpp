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
unsigned int btoui(const std::string& bin) {
    return strtoul(bin.c_str(), NULL, 2);
}
int main() {
  int N; cin >> N;
  string X; cin >> X;
  REP(i, N) {
    int ans = 0;
    string tmp = X;
    if(tmp[i] == '1') tmp[i] = '0';
    else tmp[i] = '1';
    while(true) {
      int cnt = __builtin_popcount(btoui(tmp)); // 割る数を用意
      string res = ""; // 割られる数を用意
      REP(i, N) {
        res += tmp[i];
        if(btoui(res) >= cnt) {
          int t = btoui(res) - cnt;
          stringstream ss;
          ss << bitset<16>(t);
          res = ss.str();
        }
      }
      if(btoui(res) == 0) {
        cout << ans + 1 << endl;
        break;
      } else {
        ans++;
      }
      tmp = res;
    }
  }
}