t = int(input())
def solve():
    s = input()
    n=int(s.split(' ')[0])
    x = int(s.split(' ')[1])
    if(n==x):
        print(n)
        return
    for i in range(70, -1, -1):
        if(((n>>i)&1) != ((x>>i)&1)):
            if((n>>i)&1==0):
                print(-1)
                return
            else:
                if((((n>>(i+1))&1)==0) and ((x&((1<<(i+1))-1))==0)):
                    ans = ((n>>(i+2))<<(i+2)) + (1<<(i+1))
                    if(ans>(5000000000000000000)):
                        print(ans)
                        return
                    print(ans)
                    return
                print(-1)
                return
while(t):
    t-=1
    solve()
    