//array of size n

//rotate right by k
// new index= (index+k)%n  (agar index+k overflow kre toh k%n krlena vrna not necessary)

//rotate left by k
// new index = index-k>=0?index-k:index-k+n (k<n hona chahie ...k=k%n krlena)
//or
// new index= (index - k + n)%n (k<n hona chahie (mathematically no , programitcally yes) ...k=k%n krlena)
