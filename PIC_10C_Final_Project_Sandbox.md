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

    to_celsius(10)

    ## [1] -12.22222

    to_celsius(100.0)

    ## [1] 37.77778

    cosa1 <- 1:10

    sumCpp(cosa1)

    ## [1] 55

    sumCpp(15:10)

    ## [1] 75

    meanC(cosa1)

    ## [1] 5.5

    meanC(15:10)

    ## [1] 12.5

    paste2("hi", "bye")

    ## [1] "hibye"

    removePunct("_-#h3/l/l0!-_")

    ## [1] "h3ll0"

    removePunct2("_-#h3/l/l0!-_")

    ## [1] "h3ll0"

    cosa2 <- c("hi.....$poiajefa;'a'", "hello", "this-is_a#Cosa", "'I /./.,/dont*%$#% know@##@$}{ how|| to?><-=+_ type'")

    stuff <- removePunct2(cosa2)
    stuff

    ## [1] "hipoiajefaa"             "hello"                  
    ## [3] "thisisaCosa"             "I dont know how to type"

    load(url("http://www.stat.ucla.edu/~vlew/SP18stat20/bb102.RData"))
    salaries <- bb102[["salaries10.2"]]

    salaries_long <- c(salaries$Salary, salaries$Salary, salaries$Salary, salaries$Salary,salaries$Salary, salaries$Salary, salaries$Salary)

    head(salaries$Salary, 10)

    ##  [1] $380,000   $4,575,000 $380,000   $1,034,000 $1,437,500 $1,250,000
    ##  [7] $5,500,000 $1,500,000 $380,000   $387,500  
    ## 332 Levels: $1,000,000 $1,025,000 $1,030,000 $1,034,000 ... $985,000

    head(removePunct2(salaries$Salary), 10)

    ##  [1] "380000"  "4575000" "380000"  "1034000" "1437500" "1250000" "5500000"
    ##  [8] "1500000" "380000"  "387500"

    head(gsub("\\$|,", "", salaries$Salary), 10)

    ##  [1] "380000"  "4575000" "380000"  "1034000" "1437500" "1250000" "5500000"
    ##  [8] "1500000" "380000"  "387500"

    system.time(removePunct2(salaries$Salary))

    ##    user  system elapsed 
    ##       0       0       0

    system.time(gsub("\\$|,", "", salaries$Salary))

    ##    user  system elapsed 
    ##   0.003   0.000   0.003

    system.time(removePunct2(salaries_long))

    ##    user  system elapsed 
    ##   0.002   0.000   0.003

    system.time(gsub("\\$|,", "", salaries_long))

    ##    user  system elapsed 
    ##   0.006   0.000   0.006
