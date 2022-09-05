%module lv

%include <std_pair.i>
%template() std::pair<int,int>;


%{
    #define SWIG_FILE_WITH_INIT
    #include "lv.h"
%}

%include "numpy.i"
%init %{
   import_array();
%}

%apply (int *IN_ARRAY1, int DIM1) { (int *a, int len_a), (int *b, int len_b) };

%apply (double *INPLACE_ARRAY2, int DIM1, int DIM2) { (double *out, int len,int wid) };

%apply (double *INPLACE_ARRAY1, int DIM1) { (double *ts, int len_ts), (double *xs, int len_xs), (double *ys, int len_ys) }

%include "lv.h"

