#include <bits/stdc++.h>
using namespace std;

class rectangle
{
    private:
        int x,y,height,width;
    
    public:
        void set(int a,int b,int h,int w)
        {
            x=a;
            y=b;
            height=h;
            width=w;
        }
        
        bool is_square()
        {
            if(height==width)
            return true;
            else
            return false;
        }
        int get_area()
        {
            return (height*width);
        }
        
        void print()
        {
            cout<<"Height="<<height<<" Width="<<width<<" Area="<<get_area()<<endl;
            if(is_square())
            cout<<"The rectangle is a square\n";
            else
            cout<<"The rectangle is not a square\n";
        }
};

int main() {
    rectangle obj;
    obj.set(0,0,5,5);
    obj.print();
    return 0;
}