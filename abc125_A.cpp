#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, T;
    cin >> A >> B >> T;

    int count = 0;

    for(int i = 1; i < T + 0.5; ++i) {
        if(i % A == 0) {
            count += B;
        }
    }

    cout << count << endl;
}