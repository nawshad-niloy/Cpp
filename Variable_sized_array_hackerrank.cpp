#include <iostream>
using namespace std;
int main()
{
    int n,q,s=0;
    cout<<"Enter the number of array and queries : ";
    cin>>n>>q;
    
    int *arr[n];
    int i;
    while(n--)
    {
        int e; //element enum
        cout<<"enter the number of elements : ";
        cin>>e;
        arr[s] = new int[e];
        cout<<"Enter elements of Array "<<s+1<<" : ";
        for(i=0;i<e;i++)
        {
        cin>>arr[s][i];
        }
        s++;
    }
    while(q--)
    {
        int a,b;
        cout<<"Enter desired position : ";
        cin>>a>>b;
        cout<<arr[a][b]<<endl;
    }
    return 0;
}
