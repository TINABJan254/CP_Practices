MAX_LEN = 61
C = [[0] * MAX_LEN for _ in range(MAX_LEN)]


def tohop():
    for n in range(MAX_LEN):
        C[n][0] = 1  # C(n, 0) = 1
        for k in range(1, n + 1):
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k]


def solve():
    try:
        A, B, K = map(int, input().split())
    except (ValueError, EOFError):
        return

    rem_a = A
    rem_b = B
    result = []
    for _ in range(A + B):
        if rem_a == 0:
            result.append('b')
            rem_b -= 1
            continue
        if rem_b == 0:
            result.append('a')
            rem_a -= 1
            continue
        combinations_with_a = C[rem_a - 1 + rem_b][rem_a - 1]

        if K <= combinations_with_a:
            result.append('a')
            rem_a -= 1
        else:
            K -= combinations_with_a
            result.append('b')
            rem_b -= 1

    print("".join(result))

tohop()


solve()
# b9