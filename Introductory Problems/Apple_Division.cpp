/*
    Okay so this is a standard DP algorithm for finding out the min
    difference between 2 subarrays:
    
    We mantain a bool array which tells us if the target sum is possible
    or not:
        -> Target sum here is the total / 2
    
    We then calculate the min difference as:
        -> total_sum - target - (target +- 1)
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

long long subsetMinCalc(long long sum, vector<long long> &nums) {
    set<long long> possible_sums = {0};
    
    for (long long num : nums) {
        set<long long> new_sums = possible_sums;
        for (long long s : possible_sums) {
            new_sums.insert(s + num);
        }
        possible_sums = move(new_sums);
    }

    long long target = sum / 2;
    long long closest = 0;

    for (long long s : possible_sums) {
        if (s <= target) {
            closest = max(closest, s);
        }
    }

    return abs((sum - closest) - closest);
}

int main() {
    long long n;
    cin >> n;
    
    long long sum = 0;
    vector<long long> nums(n);
    
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        nums[i] = x;
        sum += x;
    }
    
    cout << subsetMinCalc(sum, nums) << endl;
    
    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
    Okay so this is a standard bitmask algorithm for finding out the min
    difference between 2 subarrays:
    
    We iterate through all possible subsets of the array using bitmasking.
    For each subset, we calculate two subset sums: 
        -> one for the elements whose ith(i = 0 -> i = n) bit is 1 in the subset
        -> and another for the elements whose ith bit is 0 in the subset.
    We then calculate the difference between the two subsets.
*/

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    
    for (int i = 0; i < n; i++) cin >> p[i];

    ll diff = 1e9;
    
    for (int b = 0; b < (1 << n); b++) { // -> iterate through 0 -> 2^n - 1
        ll sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (b & (1 << i)) { // -> if the ith bit is set in b, add to sum1
                sum1 += p[i]; 
            } else {
                sum2 += p[i]; // -> else add to sum2
            }
        }
        diff = min(diff, abs(sum1 - sum2));
    }

    cout << diff << "\n";
}