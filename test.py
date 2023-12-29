from recuests import get

if __name__ == "__main__":
    headers = { "user-agent": "rafbot" }
    r = get("http://localhost:8000")