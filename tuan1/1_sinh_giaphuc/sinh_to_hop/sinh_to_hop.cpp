#include <iostream>

using namespace std;
int a[100];
bool cauhinhcuoi=false;
int n,k;
void sinh()
{
    int i=k;
    //cong thuc n-k+1 de ra cau hinh cuoi
    while(i>=1&&a[i]==n-k+i)
    {
        --i;
    }
    if(i==0)
    {
        cauhinhcuoi=true;
    }
    else
    {
        a[i]++;
        for(int j=i+1;j<=k;++j)
        {
            a[j]=a[j-1]+1;
        }
    }
}
int main()
{
    cout<<"nhap so luong phan tu \n";
    cin>>n;
    cout<<"nhap so luong cua moi phan tu cua to hop\n";
    cin>>k;
    for(int i=1;i<=k;i++)
        a[i]=i;
    while(!cauhinhcuoi)
    {
        for(int i=1;i<=k;i++)
        {
            cout<<a[i];
        }
        cout<<endl;
        sinh();
    }
    return 0;
}
