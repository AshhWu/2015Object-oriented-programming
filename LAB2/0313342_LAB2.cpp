#include <iostream>
#include <math.h>

using namespace std;


auto gA=numeric_limits<int>::max();
auto gB=numeric_limits<unsigned int>::max();
auto gC=numeric_limits<unsigned long long>::max();

decltype(gA) isPrime(unsigned long long int a)
{
    auto b=sqrt(a);
    auto i=2;
    for(i=2;i<=b;i++)
    {
        if(a%i==0)
        {
            cout<<"非質數"<<endl;
            return 0;
        }
    }
        cout<<"是質數"<<endl;
    return 0;
}

decltype(gA) digitSumA(decltype(gA) n)
{
    decltype(gA) sum=0,r=0;
    while(n>0)
    {
        r=n%10;
        if(r==0)
            sum+=1;
        else
            sum+=pow(r,r);
        n/=10;
    }
    return sum;
}

decltype(gB) digitSumB(decltype(gB) n)
{
    decltype(gB) sum=0,r=0;
    while(n>0)
    {
        r=n%10;
        if(r==0)
            sum+=1;
        else
            sum+=pow(r,r);
        n/=10;
    }
    return sum;
}
decltype(gC) digitSumC(decltype(gC) n)
{
    decltype(gC) sum=0,r=0;
    while(n>0)
    {
        r=n%10;
        if(r==0)
            sum+=1;
        else
            sum+=pow(r,r);
        n/=10;
    }
    return sum;
}

int main()
{
    cout<<"Maximum value for int:"<<gA<<endl
    <<"Maximum value for unsigned int:"<<gB<<endl
    <<"Maximum value for unsigned long long:"<<gC<<endl;

    cout<<"digitSum(gA)="<<digitSumA(gA)<<endl;
    isPrime(digitSumA(gA));
    
    cout<<"digitSum(gB)="<<digitSumB(gB)<<endl;
    isPrime(digitSumB(gB));
    
    cout<<"digitSum(gC)="<<digitSumC(gC)<<endl;
    isPrime(digitSumC(gC));
    
    
}