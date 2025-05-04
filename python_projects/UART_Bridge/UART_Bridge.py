import serial

PORT = 'COM3'     # UPDATE THIS TO YOUR ACTIVE PORT
BAUD = 9600

ser = serial.Serial(PORT, BAUD, timeout=1)

print("🔌 Listening to serial...")

while True:
    line = ser.readline().decode('utf-8').strip()

    if line:
        # STEP 1: Split message and checksum
        if '*' in line:
            try:
                data_part, checksum_part = line.split('*')
                received_checksum = int(checksum_part)

                # STEP 2: Calculate local checksum
                calculated_checksum = sum(ord(c) for c in data_part) % 256

                # STEP 3: Verify
                if calculated_checksum == received_checksum:
                    # Split and display values
                    parts = data_part.split(';')
                    temp = float(parts[0].split(':')[1])
                    hum = float(parts[1].split(':')[1])
                    print(f"✅ OK: Temp {temp:.1f}°C | Humidity {hum:.1f}%")
                else:
                    print(f"❌ BAD CHECKSUM: {line}")

            except Exception as e:
                print(f"⚠️ Error parsing line: {line} → {e}")
        else:
            print(f"⚠️ Invalid format (no *): {line}")
