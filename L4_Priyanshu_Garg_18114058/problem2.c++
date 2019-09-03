#include <bits/stdc++.h>
using namespace std;

int arr[500][500] = {0};
int num = 1;

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