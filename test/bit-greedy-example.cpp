#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}

int main() {
  int n;
  int a[25];
  int K;

  cin >> n;
  REP(i, n) cin >> a[i];
  cin >> K;

  bool exist = false;
  for(int bit = 0; bit < (1 << n); ++bit) {
    int sum = 0;
    for(int i = 0; i < n; ++i) {
      if(bit & (1 << i)) {
        sum += a[i];
      }
    }

    if(sum == K) exist = false;
  }

  if(exist) cout << "Yes" << endl;
  else cout << "No" << endl;
}