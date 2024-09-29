def main():
    i = input("Input: ")
    without_vowels = shorten(i)
    print("Output: " + without_vowels)


def shorten(word):
    wwv = ""
    for letter in word:
        if not letter.lower() in ['a', 'e', 'i', 'o', 'u']:
            wwv += letter
    return wwv


if __name__ == "__main__":
    main()