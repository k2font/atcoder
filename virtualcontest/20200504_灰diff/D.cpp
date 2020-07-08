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

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

int main() {
  int N; cin >> N;
  vector<int> x(N), y(N); REP(i, N) cin >> x[i] >> y[i];
  vector<int> array(N); REP(i, N) array[i] = i + 1;

  int math = 0;
  double tmp = 0;
  do{
    math++;
    for(int i = 0; i < array.size() - 1; i++){
      tmp += sqrt(pow(x[array[i] - 1] - x[array[i + 1] - 1] ,2) + pow(y[array[i] - 1] - y[array[i + 1] - 1] ,2));
    }
  } while(next_permutation(all(array)));

  double ans = tmp / math;
  cout << std::fixed << std::setprecision(15) << ans << endl;
}