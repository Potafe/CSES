#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{   
    string s;
    cin >> s;
    
    int maxi = 0;
    
    for (int i = 0; i < s.size(); i++) {
        int j = i;
        int count = 0;
        
        while (j < s.size() && s[j] == s[i]) {
            j++;
            count++;
        }
        
        maxi = max(maxi, count);
        i = j - 1;
    }
    
    cout << maxi;
 
    return 0;
}