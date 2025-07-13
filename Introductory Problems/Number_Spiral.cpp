/*

Number Spiral Formula

Let:
- `r` = row number  
- `c` = column number  
- `n = max(r, c)`

Then:

If `n` is **even**:

- If `r == n`:
  - The value is `n * n - (c - 1)`

- If `c == n`:
  - The value is `(n - 1) ^ 2 + r`

If `n` is **odd**:

- If `r == n`:
  - The value is `(n - 1) ^ 2 + c`

- If `c == n`:
  - The value is `n * n - (r - 1)`

*/

#include <iostream>
#include <algorithm>
using namespace std;


int main()
{   
    int n; 
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        long long x;
        long long y;
        
        cin >> x >> y;
        
        long long z = max(x, y);
        
        if (z % 2 == 0) {
            if (x == z) {
                cout << z * z - (y - 1) << endl;
            }
            else {
                cout << (z - 1) * (z - 1) + x << endl;
            }
        }
        
        else {
            if (x == z) {
                cout << (z - 1) * (z - 1) + y << endl;
            }
            else {
                cout << z * z - (x - 1) << endl;
            }
        }
        
    }
    
    return 0;
}