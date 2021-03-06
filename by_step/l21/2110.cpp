// https://www.acmicpc.net/problem/2110
// 2021-03-27 17:27:35 28ms
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
    int n, c; scanf("%d%d", &n, &c);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    sort(arr.begin(), arr.end());

    int end=arr[n-1]-arr[0], start=1, ans;
    while(start<=end) // 최소 거리를 기준으로 이분탐색
    {
        int mid=(end+start)/2;
        int require=c-1, prev=arr[0]; // 첫 집엔 무조건 설치
        
        for(int i=1; i<n; i++) // 주어진 거리로 공유기를 몇 개 놓을 수 있는지 확인
        {
            if(arr[i]-prev>=mid)  
            {
                require--;
                prev=arr[i];
            }
        }
        
        if(require>0)
            end=mid-1;
        else
        {
            start=mid+1;
            ans=mid;
        }
    }
    
    printf("%d", ans);
}