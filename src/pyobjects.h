#ifndef PYOBJECTS_H
#define PYOBJECTS_H

#include <Python.h>

// Original response struct
// typedef struct Response {
//     char* body;
//     size_t bodySize;
//     hashmap* headers;
//     long status;
// } Response;

typedef struct {
    PyObject_HEAD
    PyObject* body; // String
    PyObject* headers; // Dictionary
    PyObject* status; // Integer
} PyResponseObject;

#endif