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
  ll A, B, C; cin >> A >> B >> C;
  // 1の位はループする
  // for(int i = 1; i <= 20; i++) {
  //   for(int k = 1; k <= 10; ++k) {
  //     cout << pow(i, k) << endl;
  //   }
  // }

  // 末尾が0から9で周期的になることがわかった
  // 末尾: 周期
  // 0: 0
  // 1: 1
  // 2: 2, 4, 8, 6
  // 3: 3, 9, 7, 1
  // 4: 4, 6
  // 5: 5
  // 6: 6
  // 7: 7, 9, 3, 1
  // 8: 8, 4, 2, 6
  // 9: 9, 1

  // 0, 1, 5, 6は末尾がそのまま答え
  string ans = to_string(A);
  char t = ans[ans.size() - 1];
  if(t == '0' || t == '1' || t == '5' || t == '6') {
    cout << t << endl;
    return 0;
  }

  // 末尾が4か9の場合は、B^C % 2で答えが決まる
  if(t == '4' || t == '9') {
    ll p = powmod(B, C, 2);
    if(p == 1) {
      if(t == '4') cout << 4 << endl;
      else if(t == '9') cout << 9 << endl;
    } else {
      if(t == '4') cout << 6 << endl;
      else if(t == '9') cout << 1 << endl;
    }
    return 0;
  }

  // 末尾が2, 3, 7, 8の場合は、B^C % 4で答えが決まる
  if(t == '2' || t == '3' || t == '7' || t == '8') {
    ll p = powmod(B, C, 4);
    if(p == 1) {
      if(t == '2') cout << 2 << endl;
      else if(t == '3') cout << 3 << endl;
      else if(t == '7') cout << 7 << endl;
      else cout << 8 << endl;
    } else if(p == 2) {
      if(t == '2') cout << 4 << endl;
      else if(t == '3') cout << 9 << endl;
      else if(t == '7') cout << 9 << endl;
      else cout << 4 << endl;
    } else if(p == 3) {
      if(t == '2') cout << 8 << endl;
      else if(t == '3') cout << 7 << endl;
      else if(t == '7') cout << 3 << endl;
      else cout << 2 << endl;
    } else {
      if(t == '2') cout << 6 << endl;
      else if(t == '3') cout << 1 << endl;
      else if(t == '7') cout << 1 << endl;
      else cout << 6 << endl;
    }
    return 0;
  }
}