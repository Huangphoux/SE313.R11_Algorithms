#include <iostream>

using namespace std;

int a[100];
bool cauhinhcuoi=false;
int n,m;
//check coi co trung khong de tranh truong hop sinh ra 1 1
bool trung(int x,int vitri)
{
    for(int i=1;i<vitri;i++)
    {
        if(a[i]==x)
            return true;
    }
    return false;
}
void sinh()
{
    int i=m;
    while(i>=1)
    {
        int x=a[i]+1;
        while(x<=n&&trung(x,i))
        {
            x++;
        }
        if(x<=n)
        {
            a[i]=x;
            for(int j=i+1;j<=m;j++)
            {
                int y=1;
                while(trung(y,j-1))
                    y++;
                a[j]=y;
            }
            return;
        }
        --i;
    }
    cauhinhcuoi=true;
}
int main()
{
    cout<<"nhap so luong n\n";
    cin>>n;
    cout<<"nhap so luong m\n";
    cin>>m;
    for(int i=1;i<=m;i++)
        a[i]=i;
    while(!cauhinhcuoi)
    {
        for(int i=1;i<=m;i++)
            cout<<a[i];
        cout<<endl;
        sinh();
    }
    return 0;
}
