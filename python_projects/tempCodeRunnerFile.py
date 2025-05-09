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

# 🔁 Test Cases
lines = [
    "TEMP:25.4;HUM:63.2*184",  # ✅ now valid
    "TEMP:21.8;HUM:48.9*192",  # ✅ corrected
    "TEMP:30.0;HUM:60.0*195",  # ✅ corrected
    "TEMP:22.5;HUM:61.2*BAD",  # ❌ not a number
    "BROKENLINE"               # ❌ no '*'
]


for line in lines:
    validate_packet(line)
