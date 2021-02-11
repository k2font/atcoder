#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
char inverse_char(char c) {
  if(isupper(c)) return tolower(c);
  else return toupper(c);
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
struct edge {
  ll to, cost;
};

int main() {
  long double X, Y, R; cin >> X >> Y >> R;
  X = round(X * 10000); Y *= round(Y * 10000); R *= round(R * 10000);
  ll low = ceil(X - R);
  ll high = floor(X + R);
  ll p = 0; ll num = 0;
  for(int i = low; i <= high; i += 10000){
    ll idx = i;
    p = round(sqrt(R * R - ((X - idx) * (X - idx))));
    ll bottom = ceil(Y - p);
    ll top = floor(Y + p);
    bottom /= 10000; top /= 10000;
    num += ((top - bottom) + 1);
  }
  cout << num << endl;
}