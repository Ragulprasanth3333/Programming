# Input
investment_amount = float(input("Enter the amount: "))
years = int(input("Enter the number of years: "))
rate = float(input("Enter the interest rate: "))

# Convert rate to decimal
rate = rate / 100

# Initialize result variables
total_interest = 0.0

# Display the header of the table
print("%4s%18s%10s%16s" % ("Year", "Starting balance", "Interest", "Ending balance"))

# Processing the data
for year in range(1, years + 1):
    interest = investment_amount * rate
    end_balance = investment_amount + interest
    print("%4d%18.2f%10.2f%16.2f" % (year, investment_amount, interest, end_balance))

# Update variables for the next iteration
investment_amount = end_balance
total_interest += interest

# Print the total interest and ending balance
print("Ending balance: $%.2f" % end_balance)
print("Total interest earned: $%.2f" % total_interest)
