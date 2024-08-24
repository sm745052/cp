##  Couple Holding Hands

There are `n` couples sitting in `2n` seats arranged in a row and want to hold hands.

You are given an integer array `row` where `row[i]` is the ID of the person sitting in the `i`th seat. The couples are numbered in order, the first couple being `(0, 1)`, the second couple being `(2, 3)`, and so on with the last couple being `(2n - 2, 2n - 1)`.

Return the **minimum** number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

**Example 1:**

```
Input: row = [0,2,1,3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
```

**Example 2:**

```
Input: row = [3,2,0,1]
Output: 0
Explanation: All couples are already seated side by side.
```

**Constraints:**

* `2n == row.length`
* `2 <= n <= 30`
* `n` is even.
* `0 <= row[i] < 2n`
* All the elements of `row` are unique. 


### Solution

**Observations:**

1. Any swap that does not correct the position of at least one pair is inconsequential and should not be pursued.
2. If we represent each couple as a vertex (e.g., `(0, 1)` -> `A`, `(2, 3)` -> `B`), then each vertex will have exactly two edges.
3. Couples can only occupy positions like `[0, 1]`, `[2, 3]`, and not `[1, 2]`.
4. Only cycles can exist in a graph formed by connecting adjacent people from different couples. This is because all vertices have two edges that are always connected. For example, in the array `[0, 2, 3, 1]`, the graph has edges `A - B` and `B - A`.
5. Swapping elements must result in at least one more self-loop than before (refer to observation 1).
6. A swap can transform an `n`-member cycle into an `n-1` member cycle, regardless of which couple gets corrected. This continues until we reach a 2-member cycle, where a single swap corrects both members simultaneously.
7. Therefore, a greedy approach is effective. We can iterate over position buckets like `[0, 1]`, `[2, 3]` and check if the second element in the bucket is the complement of the first element. If so, we perform a swap to correct the current bucket, placing the couple to which the first element belongs. 
