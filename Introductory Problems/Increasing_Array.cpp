#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
 
int main()
{   
    int n; 
    cin >> n;
    vector<int> m(n);
    
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[i] = x;        
    }
    
    for (int i = 1; i < n; i++) {
        if (m[i] < m[i - 1]) {
           while (m[i] != m[i - 1]) {
               m[i]++;
               ans++;
           } 
        }  
    }
    
    cout << ans;
 
    return 0;
}
