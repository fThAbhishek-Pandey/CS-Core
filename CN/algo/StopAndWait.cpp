#include <iostream>
#include<vector>
using namespace std ;
int timer=0, wait_for_ack = -1, frameQ=0, t=0;
bool cansend=true;

void sender (int i, vector<int> frame){
    wait_for_ack++;
    if(wait_for_ack==3) {
        if(i== frame[t]){
            frameQ++;
            t++;
        }
        if(frameQ ==0) {
            cout<<"No frame is send at time "<<i<<endl;
        }
        if(frameQ>0 && cansend){
            cout<<"frame send at time"<<i<<endl;
            cansend=false;
            frameQ--;
            timer++;
            cout<<"tim er in sender "<<timer<<endl;
        }
        if(frameQ>0 && cansend){
            cout<<"frame in queue for transmition"<<i<<endl;
        }
        if(frameQ>0 ) t++;
        cout<<"frameQ "<<frameQ<<"\ni= "<<i<<"\nt= "<<t<<"\nframe= "<<frame[t]<<endl;
        
    }

return ;
}
void reciver(int i){
    if(timer>0) timer++;
    if(timer ==3) {
        cout<<"frame arieved at time: "<<i<<endl;
        wait_for_ack=0;
        timer=0;
    }
    else {
        cout<<"waiting for the frame at time "<<i<<endl;
        }
        return ;
}
int main() {
    // I love Abhishek ji 
    int i=0;
    vector<int> frame={1,2,3,4,5};
    for(int j=0; j<18 ; j++){
        sender(i, frame);
        reciver(i);
    }
    return 0;
}