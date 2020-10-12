import random

def generate_input():
    # Each test case has this format:
    # Multiple lines of "[R|G|B] x1 y1 x2 y2...."" where 0 <= x, y < 100
    #
    # Test cases are separated by a blank line.

    num_test_cases = random.randint(1, 8)

    for tc in range(num_test_cases):
        for col in ["Red", "Green", "Blue"]:
            input_str = col + " "
            num_coords = random.randrange(1, 10)

            for _ in range(num_coords):
                x = random.randrange(100)
                y = random.randint(x + 1, 100)

                input_str += "%d %d " % (x, y)

            print input_str

        if tc < num_test_cases - 1:
            print

if __name__ == "__main__":
    generate_input()