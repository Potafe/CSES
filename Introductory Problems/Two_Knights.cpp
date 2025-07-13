#include <iostream>
using namespace std;

int main()
{   
    int n; 
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        long long i2 = 1LL * i * i;
        long long totalAttacks = 4LL * (i - 1) * (i - 2);
        long long totalPossible = (i2 * (i2 - 1)) / 2;

        cout << totalPossible - totalAttacks << endl;
    }
    
    return 0;
}