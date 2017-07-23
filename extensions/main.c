#include <Python.h>
#include "calculation.h"

//extension module
/************************************************************/

static PyObject *sum(PyObject *self, PyObject *args){
    
    int e1, e2;
    int sum;
    if(!PyArg_ParseTuple(args, "ii", &e1, &e2)){
        return NULL;
    }
    sum = addition(e1, e2);
    return PyLong_FromLong(sum);
    
}

static PyObject *difference(PyObject *self, PyObject *args){
    
    int e1, e2;
    int diff;
    if(!PyArg_ParseTuple(args, "ii", &e1, &e2))
        return NULL;
    diff = subtraction(e1, e2);
    return PyLong_FromLong(diff);
}

static PyObject *product(PyObject *self, PyObject *args){
    int e1, e2;
    int product;
    if(!PyArg_ParseTuple(args, "ii", &e1, &e2))
        return NULL;
    product = multiplication(e1, e2);
    return PyLong_FromLong(product);
}

static PyObject *quotient(PyObject *self, PyObject *args){
    int e1, e2;
    int quo;
    if(!PyArg_ParseTuple(args, "ii", &e1, &e2))
        return NULL;
    quo = division(e1, e2);
    return PyLong_FromLong(quo);
}


/************************************************************/

// documentation for each functions.
static char sum_doc[] = "return sum";
static char diff_doc[] = "return difference";
static char product_doc[] = "return product";
static char quo_doc[] = "return quotient";

// defining our functions like below:
// function_name, function, METH_VARARGS flag, function documents
static PyMethodDef gmethods[] = {
  {"sum", sum, METH_VARARGS, sum_doc},
  {"difference", difference, METH_VARARGS, diff_doc},
  {"product", product, METH_VARARGS, product_doc},
  {"quotient", quotient, METH_VARARGS, quo_doc},
  {NULL, NULL, 0, NULL}
};


static struct PyModuleDef gcallibModule = {
  PyModuleDef_HEAD_INIT, // head informations for Python C API. It is needed to be first member in this struct !!
  "gcallib",  // module name
  NULL, // means that the module does not support sub-interpreters, because it has global state.
  -1,
  gmethods  // our functions list
};

// runs while initializing and calls module creation function.
PyMODINIT_FUNC PyInit_gcallib(void){
  return PyModule_Create(&gcallibModule);
}


