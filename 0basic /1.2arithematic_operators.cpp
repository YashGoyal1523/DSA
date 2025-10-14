#include<iostream>
using namespace std ;
int main()
{
    int a = 3;
	int b = 2;
    int c=a+b;
    cout<<c<<endl;
	cout << a + b << endl;
	cout << a - b << endl;
	cout << a*b << endl;
	cout << a/b << endl;
	cout << b % a << endl; 

	// increment and decrement operators
	int i=1;
	cout<<i<<endl;   // 1
	cout<<i++<<endl; // 1 (i=2)
	cout<<++i<<endl; // 3 (i=3)
	cout<<i--<<endl; // 3 (i=2)
	cout<<--i<<endl; // 1 (i=1)
	cout<<7%4<<endl;
	// note : 
	// in i++ , first use the value of i then increment it
	// in ++i , first increment the value of i then use it

	// same for -- operator
return 0;
}

//NOTE:
// divide / operator gives quotient 
// modulus % operator gives remainder

//TIPS:
// x % y will give result from range [0,y-1] only.....0,1,2,,y-1,0,1,.... periodically  // x % 3 will give result from range [0,2] only....0,1,2,0,....periodically
// x%10 gives last digit of x...... x%10^2 gives last two digits of x......
// x/10  removes last digit of x ..... x/10^2 removes last two digits of x.....
//x%2 gives last bit in binary form of x ..... x%2^n gives last n bits in binary form of x 
//x/2 removes last bit in binary form of x ........x/2^n removes last n bits in binary from of x....