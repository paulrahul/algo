'''
https://app.codility.com/programmers/task/max_path_from_the_left_top_corner/
'''

def find_prev_max(A, n, aux, idx1, idx2):
    if idx1 == idx2:
        return idx1 // n, idx1 % n

    r1 = idx1 // n
    c1 = idx1 % n

    r2 = idx2 // n
    c2 = idx2 % n

    if A[r1][c1] == A[r2][c2]:
        return find_prev_max(A, n, aux, aux[r1][c1], aux[r2][c2])
    else:
        if A[r1][c1] > A[r2][c2]:
            return r1, c1
        else:
            return r2, c2


def solution(A):
    m = len(A)
    n = len(A[0])

    aux = [[-1 for x in range(n)] for y in range(m)]

    # Start from the bottom-right.
    for i in range(m):
        for j in range(n):
            r = m - 1 - i
            c = n - 1 - j

            aux_r = -1
            aux_c = -1
            # Compare the two neighbours.
            if r == m - 1 and c == n - 1:
                aux_r = r
                aux_c = c
            elif r == m - 1 and c < n - 1:
                aux_r = r
                aux_c = c + 1
            elif r < m - 1 and c == n - 1:
                aux_r = r + 1
                aux_c = c
            else:
                if A[r][c + 1] == A[r + 1][c]:
                    aux_r, aux_c = find_prev_max(
                        A, n, aux, aux[r][c + 1], aux[r + 1][c])
                else:
                    if A[r][c + 1] > A[r + 1][c]:
                        aux_r = r
                        aux_c = c + 1
                    else:
                        aux_r = r + 1
                        aux_c = c

            #print("changing %d %d to %d\n" % (r, c, aux_r*n+aux_c))
            #aux[r][c] = aux[aux_r][aux_c]
            aux[r][c] = aux_r * n + aux_c
            #print(aux)

    aux[m - 1][n - 1] = -1

    # Construct the number by traversing aux from top-left to right-bottom.
    r = c = 0
    ans = ""
    while True:
        ans += str(A[r][c])

        idx = aux[r][c]
        r = idx // n
        c = idx % n

        if r < 0:
            break        
    print(aux)

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

