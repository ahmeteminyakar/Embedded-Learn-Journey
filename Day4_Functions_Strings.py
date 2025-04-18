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
