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
  int N = S.size();
  string a = S.substr(0, (N - 1) / 2);
  string b = S.substr((N + 3) / 2 - 1, (N - 1) / 2);
  
  bool flag = false;
  for(int i = 0; i < (a.size()) / 2; ++i) {
    // cout << a[i] << " " << a[a.size() - i - 1] << endl;
    if(a[i] != a[a.size() - i - 1]) {
      flag = true;
    }
  }
  // cout << a << " " << flag << " " << b << " " << endl;

  for(int i = 0; i < (b.size()) / 2; ++i) {
    // cout << b[i] << " " << b[b.size() - i - 1] << endl;
    if(b[i] != b[b.size() - i - 1]) {
      flag = true;
    }
  }
  // cout << a << " " << flag << " " << b << " " << endl;

  for(int i = 0; i < a.size(); ++i) {
    if(a[i] != b[b.size() - i - 1]) {
      flag = true;
    }
  }

  // cout << a << " " << flag << " " << b << " " << endl;
  if(flag == true) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}