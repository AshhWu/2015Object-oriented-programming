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
    
    
    
    char a;
    
    
    
    bool gender;
    
    
    
    bool join;
    
    
    
    int number_F=0,number_M=0;
    
    
    
    int vollyball=0;
    
    
    
    
    
    
    
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
            
            
            
            
            
            
            
            cout<<i<<"-th student's gender(F or M):";
            
            
            
            cin>>a;
            
            
            
            gender=(a=='F');
            
            
            
            
            
            
            
            if (gender)
                
                
                
            {
                
                
                
                number_F++;
                
                
                
                cout<<"Do you want to join the vollyball team?(1 to join or 0 to quit):";
                
                
                
                cin>>join;
                
                
                
                if(join)
                    
                    
                    
                    
                    
                    vollyball++;
                
            }
            
            else
                
                number_M++;
            
            
            
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
    
    
    
    cout<<"The number of males:"<<number_M<<endl;
    
    cout<<"The number of females:"<<number_F<<endl;
    
    cout<<"The number of females who want to join the vollyball team:"<<vollyball<<endl;
    
    
    
    return 0;
    
    
    
    
    
    
    
}