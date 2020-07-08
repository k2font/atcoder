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
int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
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
  ll N; cin >> N;
  if(N == 1) {
    cout << "Not Prime" << endl;
    return 0;
  }
  if(IsPrime(N) == false) {
    char c = to_string(N)[to_string(N).size() - 1];
    if(char_to_int(c) % 2 != 0 && char_to_int(c) != 5) {
      int cnt = 0;
      REP(i, to_string(N).size()) {
        cnt += to_string(N)[i];
      }
      if(cnt % 3 != 0) {
        cout << "Prime" << endl;
      } else {
        cout << "Not Prime" << endl;
      }
    } else {
      cout << "Not Prime" << endl;
    }
  } else if(IsPrime(N) == true) {
     cout << "Prime" << endl;
  }
}