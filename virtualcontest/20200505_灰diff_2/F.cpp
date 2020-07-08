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
  int tmp = 3000;
  int FLAG = 753;

  REP(i, S.size() - 2) {
    string str = S.substr(i, 3);
    int a = stoi(str);
    if(tmp > abs(a - FLAG)) {
      tmp = abs(a - FLAG);
    }
  }

  cout << tmp << endl;
}