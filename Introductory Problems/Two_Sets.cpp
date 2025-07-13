#include <iostream>
#include <vector>
using namespace std;

int main()
{   
    long long n; 
    cin >> n;
    
    long long sum = (n * (n + 1)) / 2;
    
    vector<long long> s1, s2;
    
    if (sum % 2 == 0) {
        cout << "YES" << endl;
        long long exp_sum = sum / 2;
        
        for (long long i = n; i >= 1; i--) {
            if (i <= exp_sum) {
                s1.push_back(i);
                exp_sum -= i;
            } else {
                s2.push_back(i);
            }
        }
        
        cout << s1.size() << endl;
        for (long long num : s1) {
            cout << num << " ";
        }
        cout << endl;
        cout << s2.size() << endl;
        for (long long num : s2) {
            cout << num << " ";
        }
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    return 0;
}
