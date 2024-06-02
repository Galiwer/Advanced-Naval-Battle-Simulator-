# Advanced-Naval-Battle-Simulator-


Advanced naval battle simulator is a simulation that can be use to experience real world
naval battles. Simulation is consisting of six sub simulations. In the first simulation first
escort ships search battleship is in range or not. If it is in range E ships destroys B ship if
not battleship check e ships are in range and if they are in range b ship will attack. All the
data will be print in the terminal and will be saved to a text file. In the second simulation its
same as the first one but now b ship is moving to a user given location from user given
location and if e ship got destroyed then it will not be present till the end. If the battleship
got destroyed the simulation will be stopped. Time to destroy e ships or b ship will be
written to a text file and whether if the b ship pr e ship destroyed or not also will be saved.
In the third simulation same as second but now b ship gun gets jammed after few
iterations. Min angle of the b ship gun will be randomly generated. In fourth fifth and sixth
same as first second and third but b ship has health and e ships shells has different impact
powers. E ships can only attack b ship once and b ship health will be reduced according to
the impact power of e ships and when b ship attack e ships, e ship will completely destroy.
All the simulations can get accessed by a menu. The menu is consisting of instructions
battleship settings escorts ship settings simulation statistics. Simulation statistics show
the data from the previous simulation. In the simulations pre-saved escort ship data and
battleship data will be used. The whole code is a combination of seven small codes.
When saving the details it saves detailes in two types.
1=Readable to the code.
It saves ship number, type notation, x location, y location, time to destroy Eship or b ship,
Escortship destroyed or not and battleship destroyed or not.
Eg:
1,A,72,14,6.56798,0,1
2,E,89,54,0,0,0
3,A,73,64,7.87778,1,0
4,C,48,77,0,0,0
5,B,59,92,0,0,0
2=Readable to the user.
Eg:
Escortship number 1 (Type D) was in (44,91)
Escortship number 2 (Type E) was in (89,91)
Escortship number 3 (Type A) was in (42,21) destroyed the Battleship. Time to destroy is 1.
Escortship number 4 (Type E) was in (78,28)
Escortship number 5 (Type E) was in (56,89)


Challenges

-Debugging and errors.

Debugging the code and solving the errors were very difficult. I mainly used the
“printf(“ check 1”);”commands to debug the code. I managed to solve errors by googling
the error code and by checking the online forums and websites like stackoverflow.
-Connecting the sub simulations to the main menu.
I tried making .h files and calling functions in the menu method. It didn't work for me. Then i
solved the problem by combining all seven codes into one code.

Improvements planning to make.

1-Break code to more simple functions without combining all the six .c files.
2-Change menu code simulation files to call only the functions in other c code files.
3-Improve how data prints in the terminal and try to store more data like ranges distance in
the text folders.
4-Make output simulation in 2d.
5-Make escort ships able to move and reduced battleship impact rate to a certain number.
6-Improve guns with different recoils and different reload times. Make both escort ships
and battle ships fire same time.
7-Improve escort ships and battleships to have different sailing speeds.

References

https://stackoverflow.com/questions/22330969/using-fscanf-vs-fgets-andsscanf
https://www.javatpoint.com/random-function-in-c
https://stackoverflow.com/questions/1675351/typedef-struct-vs-structdefinitions
https://stackoverflow.com/questions/48157930/cannon-projectile-programusing-c-programming
https://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm
https://stackoverflow.com/questions/18548157/c-header-files-andcompilation-linking
https://www.youtube.com/watch?v=8KyZedtkEhk
