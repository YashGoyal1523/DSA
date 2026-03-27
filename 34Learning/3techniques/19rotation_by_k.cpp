//array of size n

//rotate right by k
// new index= (index+k)%n   (k<n ki esi koi need nhi hai....toh k=k%n is optional ......agar index+k overflow kre toh k%n krlena)

//rotate left by k
// new index = index-k>=0?index-k:index-k+n (k<n hona chahie ...k=k%n krlena)
//or
// new index= (index - k + n)%n (k<n hona chahie ...k=k%n krlena)
