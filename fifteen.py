# Fractional Knapsack Problem using Greedy Approach

class Item:
    def _init_(self, value, weight):
        self.value = value
        self.weight = weight
        self.ratio = value / weight  # value-to-weight ratio


def fractional_knapsack(values, weights, capacity):
    items = []
    
    # Create list of items
    for i in range(len(values)):
        items.append(Item(values[i], weights[i]))
    
    # Sort items by value-to-weight ratio in descending order
    items.sort(key=lambda x: x.ratio, reverse=True)
    
    total_value = 0.0  # total profit
    remaining_capacity = capacity

    for item in items:
        if item.weight <= remaining_capacity:
            # If item can be fully added
            total_value += item.value
            remaining_capacity -= item.weight
        else:
            # If only a fraction of item can be added
            fraction = remaining_capacity / item.weight
            total_value += item.value * fraction
            remaining_capacity = 0
            break  # Knapsack is full
    
    return total_value


# --- Example Usage ---
values = [60, 100, 120]   # Profits
weights = [10, 20, 30]    # Weights
capacity = 50             # Maximum capacity of knapsack

max_profit = fractional_knapsack(values, weights, capacity)

print(f"Maximum profit using fractional knapsack = {max_profit:.2f}")
