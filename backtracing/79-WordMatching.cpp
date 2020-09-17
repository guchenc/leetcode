/*
 * @Description: µ•¥ ∆•≈‰
 * @Author: guchen
 * @Date: 2020-09-16 10:47:57
 * @LastEditTime: 2020-09-16 11:12:53
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // using back tracing
    // time: best:O(1)  worst:O((n*m)*3^L)
    // space: O(n*m)
    bool exist(vector<vector<char>>& board, string word) {
        int nrow = board.size();
        int ncol = board[0].size();
        vector<vector<bool>> visited(nrow, vector<bool>(ncol, false));    // visit status
        for (int i = 0; i < nrow; i++) {
            for (int j = 0; j < ncol; j++) {
                if (check(board, visited, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

    bool check(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int i, int j, int index) {
        if (index == word.size()) // word all matched
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) // out of bounders
            return false;
        if (visited[i][j])  // position already visited
            return false;
        if (board[i][j] == word[index]) {
            visited[i][j] = true;   // set visit status to true
            if (check(board, visited, word, i - 1, j, index + 1))
                return true;
            if (check(board, visited, word, i + 1, j, index + 1))
                return true;
            if (check(board, visited, word, i, j - 1, index + 1))
                return true;
            if (check(board, visited, word, i, j + 1, index + 1))
                return true;
            visited[i][j] = false;  // set visit status to false when four directions failed
        }
        return false;
    }

};

int main()
{
    Solution s;
    vector<vector<char>> board;
    vector<char> row;
    string word;
    string line;
    getline(cin, word);
    cout << "word: " << word << endl;
    // char c;
    // while (cin >> c) {
    //     if (c != '*')
    //         row.push_back(c);
    //     else {
    //         board.push_back(row);
    //         row.clear();
    //     }
    // }
    while (getline(cin, line)) {
        for (auto c : line)
            row.push_back(c);
        board.push_back(row);
        row.clear();
    }
    cout << "board(" << board.size() << "*" << board[0].size() << ")" << endl;
    for (auto v : board) {
        for (auto v2 : v)
            cout << v2 << " ";
        cout << endl;
    }
    cout << "result: " << s.exist(board, word) << endl;
}