'''
https://app.codility.com/programmers/task/max_path_from_the_left_top_corner/
'''

def get_neigbour_score(aux_pos, m, n, r, c):
    l = []
    if r == m - 1 and c < n  - 1:
        l.append(aux_pos[r][c+1])
    elif r < m - 1 and c == n - 1:
        l.append(aux_pos[r + 1][c])
    else:
        l.append(aux_pos[r][c + 1])
        l.append(aux_pos[r + 1][c])

    return l


def get_min_neighbour(aux_pos, m, n, r, c):
    return min(get_neigbour_score(aux_pos, m, n, r, c))

def process_diagonal(A, m, n, r, c, aux_pos):
    m = len(A)
    n = len(A[0])

    # The indices in consideration are:
    # A[r][c], A[r - 1][c + 1], A[r - 2][c + 2]....A[0][n]
    l = []
    r1 = r
    c1 = c
    while r1 >= 0 and c1 < n:
        l.append((A[r1][c1], r1 * n + c1))
        r1 -= 1
        c1 += 1

    #print("column diagonal list for %d,%d: %s" % (r, c, l))

    # Now sort (descending) l based on the value first, then neighbouring
    # values.
    llen = len(l)
    for j in range(0, llen -1):
        for k in range(j + 1, llen):
            swap = (l[k][0] > l[j][0])
            if l[k][0] == l[j][0]:
                # Check neighbours.
                n_pos1 = get_min_neighbour(
                        aux_pos, m, n, l[k][1] // n, l[k][1] % n)
                n_pos2 = get_min_neighbour(
                        aux_pos, m, n, l[j][1] // n, l[j][1] % n)

                swap = (n_pos1 < n_pos2)

            if swap:
                tmp = l[j]
                l[j] = l[k]
                l[k] = tmp

    r1 = r
    c1 = c
    k = 0
    while r1 >= 0 and c1 < n:
        val = l[k][0]
        orig_r = l[k][1] // n
        orig_c = l[k][1] % n

        aux_pos[orig_r][orig_c] = k

        k += 1
        r1 -= 1
        c1 += 1

    #print("column diagonal list for %d,%d: %s" % (r, c, l))

def solution(A):
    m = len(A)
    n = len(A[0])

    # Position of each element in the matrix in the sorted list of its
    # diagonal.
    aux_pos = [[-1 for x in range(n)] for y in range(m)]

    # Start from the bottom-right and take each diagonal.
    for i in range(n):
        c = n - 1 - i
        process_diagonal(A, m, n, m - 1, c, aux_pos)

    for i in range(m - 1):
        r = m - 2 - i
        process_diagonal(A, m, n, r, 0, aux_pos)


    #print(aux_pos)

    ans = ""
    r = 0
    c = 0
    while True:
        ans += str(A[r][c])

        if r == m - 1 and c == n - 1:
            break

        if r == m - 1 and c < n - 1:
            c += 1
        elif r < m - 1 and c == n - 1:
            r += 1
        else:
            if aux_pos[r][c + 1] < aux_pos[r + 1][c]:
                c += 1
            else:
                r += 1

    return ans

if __name__ == "__main__":
    print(solution(
        [
            [9, 9, 7],
            [9, 7, 2],
            [6, 9, 5],
            [9, 1, 2]
        ]
    ))

    print(solution(
        [
            [9],
        ]
    ))

    print(solution(
        [
            [9, 9, 9],
            [9, 9, 9],
            [9, 9, 9],
            [9, 9, 9]
        ]
    ))

    print(solution(
        [
            [9, 9, 9],
            [9, 9, 9],
            [9, 9, 5],
            [9, 1, 2]
        ]
    ))
