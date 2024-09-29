import re

def main():
    html = input("HTML: ")
    result = parse(html)
    if result:
        print(result)

def parse(s):
    iframe_pattern = r"<iframe.*?><\/iframe>"
    iframe_match = re.search(iframe_pattern, s)
    if iframe_match:
        url_pattern = r"(http(s)*:\/\/(www\.)*youtube\.com\/embed\/)([a-zA-Z0-9_]+)"
        url_match = re.search(url_pattern, s)
        if url_match:
            return "https://youtu.be/" + url_match.group(4)

if __name__ == "__main__":
    main()
