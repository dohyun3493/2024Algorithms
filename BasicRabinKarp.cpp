#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


int basicRabinKarp(string &A, string &P, int d){
    int cnt = 0;
    int p_sum = 0;
    int a_sum[1001] = {0, };
    int n = A.size();
    int m = P.size();

    for(int i = 0; i < P.size(); i++){
        p_sum = d * p_sum + (P[i] - 97);
        a_sum[0] = d * a_sum[0] + (A[i] - 97);
    }

    for(int i = 0; i < n - m + 1; i++){
        if(i == 0) cout << a_sum[0] << " ";
        else cout << a_sum[i - 1] << " ";
        if(i != 0){
            a_sum[i] = d * (a_sum[i - 1] - pow(d, m - 1) * (A[i - 1] - 97)) + (A[i + m - 1] - 97);
        }
        if(p_sum == a_sum[i]) cnt++;
    }

    return cnt;
}

int main(){
    string A, P;
    cin >> A >> P;

    cout << basicRabinKarp(A, P, 10) << endl;

    return 0;
}