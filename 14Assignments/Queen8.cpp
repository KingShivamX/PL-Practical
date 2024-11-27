#include <iostream>
using namespace std;

#define N 8

class Queen
{
public:
    int row;
    int col;
};

class EightQueens
{
public:
    Queen stack[N];
    int top = -1;
    int board[N][N];

    EightQueens()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                board[i][j] = 0;
            }
        }
    }

    void push(int row, int col);
    Queen pop();
    bool is_empty();
    bool is_safe(int row, int col);
    void solve();
    void display_solution();
};

void EightQueens::push(int row, int col)
{
    if (top < N - 1)
    {
        top++;
        stack[top].row = row;
        stack[top].col = col;
    }
}

Queen EightQueens::pop()
{
    Queen poppedQueen = {-1, -1};
    if (top >= 0)
    {
        poppedQueen = stack[top];
        top--;
    }
    return poppedQueen;
}

bool EightQueens::is_empty()
{
    return top == -1;
}

bool EightQueens::is_safe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }

        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 1)
        {
            return false;
        }

        if (col + (row - i) < N && board[i][col + (row - i)] == 1)
        {
            return false;
        }
    }
    return true;
}

void EightQueens::solve()
{
    int row = 0, col = 0;

    while (row < N)
    {
        bool placed = false;

        while (col < N)
        {
            if (is_safe(row, col))
            {
                board[row][col] = 1;
                push(row, col);
                placed = true;
                break;
            }
            col++;
        }

        if (!placed)
        {
            if (is_empty())
            {
                cout << "No solution found." << endl;
                return;
            }
            Queen last_queen = pop();
            board[last_queen.row][last_queen.col] = 0;

            row = last_queen.row;
            col = last_queen.col + 1;
        }
        else
        {
            row++;
            col = 0;
        }
    }

    display_solution();
}

void EightQueens::display_solution()
{
    cout << "Solution for Eight Queens Problem : \n\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << (board[i][j] == 1 ? "Q " : ". ");
        }
        cout << endl;
    }
}

int main()
{
    EightQueens eq;
    eq.solve();
    return 0;
}

