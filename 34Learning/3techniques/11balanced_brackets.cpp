// valid/balanced parenthesis

//balancing factor
//bal[i] = no of '(' till i   -   no of ')' till i
//for balanced brackets :
//bal[i]>=0 && bal[n-1]==0

//eg -> ((())()) => [1,2,3,2,1,2,1,0] -> balanced


// eg => ())( => [1,0,-1,-0] : unbalanced 