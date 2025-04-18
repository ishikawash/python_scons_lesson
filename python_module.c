#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "tiny_math.h"

static PyObject* tinymath_gcd(PyObject* self, PyObject* args);
static PyObject* tinymath_lcm(PyObject* self, PyObject* args);

// 1. Define method table.
static PyMethodDef tinymath_methods[] = {
    {
        "gcd",
        (PyCFunction)tinymath_gcd,
        METH_VARARGS,
        "Compute gcd(a,b)."
    },
    {
        "lcm",
        (PyCFunction)tinymath_lcm,
        METH_VARARGS,
        "Compute lcm(a,b)."
    },
    {
        NULL,
        NULL,
        0, 
        NULL
    }
};

// 2. Declare module definition structure.
static struct PyModuleDef tinymath_module = {
    PyModuleDef_HEAD_INIT,
    "tinymath",
    NULL,
    -1,
    tinymath_methods
};

// 3. Create module and register it to interpreter.
PyMODINIT_FUNC PyInit_tinymath(void)
{
    return PyModule_Create(&tinymath_module);
}

static PyObject* tinymath_gcd(PyObject* self, PyObject* args)
{
    int a, b;
    if (!PyArg_ParseTuple(args, "ii", &a, &b))
    {
        return Py_None;
    }
    int c = gcd(a, b);
    return PyLong_FromLong(c);
}

static PyObject* tinymath_lcm(PyObject* self, PyObject* args)
{
    int a, b;
    if (!PyArg_ParseTuple(args, "ii", &a, &b))
    {
        return Py_None;
    }
    int c = lcm(a, b);
    return PyLong_FromLong(c);
}
