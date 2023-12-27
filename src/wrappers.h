#ifndef WRAPPERS_H
#define WRAPPERS_H

#include <Python.h>

static PyObject* Py_RequestGET(PyObject* self, PyObject* args);
static PyObject* Py_RequestPOST(PyObject* self, PyObject* args);
static PyObject* Py_RequestPUT(PyObject* self, PyObject* args);
static PyObject* Py_RequestDELETE(PyObject* self, PyObject* args);

#endif