#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int N; cin >> N;
    int res = 0;

    res = ceil(N / 1.08);

    int result = res * 1.08;

    if(result == N) {
        cout << res << endl;
    } else {
        cout << ":(" << endl;
    }
}