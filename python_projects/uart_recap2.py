def calculate_checksum(text):

    return sum(bytearray(text.encode())) % 256


def validate_packet(payload)
    
    chcksum = calculate_checksum(payload)
    calc_checksum = int(chcksum)
    packet = f"{payload}*{calc_checksum}"
    print(packet)

