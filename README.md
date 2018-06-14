# PIC-10C-Final-Project
I created a package for R using C++. Below you will find the research and ideas I had, what the package can do, and how to install the package.

If you have any questions, feel free to email me at: acecitko@yahoo.com.

## Video demonstration of package functions
This video goes through the functions that are in the package.

[![](https://img.youtube.com/vi/p3XlIzIDmWo/0.jpg)](https://www.youtube.com/watch?v=p3XlIzIDmWo)

https://youtu.be/p3XlIzIDmWo

## Table of Contents:
* [What is in this Repository](#chapter-0)
* [Research, Ideas, and Development Process](#chapter-1)
* [The Package](#chapter-2)
* [How to Install the Package](#chapter-3)

## What is in this Repository <a id="chapter-0"></a>
This repository contains the following files:
* Anton1 is a folder that contains the cpp files for the functions in the package, the documentation generated for the package, and the RcppExports file that tells R what functions there are.  
    * Actual programing for functions can be found in PIC-10C-Final-Project/Anton1/src/rcpp_hello_world.cpp  
    * https://github.com/antonqp/PIC-10C-Final-Project/blob/master/Anton1/src/rcpp_hello_world.cpp  
* PIC 10C Final Project Sandbox files are markdown files where I played around to figure out how to get the package to work and myself trying it out.
    * Checkout PIC_10C_Final_Project_Sandbox.md for some usage of the package. It is the same one I used in the video.
* Anton1_1.0.tar.gz is the actual package that you can install and run in R.
* The other files were generated in the process of this project that help to compile the the package.

## Research, Ideas, and Development Process <a id="chapter-1"></a>
### This part is a journal where I kept track of the different ideas and sources I found to help me create a package for R. This follows along with my development process.

I originally decided to do this project because it relates well to another class I am taking this quarter, Stats 20. Stats 20 is the introduction to using R for statistical programming and I had heard that a lot of R is based on C++ behind the scenes. I thought it would be rewarding if I could figure out how to make a package for R using C++ because it would be interesting to discover how the languages are related.

The first thing I did to figure out how to make a package for R was to Google what good starting places there are to make packages. A couple of helpful links were:  
https://cran.r-project.org/doc/manuals/R-exts.pdf  
http://dirk.eddelbuettel.com/code/rcpp/Rcpp-package.pdf

Based on some of my research, it looks like Rcpp is a package designed to integrate C++ with R. Also, it has some very useful functions to create the basis for an R package using Rcpp. I think it would be a good stepping stone that would help reduce some of the initial chores to creating a package.

http://gallery.rcpp.org/

RccpExamples and its reference manual:  
https://cran.r-project.org/web/packages/RcppExamples/index.html
https://cran.r-project.org/web/packages/RcppExamples/RcppExamples.pdf

I learned the next steps was trying to write, compile, and use one. After a lot of research and some frustration, I found a really helpful forum that discussed how to do it:  
https://stackoverflow.com/questions/16107431/how-do-i-run-rcpp-hello-world

Once I went through all the steps to create it (which can be seen at the top of PIC_10C_Final_Project_Sandbox.md), I was able to run the rcpp_hello_world function! The frustration and time was worth it!

After that, I added my own function to convert a number from Fahrenheit to Celsius and tested out some functions to sum a vector and find the mean of a vector. These were easy to program.

For my final part of the project I wanted to do something that could use some of the stuff I had learned this quarter in PIC 10C. I decided to try to add a punctuation remover for CharacterVectors function using STL algorithms to move through the CharacterVector. A CharacterVector in R is essentially a vector of strings in C++.

My first go at it was met with frustration because Rcpp has trouble moving from string iterators to characters back to strings. I tried to follow along with someone that implemented a function that would paste two character vectors together into one string using the transform STL algorithm, but I still could not get past my issues. The forum for that is below:  
https://stackoverflow.com/questions/43182003/concatenate-stringvector-with-rcpp

To work around it, I made a "dumb" punctuation removal function that uses size_t to move through the CharacterVector and then the strings within that. It does remove punctuation!

After a lot of troubleshooting and research, I discovered that the best way to solve my problem would be to have an explicit conversion from Rcpp's "Rcpp::internal::string_proxy<16>" to a normal string. Once I implemented that, I was able to use the STL algorithm transform to create my punctuation remover. The function works by creating a temporary vector to hold the CharacterVector (so we can actually use iterators for strings), creating an output vector of strings, and then transforming every string and adding it to the output vector. Finally, a CharacterVector is returned, which R can use.

Below is the link that helped me figure out a workaround:  
https://github.com/RcppCore/Rcpp/issues/552

I really enjoyed this project because it gave me a lot  of freedom. I am interested in having a career in data science so R and object orientated programming are very important skills to have. This summer, if I find time I might continue working on creating more packages for R.

If I had more time to work on this project I would try to implement a way to specify certain punctuation symbols to keep for my punctuation remover function. This would be useful to keep decimals for certain situations, for example, dollar amounts.

## The Package <a id="chapter-2"></a>
#### rcpp_hello_world : function () 
* This is a basic function that comes with the Rcpp skeleton function
* It returns a list of:  
    [[1]]  
    [1] "foo" "bar"  
    [[2]]  
    [1] 0 1

#### to_celsius : function (x)  
* Converts a number from Fahrenheit to Celsius

#### meanC : function (x)  
* Calculates the mean  of a numeric vector

#### sumCpp : function (x)  
* Calculates the sum of a numeric vector

#### paste2 : function (lhs, rhs)  
* Takes two strings and then pastes them together into one string

#### removePunct : function (ori)  
* Removes all the punctuation in a CharacterVector

#### removePunct2 : function (ori) 
* Removes all the punctuation in a CharacterVector
* Utilizes the transform STL algorithm

## How to Install the Package <a id="chapter-3"></a>
1. Have an up to date version of Rstudio and open it
2. Download Anton1_1.0.tar.gz from this repository
3. In Rstudio issue the command: "install.packages("~/Anton1_1.0.tar.gz", repos = NULL, type = "source")"
4. Next, load the library with the command: "library(Anton1)"
5. From here, you are all set to use the functions

