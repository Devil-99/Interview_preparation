#include <bits/stdc++.h>
using namespace std;

class rectangle
{
    private:
        int height,width;
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

    public:
        void set(int h,int w)
        {
            height=h;
            width=w;
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
    obj.set(6,5);
    obj.print();
    return 0;
}