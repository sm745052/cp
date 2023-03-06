from functools import cmp_to_key


s = input()
freq = {}
for i in s:
    if(i in freq):
        freq[i] += 1
    else:
        freq[i] = 1
#custom compare function
def f(a, b):
    if(freq[a] == freq[b]):
        return ord(a)-ord(b)
    return freq[b]-freq[a]
#sort the keys of the dictionary
keys = list(freq.keys())
keys.sort(key=cmp_to_key(f))
# print(keys)
# print(list(freq[i] for i in keys))
for i in keys:
    if(freq[i]>3):
        print(i, end='')
print()