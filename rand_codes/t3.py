import re
stack = []
s = input()
nums = []
for i in s:
    if(i>='0' and i<='9'):
        stack.append(i)
    else:
        if(len(stack)>0):
            nums.append(int(''.join(stack)))
            stack = []
if(len(stack)>0):
    nums.append(int(''.join(stack)))
    stack = []
print(max(nums))
