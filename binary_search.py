def binary_search(list_to_search, search_element):
    """Performs binary search on a sorted list."""
    low = 0
    high = len(list_to_search) - 1
    position = -1  # Initialize position to -1 (not found)

    while low <= high:
        mid = (low + high) // 2  # Calculate the middle index (integer division)

        if list_to_search[mid] == search_element:
            position = mid
            break
        elif list_to_search[mid] < search_element:
            low = mid + 1
        else:
            high = mid - 1

    return position

# Example usage
list_to_search = [4, 6, 3, 7, 9, 2, 1]
search_element = 6

# Sort the list (binary search requires a sorted list)
list_to_search.sort()

print("Sorted List:", list_to_search)

position = binary_search(list_to_search, search_element)

if position != -1:
    print(f"Element {search_element} found at position {position}.")
else:
    print(f"Element {search_element} not found in the list.")
