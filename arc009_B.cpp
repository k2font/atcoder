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
char int_to_char(int val) {
  return '0' + val;
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
  vector<int> b(10); REP(i, 10) cin >> b[i];
  int N; cin >> N;
  vector<string> a(N); REP(i, N) cin >> a[i];

  map<int, int> m;
  int j = 1;
  for(int i = 0; i < 10; ++i) {
    m[b[i]] = j;
    j++;
  }

  REP(i, N) {
    REP(k, a[i].size()) {
      a[i].at(k) = int_to_char(m[char_to_int(a[i].at(k))]);
    }
  }

  //sort(all(a));

  REP(i, N) cout << a[i] << endl;
}