#include <bits/stdc++.h>
using namespace std;

class Data{
    char a;
    int b;
    short int c;
};

int main() {
    Data obj;
    cout<<sizeof(obj)<<endl;
    return 0;
}

// 64bit OS need 64/8 = 8 byte of memory at a time for operation.
// Now char=1 byte , int=4 byte , short int= 2 byte.
// Hence, the memory blocks will be created as 4bytes-4bytes-4bytes. The memory blocks creates according to the max variable size.
// if char and short int are created 1 after another and then int is created, then in the 1st memory block both char and short int can
//     accomodate together and int will take 4 bytes. Hence it will take 8 byte total

// Padding is the extra memory that is being wasted. Like for char its 3bytes, for short int its 2bytes.
// Greedy alignment is this characteristics of taking max size as the memory block size, and allocating memories as soon as it gets.