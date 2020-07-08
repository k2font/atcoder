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
    int N, Y; cin >> N >> Y;
    int x, y, z; x = -1; y = -1; z = -1;
    bool flag = false;
    for(int i = 0; i <= N; ++i) {
        for(int k = 0; k <= N - i; ++k) {
            int Z = N - i - k;
            if(i * 10000 + k * 5000 + Z * 1000 == Y) {
                x = i; y = k; z = Z;
                flag = true;
                break;
            }
        }
        if(flag == true) break;
    }
    cout << x << " " << y << " " << z << endl;
}