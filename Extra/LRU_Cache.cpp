#include <bits/stdc++.h>
using namespace std;

queue<int>q,temp;
unordered_map<int,int> mp;
int n=2;

void put(int key, int value){
    if(mp.size()==n){
        int x=q.front();
        q.pop();
        mp.erase(x);
    }
        q.push(key);
        mp[key]=value;
        cout<<"Null"<<endl;
}

void get(int key){
    if(mp.find(key)==mp.end()){
        cout<<"Not Found !"<<endl;
    }else{
        while(!q.empty()){
            if(q.front()!=key)
                temp.push(q.front());
            q.pop();
        }
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
        q.push(key);
        cout<<mp[key]<<endl;
    }
}

void printq(){
    queue<int>t;
    cout<<"The queue is - ";
    while(!q.empty()){
        cout<<q.front()<<",";
        t.push(q.front());
        q.pop();
    }
    cout<<endl;
    while(!t.empty()){
        q.push(t.front());
        t.pop();
    }
}

int main(){

put(1,1);
put(2,2);
get(1);
put(3,3);
get(2);
put(4,4);
get(1);
get(3);
get(4);

return 0;
}