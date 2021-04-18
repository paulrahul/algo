"""
https://app.codility.com/programmers/task/multivitamin/
"""

def solution(juice, capacity):
    n = len(juice)

    for i in range(n):
        capacity[i] = (capacity[i] - juice[i], i)
        juice[i] = (juice[i], i)

    capacity.sort()
    juice.sort()

    j_idx = [None] * n
    for i in range(n):
        j_idx[juice[i][1]] = i

    # Replace juice with a running sum at each index.
    juice_sum = [None] * n
    juice_sum[0] = juice[0][0]
    for i in range(1, n):
        juice_sum[i] = juice[i - 1][0] + juice[i][0]


    # For each capacity, find the max juice_sum possible without including
    # itself.
    ans = 1

    next_cap_idx = 0
    i = -1
    while i < n and next_cap_idx < n:
        while i + 1 < n  and juice_sum[i + 1] <= capacity[next_cap_idx][0]:
            i += 1
            continue

        # So all juices upto i are eligible for capacity[next_cap_idx].
        # Let's check if the capacity jug itself is included in the juices list
        # or not.
        juice_idx = j_idx[capacity[next_cap_idx][1]]

        if juice[juice_idx][0] > capacity[next_cap_idx][0]:
            ans = max(ans, i + 2) 
            # Since i is 0-indexed, i + 1 juice glasses, and +1 for the
            # capacity glass itself which is exclusive.
        else:
            # So the capacity glass itself is involved in the mixing which is
            # not possible. So we need to see if the next min juice glass can
            # be used or not for this capacity.
            if i + 1  < n:
                next_min_juice = juice[i + 1][0]
                depleted_sum = juice_sum[i] - juice[juice_idx][0]
                if depleted_sum + next_min_juice <= capacity[next_cap_idx][0]:
                    ans = max(ans, i + 2)
                else:
                    ans = max(ans, i + 1)
            else:
                ans = max(ans, i + 1)

        next_cap_idx += 1

    if i == n and next_cap_idx < n:
        # So we still have some capacities which can hold basically all other
        # juices. Hence ans is the max possible, which is n.
        ans = n
    elif i < n and next_cap_idx == n:
        # So some juice glasses are still left but they have more juice than
        # any available capacity or they can not be clubbed with any other
        # juice leading to a higher ans. Hence, do nothing.
        pass

    return ans

if __name__ == "__main__":
    print(solution([10, 2, 1, 1], [10, 3, 2, 2]))
    print(solution([1, 2, 3, 4], [3, 6, 4, 4]))
    print(solution([2, 3], [3, 4]))
    print(solution([1, 1, 5], [6, 5, 8]))
    print(solution([1, 1, 1], [6, 6, 6]))
