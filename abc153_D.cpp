#include <bits/stdc++.h>
using namespace std;

int main(){
    long long H;
    cin >> H;

    long long cnt = 0;
    long long num = 1;

    while(H > 0) {
        H = H / 2;
        cnt += num;
        num = num * 2;
    }

    cout << cnt << endl;
}