# PIC-10C-Final-Project
I am creating a package for R using C++. Below you will find the research and ideas I had, what the package can do, and how to install the package.

## Table of Contents:
* [What is in this Repository](#chapter-0)
* [Research, Ideas, and Development Process](#chapter-1)
* [The Package](#chapter-2)
* [How to Install the Package](#chapter-3)

## What is in this Repository <a id="chapter-0"></a>
This repository contains the following files:
* Anton1 is a folder that contains the cpp files for the functions in the package, the documentation generated for the package, and the RcppExports file that tells R what functions there are.
* PIC 10C Final Project Sandbox files are markdown files where I played around to figure out how to get the package to work and myself trying it out.
* Anton1_1.0.tar.gz is the actual package that you can install and run in R.
* The other files were generated in the process of this project that help to compile the the package.

## Research, Ideas, and Development Process <a id="chapter-1"></a>
### This part is a journal where I kept track of the different ideas and sources I found to help me create a package for R. It followed along with my development process.

The first thing I did to figure out how to make a package for R was to Google what good starting places there are to make packages. A couple of helpful links were:  

https://cran.r-project.org/doc/manuals/R-exts.pdf  
http://dirk.eddelbuettel.com/code/rcpp/Rcpp-package.pdf

Based on some of my research, it looks like Rcpp is a package designed to integrate C++ with R. Also, it has some very useful functions to create the basis for an R package using Rcpp. I think it would be a good stepping stone that would help reduce some of the initial chores to creating a package.

http://gallery.rcpp.org/

RccpExamples and its reference manual:  
https://cran.r-project.org/web/packages/RcppExamples/index.html
https://cran.r-project.org/web/packages/RcppExamples/RcppExamples.pdf

After having done research on how to create a package, the next was trying to compile and use one. After a lot of research and some frustration, I found a really helpful forum that discussed how to do it:  
https://stackoverflow.com/questions/16107431/how-do-i-run-rcpp-hello-world

Once I had it working, I was able to run the rcpp_hello_world function! The frustration and time was worth it!


## The Package <a id="chapter-2"></a>

## How to Install the Package <a id="chapter-3"></a>

