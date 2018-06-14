#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME:
 Check these declarations against the C/Fortran source code.
 */

/* .Call calls */
extern SEXP _Anton1_meanC(SEXP);
extern SEXP _Anton1_paste2(SEXP, SEXP);
extern SEXP _Anton1_rcpp_hello_world();
extern SEXP _Anton1_removePunct(SEXP);
extern SEXP _Anton1_removePunct2(SEXP);
extern SEXP _Anton1_sumCpp(SEXP);
extern SEXP _Anton1_to_celsius(SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"_Anton1_meanC",            (DL_FUNC) &_Anton1_meanC,            1},
    {"_Anton1_paste2",           (DL_FUNC) &_Anton1_paste2,           2},
    {"_Anton1_rcpp_hello_world", (DL_FUNC) &_Anton1_rcpp_hello_world, 0},
    {"_Anton1_removePunct",      (DL_FUNC) &_Anton1_removePunct,      1},
    {"_Anton1_removePunct2",     (DL_FUNC) &_Anton1_removePunct2,     1},
    {"_Anton1_sumCpp",           (DL_FUNC) &_Anton1_sumCpp,           1},
    {"_Anton1_to_celsius",       (DL_FUNC) &_Anton1_to_celsius,       1},
    {NULL, NULL, 0}
};

void R_init_Anton1(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
