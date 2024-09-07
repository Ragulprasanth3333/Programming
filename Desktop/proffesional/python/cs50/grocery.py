from collections import Counter as c

lis = []

while True:
    try:
        i = input().upper()
        lis.append(i)

    except EOFError:
        # Display the counts
        item_counts = c(lis)
        for item, count in item_counts.items():
            print(f"{count} {item}")
        exit(0)
