#include <iostream>

#include <iomanip>

#include <cmath>



using namespace std;



int main()

{
    
    int grade;
    
    int passedcounter=0,failedcounter=0;
    
    int passedsum=0,failedsum=0;
    
    double passedAverage,failedAverage;
    
    int passedsum_square=0,failedsum_square=0;
    
    int i=1;
    
    
    
    do{
        
        if(i!=23)
            
        {
            
            
            
            cout<<"Please enter the "<<i<<"-th student's grade:";
            
            cin>>grade;
            
            
            
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
    
    
    
    return 0;
    
    
    
}