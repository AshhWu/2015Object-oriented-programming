#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

int main()
{
    char command;
    string source;
    string output;

    clock_t start,end;
    double time;
    cout<<"please enter 'C' to compress or 'D' to decompress, then enter the source and output(three parts must be separated by white spaces) : "<<endl;
    cin>>command>>source>>output;
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
    start=clock();
    if(command=='c'||command=='C')
    {
        int i=0,a=0;
        int8_t x;
        unique_ptr<char []> data(new char [128]);
        while(i<n)
        {
            ifile.read(reinterpret_cast<char*>(&x),1);
            data[a]=x;
            a++;
            i++;
            ifile.read(reinterpret_cast<char*>(&x),1);
            data[a]=x;
            while(i<n)
            if(data[a]==data[a-1])
            {
                while(data[a]==data[a-1]||a<128)
                {
                    a++;
                    i++;
                    
                    ifile.read(reinterpret_cast<char*>(&x),1);
                    data[a]=x;
                    
                }
                a=-a;
                ofile.write(reinterpret_cast<char*>(&a),1);
                ofile.write(reinterpret_cast<char*>(&x),1);
                
            }
        
        
            else
            {
                while(data[a]!=data[a-1]||a<128)
                {
                    
                    a++;
                    i++;
                    
                    ifile.read(reinterpret_cast<char*>(&x),1);
                    data[a]=x;
                    
                }
                ofile.write(reinterpret_cast<char*>(&a),1);
                ofile.write(data.get(),a+1);
            }
            
            a=0;
            
        }
        
    }
    if(command=='d'||command=='D')
    {
        int i=0;
        while(i<n)
        {
            int8_t x;
            ifile.read(reinterpret_cast<char*>(&x),1);
            
            if(0<=x<=127)
            {
                unique_ptr<char []>data(new char [x+1]);
                for(int8_t j=0;j<x+1;j++)
                {
                    
                    ifile.read(reinterpret_cast<char*>(&x),1);
                    ofile.write(reinterpret_cast<char*>(&x),1);
                    
                }
        
                i=i+2;
            }
    
            else if(-128<=x<=-1)
            {
                ifile.read(reinterpret_cast<char*>(&x),1);
                for(int8_t j=0;j<-x+1;j++)
                    ofile.write(reinterpret_cast<char*>(&x),1);
                i=i+2;
            }
        
        }
    
    }
    end=clock();
    time=(double)(end-start)/CLOCKS_PER_SEC;
    
    cout<<"size of input file : "<<n<<endl;
    ofile.seekg(0,ofile.end);
    long long p = ofile.tellg();
    cout<<"size of output file : "<<p<<endl;
    cout<<"the processing time : "<<time<<endl;
    
}
