# IP-CALCULATOR

## General idea:
IP CALCULATOR was born as a school project carried out by two Italian boys attending secondary school.
The software is able to carry out different types of network subdivisions such as the "Subnetting" technique and the "VLSM (Variable Lenght Subnet Mask)" technique.
It is also possible to check whether two IP addresses belong to the same network.
The programme is very versatile, as it accepts addresses of the three main classes A, B and C. Classes D and E have been discarded as they are little used.  

## Technical aspects:
The program is written entirely in C with a simple syntax that is easy to understand even for the most inexperienced; the heart of the program is the "utils.h" library in which all the functions are contained. The code is fully commented in order to make it easier to understand from a logical and syntactic point of view.
The program's elaborations are printed in the terminal and also in a text file that is created "ip.txt", this choice because we wanted to save the elaboration data in a support that can be viewed later or for subsequent analysis.

The programme is useful for understanding how the Subnetting and VLSM techniques work, for creating small networks or as a verification tool for school exercises on networks.

**🚨Warning:**<br>
the program may have some bugs when working with many networks especially with class A addresses.

We invite all users to report bugs in the code, or just to express your feedback.

## Usage
on Unix systems compile with:
```bash
$ gcc ip_calculator.c -o ip_calculator -lm
```
run the binary with:
```bash
$ ./ip_calculator
```
or run the start.sh script:
```bash
$ chmod +x start.sh
$ ./start.sh
```
