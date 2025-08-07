import math
def solve():
    try:
        a = int(input())
    except (ValueError, EOFError):
        return
    target = 2 * a * a

    found = False
    for b in range(1, a):
        c_squared = target - b * b
        if c_squared <= 0:
            continue
        c = math.isqrt(c_squared)

        if c * c == c_squared:
            if c <= 100000:
                found = True
                break
    if found:
        print("YES")
    else:
        print("NO")
solve()

# b10