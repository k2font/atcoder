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
  int n = 5;

  for(int bit = 0; bit < (1 << n); bit++) {
    cout << bitset<8>(bit) << endl;
  }

  for(int bit = 0; bit < (1 << n); bit++) {
    vector<int> S;
    for(int i = 0; i < n; ++i) {
      if(bit & (1 << i)) {
        S.push_back(i);
      }
    }

    cout << bit << " : {";
    for(int i = 0; i < (int)S.size(); ++i) {
      cout << S[i] << " ";
    }
    cout << "}" << endl;
  }
}