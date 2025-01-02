#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void display(const vector<vector<char>> &board)
{
    cout << "\nCurrent board:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j];
            if (j < 2)
                cout << " |";
        }
        cout << "\n";
        if (i < 2)
            cout << "---|---|---\n";
    }
}

bool checkwin(const vector<vector<char>> &board, char p)
{
    // Check rows and columns
    for (int i = 0; i < 3; ++i)
    {
        if ((board[i][0] == p && board[i][1] == p && board[i][2] == p) ||
            (board[0][i] == p && board[1][i] == p && board[2][i] == p))
        {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == p && board[1][1] == p && board[2][2] == p) ||
        (board[0][2] == p && board[1][1] == p && board[2][0] == p))
    {
        return true;
    }

    return false;
}

bool isfull(const vector<vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

int main()
{
    unordered_map<int, pair<int, int>> map{
        {1, {0, 0}}, {2, {0, 1}}, {3, {0, 2}}, {4, {1, 0}}, {5, {1, 1}}, {6, {1, 2}}, {7, {2, 0}}, {8, {2, 1}}, {9, {2, 2}}};

    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currp = 'X';
    int in;

    cout << "Player 1: X\tPlayer 2: O\n";

    while (true)
    {
        display(board);
        cout << "\nPlayer " << currp << ", enter your move (cell number from 1 to 9): ";
        cin >> in;

        // Validate input
        if (map.find(in) == map.end() || board[map[in].first][map[in].second] != ' ')
        {
            cout << "Invalid move! The cell is either occupied or out of bounds. Try again.\n";
            continue;
        }

        // Make the move
        board[map[in].first][map[in].second] = currp;

        // Check for win or draw
        if (checkwin(board, currp))
        {
            display(board);
            cout << "\nPlayer " << currp << " wins! Congratulations!\n";
            break;
        }
        if (isfull(board))
        {
            display(board);
            cout << "\nIt's a draw!\n";
            break;
        }

        // Switch players
        currp = (currp == 'X') ? 'O' : 'X';
    }

    return 0;
}
