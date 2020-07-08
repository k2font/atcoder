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

bool isOK(int index, int key) {
  if(a[index] >= key) return true;
  else return false;
}

int binary_search(int key) {
  //めぐる式2分探索は、初期値に配列の範囲外のindexを設定しておく
  int ng = -1;
  int ok = a.size();

  while(abs(ng - ok) > 1) {
    int mid = (ng + ok) / 2;
    if(isOK(mid, key)) ok = mid; // もしOKだったらそれはrightにある
    else ng = mid;
  }
  return ok;
}

int main() {
  int K; cin >> K;
  cout << binary_search(K) << endl;
}