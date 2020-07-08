#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> A(N); for(int i = 0; i < N; ++i) cin >> A[i];

    int max_n = *max_element(A.begin(), A.end());
    int min_n = *min_element(A.begin(), A.end());

    cout << abs(max_n - min_n) << endl;
}