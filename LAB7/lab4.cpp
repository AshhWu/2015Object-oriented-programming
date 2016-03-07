
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <iomanip>
#include <cstdlib>
#include <memory>
using namespace std;

int main()
{
    char command;
    string source;
    string output;
    clock_t start,end;
    double time;
    cout<<"please enter 'C' to compress or 'D' to decompress, then enter the source and output(three parts must be separated by white spaces) : "<<endl;
    
    while(cin>>command>>source>>output)
    {
        fstream ifile(source,ios::binary|ios::in);
        if(!ifile)     //檢查檔案是否成功開啟，如果!file為真，表示無法開啟檔案
        {
            cerr << "Can't open file!\n";
            exit(1);
        }
        
        else
            cout<<"File open successfully!\n";
        
        fstream ofile(output,ios::binary|ios::out);
        ifile.seekg(0,ifile.end);
        long long n = ifile.tellg();
        ifile.seekg(0);
        start=clock();
        if(command=='c'||command=='C')
        {
            long long counter=0,data_counter=0;
            int8_t x,y;                 //x存前一值，y存現在值
            unique_ptr<char []> data(new char [128]);
            ifile.read(reinterpret_cast<char*>(&y),1);
            data[data_counter]=y;
            counter++;
            x=y;
            ifile.read(reinterpret_cast<char*>(&y),1);
            counter++;
            data_counter++;
            data[data_counter]=y;
            cout<<"data"<<data[data_counter]<<',';
            while(counter<n)
            {
                if(x==y)
                {
                    while((y==x)&&(data_counter<127)&&(counter<n))
                    {
                        ifile.read(reinterpret_cast<char*>(&y),1);
                        data_counter++;
                        data[data_counter]=y;
                        counter++;
                        
                    }
                    data_counter=-(data_counter-1);
                    ofile.write(reinterpret_cast<char*>(&data_counter),1);
                    ofile.write(reinterpret_cast<char*>(&x),1);
                    
                    
                    if((counter==n)&&(y!=x))
                    {
                        ofile.write(reinterpret_cast<char*>(&data_counter),1);
                        ofile.write(reinterpret_cast<char*>(&y),1);
                    }
                    
                    
                    data_counter=0;     //歸零
                    data[data_counter]=y;
                    x=y;
                    ifile.read(reinterpret_cast<char*>(&y),1);
                    counter++;
                    data_counter++;
                    data[data_counter]=y;
                }
                
                
                else
                {
                    while((y!=x)&&(data_counter<127)&&(counter<n))
                    {
                        x=y;
                        cout<<"2,y="<<y<<',';
                        ifile.read(reinterpret_cast<char*>(&y),1);
                        counter++;
                        data_counter++;
                        data[data_counter]=y;
                        
                    }
                    data_counter=data_counter-2;
                    ofile.write(reinterpret_cast<char*>(&data_counter),1);
                    ofile.write(data.get(),data_counter+1);
                    data_counter=0;     //歸零
                    data[data_counter]=x;
                    
                    data_counter++;
                    data[data_counter]=y;
                }
                
                
            }
            
            
        }
        if(command=='d'||command=='D')
        {
            long long counter=0;
            int8_t x,y;             //x存前一值，y存現在值
            
            while(counter<n)
            {
                ifile.read(reinterpret_cast<char*>(&y),1);
                cout<<'y='<<y<<',';
                counter++;
                x=y;
                
                if((y>=0)&&(y<=127))
                {
                        unique_ptr<char []>data(new char [y+1]);
                        cout<<'3'<<',';
                        ifile.read(data.get(),y+1);
                        ofile.write(data.get(),y+1);
                    
                    counter=counter+x+1;
                }
                
                else if((y>=-128)&&(y<=-1))
                {
                    
                    ifile.read(reinterpret_cast<char*>(&y),1);
                    for(int8_t j=0;j<(-x)+1;j++)
                        cout<<'4'<<',';
                        ofile.write(reinterpret_cast<char*>(&y),1);
                    counter++;
                }
                else
                    cout<<"error"<<endl;
                
            }
            
        }
        end=clock();
        time=(double)(end-start)/CLOCKS_PER_SEC;
        
        cout<<"size of input file : "<<n<<endl;
        ofile.seekg(0,ofile.end);
        long long p = ofile.tellg();
        cout<<"size of output file : "<<p<<endl;
        cout<<"the processing time : "<<setprecision(4)<<time<<"sec"<<endl;
        cout<<"please enter 'C' to compress or 'D' to decompress, then enter the source and output(three parts must be separated by white spaces) : "<<endl;
        
    }
}

