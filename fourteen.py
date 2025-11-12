# Program: Merge Sort to sort online orders by delivery time

# Function to perform merge sort
def merge_sort(orders):
    if len(orders) > 1:
        mid = len(orders) // 2
        left_half = orders[:mid]
        right_half = orders[mid:]

        # Recursive calls
        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0

        # Merging the two halves
        while i < len(left_half) and j < len(right_half):
            if left_half[i]['delivery_time'] < right_half[j]['delivery_time']:
                orders[k] = left_half[i]
                i += 1
            else:
                orders[k] = right_half[j]
                j += 1
            k += 1

        # Copy remaining elements
        while i < len(left_half):
            orders[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            orders[k] = right_half[j]
            j += 1
            k += 1

# Main program
if _name_ == "_main_":
    # List of online orders with delivery time (in hours)
    orders = [
        {'order_id': 101, 'customer_name': 'Riya', 'delivery_time': 5},
        {'order_id': 102, 'customer_name': 'Amit', 'delivery_time': 2},
        {'order_id': 103, 'customer_name': 'Karan', 'delivery_time': 8},
        {'order_id': 104, 'customer_name': 'Sneha', 'delivery_time': 3},
        {'order_id': 105, 'customer_name': 'Priya', 'delivery_time': 6},
    ]

    print("Orders before sorting:")
    for order in orders:
        print(order)

    merge_sort(orders)

    print("\nOrders after sorting by delivery time (ascending):")
    for order in orders:
        print(order)
