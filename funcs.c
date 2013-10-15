#include "Python.h"
#include "arrayobject.h"
#include "funcs.h"
#include <math.h>

static PyMethodDef _funcsMethods[] = {
    {"iterator_c", iterator_c, METH_VARARGS},
    {NULL, NULL}
};

void init_funcs()  {
    (void) Py_InitModule("_funcs", _funcsMethods);
    import_array();
}

static PyObject *iterator_c(PyObject *self, PyObject *args)  {

    PyArrayObject *arr;
    double **arr_use, it, x;
    int row, col, rows, cols, mult;

    if (!PyArg_ParseTuple(args, "O!i",
        &PyArray_Type, &arr, &mult))
        return NULL;

    rows = arr->dimensions[0];
    cols = arr->dimensions[1];

    //C array
    arr_use = pymatrix_to_Carrayptrs(arr);

    x = 0;
    it = 0;
    for (row=0; row < rows; row++) {
        for (col=0; col < cols; col++) {
            arr_use[row][col] = x;
            x += (it * mult);
            it += 1;
        }
    }
    free_Carrayptrs(arr_use);

    PyObject *Result = Py_BuildValue("i", 1);

    return Result;
}

double **ptrvector(long n) {
    double **v;
    v=(double **) malloc((n*sizeof(double *)));
    if (!v)   {
        printf("In **ptrvector. Allocation of memory for double array failed.");
        exit(0);  }
    return v;
}

double **pymatrix_to_Carrayptrs(PyArrayObject *arrayin)  {
    double **c, *a;
    int i,n,m;

     n=arrayin->dimensions[0];
     m=arrayin->dimensions[1];
     c=ptrvector(n);
     a=(double *) arrayin->data;  /* pointer to arrayin data as double */
     for ( i=0; i<n; i++)  {
         c[i]=a+i*m;  
     }
     return c;
 }

void free_Carrayptrs(double **v)  {
    free((char*) v);
}

