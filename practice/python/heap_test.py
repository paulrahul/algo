import heapq
import random

def heapify(l, mx=False):
    mul = -1 if mx else 1

    h = []
    for x in l:
        if type(x) is tuple:
            t_l = list(x)
            t_l[0] = t_l[0] * mul
            n_t = tuple(t_l)
            heapq.heappush(h, n_t)    
        else:
            heapq.heappush(h, x * mul)

    minmax_str = "max" if mx else "min"
    print("Original list: %s, %s heapified list: %s" % (l, minmax_str, [heapq.heappop(h) for i in range(len(h))]))
    print()

# Generate a random list consisting numbers 1 <= n <= 10
l = []
for _ in range(10):
    l.append(random.randint(1, 10))

# Create a min heap
heapify(l)

# # Now create a max heap of this list.
heapify(l, mx=True)

# Now fill up the list with custom values.
l.clear()
l = [12, 8, 14]

# Min heap
heapify(l)

# Max heap
heapify(l, mx=True)

# Invert the list values and retry
l = [-x for x in l]
heapify(l)
heapify(l, mx=True)

# Now a tuple list with the same values.
l = [(x, chr(ord('a') + random.randint(1, 25))) for x in l]
#heapify(l)
heapify(l, mx=True)

# l = [(12, 'u'), (8, 'i'), (14, 'j')]
heapify(l, mx=True)

h = []
heapq.heappush(h, (-12, "miso"))
heapq.heappush(h, (-8, "sushi"))
heapq.heappush(h, (-14, "ramen"))
print([x for x in h])

