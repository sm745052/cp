import subprocess as sub
import numpy as np
sub.run("g++ ./cfb.cpp -o a1.out -std=c++17", shell=True)
sub.run("g++ ./rgh.cpp -o a2.out -std=c++17", shell=True)

# write testcases
while(True):
    st = ""
    n = 50
    m = 40
    st += str(n) + ' ' + str(m) + '\n'
    for i in range(n):
        for j in range(m):
            st += str(np.random.randint(1, 3)-1)
        st += '\n'
    with open("testcase.txt", "w") as f:
        f.write(st)

    # run testcases
    sub.run("a1.out < testcase.txt > output1.txt", shell=True)
    sub.run("a2.out < testcase.txt > output2.txt", shell=True)

    st1 = open("output1.txt", "r").read()
    st2 = open("output2.txt", "r").read()
    if st1.strip() == st2.strip():
        print("AC")
    else:
        print("WA")
        print(st1)
        print(st2)
        break
