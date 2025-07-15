/*

The concept I think is based on recursion, and to pick or not pick a character.

We can use a recursive function to generate all possible strings by either 
including or excluding each character in the original string. 

The base case will be when we've processed all characters, 
at which point we can add the current combination to our results.

So we init a vector to hold the results, and a string to build the current combination.
We call the recursive function starting from the first character.

*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void recursiveGen(string s, string cur, vector<string> &ans, vector<bool> &used) {
    if (cur.size() == s.size()) {
        ans.push_back(cur);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (used[i]) continue;
        if (i > 0 && s[i] == s[i-1] && !used[i-1]) continue;

        used[i] = true;
        cur.push_back(s[i]);
        recursiveGen(s, cur, ans, used);
        cur.pop_back();
        used[i] = false;
    }
}

int main() {
    string s;
    cin >> s;

    int n = s.size();
    vector<string> ans;
    vector<bool> used(n, false);
    sort(s.begin(), s.end());

    recursiveGen(s, "", ans, used);
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
