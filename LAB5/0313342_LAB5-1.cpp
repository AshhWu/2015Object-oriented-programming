#include <iostream>

using namespace std;

enum state{ NEW=0, READY, RUNNING, WAITING, TERMINATED};

class Process
{
public:
    void admit(state &s){if(s==NEW||s==WAITING) s=READY; else cout<<"Cannot be processed!";}
    void dispatch(state &s){if(s==READY) s=RUNNING; else cout<<"Cannot be processed!";}
    void interrupt(state &s){if(s==RUNNING) s=READY; else cout<<"Cannot be processed!";}
    void wait(state &s){if(s==RUNNING) s=WAITING; else cout<<"Cannot be processed!";}
    void exit(state &s){if(s==RUNNING) s=TERMINATED; else cout<<"Cannot be processed!";}
    void displayState(const int s){
        switch(s)
        {
            case 0:
                cout<<"NEW"<<endl;
                break;
            case 1:
                cout<<"READY"<<endl;
                break;
            case 2:
                cout<<"RUNNING"<<endl;
                break;
            case 3:
                cout<<"WAITING"<<endl;
                break;
            case 4:
                cout<<"TERMINATED"<<endl;
                break;
            default:
                cout<<"error!";
                break;
        }
    }
};
    
int main()
{
    Process p;
    state current_state=NEW;
    char demand;
    cout<<"current state:";
    p.displayState(current_state);
    cout<<"'A' or 'a':admit\n 'D' or 'd':dispatch\n 'I' or 'i':interrupt\n 'W' or 'w':wait\n 'E' or 'e':exit"<<endl
    <<"Enter the characters to change the state:";
    while(cin>>demand)
    {
        switch(demand)
        {
            case 'A':
            case 'a':
                p.admit(current_state);
                break;
            case 'D':
            case 'd':
                p.dispatch(current_state);
                break;
            case 'I':
            case 'i':
                p.interrupt(current_state);
                break;
            case 'W':
            case 'w':
                p.wait(current_state);
                break;
            case 'E':
            case 'e':
                p.exit(current_state);
                break;
            default:
                cout<<"error!"<<endl;
                break;
                
                
        }
        
        if(current_state==TERMINATED)
            break;
        cout<<"current state:";
        p.displayState(current_state);
        cout<<"'A' or 'a':admit\n 'D' or 'd':dispatch\n 'I' or 'i':interrupt\n 'W' or 'w':wait\n 'E' or 'e':exit"<<endl
        <<"Enter the characters to change the state:";
    }
    cout<<"current state:";
    p.displayState(current_state);
    cout<<"END"<<endl;
}