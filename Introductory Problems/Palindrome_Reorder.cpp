    /*

    Input:
    AAAACACBA

    Output:
    AACABACAA

    Pattern:
    1. we have 6 A's, 2 C's, and 1 B.
    2. to form a palindrome -> 
        we can keep B in the middle as it appears only once.
        we have to now arrange the remaining characters in a way that they are equal on both sides.

    map = {a: 6, c: 2, b: 1}

    string a = ""
    string b = ""
    string mid = ""

    for char in map:
        if char.second % 2 == 0:
            a += char * (char.second // 2)
            b += char * (char.second // 2)
        else if char.second == 1:
            mid = char

    string ans = a + mid + b
    */

// #include <iostream>
// #include <algorithm>
// #include <unordered_map>
// using namespace std;

// int main()
// {
//     string s;
//     cin >> s;

//     unordered_map<char, int> mp;

//     for (int i = 0; i < s.size(); i++) {
//         mp[s[i]]++;
//     }

//     int oddCount = 0;
//     for (auto& chr : mp) {
//         if (chr.second % 2 == 1) {
//             oddCount++;
//         }

//         if (oddCount > 1) {
//             cout << "NO SOLUTION" << endl;
//             return 0;
//         }
//     }

//     string a = "";
//     string b = "";
//     string mid = "";

//     for (auto& chr : mp) {
//         while (chr.second % 2 == 0 && chr.second > 0) {
//             a += chr.first;
//             b += chr.first;
//             chr.second -= 2;
//         }
//         while (chr.second % 2 != 0) {
//             while (chr.second > 0) {
//                 mid += chr.first;
//                 chr.second -= 1;
//             }
//         }
//     }
    
//     reverse(b.begin(), b.end());
    
//     string ans = a + mid + b;

//     cout << ans;

//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    string s;
    cin >> s;

    map<char, int> mp;
    for (char ch : s) {
        mp[ch]++;
    }

    int oddCount = 0;
    char oddChar = '\0';
    for (auto& chr : mp) {
        if (chr.second % 2 == 1) {
            oddCount++;
            oddChar = chr.first;
        }
    }

    if (oddCount > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string left = "", mid = "";

    for (auto& chr : mp) {
        int count = chr.second;

        left.append(count / 2, chr.first);

        if (count % 2 == 1) {
            mid.append(count % 2, chr.first);
        }
    }

    string right = left;
    reverse(right.begin(), right.end());

    cout << left + mid + right << endl;
    return 0;
}
