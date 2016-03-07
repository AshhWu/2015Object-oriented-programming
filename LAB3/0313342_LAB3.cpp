#include <iostream>
#include <string>
#include <vector>

using namespace std;

void createStringArray(const string& text,const string&
                       delimiter,vector<string>& vOut)
{
    size_t Pos2=text.find(delimiter,0);
    
    size_t Pos1=0;
    
    vOut.push_back(text.substr(Pos1,Pos2-Pos1));
    while(Pos2!=text.npos)
    {
        
        Pos1=Pos2+delimiter.length();
        Pos2=text.find(delimiter,Pos1);
        
        vOut.push_back(text.substr(Pos1,Pos2-Pos1));
        
    }
    cout<<vOut.size()<<endl;
    for(size_t i=0;i<vOut.size();i++)
    {
        cout<<vOut[i]<<endl;
    }
}

int main()
{
    string s;
    string d;
    vector<string> v;
    cout<<"please enter a text:"<<endl;
    
    while(getline(cin,s))
    {
        cout<<"please enter a delimiter:"<<endl;
        getline(cin,d);
        if(d.empty())
            d=" ";
        createStringArray(s, d, v);
        cout<<"\nplease enter a text:"<<endl;
    }
    cout<<"end."<<endl;
}

