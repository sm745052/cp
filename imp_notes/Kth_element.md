# To find the Kth element from a list of numbers.
# 1 [Divide and conquer. no add,  update, delete queries handled.]
-> sort the array \
-> use divide and conquer. Like divide array into 2. see if left contains more than k elements then search kth element in left subarray else search k minus (number of elements in left subarray) th element in right subarray. \
-> if number of elements in array is one, return the number. \
-> Time complexity: O(nlogn) [sorting] + q * O(logn) [queries] 
# 2 [multiset. update, delete, add handled]
-> add all elements to multiset \
-> do a binary search over min(elements of array) to max(min(elements of array)) and see the number of elements below it. \
-> use upper_bound, lower_bound for it.
->Time complexity: o(nlogn) build the set, check in binary search -> O(logn), binary search would take O((logn)^2). Hence, O(nlogn) + q * O((logn)^2)]
# 3 [Segment Tree. update, delete, add handled]
-> make count array of all numbers.[use compression of max is huge] \
-> build segment tree of range sum over it. \
-> do a binary search over min(elements of array) to max(min(elements of array)) and see the number of elements below it using segment tree query. \
->Time complexity: O(nlogn) build the segment tree, check in binary search -> O(logn), binary search would take O((logn)^2). Hence, O(nlogn) + q * O((logn)^2) 
# 4 [BEST, Segment Tree. update, delete, add handled]
-> make count array of all numbers.[use compression of max is huge] \
-> build segment tree of range sum over it. \
-> make a function  that uses divide and conquer technique i.e. see the left child, right child and traverse accordingly. \
-> Here each query is O(log n). \
-> Time complexity: O(nlogn) + q * O(logn)
