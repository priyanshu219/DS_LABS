/**
 * @file problem2.c++
 * @brief A c++ program to find the triplets(i, j, k) such that  Ai⊕Ai+1⊕…⊕Aj−1 = Aj⊕Aj+1⊕…⊕Ak
 * @author Priyanshu Garg
 * @date 20/08/2019
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * A structure to define the node of linked list
 */
typedef struct node
{
    int data;   /**< To store the data of a node */
    int st;     /**< To store the starting index(i)*/
    int end;    /**< To store the end index(k) */
    struct node *bottom;    /**< Pointer points to the next head*/
    struct node *right;     /**< Pointer to the nodes which stores the prefix xor*/
} node;

node *root = NULL;  /**< Points towards the root node of linked list */
node *head = NULL;  /**< Points towards the head i.e starting index */

/**
 * @brief To apply both dynamic programming and linked list to find the triplets
 */
int main()
{
    clock_t c_start = clock();
    auto t_start = std::chrono::high_resolution_clock::now();
    int n, i, j, k, cnt = 0;
    cout<<"Enters number of terms:\n";
    cin >> n;
    int a[n + 1];
    a[0] = 0;
    node *current = NULL;
    cout<<"Enter numbers:\n";
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        node *node = new struct node();
        node->data = a[i];
        if (!root)
        {
            root = node;
            current = root;
        }
        else
        {
            current->bottom = node;
            current = current->bottom;
        }
        current->bottom = NULL;
    }
    int dp[n + 1][n + 1] = {0};
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (i == j)
                dp[i][j] = a[i];
            else
            {
                dp[i][j] = dp[i][j - 1] ^ a[j];
                if (dp[i][j] == 0)
                    cnt += (j - i);
            }
        }
    }
    cout << "From dynamic programming:\n";
    cout << "Number of triplets: "<<cnt << "\nTriplets are:\n";
    for (i = 1; i <= n; i++)
        for (j = i; j <= n; j++)
            if (dp[i][j] == 0)
                for (k = i + 1; k <= j; k++)
                    cout << "(" << i << "," << k << "," << j << ")\n";
    cout << "\nFrom Linked List:\n";
    cnt = 0;
    head = root;
    current = root;
    for (i = 1; i <= n; i++)
    {
        current = head;
        for (j = i; j <= n; j++)
        {
            node *node = new struct node();
            if (i == j)
                node->data = a[i];
            else
                node->data = current->data ^ a[j];
            current->right = node;
            current = current->right;
            current->st = i;
            current->end = j;
            current->right = NULL;
            if (current->data == 0)
                cnt += (j - i);
        }
        head = head->bottom;
    }
    cout << "Number of triplets: "<<cnt << "\nTriplets are:\n";
    head = root;
    while (head)
    {
        current = head->right;
        while (current)
        {
            if (current->data == 0)
                for (k = current->st + 1; k <= current->end; k++)
                    cout << "(" << current->st << "," << k << "," << current->end << ")\n";
            current = current->right;
        }
        head = head->bottom;
    }
    clock_t c_end = clock();
    auto t_end = std::chrono::high_resolution_clock::now();
    cout << fixed << setprecision(2) << "CPU time: " << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";
    cout << "Real time passed: " << std::chrono::duration<double, milli>(t_end - t_start).count() << " ms\n";
}