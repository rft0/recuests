from recuests import post

if __name__ == "__main__":
    headers = { "user-agent": "gbot" }
    r = post("http://localhost:8000")
    print(r.body)