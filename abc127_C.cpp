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

int main() {
	int N, M; cin >> N >> M;
	vector<int> L(M), R(M); REP(i, M) cin >> L.at(i) >> R.at(i);
	vector<int> ans(N + 2); REP(i, N + 2) ans.at(i) = 0;
	REP(i, M) {
		ans.at(L.at(i)) += 1;
		ans.at(R.at(i) + 1) -= 1;
	}
	vector<ll> tmp(N + 1); REP(i, N + 1) tmp.at(i) = 0;
	int res = 0;
	REP(i, N + 1) {
		if(i == 0) continue;
		tmp.at(i) += tmp.at(i - 1) + ans.at(i);
		if(tmp.at(i) == M) res++;
	}
	cout << res << endl;
}
