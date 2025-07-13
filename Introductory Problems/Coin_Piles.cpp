#include <iostream>
using namespace std;

int main()
{   
    long long n; 
    cin >> n;
    
    for (long long i = 0; i < n; i++) {
        long long x;
        long long y;
        
        cin >> x >> y;
        
        int rem = (x + y) % 3;
        int min_val = min(x, y);
        int max_val = max(x, y);

        if (rem == 0 && min_val * 2 >= max_val) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}