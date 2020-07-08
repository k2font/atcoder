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
  int n = 10;
  int A = (1 << 2) | (1 << 3) | (1 << 5) | (1 << 7);

  for(int bit = A; ; bit = (bit - 1) & A) {

  }
}