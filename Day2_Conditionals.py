"""
Day 2 – Conditional Statements Project (Advanced)
Author: Ahmet E. Yakar
Date: April 15, 2025

This script asks the user to enter 3 numbers and:
- Checks if all three are equal
- Checks if only two are equal
- Otherwise, prints the largest and smallest numbers
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
