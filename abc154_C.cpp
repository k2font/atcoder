#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];

    sort(A.begin(), A.end());

    bool flag = false; 
    for(int i = 1; i < N; ++i) {
        if(A[i - 1] == A[i]) {
            cout << "NO" << endl;
            flag = true;
            break;
        }
    }

    if(flag == false) {
        cout << "YES" << endl;
    }
}