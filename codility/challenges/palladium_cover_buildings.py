def solution(a):
    n = len(a)

    left_max_arr = [None] * n
    left_max_arr[0] = mx = a[0]
    for i in range(1, n):
        left_max_arr[i] = mx = max(mx, a[i])

    right_max_arr = [None] * n
    right_max_arr[n - 1] = mx = a[n - 1]
    for i in range(n - 2, -1, -1):
        right_max_arr[i] = mx = max(mx, a[i])

    ans = mx * n
    for p in range(1, n):
        tmp = (left_max_arr[p - 1] * p) + (right_max_arr[p] * (n - p))
        ans = min(ans, tmp)
        # print("%d %d %d\n" % (p, tmp, ans))

    return ans

if __name__ == "__main__":
    print(solution([3, 1, 4]))
    print(solution([5, 3, 2, 4]))
    print(solution([5, 3, 5, 2, 1]))
    print(solution([7, 7, 3, 7, 7]))
    print(solution([1, 1, 7, 6, 6, 6]))
    print(solution([1]))
    print(solution([1, 1, 1]))
