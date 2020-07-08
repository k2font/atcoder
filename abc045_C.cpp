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
  string S; cin >> S;

  int N = S.size();
  vector<int> tmp;
  vector<string> str;
  ll ans = 0;
  for(int bit = 0; bit < (1 << (N - 1)); ++bit) {
    REP(i, N - 1) {
      if(bit & (1 << i)) tmp.push_back(i);
    }

    if(bit == 0) str.push_back(S);

    REP(i, tmp.size()) {
      if(i == 0) {
        if(tmp.at(0) == 0) {
          str.push_back(S.substr(0, 1));
        } else {
          str.push_back(S.substr(0, tmp.at(i) + 1));
        }
      } else {
        str.push_back(S.substr(tmp[i - 1] + 1, tmp[i] - tmp[i - 1]));
      }

      if(i == tmp.size() - 1) {
        str.push_back(S.substr(tmp.at(i) + 1));
      }
    }

    REP(i, str.size()) {
      ans += stoll(str[i]);
    }

    tmp.clear();
    str.clear();
  }

  cout << ans << endl;
}