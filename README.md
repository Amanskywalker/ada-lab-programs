# ada-lab-programs
Ada Lab programs

vtu 4th sem ADA lab programs

These programs are written in linux environment and compiled using the GCC & g++ compiler.

testbench_c.bash or testbench_c++.bash are the script written in bash to test the algorithm written in c or c++

it required R to process the data and produce a graph (saved as figure.png) to show the time and no of input relationship 

if u don't have R installed use 

--sudo apt-get -y install r-base

to install the R

usage: bash testbench_*.bash [file] [test]

 [file] 	file name <name>.c or <name>.cpp
 [test]		an integer value the number of time the test has to be performed
			defult increment value in 100 (can be changed in testbench_*.bash file) 


also use 

passing argument by commandline (container vector)

i.e.

int main(int argc,char *argv[])
{
}

else it wont able to pass argument for test

also don't take any user input in your program 

You can refer sample (sample.cpp) program to get the idea on who to write compatiable program for testing

