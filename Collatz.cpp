#include<iostream>

using namespace std;

int main()
{
    int num;
    cin>>num;
    while(num!=1)
    {
        if(num%2==1)
        {
            cout <<num<<" * 3 + 1 ="<<num*3+1<<endl;
            num=3*num+1;
        }
        else
        {
            cout <<num<<" / 2 = "<<num/2<<endl;
            num/=2;
        }
    }
    cout <<"End"<<endl;
}