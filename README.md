## Recuests
Python bindings for my [HTTP client](https://github.com/epsilonr/httpclient) as its name implies it have `requests` like interface.

### Struct of Response
```py
@final
class Response:
    body: str
    headers: dict
    status: int
```


### Methods
All methods are overloaded by C library.

```py
def get(url: str, headers: Optional[Dict[str, str]] = None) -> Response:

def post(url: str, headers: Optional[Dict[str, str]] = None, data: str = "") -> Response:

def put(url: str, headers: Optional[Dict[str, str]] = None, data: str = "") -> Response:

def delete(url: str, headers: Optional[Dict[str, str]] = None) -> Response:
```

### Requirements
* Precompiled binaries only for linux (yet you can still generate yours with make)
* Only tested with python 3.11