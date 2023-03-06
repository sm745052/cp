import subprocess as sub
import numpy as np
sub.run("g++ ./cf1763b.cpp -o a1.out -std=c++17", shell=True)
sub.run("g++ ./code2c.cpp -o a2.out -std=c++17", shell=True)

# write testcases
st = ""
ctr = 0
for i in range(1, 100):
    for j in range(1, 100):
        ctr+=1
        st += str(i) + " " + str(j) + '\n' + ' '.join(np.random.uniform(low=1, high=100, size=(i,)).astype(int).astype(str)) + '\n' + ' '.join(np.random.uniform(low=1, high=100, size=(i,)).astype(int).astype(str)) + '\n'
st = str(ctr) + '\n' + st
with open("testcase.txt", "w") as f:
    f.write(st)

# run testcases
sub.run("./a1.out < testcase.txt > output1.txt", shell=True)
sub.run("./a2.out < testcase.txt > output2.txt", shell=True)

st1 = open("output1.txt", "r").read()
st2 = open("output2.txt", "r").read()
if st1 == st2:
    print("AC")
else:
    print("WA")
    print(st1)
    print(st2)