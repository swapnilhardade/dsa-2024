n = int(input("Enter number of items: "))
weights = []
profits = []

for i in range(n):
    print(f"\nEnter details for item {i+1}:")
    w = float(input("Weight: "))
    p = float(input("Profit: "))
    weights.append(w)
    profits.append(p)

capacity = float(input("\nEnter knapsack capacity: "))

ratio = [(profits[i]/weights[i], weights[i], profits[i]) for i in range(n)]
ratio.sort(reverse=True)

total_profit = 0
remain = capacity
print("\nItems considered (in order of profit/weight ratio):")
for r, w, p in ratio:
    if remain == 0:
        break
    if w <= remain:
        print(f"Take full item with weight {w} and profit {p}")
        remain -= w
        total_profit += p
    else:
        print(f"Take {remain} of item with weight {w} and profit {p}")
        total_profit += r * remain
        remain = 0

print("\nMaximum Profit =", total_profit)
