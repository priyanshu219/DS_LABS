#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data, st, end;
    struct node *bottom, *right;
}node;

node *root = NULL, *head = NULL;

int main(){
    int n,i, j, k, cnt = 0;
    cin >> n;
    int a[n+1];
    a[0] = 0;
    node* current = NULL;
    for(i = 1; i <= n; i++){
        cin >> a[i];
        node* node = new struct node();
        node -> data = a[i];
        if(!root){
            root = node;
            current = root;
        }
        else{
            current -> bottom = node;
            current = current -> bottom;
        }
        current -> bottom = NULL;
    }
    int dp[n+1][n+1]={0};
    for(i = 1; i <= n; i++){
        for(j = i ; j<= n; j++){
            if(i == j)
                dp[i][j] = a[i];
            else{
                dp[i][j] = dp[i][j-1]^a[j];
                if(dp[i][j] == 0)
                    cnt+=(j-i);
            }
        }
    }
    cout<<"From dynamic programming:\n";
    cout<<cnt<<"\n";
    for(i = 1; i <= n; i++)
        for(j = i; j <= n; j++)
            if(dp[i][j] == 0)
                for(k = i+1; k <= j; k++)
                    cout<<"("<<i<<","<<k<<","<<j<<")\n";
    cout<<"\nFrom Linked List:\n";
    cnt = 0;
    head = root;
    current = root;
    for(i = 1; i <= n; i++){
        current = head;
        for(j = i; j <= n; j++){
            node *node = new struct node();
            if(i == j)
                node->data = a[i];
            else
                node -> data = current -> data ^ a[j];
            current->right = node;
            current = current->right;
            current -> st = i;
            current -> end = j;
            current -> right = NULL;
            if(current->data == 0)
                cnt+=(j-i);
        }
        head = head -> bottom;
    }
    cout<<cnt<<"\n";
    head = root;
    while(head){
        current = head -> right;
        while(current){
            if(current -> data == 0)
                for(k = current->st+1; k <= current->end; k++)
                    cout<<"("<<current->st<<","<<k<<","<<current->end<<")\n";
            current = current -> right;
        }
        head = head -> bottom;
    }
}