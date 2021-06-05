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
char inverse_char(char c) {
  if(isupper(c)) return tolower(c);
  else return toupper(c);
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

class segment_tree {
private:
	int sz;
	std::vector<int> seg;
	std::vector<int> lazy;
	void push(int k) {
		if (k < sz) {
			lazy[k * 2] = max(lazy[k * 2], lazy[k]);
			lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
		}
		seg[k] = max(seg[k], lazy[k]);
		lazy[k] = 0;
	}
	void update(int a, int b, int x, int k, int l, int r) {
		push(k);
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			lazy[k] = x;
			push(k);
			return;
		}
		update(a, b, x, k * 2, l, (l + r) >> 1);
		update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
		seg[k] = max(seg[k * 2], seg[k * 2 + 1]);
	}
	int range_max(int a, int b, int k, int l, int r) {
		push(k);
		if (r <= a || b <= l) return 0;
		if (a <= l && r <= b) return seg[k];
		int lc = range_max(a, b, k * 2, l, (l + r) >> 1);
		int rc = range_max(a, b, k * 2 + 1, (l + r) >> 1, r);
		return max(lc, rc);
	}
public:
	segment_tree() : sz(0), seg(), lazy() {};
	segment_tree(int N) {
		sz = 1;
		while (sz < N) {
			sz *= 2;
		}
		seg = std::vector<int>(sz * 2, 0);
		lazy = std::vector<int>(sz * 2, 0);
	}
	void update(int l, int r, int x) {
		update(l, r, x, 1, 0, sz);
	}
	int range_max(int l, int r) {
		return range_max(l, r, 1, 0, sz);
	}
};

int main() {
  int W, N; cin >> W >> N;
  vector<int> L(N), R(N); REP(i, N) cin >> L[i] >> R[i];
  segment_tree seg(W);
  REP(i, N) {
    int h = seg.range_max(L[i] - 1, R[i]);
    seg.update(L[i] - 1, R[i], h + 1);
    cout << h + 1 << endl;
  }
}