// note: array:  no of elements==no of dabbas ,size is no of dabbas or no of elements ,size batanaa padta fir sab dabbas ek saath allocated  on basis of size ,dabbas continous, new  dabbas add ya dabbas remove cant be done without changing size
// na initialise krke hum dabbe remove nhi krre...garbage value aajati apneappp...
 //vector: array ki trah hi isme bhi  continous dabbes hota par isme bada dabba ek saath nhi allocate hota ie sab dabbes ek saath nhi allocate hote ... isme dabbes bante while insertion of elements ..vector mein no of elements present and no of dabbas alag ho skte ...dekho iske processs se kyuuu.........process: first element aata(push in hota) uske liye ek chota dabba banjata and uss me daljata ..agla element aata uske liye check hota agar current dabbe full hai toh current jitne dabbe h uska double hojata jse yaha full hai toh phle wali space ka double hojata yaani total do dabbe bangye yaani ek aur aagya ab and second m dal jaata element... ..fir third element aara hota jab toh dabbe full hai ..toh phle do dabbe the toh uska double hojataa yaani do aur aajate and total chaar hojaate... and  and third mein dal jaata......ab fourth aaya and cap not full fourth khaali h  so no more dabbes abhi toh fourth m hi dal jaata.. ab 5th aya toh full toh 4 aur esee.... 
 //note: vector> have two terms size and capacity:size is no of elements present and capacity is no of dabbas present..(both are not fixed value and are flexible to change) (capacity gets doubled when new member is coming after its full)
 // mechanism : initially vector khaali h...cap 0 size 0...ab phla element aara h ...cap becomes 1 ...size becomes 1.....ab dusra aara h .....cap becomes 2 ...size becomes 2.....ab teesra aara h ....cap becomes 4....size becomes 3....ab fourth aara h....cap still 4.....size becomes 4.....ab fifth aara h....cap becomes 8...size becomes 5...and so on
 //so inserting first element ke baad size1 cap1 second ke baad size 2 cap 2 third ke baad size3 cap 4 4th ke baad size 4 cap 4 ...so on
 //.So...ese.....apne aap elements ke insertion ke hisaab se size and capacity leleta and hume kuch declare nhi krna hota size ,capacity vagarah phle se
// all these dabbas are continous
// note:ese hi hum elements ko hata bhi skte(pop out kr skte).....elements hatna last se shuru hotee and accordingly size  bhi change hoti rhti..(capacity nhi hoti)....
//toh see kuch fix size vagarah declare vagarah nhi krna hota phle se...marzi se element daalo hatao kuch karooo koi restriction nhi hai jaise array mein phle hi size fix krna hota and uske acc hi kaam krna hota ..jo size bangya utne hi element aayege ..na kuch add kar skte na subtract without changing size.
// we can say vector is dynamic array....ie array ki trah cont data hi hai bas size increase shrink ho sktaa


#include<iostream>
#include<vector>
using namespace std ;
int main()
{
    //method 1 // declaration ,initialisation separate
    vector<int>v1;   // vector v1 created  ..empty created..ie....created with  cap 0 ...size 0....zero elements
    v1.push_back(5);   //  element inserting ..its first element....cap becomes 1 ...size becomes 1 ....first element is 5
    v1.push_back(3);   // element inserting....its second element....cap becomes 2..size 2...second ellement is 3
    v1.push_back(2);   //  element inserting..its third element....cap becomes 4...size 3...third element is 2
    v1.push_back(6);   //  element inserting..its fourth element.....cap is 4...size 4...fourth element is 6
    v1.push_back(7);   //  element inserting..its fifth element.....cap becomes 8...size 5...fifth element is 7
    

    // method 2 // declaration with initial initialisation of elements ie elements already present
     vector<int>v2(5,1); // vector v2 created with size 5 ie five elements present and are valued 1 ....... note cap is also size jitni ie 5......voh doubling wala system ab aage se shuru hoga
     v2.push_back(2);  // next element ie 6th element is inserting ...cap becomes 10   size becomes 6 ..... 6th element is 2
    cout<<v2.capacity();
    //note
    vector<int>v0(5); // vector v0 created with size 5 and elements valued 0...kuch value nhi di toh zero by default.
    
    //  // method 3
    //  vector<int>v3={1,2,3,4,5};   // vector v3 created with elements valued 1,2,3,4,5 present ......cap doubling wala aage se shuru 

    //  // method 4
    //  vector<int>v4{1,2,3,4,5};// vector v3 created with elements valued 1,2,3,4,5 present

return 0;
}


// method 3 and 4 zruri nhi har compiler m chale par shi h




// note : vector<int>(5,1); // vector created with 5 elements valued 1 without any name...note: it cant be accessed as has no name

