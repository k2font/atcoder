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
  int A, B, C; cin >> A >> B >> C;
  int first = 0;
  int second = 0;
  int third = 0;
  if(A > B && A > C) {
    first = 1;
    if(B > C) {
      second = 2;
      third = 3;
    } else {
      second = 3;
      third = 2;
    }
  }

  if(B > A && B > C) {
    second = 1;
    if(A > C) {
      first = 2;
      third = 3;
    } else {
      first = 3;
      third = 2;
    }
  }

  if(C > A && C > B) {
    third = 1;
    if(A > B) {
      first = 2;
      second = 3;
    } else {
      first = 3;
      second = 2;
    }
  }

  cout << first << endl;
  cout << second << endl;
  cout << third << endl;
}