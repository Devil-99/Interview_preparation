- **Activation Record** - An activation record is a contiguous block of storage that manages information required by a single execution of a procedure.     
So, whenever a function call occurs, then a new activation record is created and it will be pushed onto the top of the stack. It will remain in stack till the execution of that function. So, once the procedure is completed and it is returned to the calling function, this activation function will be popped out of the stack.    
It consist of **Actual parameters, Number of arguments, Return address, Return value, Old stack pointer(SP), Local data of a function.**

- Faster access to a non-local variables is achieved using an array of pointers to activation records called a **Activation Tree**.

- **Types of Pointers-**
    - Integer Pointer - int* ptr;
    - Array Pointer - data_type ptr= &array_name;
    - Structure Pointer - struct struct_name *ptr;
    - **[Function Pointer](https://www.geeksforgeeks.org/function-pointer-in-c/)** - void (*fun_ptr)(arguments data_type) = &fun;
    - Double Pointer - pointer of a pointer
    - **Null Pointer** - That do not point to any memory location.
    - **Void Pointer** - That do not have any predefined data_type. It can take any type of data after declaration and type casting.
    - **Wild Pointer** - That have not been initialised yet.    
    ---
    - **[Near,Far,Huge Pointer](https://www.geeksforgeeks.org/what-are-near-far-and-huge-pointers/)**
    - **[Dangling Pointer](https://www.geeksforgeeks.org/dangling-void-null-wild-pointers/)** - A pointer pointing to a memory location that has been deleted (or freed) is called a dangling pointer.

- **Address on array**-
    - If base address of array A[] is 'Base' and the array start from 'x' index (just like 0 base indexing, it is 'x' base indexing) and each element size 'B' byte.   
    Then the address of A[y] will be = **Base + (y-x) * B**;
    - For array A[m][n] where starting row is m and starting column is n then address of A[x][y] will be = **Base + (x-m) * n * B + (y-n)**;

- **