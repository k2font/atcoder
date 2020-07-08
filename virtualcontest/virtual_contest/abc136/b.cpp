#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int N; cin >> N;

    int res = 0;
    REP(i, N+1) {
        if(i == 0) continue;

        int num = i;
        int cnt = 0;
        while(true) {
            num = num / 10;
            cnt++;

            if(num == 0) {
                if(cnt % 2 == 1) {
                    res++;
                }
                break;
            }
        }
    }

    cout << res << endl;
}