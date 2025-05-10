import tkinter as tk
from enum import Enum

class FSMState(Enum):
    WAIT = 0
    VALID = 1
    ERROR = 2

current_state = FSMState.WAIT


def calculate_checksum(text):

    chcksum= sum(bytearray(text.encode()))%256
    return chcksum
    

def gen_valid_uart(temp,hum):
    # Generate a valid UART message
    payload = f"TEMP:{temp:.1f};HUM:{hum:.1f}"
    calc_cheksum = calculate_checksum(payload)
    return f"{payload}*{calc_cheksum}"

def validate_and_display(line):
    global current_state
    try:
        payload, chksum = line.strip().split("*")
        rcv_chcksum = int(chksum)
        calc = calculate_checksum(payload)

        if rcv_chcksum == calc:
            current_state = FSMState.VALID
            label.config(text=f"[{current_state.name}] {payload}", fg="green")
        else:
            current_state = FSMState.ERROR
            label.config(text=f"[{current_state.name}] MISMATCH!", fg="red")
    except:
        current_state = FSMState.ERROR
        label.config(text=f"[{current_state.name}] FORMAT ERROR", fg="orange")



test_lines = [

    gen_valid_uart(24.2,55),
    gen_valid_uart(38,34),
    gen_valid_uart(29.8,43.6),
    "TEMP:34.3;HUM:56.1*255"
]

index=  0

root = tk.Tk()

root.title = ("UART_GUI")

label = tk.Label(root , text ="WAITING..." , font = ("Courier", 18), fg="black")

label.pack(padx=30 , pady=30)


def simulate_uart():
    global index, current_state

    if index < len(test_lines):
        # BEFORE the packet: enter WAIT state
        current_state = FSMState.WAIT
        label.config(text=f"[{current_state.name}] Waiting...", fg="black")

        # Simulate delay + process next packet
        line = test_lines[index]
        print(f"Simulated UART: {line}")
        validate_and_display(line)
        index += 1

    root.after(1000, simulate_uart)

simulate_uart()
root.mainloop()