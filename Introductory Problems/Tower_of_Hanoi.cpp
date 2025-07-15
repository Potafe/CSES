/*

Consists of three stacks (left, middle and right) and n round disks of different sizes. 
Initially, the left stack has all the disks, in increasing order of size from top to bottom.

The objective is to move all the disks from the left stack to the right stack, following these rules:

1. Only one disk can be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty stack.
3. No disk may be placed on top of a smaller disk.
4. The left stack is the source, the right stack is the destination, and the middle stack is used as an auxiliary.

Input
    The only input line has an integer n: the number of disks.

Output
    First print an integer k: the minimum number of moves.
    After this, print k lines that describe the moves. 
    Each line has two integers a and b: you move a disk from stack a to stack b.

The solution:
    We use recursion to solve the Tower of Hanoi problem. 
    The function `moveDisks` takes the number of disks and the indices of the source, destination, and auxiliary stacks. 
    It recursively moves the disks according to the rules specified above, storing each move in a vector of pairs. 
    
    What we do is basically like this:
        1. Move n-1 disks from the source stack to the auxiliary stack. (this is to keep the small disk on top)
        2. Move the nth disk from the source stack to the destination stack.
        3. Move the n-1 disks from the auxiliary stack to the destination stack.

*/

#include <iostream>
#include <vector>
using namespace std;

void moveDisks(int n, int from, int to, int aux, vector<pair<int, int>>& moves) {
    if (n == 1) {
        moves.push_back({from, to});
        return;
    }
    moveDisks(n - 1, from, aux, to, moves);
    moves.push_back({from, to});
    moveDisks(n - 1, aux, to, from, moves);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> moves;
    moveDisks(n, 1, 3, 2, moves);

    cout << moves.size() << endl;
    for (const auto& move : moves) {
        cout << move.first << " " << move.second << endl;
    }

    return 0;
}
