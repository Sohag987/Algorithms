# This is recursiveapproach for solvin DP 
def _01_knapsack(items: list, W: int, n: int):
    include: int = 0
    exclude: int = 0

    if n == 0 or W == 0:
        return 0

    weight: int = items[n - 1][0]
    value: int = items[n - 1][1]

    if weight <= W:
        include = value + _01_knapsack(
            items,
            W - weight,
            n - 1
        )

        exclude = _01_knapsack(
            items,
            W,
            n - 1
        )

        result = max(include, exclude)
        return result

    else:
        return _01_knapsack(items, W, n - 1)


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

    print(_01_knapsack(items, capacity, n))