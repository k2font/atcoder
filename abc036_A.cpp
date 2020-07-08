#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
  double A, B; cin >> A >> B;
  
  if(A > B) {
      cout << 1 << endl;
  } else {
      double d = B / A;
      cout << ceil(d) << endl;
  }
}
