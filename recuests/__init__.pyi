from typing import Dict, Optional, overload, final

@final
class Response:
    body: str
    headers: dict
    status: int

@overload
def get(url: str, headers: Optional[Dict[str, str]] = None) -> Response:
    pass

@overload
def post(url: str, headers: Optional[Dict[str, str]] = None, data: str = "") -> Response:
    pass

@overload
def put(url: str, headers: Optional[Dict[str, str]] = None, data: str = "") -> Response:
    pass

@overload
def delete(url: str, headers: Optional[Dict[str, str]] = None) -> Response:
    pass