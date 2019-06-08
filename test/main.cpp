#include<iostream>
using namespace std;

void swap(int& i,int& j)
{
    int t=i;
    i=j;
    j=t;
}

int main()
{
    int i=1;
    int j=2;
    swap(i,j);
    cout<<i<<" "<<j<<endl;
    return 0;
}
