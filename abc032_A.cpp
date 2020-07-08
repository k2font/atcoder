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

int gcd(int a, int b) {
   if (a%b == 0) {
       return(b);
   } else {
       return(gcd(b, a%b));
   }
}

int lcm(int a, int b) {
   return a / gcd(a, b) * b;
}


int main() {
  int a, b, n; cin >> a >> b >> n;

  int ans = 0;
  int tmp = lcm(a, b);
  int i = 1;
  while(true) {
    if(tmp * i >= n) {
      ans = tmp * i;
      break;
    }
    i++;
  }

  cout << ans << endl;
}