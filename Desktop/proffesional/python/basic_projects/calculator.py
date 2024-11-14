import tkinter as tk

# Create the main application window
root = tk.Tk()
root.title(" just a Calculator")

# Entry widget to display expressions
entry = tk.Entry(root, width=35, borderwidth=5)
entry.grid(row=0, column=0, columnspan=5)

# Function to handle button clicks
def button_click(value):
    current = entry.get()
    entry.delete(0, tk.END)
    entry.insert(0, current + str(value))

# Function to clear the entry widget
def button_clear():
    entry.delete(0, tk.END)

# Function to evaluate the expression
def button_equal():
    try:
        result = eval(entry.get())
        entry.delete(0, tk.END)
        entry.insert(0, str(result))
    except Exception as e:
        entry.delete(0, tk.END)
        entry.insert(0, "Error")

# Button layout
buttons = [
    ('7', 1, 0), ('8', 1, 1), ('9', 1, 2), ('/', 1, 3),
    ('4', 2, 0), ('5', 2, 1), ('6', 2, 2), ('*', 2, 3),
    ('1', 3, 0), ('2', 3, 1), ('3', 3, 2), ('-', 3, 3),
    ('0', 4, 0), ('.', 4, 1), ('+', 4, 2), ('=', 4, 3),
]

# Adjust the button layout to include a larger font size
for (text, row, col) in buttons:
    if text == '=':
        tk.Button(root, text=text, width=10, height=2, font=("Helvetica", 20), command=button_equal).grid(row=row, column=col)
    else:
        tk.Button(root, text=text, width=10, height=2, font=("Helvetica", 20), command=lambda t=text: button_click(t)).grid(row=row, column=col)

# Clear button with larger font
tk.Button(root, text='C', width=10, height=2, font=("Helvetica", 20), command=button_clear).grid(row=5, column=0, columnspan=4)

# Run the application
root.mainloop()
