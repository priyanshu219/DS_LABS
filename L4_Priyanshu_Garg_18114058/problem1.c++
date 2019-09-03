#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, n, start;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++)
        cin >> a[i];
    cin >> n;
    int sum = 0, len = 0;
    start = 0;
    unordered_map<int, int> unmap;
    for(int i = 0; i < N; i++){
        sum += a[i];
        if(unmap.find(sum) == unmap.end())
            unmap[sum] = i;
        if(sum == n)
            len = i+1;
        if(unmap.find(sum - n) != unmap.end())
            if(len < (i - unmap[sum - n])){
                len = i - unmap[sum - n];
                start = unmap[sum - n] + 1;
            }
    }
    if(len != 0)
    cout<<"Length of longest subarray is: "<<len
    <<"\nIndex from "<<start<<" to "<<start+len-1<<"\n";
    else    
        cout<<"NOT FOUND";
}