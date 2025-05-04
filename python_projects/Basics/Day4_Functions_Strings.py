"""
📌 Project: Age Classifier using Functions
📅 Day 4 of 41 – Embedded & IoT Journey

🎯 Description:
- Takes user's age as input
- Classifies age into child, teen, adult, senior
- Demonstrates function definition and return logic

🛠️ Tools:
- Python 3.x
- def, return, int(), if/elif/else, input(), try/except

Author: Ahmet Emin Yakar
"""




def classify_age(age):
    if age < 0:
        return "Invalid age."
    elif age <= 12:
        return "You are a child."
    elif age <= 19:
        return "You are a teenager."
    elif age <= 64:
        return "You are an adult."
    else:
        return "You are a senior."

try:
    user_input = input("Enter your age: ")
    age = int(user_input)
    result = classify_age(age)
    print(result)
except:
    print("Invalid input. Please enter a number.")
