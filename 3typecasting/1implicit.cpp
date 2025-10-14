#include<iostream>           // also known as type conversion     (done by compiler)
using namespace std ;
int main()
{

    // float to int

    float num1=5.5;
    int num2=num1; // float int mein store hora // implicit conversion of num1 from float to int ....5.5 to 5
    cout<<num2<<endl;
    int n2=5.5; // implicit conversion of 5.5 from float to int ..5
    cout<<n2;

    cout<<endl;


//int to float


// note
    int num=5;
    float num0=num;// int float m store hora // implicit conversion of num1 from int to float ...5 to 5.0
    cout<<num0;     // note : print mein it will show 5 only in c++...in c lang it will show 5.0000 // in cpp ,printing a float value with decimal value zero will only print integer part and not decimal



// note: compiler does operations on operands of same datatype and give resultant of same  datatype: int+int=int ,int-int=int ,int*int=int , int/int=int ,float/float=float..... etc. .... if operands are of different datatypes then typeconversion occurs to make same
// implicit conversion  in operations
int num3=5;
float num4=5.5;
float ans1=num3+num4;// datatype same krne k liye implicit conversion of num3 from int to float ( int to float occurs and not float to int)...ie yaha 5 ka 5.00 hora hai phle....and resultant is float... fir resultant float is getting stored in float normally
int ans2=num3+num4; // implicit conversion of num3 from int to float ie 5 to 5.00 and num4 as it is and then then resultant(is float) ka float to int as  getting stored in int ie again implicit  
int a3=5+5.5; // same as above
cout<<ans1<<endl<<ans2<<endl<<a3<<endl;

cout<<endl;


int n4=5;
float n5=5.5;
float ann=n4/n5; // typeconversion of n4 from int to float (5 se 5.0)
int an=n4/n5; // typeconversion of n4 from int to float (5 se 5.0) and then resultant float to int
cout<<ann<<endl<<an<<endl;

// so note: int/float , float/int will give float resultant (int wale ka typeconversion hojayega)




//int to char

int num5=97;
char ch=num5;// int ..char mein store hora // implicit conversion of num5 from int to char (ascii value ke acc conversion)
char ch1=97; // same as above...conversion of 97 to A

cout<<ch<<endl<<ch1;


cout<<endl;

// char to int
char cha='A';
int ans4=cha;  // implicit conversion of cha from char to int (converted to its ascii value)
int a4='A'; // same as above
cout<<ans4<<endl<<a4<<endl;

cout<<endl;


// operations

char chara='A';
int ans5=chara+1; //implicit conversion of chara from char to int ie A to 65 (char to int takes place and not int to char) and resultant is int
char ans6=chara+1;//implicit conversion of chara from char to int then resultant int to char 
char a5='A'+1;// same as above
cout<<ans5<<endl<<ans6<<endl<<a5<<endl;

float a6=chara+1;// implicit conversion of chara from char to int and then resultant int to float

cout<<a6<<endl;
return 0;
}




// int+long : int changes to long implicitly and result is long


//arithmetic operations on char values promote them to int and resultant is int
// eg: char+char,char-char : both implicitly converted to int (their ascii value) fir unka operation and result is int


//      int a,int b;
//           long c=a+b;
//                         yaha  a+b ka resultant nikalega  and filhaal voh int hi hai...  fir voh long int m convert hoke(implicit) long m store hoga ... note  agar a+b out of range of int chala gya even though long ki range m ho toh runtime error ajayega as intially toh voh int m hi hai and bound se bahar chala gya toh dikkat



// bool b=4;  // implicit converion of int 4 to bool true occurs  //Any non-zero integer  will be converted to true.The integer 0 will be converted to false
// bool b=4.5; // implicit conversion of float 4.5 to bool true occurs  //Any non-zero floating-point value  will be converted to true . The value 0.0 will be converted to false.


//note:

// arr[char] : char ka implicit conversion hojayegi to int (ascii value) (as int is expected in [])  and fir voh  dekhi jaayegi

//vector<int>v;
// v.push_back(char);  isme char ka implicit typecaste hojayega to int (acc to ascii) (as idhar int expected h )..fir push hojayega voh int
// vector<char>v1;
// v1.push_back(int); isme int ka implicit typecaste hojayega to char (acc to ascii) (as idhar char expected h )..fir push hojayega voh char

//  int-char mein ese adjustment ho skti