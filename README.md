## Recuests
Python bindings for my [HTTP client](https://github.com/epsilonr/httpclient) as its name implies it have `requests` like interface.

### Struct of Response
```py
class Response:
    def __init__(self, body: str, status: int, headers: dict):
        self.body = body
        self.headers = headers
        self.status = status

    def json(self) -> dict:
        return self.body

    def __str__(self) -> str:
        return self.body

    def __repr__(self) -> str:
        return f"<Response {self.status}>"
```


### Methods
```py
def get(url: str, headers: Optional[Dict[str, str]] = None) -> Response:
    r = rec.get(url, headers)

    return Response(r.body, r.status, r.headers)

def post(url: str, headers: Optional[Dict[str, str]] = None, data: str = "") -> Response:
    r = rec.post(url, headers, data)

    return Response(r.body, r.status, r.headers)

def put(url: str, headers: Optional[Dict[str, str]] = None, data: str = "") -> Response:
    r = rec.put(url, headers, data)

    return Response(r.body, r.status, r.headers)

def delete(url: str, headers: Optional[Dict[str, str]] = None) -> Response:
    r = rec.delete(url, headers)

    return Response(r.body, r.status, r.headers)
```