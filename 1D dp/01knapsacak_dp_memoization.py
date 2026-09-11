def _01_knapsack_memoization(items: list, W: int, n: int,dp:list):
    include: int = 0
    exclude: int = 0

    if n == 0 or W == 0:
        return 0

    if dp[n][W] != -1:
        return dp[n][W] 

    weight: int = items[n - 1][0]
    value: int = items[n - 1][1]

    if weight <= W:
        include = value + _01_knapsack_memoization(
            items,
            W - weight,
            n - 1,dp
        )

        exclude = _01_knapsack_memoization(
            items,
            W,
            n - 1,dp
        )

        result = max(include, exclude)
        return result

    else:
        return _01_knapsack_memoization(items, W, n - 1,dp)


if __name__ == "__main__":
    items: list = [
        [3, 40],
        [5, 90],
        [3, 78],
        [1, 20],
        [5, 90]
    ]

    capacity: int = 15
    n: int = len(items)

    dp = [[-1]*(capacity+1) for _ in range(n+1)]

    print(_01_knapsack_memoization(items, capacity, n,dp))