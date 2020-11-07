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
  vector<ll> A(N); REP(i, N) cin >> A[i];
  ll ans = 0; int right = 0; ll sum = 0;
  for(int left = 0; left < N; ++left) {
    while(right < N && sum < N) {
      sum += A[right];
      right++;
      // cout << A[right] << " " << left << " " << right << " " << sum << endl;
    }
    if(sum == N) ans++;
    if(left == right) right++;
    sum -= A[left];
    // cout << ans << endl;
  }
  cout << ans << endl;
}