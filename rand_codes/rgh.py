ctr=0
flag=0
for i in range(1, 50):
    for k in range(10**i-10**(i-1)):
        for j in range(i):
                ctr+=1
                if(ctr>6920 and ctr<6940):
                    print(i, k, j, ctr)