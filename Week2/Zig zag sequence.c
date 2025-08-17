#include <stdio.h>
#include <stdlib.h>

int cmpAsc(const void*a,const void*b){
    return (*(int*)a-*(int*)b);
}
void zigzag(int arr[],int n){
    qsort(arr,n,sizeof(int),cmpAsc);
    int mid=(n-1)/2;
    int temp=arr[mid];
    arr[mid]=arr[n-1];
    arr[n-1]=temp;
    int s=mid+1;
    int e=n-2;
    while(s<=e){
        temp=arr[s];
        arr[s]=arr[e];
        arr[e]=temp;
        s++;
        e--;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        zigzag(arr,n);
        
    }
    return 0;
}
