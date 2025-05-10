def calc_checksum(text):
    return sum(bytearray(text.encode())) % 256

def validate_packet(line):
    try:
        payload, chckstr = line.strip().split('*')
        checksum = int(chckstr)

        calculated_checksum = calc_checksum(payload)

        print(f"Payload       : {payload}")
        print(f"Recv Checksum : {checksum}")
        print(f"Calc Checksum : {calculated_checksum}")

        if calculated_checksum == checksum:
            print("✅ VALID UART PACKET\n")
        else:
            print("❌ INVALID UART PACKET\n")

    except Exception as e:
        print(f"❗ Error: {e}\n")

# ✅ Function to generate valid packets
def generate_valid_uart(temp, hum):
    payload = f"TEMP:{temp:.1f};HUM:{hum:.1f}"
    chk = calc_checksum(payload)
    return f"{payload}*{chk}"

# 🔁 Test Cases (some auto-fixed, some corrupt)
lines = [
    generate_valid_uart(25.4, 63.2),  # ✅ auto-valid
    generate_valid_uart(21.8, 48.9),  # ✅ auto-valid
    generate_valid_uart(30.0, 60.0),  # ✅ auto-valid
    "TEMP:22.5;HUM:61.2*BAD",         # ❌ not a number
    "BROKENLINE"                      # ❌ no '*'
]

# 🔍 Run validation
for line in lines:
    validate_packet(line)
