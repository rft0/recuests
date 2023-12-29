import recuests.recuests as rec

from typing import Dict, Optional

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

def get(url: str, headers: Optional[Dict[str, str]] = None) -> Response:
    r = rec.get(url, headers)

    return Response(r.body, r.status, r.headers)

def post(url: str, body: str, headers: Optional[Dict[str, str]] = None) -> Response:
    r = rec.get(url, headers, body)

    return Response(r.body, r.status, r.headers)

def put(url: str, headers: Optional[Dict[str, str]] = None) -> Response:
    r = rec.get(url, headers)

    return Response(r.body, r.status, r.headers)

def delete(url: str, headers: Optional[Dict[str, str]] = None) -> Response:
    r = rec.get(url, headers)

    return Response(r.body, r.status, r.headers)