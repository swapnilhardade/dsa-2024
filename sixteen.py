text = input("Enter the text: ")
pattern = input("Enter the pattern to search: ")

n = len(text)
m = len(pattern)
positions = []

for i in range(n - m + 1):
    if text[i:i+m] == pattern:
        positions.append(i)

if positions:
    print("\nPattern found at positions:", positions)
    print("Total occurrences:", len(positions))
else:
    print("\nPattern not found in the text.")
