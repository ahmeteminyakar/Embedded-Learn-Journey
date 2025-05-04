"""
📌 Project: Conditional Logic – Number Comparison
📅 Day 2 of 41 – Embedded & IoT Journey

🎯 Description:
- Asks the user to enter 3 numbers
- Checks if all or two of them are equal
- Prints the largest and smallest number

🛠️ Tools:
- Python 3.x
- Functions used: input(), float(), if/elif/else, max(), min()

Author: Ahmet Emin Yakar
"""


# Get input from the user
num1 = input("First number: ")
num2 = input("Second number: ")
num3 = input("Third number: ")

# Convert inputs to float
n1 = float(num1)
n2 = float(num2)
n3 = float(num3)

# Check if all numbers are equal
if n1 == n2 == n3:
    print("All numbers are equal.")

# Check if only two numbers are equal
elif n1 == n2 or n1 == n3 or n2 == n3:
    print("Two numbers are equal.")

# If all numbers are different
else:
    biggest_number = max(n1, n2, n3)
    smallest_number = min(n1, n2, n3)
    print("The biggest number is:", biggest_number)
    print("The smallest number is:", smallest_number)
