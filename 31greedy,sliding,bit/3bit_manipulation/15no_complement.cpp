// lc 476

// https://youtu.be/QaVwcw2f-pM?si=nqxh0Rnl6KyqpYMR

// ek bit ka xor with bit 1 -> flips the bit
// ek bit ka xor with bit 0 -> no change

// m1
// last se ek ek krke har bit ko flip krdege
// last bit ke liye num ka 0...0001 (num ke bits jitni bits)  se xor krdo , fir second last bit ke liye num ka 0...00010 se xor krdo , fir third last ke liye 0..00100 se krdo ...so on...first bit ke liye 1000...00 (num ke bits jitni bits) se krdo
// to get 000..01  do 1<<0 , to get 0...010 do 1<<1......to get 100..0 do 1<<(bitscnt in num -1)
class Solution
{
public:
    int findComplement(int num)
    {

        // no of bits in num
        int bitscnt = (int)log2(num) + 1; // log() fn :  log_base(number) : if base not defined then natural logarithmic ie base e

        for (int i = 0; i < bitscnt; i++)
        {
            num = num ^ (1 << i); // phle iteration m 00..01 se hoga , dusre mein 000..010 se hoga , ..... , last m 10000..00 se hoga
        }

        return num;
    }
};

// m2
// sab bits ko ek saath flip maardo
// num ka xor krdo with 1111...11 (num ke bits jitni bits)

// to create this mask of 111..11 with bitscnt no of bits
// do (1<<bitscnt)-1

class Solution {
public:
    int findComplement(int num) {
        int bitscnt=(int)log2(num)+1 ;
        unsigned int mask=(1u<<bitscnt)- 1 ;   // int mein out of bound jaara tha toh unsigned int leliya
        int ans=num^mask ;
        return ans ;
    }
};

// m3
// ek baari complement mein saare bits 0 lelo
// ab num ke piche se ek ek bit uthao and if its 1 then aage  bhado and if its 0 then complement mein uska 0 ki jagah 1 krdo
class Solution
{
public:
    int findComplement(int num)
    {
        int i = 0;
        int compliment = 0;
        while (num)
        {
            if (!(num & 1)) //last bit check // if its 0, then we need to flip for it in complement
            { 
                compliment |= (1 << i);
            }
            num >>= 1; // right shifting num ...last bit will be updated ie curr last will be dropped and uske piche wali shift ho jaayegi and last par ab uske piche wali ajaayegi
            i++;
        }
        return compliment;
    }
};