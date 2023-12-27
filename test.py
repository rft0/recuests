from recuests import get

if __name__ == "__main__":
    res = get("https://www.google.com")
    print(res["body"])