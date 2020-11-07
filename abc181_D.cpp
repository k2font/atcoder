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
  string S; cin >> S;
  string ans = "No";
  bool judge = false; int hantei = 0;
  if(S.size() == 1) {
    for(int i = 1; i <= 9; ++i) {
      // 本題
      if(i % 2 == 0) { // 下2桁をを2で割る
        int a = i / 2;
        if(a % 4 == 0) {
          if(i == stoi(S)) ans = "Yes";
        }
      }
    }
  } else if(S.size() == 2) {
    for(int i = 11; i <= 99; ++i) {
      bool f = false;
      string tmp = to_string(i); // 0が含まれていたらcontinue;
      REP(i, tmp.size()) {
        if(tmp[i] == '0') {
          f = true;
          break;
        }
      }
      if(f == true) continue;

      // 本題
      if(i % 2 == 0) { // 下2桁をを2で割る
        int a = i / 2;
        if(a % 4 == 0) {
          string t = to_string(i);
          sort(all(S)); sort(all(t));
          if(S == t) ans = "Yes";
        }
      }
    }
  } else { // 3桁以上のとき
    sort(all(S));
    for(int i = 111; i <= 999; ++i) {
      bool f = false;
      string tmp = to_string(i); // 0が含まれていたらcontinue;
      REP(i, tmp.size()) {
        if(tmp[i] == '0') {
          f = true;
          break;
        }
      }
      if(f == true) continue;

      // 本題
      if(i % 2 == 0) { // 下3桁をを2で割る
        int a = i / 2;
        string a_s = to_string(a);
        if(a_s.size() == 1 || a_s.size() == 2) {
          if(stoi(a_s) % 4 == 0) {
            string t = to_string(i);
            sort(all(t)); int p = 0;
            REP(k, S.size()) {
              if(t[p] == S[k]) p++;
            }
            if(p == 3) {
              ans = "Yes";
            }
          }
        } else {
          string b = a_s.substr(a_s.size() - 2, 2);
          if(stoi(b) % 4 == 0) {
            string t = to_string(i);
            sort(all(t)); int p = 0;
            REP(k, S.size()) {
              if(t[p] == S[k]) p++;
            }
            if(p == 3) {
              ans = "Yes";
            }
          }
        }
      }
    }
  }

  if(judge == true) {
    
  }

  cout << ans << endl;
}