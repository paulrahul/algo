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

    # Merge the two arrays.
    i = 0
    j = 0

    ans = 1 # Mixing with no one else, so 1 count for self.
    while i < n and j < n:
        if juice_sum[i] <= capacity[j][0]:
            i += 1
        else:
            juice_idx = j_idx[capacity[j][1]]
            if juice_idx >= i:
                ans = max(ans, i + 1)
                # i for the other juices to be mixed and +1 for the container
                # "hosting" those other juices since all of them are exclusive.
            else:
                # "Host" itself is one of the juices to be mixed. So we can not
                # double add that juice. Hence, we'll subtract that juice
                # quantity from the sum first, and then see if a further juice
                # could be added.
                # We need to see how further ahead, capacity could have been
                # placed, now that we need to remove juice[juice_idx]. BTW, it
                # can go further by only one index since anything at >=i will
                # be >= juice[juice_idx]. So the difference left will not be
                # able to accommodate any more element.
                depleted_sum = juice_sum[i] - juice[juice_idx][0]
                if (i + 1 < n and depleted_sum + juice[i + 1][0] <=
                    capacity[j][0]):
                    # Again, "host" is exclusive from all other juices added,
                    # hence i + 1 as explained above.
                    ans = max(ans, i + 1)
                else:
                    # "Host" is one of the juices added.
                    ans = max(ans, i)

            j += 1

    if j < n:
        # That means all juices can be used.
        ans = i + 1

    return ans

if __name__ == "__main__":
    print(solution([10, 2, 1, 1], [10, 3, 2, 2]))
    print(solution([1, 2, 3, 4], [3, 6, 4, 4]))
    print(solution([2, 3], [3, 4]))
    print(solution([1, 1, 5], [6, 5, 8]))
