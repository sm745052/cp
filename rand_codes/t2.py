n, m = map(int, input().split(' '))
k = n//m
if(n-m*k < m*(k+1)-n):
    print(m*k)
elif(n-m*k > m*(k+1)-n):
    print(m*(k+1))
else:
    print(m*(k+1))