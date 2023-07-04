iterate over submasks of all submasks of a mask
like 
for (int m=0; m<(1<<n); ++m)
    for (int s=m; s; s=(s-1)&m)
 ... s and m ...

total number of iterations is 3^n (n=no of set bit). Since each set bit has 3 options.

https://cp-algorithms.com/algebra/all-submasks.html#enumerating-all-submasks-of-a-given-mask
