from recuests import get

if __name__ == "__main__":
    headers: dict = { "user-agent": "rafbot" }
    r = get("http://localhost:8000", headers)
    print(r.headers)