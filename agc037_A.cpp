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
  vector<string> vec;
  vector<string> ans;
  vec.push_back(char_to_string(S[0]));
  ans.push_back(char_to_string(S[0]));
  string tmp = "";
  int k = 1;
  REP(i, S.size()) {
    if(i == 0) continue;
    tmp += char_to_string(S[i]);
    if(vec[k - 1] != tmp) {
      vec.push_back(tmp);
      ans.push_back(tmp);
      tmp = "";
      k++;
    }
  }
  cout << vec.size() << endl;
}