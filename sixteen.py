# Naive String Matching Algorithm

def naive_string_match(text, pattern):
    n = len(text)
    m = len(pattern)
    occurrences = []

    # Check pattern at every possible position in text
    for i in range(n - m + 1):
        match = True
        for j in range(m):
            if text[i + j] != pattern[j]:
                match = False
                break
        if match:
            occurrences.append(i)

    return occurrences


# Main Program
if _name_ == "_main_":
    text = input("Enter the text: ")
    pattern = input("Enter the pattern to search: ")

    result = naive_string_match(text, pattern)

    if result:
        print(f"Pattern found at positions: {result}")
    else:
        print("Pattern not found in the given text.")
