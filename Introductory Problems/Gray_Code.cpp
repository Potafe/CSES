#include <iostream>
using namespace std;

char xorChar(char a, char b) { 
    return (a == b) ? '0' : '1'; 
}

string binToGrey(string binary) {
    string gray = "";

    gray += binary[0];

    for (int i = 1; i < binary.length(); i++) {
        
        gray += xorChar(binary[i - 1], binary[i]);
    }

    return gray;
}

string binaryOf(int i, int n) {
    string bin = "";
    
    while (i > 0) {
        bin = char('0' + i % 2) + bin;
        i /= 2;
    }
    
    while (bin.length() < n) {
        bin = '0' + bin;
    }
    
    return bin;
}

int main() {
    int n;
    cin >> n;
    
    int allCombs = 1;
    
    for (int i = 0; i < n; i++) {
        allCombs *= 2;
    }
    
    for (int i = 0; i < allCombs; i++) {
        if (i == 0 || i == 1) cout << binaryOf(i, n) << endl;
        else {
            string bin = binaryOf(i, n);
            cout << binToGrey(bin) << endl;
        }
    }
    
    return 0;
}