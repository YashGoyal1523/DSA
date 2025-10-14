#include<iostream>
using namespace std ;
int main()
{
    int arr[]={10,20,30,40,50,60,70,80};

    // &arr gives address of arr daba(whole array)(ek bada dabba made up of chote dabbas)  // address of array is equal to base address ie add of 0 index dabba ie first byte of 0 index dabba // gives address of 0 index dabba ie first byte of 0 index dabba

    // arr is a pointer (pointer to single dabba) which points to first dabba of array ie 0 index dabba ie store add of 0 index dabba ie first byte of 0 index dabba 

    //&arr+1 will give add of byte present just after skipping a dabba of size that of arr daba (whole array)
    //arr+1 will give add of byte just after skipping dabba of size of  dabba to which it points ie 0 index daba(ie size of chota dabba of array)..note it will be address of next chota dabba ie it will give add of 1 index

    //*(&arr) gives us the pointer arr   // trick se socho * and & nullify sirf arr bacha h...socho sirf arr likha h
    //*arr gives us the value stored at address jisko arr points ie 0 index ki value

    // arr[i] or [i]arr  gives value of i index dabba  // arr[i] and i[arr]  works at back as  *(arr+i) 
    // &arr[i]  gives address of i index dabba(chota dabba)    // precedence  []>*>&
    // (&arr)[i] -> *(&arr+i) : gives address of byte after i dabbe skip    (doubt ho skta ki element milna chahie uss address ka par jo voh shift ke baad wala address milra voh h toh &arr type ka hi toh address hi hoga)

    // *(&arr[i]) gives value at i index

    // (*(&arr))[i])->arr[i] gives value at i index


    // note: address in arr pointer cannot be changed : it is a constant pointer 
   

    int *ptr=arr; // ptr (pointer to int) storing value of arr pointer ie storing add of 0 index dabba //  note: int*ptr=&arr nhi kr skte as arr is an array ie not single dabba its collection of dabbas so iska address cant be stored in pointer to single dabba .....we need pointer to array for this 
    
    
    
    cout<<&arr<<endl<<arr<<endl<<&arr[0]<<endl<<*arr<<endl<<arr[0]<<endl<<arr+1<<endl;
    cout<<ptr<<endl<<*ptr<<endl<<ptr[0]<<endl; ;   

    cout<<endl<<endl;

    cout<<*arr<<endl<<*arr+1<<endl<<*(arr)+1<<endl<<*(arr+1)<<endl;

    cout<<*(&arr)+1<<endl<<arr+1<<endl;

    cout<<*(*(&arr))<<endl;


    
return 0;
}







