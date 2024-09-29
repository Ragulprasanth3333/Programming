from twttr import shorten


def main():
    test_letter()
    test_num()
    test_punc()


def test_letter():
    assert shorten("apple") == "ppl"
    assert shorten("BANANA") == "BNN"
    assert shorten("OrAnGe") == "rnG"


def test_num():
    assert shorten("1234") == "1234"


def test_punc():
    assert shorten("!?.,") == "!?.,"


if __name__ == "__main__":
    main()