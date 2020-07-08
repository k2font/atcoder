#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int N; cin >> N;

    int res = 0;
    int result = 0;
    REP(i, N + 1) {
        if(N == 1) {
            result = 1;
            break;
        }

        if(i == 0) continue;

        int cnt = 0;
        if(i % 2 == 0) {
            int num = i;
            while(true) {
                cnt++;
                num = num / 2;
                if(num % 2 == 1) break;
            }
        }

        if(res < cnt) {
            res = cnt;
            result = i;
        }
    }

    cout << result << endl;
}