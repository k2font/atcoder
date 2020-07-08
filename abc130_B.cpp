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
    int N, X; cin >> N >> X;
    vector<int> L(N); REP(i, N) cin >> L[i];
    int cnt = 1;
    int l = 0;
    REP(i, N) {
        l = l + L[i];
        if(l > X) break;
        cnt++;
    }
    cout << cnt << endl;
}