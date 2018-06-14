Initial creation of package
---------------------------

library(Rcpp)

Rcpp.package.skeleton(“Anton1”)  
R CMD build Anton1  
R CMD check Anton1  
R CMD install Anton1\_1.0.tar.gz  
^ that is all in the terminal

compileAttributes(“/Users/Anton/PIC-10C-Final-Project/Anton1/”,
verbose=TRUE)

library(tools)  
package\_native\_routine\_registration\_skeleton(“/Users/Anton/PIC-10C-Final-Project/Anton1/”,
character\_only = FALSE)

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

    thingy <- 1:10

    to_celsius(100.0)

    ## [1] 37.77778

    sumCpp(thingy)

    ## [1] 55

    meanC(thingy)

    ## [1] 5.5

    to_celsius(10)

    ## [1] -12.22222

    paste2(c("hi"), c("bye"))

    ## [1] "hibye"

    removePunct(c("hi.....$poiajefa;'a'"))

    ## [1] "hipoiajefaa"
