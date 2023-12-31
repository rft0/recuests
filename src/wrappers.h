#ifndef WRAPPERS_H
#define WRAPPERS_H

#include <Python.h>

PyObject* Py_RequestGET(PyObject* self, PyObject* args);
PyObject* Py_RequestPOST(PyObject* self, PyObject* args);
PyObject* Py_RequestPUT(PyObject* self, PyObject* args);
PyObject* Py_RequestDELETE(PyObject* self, PyObject* args);

#endif