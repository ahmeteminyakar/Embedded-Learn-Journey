from datetime import datetime

co2 = 805.5
timestamp = datetime.now().strftime("%H:%M:%S")

with open("co2_log.csv", "a") as f:
    f.write(f"{timestamp},{co2}\n")

print("✅ CO2 reading logged.")
