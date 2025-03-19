arr = [4, 2, 5, 7, 8, 6]
key = 5
found = False

for i in range (len(arr)):
    if arr[i] == key:
        print(f"Element {key} found at position {i}")
        found = True
        break

if not found:
    print(f"element {key} not found")
