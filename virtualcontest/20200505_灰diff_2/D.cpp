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
  int A, B, C, D, E; cin >> A >> B >> C >> D >> E;
  int all_n = A + B + C + D + E;
  int a = 0;
  int max_n = 0;
  if(A % 10 != 0) {
    int tmp = ((A / 10) + 1) * 10;
    int dif = abs(A - tmp);
    all_n += dif;
    if(max_n < dif) max_n = dif;
  }

  if(B % 10 != 0) {
    int tmp = ((B/ 10) + 1) * 10;
    int dif = abs(B - tmp);
    all_n += dif;
    if(max_n < dif) max_n = dif;
  }

  if(C % 10 != 0) {
    int tmp = ((C / 10) + 1) * 10;
    int dif = abs(C - tmp);
    all_n += dif;
    if(max_n < dif) max_n = dif;
  }

  if(D % 10 != 0) {
    int tmp = ((D / 10) + 1) * 10;
    int dif = abs(D - tmp);
    all_n += dif;
    if(max_n < dif) max_n = dif;
  }

  if(E % 10 != 0) {
    int tmp = ((E / 10) + 1) * 10;
    int dif = abs(E - tmp);
    all_n += dif;
    if(max_n < dif) max_n = dif;
  }

  cout << all_n - max_n << endl;
}