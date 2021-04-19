'''
Solution for https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

Correctness - 100%

Complexity:
R - O(1)
S - 0(1)
'''

def Solution(n):
    gap_started = False
    ans = 0

    curr_count = 0
    while n:
        curr = n & 1
        if curr:
            if gap_started:
                ans = max(ans, curr_count)
            else:
                gap_started = True
            
            curr_count = 0
        else:
            curr_count += 1

        n >>= 1

    return ans

if __name__ == "__main__":
    print(Solution(1041))
    print(Solution(32))
    print(Solution(529))
    print(Solution(9))
    print(Solution(20))
    print(Solution(15))
    print(Solution(1))
    print(Solution(2))