#include <Python.h>

#include "wrappers.h"

static PyMethodDef methods[] = { 
    {"get", Py_RequestGET, METH_VARARGS, "Python binding for RequestGET function."},  
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "recuests",
    "Python bindings for https://github.com/epsilonr/httpclient",
    -1,
    methods
};

PyMODINIT_FUNC PyInit_recuests(void) {
    return PyModule_Create(&module);
}