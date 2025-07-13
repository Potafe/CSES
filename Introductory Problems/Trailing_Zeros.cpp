/*
The number of trailing zeros in a number equals the number of times we can divide it by 10. 
Since 10= 2 * 5, we should focus on factors 2 and 5.

In a factorial, the number of factors 5 is always smaller than the number of factors 2, 
and the number of trailing zeros equals the number of factors 5. 

For example, 20! = 2^18 * 3^8 * 5^4 * 7^2 * 11 * 13 * 17 * 19, 
so factor 2 appears 18 times and factor 5 appears 4 times. Thus, 20! has 4 trailing zeros.
*/

#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long ans = 0;
    for (long long i = 5; n / i >= 1; i *= 5) {
        ans += n / i;
    }

    cout << ans;
    return 0;
}
