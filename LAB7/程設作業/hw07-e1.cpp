#include <iostream>

#include <iomanip>

#include <cmath>

#include <cstdlib>



using namespace std;



int hgrade(int,int);

int lgrade(int,int);

int hgrade(double,double);

int lgrade(double,double);

int correct(int);

unsigned long long factorial(unsigned long);


int main()

{
    
    int grade;
    
    int passedcounter=0,failedcounter=0;
    
    int passedsum=0,failedsum=0;
    
    double passedAverage,failedAverage;
    
    int passedsum_square=0,failedsum_square=0;
    
    int i=1;
    
    
    int maxg=0,ming=100;
    
    
    char department1;
    
    enum department{IE,IMF,MS,TLM,nun};
    
    department de;
    
    int Icounter=0,Fcounter=0,Mcounter=0,Tcounter=0;
    
    char a;
    bool gender;
    bool join;
    int Fnumber=0,Mnumber=0;
    int basketball=0;
    
    
    double higha,lowa;
    
    
    do{
        
        if(i!=23)
            
        {
            
            
            
            cout<<"Please enter the "<<i<<"-th student's grade:";
            
            cin>>grade;
            
            grade=correct(grade);
            
            
            
            if(grade<=60){
                
                failedcounter += 1;
                
                failedsum=failedsum+grade;
                
                failedsum_square=failedsum_square+grade*grade;
                
            }
            
            else
                
            {
                
                passedcounter +=1;
                
                passedsum=passedsum+grade;
                
                passedsum_square=passedsum_square+grade*grade;
                
            }
            
            
            
            ming=lgrade(ming,grade);
            
            maxg=hgrade(maxg,grade);
            
            cout<<"What's your gender?(F or M):";
            cin>>a;
            
            gender=(a=='F');
            
            if(gender)
                Fnumber++;
            else
                Mnumber++;
            
            
            cout<<"Which department are you in ?(I,F,M or T):";
            
            cin>>department1;
            
            
            
            switch(department1){
                    
                    
                    
                    
                    
                case 'I':
                    
                    de=IE;
                    
                    break;
                    
                case 'F':
                    
                    de=IMF;
                    
                    break;
                    
                case 'M':
                    
                    de=MS;
                    
                    break;
                    
                case 'T':
                    
                    de=TLM;
                    
                    break;
                    
                default:
                    
                    de=nun;
                    
                    break;
                    
                    
                    
            }
            
            
            
            if(de==IE)
                
                Icounter++;
            
            else if(de==IMF)
                
                Fcounter++;
            
            else if(de==MS)
                
                Mcounter++;
            
            else if(de==TLM)
                
                Tcounter++;
            
            
            if(de==IE&&gender)
            {
                cout<<"Do you want to join the IE basketball team?(1 to join or 0 to quit):";
                cin>>join;
                
                if(join)
                    basketball++;
            }
            
        }
        
        i++;
        
        
        
        
        
        
        
    }while(i<=50);
    
    
    
    passedAverage=static_cast<double>(passedsum)/passedcounter;
    
    
    
    cout<<"The sum of the passed students:"<<passedsum<<endl;
    
    cout<<"average:"<<fixed<<setprecision(2)<<passedAverage<<endl;
    
    cout<<"standard deviation:"<<fixed<<setprecision(2)<<pow(static_cast<double>(passedsum_square)/passedcounter-passedAverage*passedAverage,0.5)<<"\n"<<endl;
    
    
    
    failedAverage=static_cast<double>(failedsum)/failedcounter;
    
    
    
    cout<<"The sum of the failed students:"<<failedsum<<endl;
    
    cout<<"average:"<<fixed<<setprecision(2)<<failedAverage<<endl;
    
    cout<<"standard deviation:"<<fixed<<setprecision(2)<<pow(static_cast<double>(failedsum_square)/failedcounter-failedAverage*failedAverage,0.5)<<endl;
    
    
    
    cout<<"MAX:"<<maxg<<endl;
    
    cout<<"MIN:"<<ming<<endl;
    
    higha=hgrade(passedAverage,failedAverage);
    lowa=lgrade(failedAverage,passedAverage);
    
    if(higha==1)
        cout<<"The average of passed students is higher than failed students."<<endl;
    else
        cout<<"ERROR!!!"<<endl;
    
    if(lowa==1)
        cout<<"The average of failed students is lower than passed students."<<endl;
    else
        cout<<"ERROR!!!"<<endl;
    
    cout<<"Female:"<<Fnumber<<endl;
    cout<<"Male:"<<Mnumber<<endl;
    
    
    
    cout<<"Number of the students in IE department:"<<Icounter<<endl;
    
    cout<<"Number of the students in IMF department:"<<Fcounter<<endl;
    
    cout<<"Number of the students in MS department:"<<Mcounter<<endl;
    
    cout<<"Number of the students in TLM department:"<<Tcounter<<endl;
    
    cout<<"Number of the students who want to join IE basketball team:"<<basketball<<endl;
    
    cout <<"Randomly choose a student to participate in a contest:" << (1+rand()%50)<<endl;
    
    cout<<"The number of possible permutations of 50 students in a queue:"<<factorial(50)<<endl;
    
    system("pause");
    
    return 0;
    
    
    
}



int hgrade(int a,int b)

{
    
    if(a<b)
        
        return b;
    
    else
        
        return a;
    
}



int lgrade(int a,int b)

{
    
    if(a<b)
        
        return a;
    
    else
        
        return b;
    
}

int hgrade(double a,double b)

{
    
    if(a>b)
        
        return 1;
    
    else
        
        return 0;
    
}



int lgrade(double a,double b)

{
    
    if(a<b)
        
        return 1;
    
    else
        
        return 0;
    
}


int correct(int a=60)
{
    if(a<0)
        a=0;
    else if(a>100)
        a=100;
    return a;
}


unsigned long long factorial(unsigned long long sum)
{
    if(sum==0)
        return 1;
    else
        return sum=sum*factorial(sum-1);
}