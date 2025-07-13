#include <iostream>
using namespace std;

int MOD = 1e9 + 7;
int main()
{   
    long long n; 
    cin >> n;
    
    long long ans = 1;
    for (long long i = 0; i < n; i++) {
        ans *= 2;
        ans %= MOD;
    }
    
    cout << ans % MOD;
    
    return 0;
}