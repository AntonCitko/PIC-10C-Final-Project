Initial creation of package
---------------------------

In R: library(Rcpp) Rcpp.package.skeleton(“Anton1”)

In the console: R CMD build Anton1  
R CMD check Anton1  
^ that is all in the terminal

Back in R:
compileAttributes(“/Users/Anton/PIC-10C-Final-Project/Anton1/”,
verbose=TRUE)

library(tools)  
package\_native\_routine\_registration\_skeleton(“/Users/Anton/PIC-10C-Final-Project/Anton1/”,
character\_only = FALSE) ^ copy the output of this into the file
~/Anton1/src/init.c

install.packages(“~/PIC-10C-Final-Project/Anton1\_1.0.tar.gz”, repos =
NULL, type = “source”)

    library(Anton1)

    rcpp_hello_world()

    ## [[1]]
    ## [1] "foo" "bar"
    ## 
    ## [[2]]
    ## [1] 0 1

Adding a function to convert a number to celsius, sum a vector, and find the mean of a vector
---------------------------------------------------------------------------------------------

    cosa1 <- 1:10

    to_celsius(100.0)

    ## [1] 37.77778

    sumCpp(cosa1)

    ## [1] 55

    meanC(cosa1)

    ## [1] 5.5

    to_celsius(10)

    ## [1] -12.22222

    paste2(c("hi"), c("bye"))

    ## [1] "hibye"

    cosa2 <- c("hi.....$poiajefa;'a'", "hello", "this-is_a#Cosa")

    stuff <- removePunct2(cosa2)
    stuff

    ## [1] "hipoiajefaa" "hello"       "thisisaCosa"

    removePunct2("I /./.,/dont*%$#% know@##@$}{ how|| to?><-=+_ type")

    ## [1] "I dont know how to type"
