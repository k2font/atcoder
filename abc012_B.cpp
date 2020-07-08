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
  int N; cin >> N;
  int hh = 0;
  int mm = 0;
  int ss = N % 60;

  int f = N - ss;
  mm = f / 60;
  hh = mm / 60;
  mm = mm - hh * 60;
  string ans1 = to_string(hh);
  string ans2 = to_string(mm);
  string ans3 = to_string(ss);
  if(to_string(hh).size() == 1) ans1 = "0" + to_string(hh);
  if(to_string(mm).size() == 1) ans2 = "0" + to_string(mm);
  if(to_string(ss).size() == 1) ans3 = "0" + to_string(ss);
  cout << ans1 << ":" << ans2 << ":" << ans3 << endl;
}