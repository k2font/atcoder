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
  int n, Q; cin >> n >> Q;
  vector<ll> a(n); REP(i, n) cin >> a[i];

  for(int j = 0; j < Q; ++j) {
    ll x; cin >> x;
    ll res = 0;

    int right = 0;
    ll sum = 0;
    for(int left = 0; left < n; ++left) {
      cout << "left: " << left << " right: " << right << endl;
      while(right < n && sum + a[right] <= x) {
        sum += a[right];
        right++;
      }

      res += (right - left);

      if(right == left) ++right;
      else sum -= a[left];
    }

    cout << res << endl;
  }
}
