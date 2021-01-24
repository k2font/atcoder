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

long long powmod(long long x, long long k, long long m){
  if(k == 0){return (1);}
  if(k%2 == 0){return powmod(x*x % m, k/2, m);}
  else{return (x*powmod(x, k - 1, m) % m);}
}

int main() {
  ll N; cin >> N;
  ll M; cin >> M;
  ll a = powmod(10, N, M * M) ;
  cout << (a / M) % M << endl;
}
