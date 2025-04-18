def get_min_max():
    largest = None
    smallest = None

    while True:
        num = input("Enter a number: ")

        if num == "done":
            break

        try:
            n = int(num)
        except:
            print("Invalid input")
            continue

        if largest is None or n > largest:
            largest = n
        if smallest is None or n < smallest:
            smallest = n

    return (smallest, largest)

# Çıktı yazdır
min_val, max_val = get_min_max()
print("Maximum is", max_val)
print("Minimum is", min_val)
