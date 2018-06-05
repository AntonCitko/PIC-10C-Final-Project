
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
List rcpp_hello_world() {

    CharacterVector x = CharacterVector::create( "foo", "bar" )  ;
    NumericVector y   = NumericVector::create( 0.0, 1.0 ) ;
    List z            = List::create( x, y ) ;

    return z ;
}

// [[Rcpp::export]]
double meanC(NumericVector x) {
    int n = x.size();
    double total = 0;
    
    for(int i = 0; i < n; ++i) {
        total += x[i];
    }
    return total / n;
}


// [[Rcpp::export]]
int sumCpp (IntegerVector x) {
    int n = x.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += x[i];
    }
    return res;
}


// [[Rcpp::export]]
double to_celsius(double x) {
    double res = (x - 32)  / 9.0 * 5.0;
    
    return res;
}
