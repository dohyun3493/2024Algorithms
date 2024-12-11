#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int mod(long long x, long long y){
    return (((x % y) + y) % y);
}

int RabinKarp(string &A, string &P, int d, int q){
    long long p_sum = 0;
    int cnt = 0;
    int n = A.size();
    int m = P.size();
    long long a_sum[n - m + 1] = {0, };

    for(int i = 0; i < m; i++){
        p_sum = mod(d * p_sum + (P[i] - 97), q);
        a_sum[0] = mod(d * a_sum[0] + (A[i] - 97), q);
    }

    int h = mod(pow(d, m - 1), q);

    for(int i = 0; i < n - m + 1; i++){
        if(i == 0) cout << a_sum[0] << " ";
        else cout << a_sum[i - 1] << " ";
        if(i != 0) a_sum[i] = mod(d * (a_sum[i - 1] - h * (A[i - 1] - 97)) + (A[i + m - 1] - 97), q);
        if(p_sum == a_sum[i]) {
             if (A.substr(i, m) == P) cnt++;
        }
    }

    return cnt;
}


int main(){
    string A, P;

    cin >> A >> P;

    cout << RabinKarp(A, P, 26, 113) << endl;

    return 0;
}