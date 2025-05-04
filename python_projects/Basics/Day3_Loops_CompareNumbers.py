"""
📌 Project: Min/Max Finder with Input Loop
📅 Day 3 of 41 – Embedded & IoT Journey

🎯 Description:
- Takes unlimited numeric input from the user
- Ends on 'done' keyword
- Handles invalid inputs using try/except
- Returns maximum and minimum values entered

🛠️ Tools:
- Python 3.x
- while loop, break, continue, int(), try/except

Author: Ahmet Emin Yakar
"""




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
