def solve(a, b):
    # Iterate both on a and b first pushing in the elements of a till we get an
    # element which is >= next element of b.

    n = len(a)
    m = len(b)

    i = n - 1
    j = 0
    while i >= 0 and j < m:
        if a[i] >= b[j]:
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