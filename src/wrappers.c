
#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "client.h"
#include "pyobjects.h"

#define DEBUG

#ifdef DEBUG
PyObject* testPyObject() {
    PyObject* pyHeaders = PyDict_New();

    PyObject* pyRes = Py_BuildValue(
        "{s:s, s:O, s:l}",
        "body", "test body",
        "headers", pyHeaders,
        "status", 200L
    );
    return pyRes;
}
#endif

void HashmapToDict(void* key, size_t ksize, uintptr_t value, void* userdata) {
    PyObject* pyKey = Py_BuildValue("s", key);
    PyObject* pyValue = Py_BuildValue("s", (char*)value);

    PyDict_SetItem((PyObject*)userdata, pyKey, pyValue);
}

PyObject* Py_RequestGET(PyObject* self, PyObject* args) {

    char* url;
    PyObject* headersObj = Py_None;

    if (!PyArg_ParseTuple(args, "s|O", &url, &headersObj)) {
        return NULL;
    }

    if (headersObj != Py_None && !PyDict_Check(headersObj)) {
        PyErr_SetString(PyExc_TypeError, "Error: Headers must be a dictionary.");
        return NULL;
    }

    HTTPHeader* headers = NULL;
    Py_ssize_t numHeaders = 0;
    if (headersObj != Py_None && PyDict_Size(headersObj) > 0) {
        numHeaders = PyDict_Size(headersObj);

        headers = malloc(sizeof(HTTPHeader) * numHeaders);
        if (headers == NULL) {
            PyErr_SetString(PyExc_MemoryError, "Error: malloc() failed for headers.");
            return NULL;
        }

        PyObject* key;
        PyObject* value;
        Py_ssize_t pos = 0;

        while (PyDict_Next(headersObj, &pos, &key, &value)) {
            if (!PyUnicode_Check(key) || !PyUnicode_Check(value)) {
                PyErr_SetString(PyExc_TypeError, "Error: Dictionary keys must be unicode strings.");
                free(headers);
                return NULL;
            }

            const char* keyStr = PyUnicode_AsUTF8(key);
            const char* valueStr = PyUnicode_AsUTF8(value);

            headers[pos].key = malloc(sizeof(char) * (strlen(keyStr) + 1));
            headers[pos].value = malloc(sizeof(char) * (strlen(valueStr) + 1));

            if (headers[pos].key == NULL || headers[pos].value == NULL) {
                PyErr_SetString(PyExc_MemoryError, "Error: malloc() failed for key or value.");
                free(headers);
                return NULL;
            }

            strcpy(headers[pos].key, keyStr);
            strcpy(headers[pos].value, valueStr);
        }

    }

    Response res = RequestGET(url, headers);

    if (headers != NULL) {
        for (size_t i = 0; i < (size_t)numHeaders; i++) {
            free(headers[i].key);
            free(headers[i].value);
        }

        free(headers);
    }

    PyObject *pyBody, *pyStatus;

    // res.body[res.bodySize] = '\0';
    pyBody = PyBytes_FromString(res.body);
    pyStatus = PyLong_FromLong(res.status);

    PyObject* pyHeaders = PyDict_New();
    hashmap_iterate(res.headers, HashmapToDict, pyHeaders);

    PyObject* pyRes = PyObject_CallObject((PyObject*)&PyResponseObject, Py_BuildValue("OOO", pyBody, pyHeaders, pyStatus););

    // PyObject* pyRes = Py_BuildValue(
    //     "{s:s#, s:O, s:l}",
    //     "body", res.body, res.bodySize,
    //     "headers", pyHeaders,
    //     "status", res.status
    // );

    #ifdef DEBUG
    // res.body[res.bodySize] = '\0';
    // PyObject* resData = PyBytes_FromString(res.body);
    // PyObject* pyRes = Py_BuildValue(
    //     "{s:s, s:O, s:l}",
    //     "body", resData,
    //     "headers", pyHeaders,
    //     "status", res.status
    // );

    // Py_DECREF(resData);
    #endif

    // Cleaning
    FreeResponse(&res);

    Py_DecRef(pyHeaders);
    Py_DecRef(pyStatus);
    Py_DecRef(pyBody);
    Py_Finalize();

    return pyRes;
}