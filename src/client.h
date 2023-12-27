#ifndef REQUEST_H
#define REQUEST_H

#include "hashmap.h"

typedef struct HTTPHeader {
    const char* key;
    const char* value;
} HTTPHeader;

typedef struct Response {
    char* body;
    size_t bodySize;
    hashmap* headers;
    long status;
} Response;

Response RequestGET(const char* url, HTTPHeader* headers);
Response RequestPOST(const char* url, HTTPHeader* headers, const char* body);
Response RequestPUT(const char* url, HTTPHeader* headers, const char* body);
Response RequestDELETE(const char* url, HTTPHeader* headers);

char* GetResHeader(Response* res, const char* key);

void FreeResponse(Response* res);

#endif