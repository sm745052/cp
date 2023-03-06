t = int(input())
while(t):
    t-=1
    s = input()
    n=int(s.split(' ')[0])
    x = int(s.split(' ')[1])
    ans = n
    while(ans!=x):
        n+=1
        ans =ans&n
        if(ans==0):break
    if(ans==x):print(n)
    else:print(-1)