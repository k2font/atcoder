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
  string s = S.substr(0, 13);
  if(s == "WBWBWWBWBWBWW") cout << "Do" << endl;
  else if(s == "WBWWBWBWBWWBW") cout << "Re" << endl;
  else if(s == "WWBWBWBWWBWBW") cout << "Mi" << endl;
  else if(s == "WBWBWBWWBWBWW") cout << "Fa" << endl;
  else if(s == "WBWBWWBWBWWBW") cout << "So" << endl;
  else if(s == "WBWWBWBWWBWBW") cout << "La" << endl;
  else if(s == "WWBWBWWBWBWBW") cout << "Si" << endl;
}
