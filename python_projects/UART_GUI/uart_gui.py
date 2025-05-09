import tkinter as tk


def calculate_checksum(text):

    chcksum= sum(bytearray(text.encode()))%256
    return chcksum
    

def gen_valid_uart(temp,hum):
    # Generate a valid UART message
    payload = f"TEMP:{temp:.1f};HUM:{hum:.1f}"
    calc_cheksum = calculate_checksum(payload)
    return f"{payload}*{calc_cheksum}"

def validate_and_display(line):
    try:
        payload, chcksum = line.strip().split("*")
        rcv_chcksum = int(chcksum)
    
        if calculate_checksum(payload) == rcv_chcksum:
            label.config(text=payload , fg="green") 
        else :
            label.config(text= "MISMATCH!", fg= "red")
    except:
        label.config(text= "FORMAT ERROR", fg= "red")



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
    global index

    if index<len(test_lines):
        line = test_lines[index]
        print(f"Simulated UART: {line}")

        validate_and_display(line)
        index +=1
    root.after(1000, simulate_uart)

simulate_uart()
root.mainloop()