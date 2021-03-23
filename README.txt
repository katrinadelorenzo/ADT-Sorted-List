This program is made up of multiple files, making use of UnsortedType class to store
appointments. 

1. To compile the whole program in one single command:

  g++ Appointment.cpp sorted.cpp listDriver.cpp 

 or,

  g++ -o apptBookApp  Appointment.cpp sorted.cpp listDriver.cpp 

  

2. One can also compile the program in multiple steps: 

 a). Compile each .cpp file separately, which will generate corresponding .o file 
   -c option means only compile (to .o file)

  g++ -c Appointment.cpp  
  g++ -c sorted.cpp
  g++ -c listDriver.cpp

 b) Link all .o files together to generate executable file

  g++ Appointment.o sorted.o listDriver.o //This will generate a.out or a.exe file

  g++ -o apptBookApp Appointment.o unsorted.o listDriver.o //This will generate executable file
   // named apptBookApp 

  -o option to g++ is used to specify the name for the executable file 
 
3. You can create a script with the command inside it, to avoid typing the whole command everytime.
  see example file:  build
  
  c) Execute the program using:
  
  ./a.out or ./a.exe
