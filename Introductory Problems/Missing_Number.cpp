#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
 
int main()
{   
    int n;
    cin >> n;
    vector<int> m(n, 0);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        m[i] = x;
    }
    
    sort(m.begin(), m.end());
    
    for (int i = 0; i < n; i++) {
        if (i != m[i]) {
            cout << i;
            break;
        }
    }
    
    if (m[n - 1] != n) {
        cout << n;
    
    }
    return 0;
}
