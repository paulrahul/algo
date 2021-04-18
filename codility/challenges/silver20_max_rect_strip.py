from collections import defaultdict

def solution(A, B):
    side_rect_count = defaultdict(int)

    n = len(A)
    ans = 1
    for i in range(n):
        l = A[i]
        b = B[i]

        if l == b:
            side_rect_count[l] += 1
        else:
            side_rect_count[l] += 1
            side_rect_count[b] += 1

        ans = max(ans, side_rect_count[l], side_rect_count[b])

    return ans

if __name__ == "__main__":
    print(solution([2, 3, 2, 3, 5], [3, 4, 2, 4, 2]))
    print(solution([2, 3, 1, 3], [2, 3, 1, 3]))
    print(solution([2, 10, 4, 1, 4], [4, 1, 2, 2, 5]))
