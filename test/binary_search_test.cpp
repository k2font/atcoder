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

vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

int binary_search(int key) {
  int left = 0; int right = (int)a.size() - 1;
  while(right >= left) {
    cout << left << " " << right << endl;
    int mid = (left + right) / 2;
    if(a[mid] == key) return mid;
    else if(a[mid] > key) right = mid - 1;
    else if(a[mid] < key) left = mid + 1;
  }
  return -1; // 見つからなかったら-1を返す
}

int main() {
  int K; cin >> K;
  cout << binary_search(K) << endl;
}