# xv6 project
xv6 is a re-implementation of unix 6 edition in which it's an open source and a learning material which supports what operating system needs and we modified on it and added some system calls and user programs to make the our three modue, the first is the lottery scheduler, second is Null-pointer Dereference and the third module (optional) is adding kernel threads to xv6 
## lottery sched
The first module is Lottery scheduler, the basic idea is that every process has number of tickets generated by a function we will talk about later in this file and the more tickets process have, the more it runs on the cpu. this is the basic idea and we will acquire it by the following procedure

first we added `settickets()` which has a role to set the number of tickets for each process the second is `getpinfo()` which returns some information about running procceess from the process table, now we will explain each system call and how we added them to complete the lottery scheduler module

to add a system call we need to make changes to files to add our system call to kernel so firstly we added our system call to syscall.h file so that we can assign our system call a number and we assigned it to 24 so that we added two system calls to make it clear for this module of lottery scheduler the first is `settickets()` and the other is `getpinfo()` and defined each of them a number to refer for 
![image](https://user-images.githubusercontent.com/48224880/105907109-3e4d9a00-602d-11eb-8650-7df9b3261a9f.png)

the second file we edited is the `syscall.c` ile where we will add a pointer in it to refer to our call to refer that the system calls 24 and 25 pointed to the functions written in the file as follows

![image](https://user-images.githubusercontent.com/48224880/105905090-b5cdfa00-602a-11eb-9a70-1de17d03bafd.png)

then we're goint to add the function prototype in the same file also like this : 

![image](https://user-images.githubusercontent.com/48224880/105905147-c4b4ac80-602a-11eb-8325-b97663e2591e.png)

then we will implement function in the sysproc.c file as follows:

![image](https://user-images.githubusercontent.com/48224880/105905312-f6c60e80-602a-11eb-92d5-993627f1a8f3.png)

now we have to define how the user programs can access the system call so we will edit two more files which are usys.s

![image](https://user-images.githubusercontent.com/48224880/105905560-43114e80-602b-11eb-8d14-7aca58391109.png)

and another file `user.h` to define that this is the function that user program will call 
![image](https://user-images.githubusercontent.com/48224880/105905792-8bc90780-602b-11eb-88b3-347cb2cf4b21.png)

now we added both system calls we need to test them using user programs to run on the screen and display output about information for each process
we made `schedtest.c` and `getinfotest.c` to test that the calls are working correctly and to plot graph 
`getinfotest.c` is to display the output and the process information while `shcedtest.c` is to give tickets to processes 

we ran on qemu this order to give each process number of tickets:
![image](https://user-images.githubusercontent.com/48224880/105906799-d39c5e80-602c-11eb-8318-78ab6ed6ac1e.png)


then we got this output as 

![image](https://user-images.githubusercontent.com/48224880/105906923-fcbcef00-602c-11eb-9722-3722d7790b58.png)

so we plotted the graph as per output to describe how three processes with tickets ratios 1:2:3 will divide time slices and the graph where as shown 
![image](https://user-images.githubusercontent.com/48224880/105909454-40fdbe80-6030-11eb-8020-896e3bdb933e.png)


Read-Only

in this module we added to syscalls that will pe used to mark/unmark the required pages (in user space)
as Read_Only pages to prevent a bugy program from writing on it's own code in memory.

The syscalls are mprotect and munprotect.

Both calls check whether the given page addr is in the current address space , the page is aligned,
in the user space, or not and whether the num of pages given is in the limit or not if any of these checks came negative the call will trap 

![image](https://user-images.githubusercontent.com/47832007/105965207-cfebf480-608b-11eb-98f7-ae9b82dfc44b.png)


## kerneal thread
we made two system calls clone() and join() and two functions thread_create and thread_join and the three other functions (lock_inti ,aquire and release) is already bulit in in spinlock.c
![image](https://user-images.githubusercontent.com/47832007/106009861-7d2d2f80-60c1-11eb-9b71-c347c3d821ba.png)

![image](https://user-images.githubusercontent.com/47832007/106010005-abab0a80-60c1-11eb-9c02-a63f7cab9e20.png)

![image](https://user-images.githubusercontent.com/47832007/106010114-c2e9f800-60c1-11eb-90bd-f14e9ee678e8.png)

![image](https://user-images.githubusercontent.com/47832007/106010208-db5a1280-60c1-11eb-9621-abc2c694c789.png)

the output is

![image](https://user-images.githubusercontent.com/47832007/106010419-19573680-60c2-11eb-8816-4331bbe65fa7.png)







