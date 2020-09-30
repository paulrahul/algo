'''
https://app.codility.com/programmers/task/falling_disks/
RT: O(N)
S: O(N)
'''

def solve(a, b):
    n = len(a)
    m = len(b)

    last_min_gap = [a[0]]
    for i in range(1, n):
        last_min_gap.append(min(last_min_gap[i - 1], a[i]))

    # Iterate both on a and b first pushing in the elements of a till we get an
    # element which is >= next element of b. This means b[j] can fit into
    # current a but we need to still iterate on a till we find the last_min
    # element which is >= b.
    i = n - 1
    j = 0
    while i >= 0 and j < m:
        if a[i] >= b[j]:
            while i >= 0 and last_min_gap[i] < b[j]:
                i -= 1
            # We have now found the final position for b[j], so move to next
            # element of b.
            if i >= 0:
                j += 1

        i -= 1

    return min(j, m)

if __name__ == "__main__":
    while True:
        try:
            a = [int(x) for x in raw_input().split()]
            b = [int(x) for x in raw_input().split()]

            print solve(a, b)
        except EOFError:
            break
