'''
https://app.codility.com/programmers/task/max_path_from_the_left_top_corner/
'''

from functools import cmp_to_key

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

# l is [ (min_neighbour_val, coord), ... ]
def count_sort(l):
    llen = len(l)

    m = max(l, key=lambda item:item[0])[0]
    carr = [0] * (m + 1)

    #print("max for %s is %d\n" % (l, m))

    for i in range(llen):
        carr[l[i][0]] += 1

    for i in range(1, m + 1):
        carr[i] += carr[i - 1]

    #print("carr for %s is %s\n" % (l, carr))

    out = [None] * llen
    for i in range(llen):
        pos = carr[l[i][0]] - 1
        out[pos] = l[i]
        carr[l[i][0]] -= 1

    #print("out for %s is %s\n" % (l, out))

    return out

def process_diagonal(A, m, n, r, c, aux_pos):
    m = len(A)
    n = len(A[0])

    # The indices in consideration are:
    # A[r][c], A[r - 1][c + 1], A[r - 2][c + 2]....A[0][n]
    d_map = {}
    r1 = r
    c1 = c
    while r1 >= 0 and c1 < n:
        val = A[r1][c1]
        if val in d_map:
            d_map[val].append(r1 * n + c1)
        else:
            d_map[val] = [r1 * n + c1]
        r1 -= 1
        c1 += 1

    #print("column diagonal list for %d,%d: %s" % (r, c, d_map))

    def cmp(coord1, coord2):
        # Check neighbours.
        n_pos1 = get_min_neighbour(
                aux_pos, m, n, coord1 // n, coord1 % n)
        n_pos2 = get_min_neighbour(
                aux_pos, m, n, coord2 // n, coord2 % n)

        return n_pos1 - n_pos2


    # Now sort (descending) l based on neighbouring values.
    for k, v in d_map.items():
        lv = len(v)
        if lv > 1:
            for i in range(lv):
                sort_list = ([
                    (get_min_neighbour(aux_pos, m, n, x // n, x % n), x) for x in
                    v])
            sort_list = count_sort(sort_list)
            d_map[k] = [x[1] for x in sort_list]

    # Now flatten the list by iterating from 9 to 1, taking each key's
    # elements from the respective list in order.
    flat_list = []
    for key in range(9, 0, -1):
        if not key in d_map:
            continue
        llen = len(d_map[key])
        for i in range(llen):
            flat_list.append((key, d_map[key][i]))

    r1 = r
    c1 = c
    k = 0
    while r1 >= 0 and c1 < n:
        val = flat_list[k][0]
        orig_r = flat_list[k][1] // n
        orig_c = flat_list[k][1] % n

        aux_pos[orig_r][orig_c] = k

        k += 1
        r1 -= 1
        c1 += 1

    #print("column diagonal list for %d,%d: %s" % (r, c, flat_list))

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
