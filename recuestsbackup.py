# ---------------------------------
# Class to handle recuests response
# ---------------------------------

import json

class Response:
    def __init__(self, status_code, headers, body):
        self.status_code = status_code
        self.headers = headers
        self.body = body

    def json(self):
        return json.loads(self.body)

    def __repr__(self):
        return f"<Response [{self.status_code}]>"