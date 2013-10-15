static PyObject *iterator_c(PyObject *self, PyObject *args);

/* .... C matrix utility functions ..................*/
double **ptrvector(long n);
double **pymatrix_to_Carrayptrs(PyArrayObject *arrayin);
void free_Carrayptrs(double **v);
