#include <iostream>

using namespace std;
int a[100];
bool cauhinhcuoi=false;
int n;
void sinh()
{
    int i=n;
    while(i>=1&&a[i]==1)
    {
        a[i]=0;
        --i;
    }
    if(i==0)
    {
        cauhinhcuoi=true;
    }
    else
    {
        a[i]=1;
    }
}
int main()
{
    cout<<"nhap so luong so bit muon sinh\n";
    cin>>n;
    for(int i=1;i<=n;i++)
        a[i]=0;
    while(!cauhinhcuoi)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<a[i];
        }
        cout<<"\n";
        sinh();
    }
    return 0;
}
