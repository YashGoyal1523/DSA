
// to find lcm

//m1
// lcm*gcd=a*b -> lcm=a*b/gcd  find gcd using euclid

 //m2
// int LCM(int a, int b)
// {   
//     int ans=-1;
//     int greater = max(a, b);
//     int smallest = min(a, b);
//     for (int i = greater; ; i += greater) {
//         if (i % smallest  == 0)
//             ans=i;
//             break;
//     }
//     return ans;
// }
// //or
// int LCM(int a, int b)
// {   int ans=-1;
//     int greater = max(a, b);
//     int smallest = min(a, b);
//     while(1){
//         int x=greater;
//         if(x%smallest==0){
//             ans=x;
//             break;
//         }
//         x+=greater;
//     }
//     return ans;
// }
