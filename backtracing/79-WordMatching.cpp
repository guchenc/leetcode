/*
 * @Description: ����ƥ��
 * @Author: guchen
 * @Date: 2020-09-16 10:47:57
 * @LastEditTime: 2020-11-03 20:30:47
 */
#include "../alg.h"

class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size(), c = board[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (path_exist(board, word, i, j, 0)) return true;
            }
        }       
        return false;
    }

    bool path_exist(vector<vector<char>>& board, string& word, int x, int y, int idx) {
        // print(board, idx, x, y);
        bool found = false;
        if (idx == word.size() - 1 && board[x][y] == word[idx]) return true;
        if (board[x][y] != word[idx]) return false;
        char temp = board[x][y];
        board[x][y] = '-';
        for (auto& dir : dirs) {
            int nx = x + dir.first, ny = y + dir.second;
            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || board[nx][ny] == '-') continue;
            found = path_exist(board, word, nx, ny, idx + 1);
            if (found) return true;
        }
        board[x][y] = temp;
        return false;
    }

    void print(vector<vector<char>>& board, int idx, int x, int y) {
        cout << idx << "(" << x << ", " << y << ")" << endl;
        for (auto& r : board) {
            for (auto c : r) cout << c << " ";
            cout << endl;
        }
        cout << "------------------------" << endl;
    }

};

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