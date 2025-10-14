//learned concept

// next power of 2 value for a given no


//m1 
//start with 1. keep on multiplying 2... till result is <= given no
// int nextPowerOfTwo(int x) {
//     int res = 1;
//     while (res <= x) {
//       res =res<< 1;  //res=res*2;
// }
//     return res;
// }

//m2
//use __builtin_clz() 
// int nextPowerOfTwo(int x) {
//     if (x <= 0) return 1;
//     if ((x & (x - 1)) == 0) return x << 1; // already a power of 2 //optimisation
//     int leadingZeros = __builtin_clz(x);
//     int nextPower = 1 << (32 - leadingZeros); //left shift 1 (32-leading zeros) times
//     return nextPower;
// }