lim = 10 ** 18
a = 0
b = 1

f = a + b
fibs = [f]
while f < lim:
    a = b
    b = f
    f = a + b
    fibs.append(f)

print f

# Generate all prime numbers in an array up to lim / 2

# For each input number, iterate through all fibs <= num / 2 to check if they
# divide. 

# Else, start multiplying num by increasing prime numbers to find if any of them
# is a fibonacci number.


# FUCK!
# Factorize num and see if any of them divides any of the fibs or not.