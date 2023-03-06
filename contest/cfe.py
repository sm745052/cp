te = int(input())
while(te):
    te -= 1
    n, k = map(int, input().split(' '))
    s = input()
    t = input()
    if(k>n):
        if(s==t):
            print("yes")
        else:
            print("no")  
        continue  
    elif(s[n-k:k]==t[n-k:k] and ((n-k-1>=k and sorted(list(s)) == sorted(list(t))) or (n-k-1<k and sorted(list(s[:n-k])+list(s[k:])) == sorted(list(t[:n-k])+list(t[k:]))))):
        print("yes")
        continue
    print("no")