I was learning integer partition of a number n into k parts(with minimum 1 in each part) and came across this recurrence :

part(n,k) = part(n-1,k-1) + part(n-k,k)

But, I cannot understand the logic behind this recurrence. Can someone please help me visualize this recurrence?




ANSWER
p(n,k) is the number of ways to partition n into k parts. It is the same as the number of different ways of placing n objects into k pots with atleast one object in every pot. Firstly put 1 object in each pot. Total k objects have been put and now we have to put remaining n−k objects into k pots. 
Hence,
p(n,k)=p(n−k,1)+p(n−k,2)+⋯+p(n−k,k−1)+p(n−k,k)
Also observe that,
p(n−1,k−1)=p(n−k,1)+p(n−k,2)+⋯+p(n−k,k−1)
From the above two equations, we conclude:
p(n,k)=p(n−1,k−1)+p(n−k,k)

base case - 
```cpp
if(n<0)return 0;
if(n==0){
  if(k==0)return 1;
  return 0;
}
```
