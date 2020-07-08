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

int main() {
    int R; cin >> R;

    cout << std::fixed << std::setprecision(15) << 2 * R * 3.1415926535 << endl;
}