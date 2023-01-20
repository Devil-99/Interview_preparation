// Total number of smaller element after self for each element.
// Ex- [5,3,2,4,1]. Number of smaller element = [4,2,1,1,0]. Total = 8

#include <bits/stdc++.h>
using namespace std;

void merge(int a[],int left,int mid,int right,int &count)
{
    int n1=mid-left+1;
    int n2=right-mid;

    int temp1[n1],temp2[n2];

    for(int i=0;i<n1;i++)
    temp1[i]=a[left+i];

    for(int i=0;i<n2;i++)
    temp2[i]=a[mid+i+1];

   int i=0,j=0,k=left;
    while(i<n1 && j<n2)
    {
        if(temp1[i]<temp2[j])
            a[k++]=temp1[i++];
        else{
            count += (n1-i);
            a[k++]=temp2[j++];
        }
        cout<<count<<" ";
    }

    while(i<n1)
    a[k++]=temp1[i++];

    while(j<n2)
    a[k++]=temp2[j++];

}

void merge_sort(int a[],int left,int right,int &count)
{
    if(left<right)
    {
        int mid=(right+left)/2;
        merge_sort(a,left,mid,count);
        merge_sort(a,mid+1,right,count);

        merge(a,left,mid,right,count);
    }
}
int main() {
    int arr[]={5,3,2,4,1};
    int n=5;
    int count=0;
    merge_sort(arr,0,4,count);

    // for(int i=0;i<5;i++)
    // cout<<arr[i]<<" ";
    cout<<count;

    return 0;
}