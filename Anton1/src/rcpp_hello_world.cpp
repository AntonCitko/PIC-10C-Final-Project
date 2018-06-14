
#include <Rcpp.h>
#include <algorithm>
#include <cctype>
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

struct Functor {
    std::string
    operator()(const std::string& lhs, const internal::string_proxy<STRSXP>& rhs) const
    {
        return lhs + rhs;
    }
};

// [[Rcpp::export]]
CharacterVector paste2(CharacterVector lhs, CharacterVector rhs)
{
    //This function is an example I am using to create a similar function to remove punctuation
    //All credit to: nrussell
    //https://stackoverflow.com/questions/43182003/concatenate-stringvector-with-rcpp
    
    std::vector<std::string> res(lhs.begin(), lhs.end());
    std::transform(res.begin(), res.end(),
                   rhs.begin(), res.begin(),
                   Functor());
    return wrap(res);
}

// [[Rcpp::export]]
CharacterVector removePunct(const CharacterVector& ori)
{
    std::vector<std::string> res(ori.size());
    std::string temp;
    for (size_t i = 0; i < ori.size(); ++i) {
        temp = "";
        for (size_t j = 0; j < ori[i].size(); ++j) {
            if (!(std::ispunct(ori[i][j]))) {
                temp.push_back(ori[i][j]);
            }
        }
        res[i] = temp;
    }
    
    return wrap(res);
}

std::vector<std::string> explicit_string_conv(const CharacterVector& X) {
    std::vector<std::string> conv(X.size());
    for (size_t i = 0; i < X.size(); ++i) {
        conv[i] = X[i];
    }
    
    return conv;
}

std::string pr (const std::string& x) {
    std::string temp = "";
    for (auto j = x.begin(); j != x.end(); ++j) {
        if (!(std::ispunct(*j))) {
            temp.push_back(*j);
        }
    }
    return temp;
}

// [[Rcpp::export]]
CharacterVector removePunct2(CharacterVector ori)
{
    std::vector<std::string> temp = explicit_string_conv(ori);
    std::vector<std::string> res(ori.size());
    std::transform(temp.begin(), temp.end(), res.begin(), pr);
    
    return wrap(res);
}
