#include<iostream>

using namespace std;


int emp=5; 
int full=0;

int mutex=1;

int x=0;


void producer(){
    --mutex;
    ++full;
    --emp;

    x++;
    cout<<"Produce"<<x<<endl;

    ++mutex;
}

void consume(){
    --mutex;
    --full;
    ++emp;
    
    cout<<"Consume"<<x<<endl;
    x--;
    
    ++mutex;
}


int main(){
    int c=0;

    while(c==0){
        int val=0;
        cout<<"1. Producer"<<endl;
        cout<<"2. Consume"<<endl;
        cout<<"3. Exist"<<endl;

        cin>>val;

        switch (val){
        case 1:
            if(mutex==1 && emp!=0){
                producer();
            }else{
                cout<<"Buffer is full"<<endl;
            }

            break;
        case 2:
            if(mutex==1 && full!=0){
                consume();
            }else{
                cout<<"Buffer empty"<<endl;
            }
            
            break;
        case 3:
            c=1;   
        default:
            break;
        }
    }


}