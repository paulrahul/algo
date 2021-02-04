"""
https://app.codility.com/programmers/task/multivitamin/
"""

def solution(juice, capacity):
    capacity = [ (t[1] - t[0]) for t in zip(capacity, juice) ]
    max_c = max(capacity)

    juice = sorted(juice)

    # Replace juice with a running sum at each index.
    n = len(juice)
    for i in range(1, n):
        juice[i] += juice[i - 1]

    # Now return the farthest index till which max_c can go.
    i = 0
    while i < n and max_c >= juice[i]:
        i += 1

    return i + 1

if __name__ == "__main__":
    print(solution([10, 2, 1, 1], [10, 3, 2, 2]))
