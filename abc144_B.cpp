#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    bool flag = false;

    for(int i = 1; i < 10; ++i) {
        if(N % i == 0 && flag == false) {
            if(N / i < 10) {
                cout << "Yes" << endl;
                flag = true;
            }
        }
    }

    if(flag == false) {
        cout << "No" << endl;
    }
}