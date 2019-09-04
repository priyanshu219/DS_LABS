/**
 * @file problem2.++
 * @brief Implement N Queens problem to show all the possible combinations in N x N binary matrix and to display the total number of such combinations at the end
 * @date 03/09/2019
 * @author Priyanshu Garg
 */
#include <bits/stdc++.h>
using namespace std;

int arr[500][500] = {0};    /**< Array to store the arrangement of Queens*/
int num = 1;    /**<Number to count the arrangement */

/**
 * @brief To display each arrangement
 * @param n Number of queens we want to place
 */
void display(int n)
{
    cout << "Arrangement No. " << num << ":\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
    num++;
}

/**
 * @brief To check whether or not it is safe to place the queen at given cell
 * @param col Column number in which we want to place the queen
 * @param row Row number in which we want to place the queen
 * @param n Number of queens we want to place
 * @return true When we can place the queen at specific cell
 * @return false When we can not place the queen at specific cell
 */
bool safe(int col, int row, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == row)
        {
            for (int j = 0; j <= col - 1; j++)
                if (arr[row][j] == 1)
                    return false;
        }
        else if (i < row)
        {
            if ((i - abs(row - col)) >= 0 && arr[i][i - abs(row - col)] == 1)
                return false;
            else if (arr[i][i + abs(row - col)] == 1)
                return false;
        }
        else if (i > row)
            if (arr[i][row + col - i] == 1)
                return false;
    }
    return true;
}
/**
 * @brief To place the queen at each cell and check recursively whether or not we can place the queen at given cell
 * @param col Column number in which we want to place queen
 * @param rows Total number of rows in chess board
 */
void placequeen(int col, int rows)
{
    if (col >= rows)
    {
        display(rows);
        return;
    }
    for (int i = 0; i < rows; i++)
    {
        if (safe(col, i, rows))
        {
            arr[i][col] = 1;
            placequeen(col + 1, rows);
            arr[i][col] = 0;
        }
    }
}
/**
 * @brief It calls the printqueen function to print all the arrangements on chess_board
 */
int main()
{
    clock_t c_start = clock();
    auto t_start = std::chrono::high_resolution_clock::now();
    int n;
    cout<<"Number of queens you want to place:\n";
    cin >> n;
    if(n > 3){
        cout<<"Total arrangements are:\n";
        placequeen(0, n);
    }
    else
        cout<<"NO ARRANGEMENT FOUND\n";
    clock_t c_end = clock();
    auto t_end = std::chrono::high_resolution_clock::now();
    cout << fixed << setprecision(2) << "CPU time: " << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";
    cout << "Real time passed: " << std::chrono::duration<double, milli>(t_end - t_start).count() << " ms\n";
}