
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define M_PI 3.14159265358979323846 //Defining the pi 

struct eship  //Normal detailes of an Eship
{
    int destroy;
    char ntype[50];
    int locx;
    int locy;   
};

struct Eshipvalues // Calculated detailes of an Eship 
{
    float minangle;
    float maxfinalangle;
    float minvel;
    float maxvel;
    float distancetoB;
};

struct shipData  //Store escortship data from text file 
{
    char typenotation;
    char typename[50];
    char gunname[50];
    float impactpower;
    int anglerange;
    char minimumangle;
    char minvelocity;
    char maxvelocity;
};

struct bshipData  //Store battleship data from text file 
{
    
    char typename[50];
    char typenotation;
    char gunname[50];
};

struct textfile1 // Use to store from to save.text
{
    int number;
    char typenotation;
    int locationx;
    int locationy;       
};

struct textfile2 //Use to store data from savenew.txt
{
    int number;
    char typenotation;
    int locationx;
    int locationy;
    float time;   
    int bdestroy;
    int edestroy;
};

struct textfile3 //Use to display final 
{
    int number;
    char type;
    int x;
    int y;
    float time;
    int ED;
    int BD;
};


// Declare  arrays 
struct shipData shipData[256];
struct eship ships[100];
struct Eshipvalues eships[100];
struct bshipData bshipData[256];
struct textfile1 file1[256];
struct textfile2 file2[256];
struct textfile3 file3[256];

//Function declarations

double calculateDistance(int x1, int y1, int x2, int y2);
float searchEShips(struct eship *ships,struct Eshipvalues *eships, int N, int x, int y,float radius,char bt,float randomBvelocity,float Bshellalltime,float timetodestroyEships,FILE *outputFile2);
float searchEShips2(struct eship *ships,struct Eshipvalues *eships, int N, int x, int y,float radius,char bt,float randomBvelocity,float Bshellalltime,float timetodestroyEships,FILE *outputFile2);
float searchEShips3(struct eship *ships,struct Eshipvalues *eships, int N, int x, int y,float radius,char bt,float randomBvelocity,float Bshellalltime,float timetodestroyEships,int jamcheck,FILE *outputFile);
void checkSearch(int BX, int BY, int csx, int csy);
char checkbt(char bt);
float destroyship(struct eship *ship,struct shipData *shipData,char bt, float randombvelocity, float Bangle,float distance,int i,float Bshellalltime,FILE *outputFile2,int g);
float destroyship2(struct eship *ship,struct shipData *shipData,char bt, float randombvelocity, float Bangle,float distance,int i,float Bshellalltime,FILE *outputFile2,int g,int jamcheck);
float destroyship3(struct eship *ships,struct shipData *shipData, char bt, float randombvelocity, float Bangle,float distance,int i,FILE *outputFile2,float Bshellalltime);
float minimumanglecheck(struct shipData *shipData,float minimumangle,float finalminimumangle,int x);
float bmaxrangespeed(int canvasSizeX);
float calculateRange(float velocity, float angle);
int finaltext(struct textfile1 *file1,struct textfile2 *file2);
int checkdestroy(struct eship *ships,int i);
void Bdetails(struct bshipData *bshipData);
void lasttext(struct textfile3 *file3);
void generateRandomEscortships(struct eship *ships, struct shipData *shipData,int N, int csx, int csy);

// Functions of simulations

int s1a(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData);
int s1b(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData);
int s1b2(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData);
int s1c(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData);
int s1c1(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData);
int s1c2(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData);

//Functions of menu

void startSimulation(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData);
int mainmenu(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData,struct textfile3 *file3);
void viewinstructions(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData);
int eshipsettings(struct shipData *shipData);
void setup(struct shipData *shipData,struct bshipData *bshipDatastruct,struct textfile1 *file1,struct textfile2 *file2);
void submenu(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData,struct textfile3 *file3);


int main() 
{
    int r;
    r = mainmenu(shipData,file1,file2,bshipData,file3); //calling mmain menu function 
    return r;  
}

void startSimulation(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData) //start simulation menu
{    
    int z;


        printf("\nSimulation types\n\n");
        
        printf("1-Simulation 1 (Original)\n");
        printf("2-Simulation 2 (Moving Battleship)\n");
        printf("3-Simulation 3 (Moving B ship with jammed gun)\n");
        printf("4-Simulation 4 (Original with health included)\n");
        printf("5-Simulation 5 (Moving B ship(health included))\n");
        printf("6-Simulation 6 (Moving B ship(health included) with jammed gun)\n");
        printf("Enter your choice: ");
        scanf("%d", &z);

         switch(z) //choosing simulation type
        {
            case 1:
                s1a(shipData,file1,file2,bshipData);
                break;     
            case 2:
                s1b(shipData,file1,file2,bshipData);
                break;            
            case 3:
                s1b2(shipData,file1,file2,bshipData);
                break;  
            case 4:
                s1c(shipData,file1,file2,bshipData);
                break;         
            case 5:
                s1c1(shipData,file1,file2,bshipData);
                break; 
            case 6:
                s1c2(shipData,file1,file2,bshipData);
                break; 
            default:
                printf("Error Invalid input\n");
                startSimulation(shipData,file1,file2,bshipData);
        }
 
}

//main menu function
int mainmenu(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData,struct textfile3 *file3)
{
    int z;
    int y;


        printf("\nMain Menu Options\n");
        printf("1-Start Simulations\n");
        printf("2-View Instructions\n");
        printf("3-Simulation Statistics\n");
        printf("4-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &z);


        switch(z) 
        {
            case 1:
               submenu(shipData,file1,file2,bshipData,file3);
                break; 
            case 2:
                viewinstructions(shipData,file1,file2,bshipData);                
                break; 
            case 3:
                lasttext(file3);
                break;
            case 4:
                printf("Exiting the menu.\n");                 
                 return 1;
            default:
                printf("Error Invalid input\n");
                mainmenu(shipData,file1,file2,bshipData,file3);
        }    
}


//instructions function
void viewinstructions(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData)
{
    printf("\nGive all the Data simulation requests.Battleship data and Escortship data will be generated in the simulation.\n");
    mainmenu(shipData,file1,file2,bshipData,file3);
}

//submenu function
void submenu(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData,struct textfile3 *file3)
{

    int z;
    printf("\nStart simulation submenu Options\n");
    printf("1-Setup\n");
    printf("2-Show Simulations\n");        
    printf("Enter your choice: ");
        scanf("%d", &z);


        switch(z) 
        {
            case 1:
                setup(shipData,bshipData,file1,file2);
                break; 
            case 2:
                startSimulation(shipData,file1,file2,bshipData);             
                break;         
            default:
                printf("Error Invalid input\n");
                mainmenu(shipData,file1,file2,bshipData,file3);
        }
}


// setupfunction
void setup(struct shipData *shipData,struct bshipData *bshipDatastruct,struct textfile1 *file1,struct textfile2 *file2) 
{
    int c;
        
        do
        {

        
            printf("\nSetup\n");
            printf("1-Battleship Properties\n");
            printf("2-Escort ships Settings\n");
            printf("3-Seed value\n");
            printf("4-Return to Main Menu\n");
            printf("Enter your choice: ");
            scanf("%d", &c);
                  
        } while (c<1||c>4);

        switch(c) 
        {
            case 1:
                Bdetails(bshipData);
                printf("Max range of Battle ship will be half of the canvas.\n");
                break;
            case 2:
                eshipsettings(shipData);
                break;
            case 3:
                printf("\nSeed value is null (You cannot change the seed value)\n");
                break;
            case 4:
                 mainmenu(shipData,file1,file2,bshipData,file3);
                return;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        setup(shipData,bshipData,file1,file2);   
}


//eship settings function 
int eshipsettings(struct shipData *shipData)
{
    FILE *inputFile = fopen("eshipsdata.txt", "r");// open eshipdata text file

    if (inputFile == NULL)
    {
        printf("Error opening the input file.\n");
    }
        

    int c=0;
    char line[256];

    // Read ship data from file eshipdata.txt
    while (fgets(line, sizeof(line), inputFile) != NULL)
    {
        sscanf(line, "%c,%49[^,],%49[^,],%f,%d,%c,%c,%c",
               &shipData[c].typenotation,
               &shipData[c].typename[0],
               &shipData[c].gunname[0],
               &shipData[c].impactpower,
               &shipData[c].anglerange,
               &shipData[c].minimumangle,
               &shipData[c].minvelocity,
               &shipData[c].maxvelocity);
        c++;
    }
    
    //print the ship data

    for (int i = 0; i < c; i++)
    {
        printf("Type Notation: %c\n", shipData[i].typenotation);
        printf("Type Name: %s\n", shipData[i].typename);
        printf("Gun Name: %s\n", shipData[i].gunname);
        printf("Impact Power: %f\n", shipData[i].impactpower);
        printf("Angle Range: %d\n", shipData[i].anglerange);
        printf("Minimum Angle: %c\n", shipData[i].minimumangle);
        printf("Min Velocity: %c\n", shipData[i].minvelocity);
        printf("Max Velocity: %c\n", shipData[i].maxvelocity);
        printf("\n");
    }

    fclose(inputFile);//closing the file

    return c;
}

void generateRandomEscortships(struct eship *ships, struct shipData *shipData,int N, int csx, int csy) 
{
    FILE *outputFile = fopen("save.txt", "w");
    if (outputFile == NULL)
    {
        printf("Error creating the output file.\n");
        fclose(outputFile);        
    }

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        int randomnumber = rand() % 5;
        ships[i].ntype[0] = 'A' + randomnumber;
        ships[i].ntype[1] = '\0';

        int randomx = rand() % csx;
        ships[i].locx = randomx;

        int randomy = rand() % csy;
        ships[i].locy = randomy;

        int EAR = shipData[i].anglerange;
        int REAR = 90 - EAR;

        int randomMA = rand() % REAR;
        int FinalEAngle = randomMA + EAR;

        printf("\nShip %d: Type: %s, Location: (%d, %d)\n", i + 1, ships[i].ntype, ships[i].locx, ships[i].locy);
        fprintf(outputFile, "%d,%s,%d,%d\n", i + 1, ships[i].ntype, ships[i].locx, ships[i].locy);
    }
    
    fclose(outputFile);
}


//-------------------------------------------------------------------------------------------------SIMULATION 1
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


int s1a(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData)
{

    FILE *outputFile2 = fopen("savenew.txt", "w"); // open file to write data
    if (outputFile2 == NULL)
    {
        printf("Error creating the output file.\n");
        fclose(outputFile2);
        return 1;
    }

   int c = eshipsettings(shipData); //get escortship data

    //Definning the canvas
    int N, canvasSizeX, canvasSizeY;
    do
    {     
     printf("\nEnter the canvas square size(10 - 1000) D=D:= ");
     scanf("%d", &canvasSizeX);
    }while(canvasSizeX<10 || canvasSizeX >1000);
    
    

    canvasSizeY = canvasSizeX;//Because canvas is a square
    int csx = canvasSizeX + 1;//Important to generate random numbers.
    int csy = canvasSizeY + 1;

                                                                                 //Escort ship 

    do 
    {
     printf("\nEnter number of escort ships (Less than 1000):");
     scanf("%d", &N);     
    }while(N<1 || N >1000);


    generateRandomEscortships(ships,shipData,N,csx,csy);//Generate random  e ships and  other things of e ships

    int  x;
    float finalminimumangle; 

    for(x=0;x<c;x++) // generate minimmum and maxangles for the each escort ship
    {    
      eships[x].minangle = minimumanglecheck(shipData,shipData[x].minimumangle,finalminimumangle,x);// funnction to random generate minimum angle.
      eships[x].maxfinalangle = eships[x].minangle + shipData[x].anglerange;
      printf("\nEscortship %c ship min angle is %f and max angle %f:",shipData[x].typenotation,eships[x].minangle,eships[x].maxfinalangle);

    }        
    

                                                                            //Battleship 
    
    Bdetails(bshipData);//Print battleship data

    char bt;
    do
    {
        printf("\n\nEnter the Battleship type: "); //Getting battle ship type as an user input
        scanf(" %c", &bt);
    } while (checkbt(bt) != 1);
    

    float maxbmaxrangespeed = bmaxrangespeed(canvasSizeX);//Battleship shell velocity thet goes maxximum range(Half the canvas)
     
    printf("\nBattleships max range velocity : %f",maxbmaxrangespeed);

    int BX, BY;
    float searchRadius = (canvasSizeX/2);//Battleship maximum range = cannvassize/2
    
    do
    {
        printf("\nEnter the Battleship location point (x y): "); //Gettingg batttle ship locations from thhe user.
        scanf("%d %d", &BX, &BY);
        checkSearch(BX, BY, csx, csy);//Checking inputted data is correct using a function.
    } while (BX < 0 || BX > csx || BY < 0 || BY > csy);



                                                     //Decide what ship is going to sink.
    float bms = (maxbmaxrangespeed/4)*3;
    float bms2= (maxbmaxrangespeed/3);    

    float Btime;
    int h;
    
    int CBD=0;
    float Bshellalltime = 0;
    float timetodestroyEships=0;


    for(h=0;h<N;h++) //checking battleship is in escort ships range
    {

        float maxRange=0, minRange=0;
        float maxVel, maxAng, minVel, minAng,velocity,angle,range;
        float maxVelocity,Btime,minVelocity;

        //calculate max velocity and min velocity of e ships
        maxVelocity=(float)rand()/RAND_MAX*(maxbmaxrangespeed-bms)+bms;
        minVelocity=(float)rand()/RAND_MAX*(bms-bms2)+bms2;

        if (shipData[h].maxvelocity == 'D') 
        {
            maxVelocity = (1.2 * maxbmaxrangespeed);            
        } 
        
        velocity=(float)rand()/RAND_MAX*(maxVelocity - minVelocity) +minVelocity;



            for (angle = eships[h].minangle; angle <= eships[h].maxfinalangle; angle++) 
            {
                range = calculateRange(velocity, angle);
                 
                if (range > maxRange) 

                {

                     maxRange = range;
                     eships[h].maxvel = velocity;                    
                     maxAng = angle;                   
                }
                else
                {
                    minRange = range;
                    eships[h].minvel = velocity;                    
                    minAng = angle;   
                }
           }        
        

        float distance = calculateDistance(BX, BY, ships[h].locx, ships[h].locy);       

        if (distance <= maxRange && distance>= minRange) 
        {
            printf("\nBattle ship is in Escortship no %d (type %s) range.distance is %f",h+1,ships[h].ntype,distance); 
            int Eangle;
            int g = 0;
            destroyship(ships,shipData, bt,velocity,Eangle,distance,h,Bshellalltime,outputFile2,g);
            CBD++;
        } 

    }    

    //Confirming battleship destroyed or not.
    if (CBD>0) 
    {
        printf("\n\nBattleship got destroyed by above Escortships.\n");
    }
    else 
    {        
        printf("\n\nBattleship is not in any escortships ranges\n");

        float randomBvelocity =maxbmaxrangespeed;
       
        
        Btime = searchEShips(ships,eships,N, BX, BY, searchRadius,bt,randomBvelocity,Bshellalltime,timetodestroyEships,outputFile2);// Check what escorships are in battleships range 

        if (Btime>0)
        {
        printf("\nIt took %f seconds to Destroy Escortships.\n",Btime);//Display time to destroy escortships
        }


        
        
    }
    fclose(outputFile2);
    finaltext(file1,file2);
    return 0;
}


//-------------------------------------------------------------------------------------------------SIMULATION 2
///////////////////////////////////////////////////////////////////////////////////////////////////////////////



int s1b(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData)
{
    FILE *outputFile2 = fopen("savenew.txt", "w"); // open file to write data
    if (outputFile2 == NULL)
    {
        printf("Error creating the output file.\n");
        fclose(outputFile2);
        return 1;
    }

    int c = eshipsettings(shipData);//get escort ship data
    
    //defining the canvas 
    int N, canvasSizeX, canvasSizeY;
    do
    {     
     printf("\nEnter the canvas square size(10 - 1000) D=D:= ");
     scanf("%d", &canvasSizeX);
    }while(canvasSizeX<10 || canvasSizeX >1000);

    canvasSizeY= canvasSizeX;
    int csx = canvasSizeX + 1;
    int csy = canvasSizeY + 1;

                                                                                 //Escort ship 
    //getting escortship number from the user
    do 
    {
    printf("\nEnter number of escort ships (Less than 1000):");
    scanf("%d", &N);
    }while(N<1 || N >1000);  


    generateRandomEscortships(ships,shipData,N,csx,csy);//Generate random  e ships and  other things of e ships

    int  x;
    float finalminimumangle; 

    for(x=0;x<c;x++)//checking escortship minimum angles and maximum angles    
    {    
      eships[x].minangle = minimumanglecheck(shipData,shipData[x].minimumangle,finalminimumangle,x);
      eships[x].maxfinalangle = eships[x].minangle + shipData[x].anglerange;
      printf("\nEscortship %c ship min angle is %f and max angle %f:",shipData[x].typenotation,eships[x].minangle,eships[x].maxfinalangle);

    }        
    

                                                                            //Battleship 
    
    Bdetails(bshipData);//Print battleship data
    char bt;
    do
    {
        printf("\n\nEnter the Battleship type: ");//Getting battle ship data from user
        scanf(" %c", &bt);
    } while (checkbt(bt) != 1);
    

    float maxbmaxrangespeed = bmaxrangespeed(canvasSizeX);//max shell speed of
     
    printf("\nBattleships max range velocity : %f",maxbmaxrangespeed);


    int BX, BY,BNX,BNY;
    double searchRadius = (canvasSizeX/2);//battleship radius is half of the canvas
    
    do
    {
        printf("\nEnter the Battleship location point (x y): ");//battleship starting location
       
        scanf("%d %d", &BX, &BY);
       
        checkSearch(BX, BY, csx, csy);
        printf("\nEnter the Battleship next location point (x y): ");//battleship ending location
       
        scanf("%d %d", &BNX, &BNY);
        
        checkSearch(BNX, BNY, csx, csy);

   
        
    } while (BX < 0 || BX > csx || BY < 0 || BY > csy||BNX < 0 || BNX > csx || BNY < 0 || BNY > csy||BX==BNX||BY==BNY);

    //use to find  max and min battleship shell speeds
    float bms = (maxbmaxrangespeed/4)*3;
    float bms2= (maxbmaxrangespeed/3);

     // find the path 
    int maxXl,maxYl,minXl,minYl;
    if (BNX>BX)
    {
        maxXl=BNX;
        minXl=BX;
    }
    else
    {
        maxXl=BX;
        minXl=BNX;
    }
    if (BNY>BY)
    {
        maxYl=BNY;
        minYl=BY;
    }
    else
    {
        maxYl=BY;
        minYl=BNY;
    }
    
    int j=(canvasSizeX/10);
    int NX=minXl;
    int NY=minYl;
    int CBD=0;
    float Btime;
    float time =0;

    //change the location of battle ship using while loop

    while(NX <=minXl || NY<=maxYl)
    {
            if (CBD>=1)// if battle ship is destroyed looping will stop
            {
                break;
            }
            else if(CBD<1)
            {

                BY=NY;
                BX=NX;

                printf("\nBattleship current location is (%d,%d)\n",BX,BY);

                 ///--------------------------------------------------------------//determine what ship is going to sink.
                
                int h;
                
                
                float Bshellalltime = 0;
                float timetodestroyEships=0;


                
                for(h=0;h<N;h++)
                {
                    //check if the escortship is destroyed or not
                    if (checkdestroy(ships,h)!=1)
                    {

                        float maxRange=0, minRange=0;
                        
                        float maxVel, maxAng, minVel, minAng,velocity,angle,range;
                        float maxVelocity,Btime,minVelocity;

                        float maxV=(float)rand()/RAND_MAX*(maxbmaxrangespeed-bms)+bms;

                        float minV=(float)rand()/RAND_MAX*(bms-bms2)+bms2;

                        if(minV<maxV)
                        {
                            minVelocity = minV;
                            maxVelocity = maxV;
                        }
                        
                        if(minVel>maxVel)
                        {
                            minVelocity = maxV;
                            maxVelocity = minV;
                        }
                                        
                        if (shipData[h].maxvelocity == 'D') 
                        {
                            maxVelocity = (1.2 * maxbmaxrangespeed);                            
                        } 
                        
                        //calculate escortship velocity to find min and max angles and min and max ranges
                        velocity=(float)rand()/RAND_MAX*(maxVelocity - minVelocity) +minVelocity;

                            for (angle = eships[h].minangle; angle <= eships[h].maxfinalangle; angle++) 
                            {
                                range = calculateRange(velocity, angle);
                                
                                if (range > maxRange) 

                                {

                                    maxRange = range;
                                    eships[h].maxvel = velocity;                                    
                                    maxAng = angle;                                    
                                }
                                else
                                {
                                    minRange = range;
                                    eships[h].minvel = velocity;                                    
                                    minAng = angle;   
                                }
                        }        
                        
                        //calculate distance between bship and Eship

                        float distance = calculateDistance(BX, BY, ships[h].locx, ships[h].locy);

                        if (distance <= maxRange && distance>= minRange) 
                        {
                            printf("\nBattle ship is in Escortship no %d (type %s) range.distance is %f",h+1,ships[h].ntype,distance); 
                            int Eangle;
                            int g =0;
                            destroyship(ships,shipData, bt,velocity,Eangle,distance,h,Bshellalltime,outputFile2,g);//destroy b ship
                            CBD++;
                        } 

                    }                   
                }

                //check wether b ship destroyed or not and print to a file what eship destryed the Bship

                if (CBD>0)
                {
                    printf("\n\nBattleship in (%d,%d) got destroyed   by above Escortship/ships.\n",BX,BY);
                        
                    int g=1;
                    
                }
                else 
                {        
                    printf("\n\nBattleship is not in any escortships ranges\n");

                    float randomBvelocity =maxbmaxrangespeed;
                    
                    Btime = searchEShips2(ships,eships,N, BX, BY, searchRadius,bt,randomBvelocity,Bshellalltime,timetodestroyEships,outputFile2);

                    if (Btime>0)
                    {
                    printf("\nIt took %f seconds to Destroy Escortships.\n",Btime);
                    }
                        
                     
                } 
            }

            NX+=j;
            NY+=j;
            time = time + Btime;

    }
    printf("\n\nIt took %f seconds to end the battle\n",time);
    fclose(outputFile2);
    finaltext(file1,file2);
    return 0;
}


//-------------------------------------------------------------------------------------------------SIMULATION 3
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


int s1b2(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData)
{
    FILE *outputFile2 = fopen("savenew.txt", "w"); // open file to write data
    if (outputFile2 == NULL)
    {
        printf("Error creating the output file.\n");
        fclose(outputFile2);
        return 1;
    }


    int c = eshipsettings(shipData);//get escortship details
   
    int N, canvasSizeX, canvasSizeY;
    do
    {     
     printf("\nEnter the canvas square size(10 - 1000) D=D:= ");
     scanf("%d", &canvasSizeX);
    }while(canvasSizeX<10 || canvasSizeX >1000);

    canvasSizeY= canvasSizeX;
    int csx = canvasSizeX + 1;
    int csy = canvasSizeY + 1;

                                                                                 //Escort ship 

    do 
{
    printf("\nEnter number of escort ships (Less than 1000):");
    scanf("%d", &N);
}while(N<1 || N >1000);

    srand(time(NULL));

    
    generateRandomEscortships(ships,shipData,N,csx,csy);//Generate random  e ships and  other things of e ships

    int  x;
    float finalminimumangle; 

    for(x=0;x<c;x++)
    {    
      eships[x].minangle = minimumanglecheck(shipData,shipData[x].minimumangle,finalminimumangle,x);
      eships[x].maxfinalangle = eships[x].minangle + shipData[x].anglerange;
      printf("\nEscortship %c ship min angle is %f and max angle %f:",shipData[x].typenotation,eships[x].minangle,eships[x].maxfinalangle);

    }        
    

                                                                            //Battleship 
    
    Bdetails(bshipData);//Print battleship data
    char bt;
    do
    {
        printf("\n\nEnter the Battleship type: ");
        scanf(" %c", &bt);
    } while (checkbt(bt) != 1);
    

    float maxbmaxrangespeed = bmaxrangespeed(canvasSizeX);
     
    printf("\nBattleships max range velocity : %f",maxbmaxrangespeed);


    float randomBangle = ((float)rand()/RAND_MAX) * 90;
    
    printf("\nRandom angle of Battleship is: %f\n",randomBangle);

    int BX, BY,BNX,BNY;
    double searchRadius = (canvasSizeX/2);

    float BNMin = ((float)rand()/RAND_MAX)*(30 - 0);//After jammming
    float NBangle=((float)rand()/RAND_MAX)*(90 - BNMin);//Angle of battle ship after jamming 
    
    do
    {
        printf("\nEnter the Battleship location point (x y): ");
       
        scanf("%d %d", &BX, &BY);
       
        checkSearch(BX, BY, csx, csy);
        printf("\nEnter the Battleship next location point (x y): ");
       
        scanf("%d %d", &BNX, &BNY);
        
        checkSearch(BNX, BNY, csx, csy);

   
        
    } while (BX < 0 || BX > csx || BY < 0 || BY > csy||BNX < 0 || BNX > csx || BNY < 0 || BNY > csy||BX==BNX||BY==BNY);

    float bms = (maxbmaxrangespeed/4)*3;
    float bms2= (maxbmaxrangespeed/3);
    int jamcheck=0;

     // find the path 
    int maxXl,maxYl,minXl,minYl;
    if (BNX>BX)
    {
        maxXl=BNX;
        minXl=BX;
    }
    else
    {
        maxXl=BX;
        minXl=BNX;
    }
    if (BNY>BY)
    {
        maxYl=BNY;
        minYl=BY;
    }
    else
    {
        maxYl=BY;
        minYl=BNY;
    }
    
    int j=(canvasSizeX/10);
    int NX=minXl;
    int NY=minYl;
    int CBD=0;
    float Btime;
    float time =0;

    while(NX <=minXl || NY<=maxYl)
    {
            if (CBD>=1)
            {
                break;
            }
            else if(CBD<1)
            {

                BY=NY;
                BX=NX;

                printf("\n\n\n--------------Battleship current location is (%d,%d)\n",BX,BY);

                                            //determine what ship is going to sink.
                
                int h;
                
                
                float Bshellalltime = 0;
                float timetodestroyEships=0;



                for(h=0;h<N;h++)
                {
                    
                    if (checkdestroy(ships,h)!=1)//check e ship destroyed or not 
                    {

                        float maxRange=0, minRange=0;
                        
                        float maxVel, maxAng, minVel, minAng,velocity,angle,range;
                        float maxVelocity,Btime,minVelocity;

                        maxVelocity=(float)rand()/RAND_MAX*(maxbmaxrangespeed-bms)+bms;
                        minVelocity=(float)rand()/RAND_MAX*(bms-bms2)+bms2;                        
       
                        if (shipData[h].maxvelocity == 'D') 
                        {
                            maxVelocity = (1.2 * maxbmaxrangespeed);                           
                        } 
                        
                        velocity=(float)rand()/RAND_MAX*(maxVelocity - minVelocity) +minVelocity;

                        if(NX >=(minXl/2) && NY>=(maxYl/2) && CBD==0 && jamcheck == 0)//after jamming B ship angle will be changed
                        {
                            randomBangle=NBangle;
                            printf("\n------------------Gun on Battleship  is now jammed------------------\n");  
                            jamcheck++;                          
                        }
                        if(NX >=(minXl/2) && NY>=(maxYl/2) && CBD==0)
                        {
                            jamcheck++; 
                        }


                            for (angle = eships[h].minangle; angle <= eships[h].maxfinalangle; angle++) 
                            {
                                range = calculateRange(velocity, angle);
                                
                                if (range > maxRange) 

                                {

                                    maxRange = range;
                                    eships[h].maxvel = velocity;                                    
                                    maxAng = angle;                                    
                                }
                                else
                                {
                                    minRange = range;
                                    eships[h].minvel = velocity;                                    
                                    minAng = angle;   
                                }
                        }        
                        
                        float distance = calculateDistance(BX, BY, ships[h].locx, ships[h].locy);                      

                        if (distance <= maxRange && distance>= minRange) 
                        {
                            printf("\nBattle ship is in Escortship no %d (type %s) range.distance is %f",h+1,ships[h].ntype,distance); 
                            int Eangle;
                            int g=0;
                            destroyship(ships,shipData, bt,velocity,Eangle,distance,h,Bshellalltime,outputFile2,g);//search and destroy batttleship
                            CBD++;
                        } 
                    }                   
                }

                if (CBD>0)
                {
                    printf("\n\nBattleship in (%d,%d) got destroyed   by above Escortship/ships.\n",BX,BY);
                        
                        int g=1;
                         
                }
                else 
                {        
                    printf("\n\nBattleship is not in any escortships ranges\n");

                    float randomBvelocity =maxbmaxrangespeed;
                    
                    Btime = searchEShips3(ships,eships,N, BX, BY, searchRadius,bt,randomBvelocity,Bshellalltime,timetodestroyEships,jamcheck,outputFile2);//search and destroy escort  ships

                    if (Btime>0)
                    {
                    printf("\nIt took %f seconds to Destroy Escortships.\n",Btime);
                    }

                     
                     
                } 
            }

            NX+=j;
            NY+=j;
            time = time + Btime;

    }
    printf("\n\nIt took %f seconds to end the battle\n",time);
    
    fclose(outputFile2);
    finaltext(file1,file2);
    return 0;
}



//-------------------------------------------------------------------------------------------------SIMULATION 4
///////////////////////////////////////////////////////////////////////////////////////////////////////////////



int s1c(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData)
{
    FILE *outputFile2 = fopen("savenew.txt", "w"); // open file to write data
    if (outputFile2 == NULL)
    {
        printf("Error creating the output file.\n");
        fclose(outputFile2);
        return 1;
    }

    int c = eshipsettings(shipData);

    int N, canvasSizeX, canvasSizeY;
    do
    {     
     printf("\nEnter the canvas square size(10 - 1000) D=D:= ");
     scanf("%d", &canvasSizeX);
    }while(canvasSizeX<10 || canvasSizeX >1000);

    canvasSizeY= canvasSizeX;
    int csx = canvasSizeX + 1;
    int csy = canvasSizeY + 1;

                                                                                 //Escort ship 
do 
{
    printf("\nEnter number of escort ships (Less than 1000):");
    scanf("%d", &N);
}while(N<1 || N >1000);

    
    generateRandomEscortships(ships,shipData,N,csx,csy);//Generate random  e ships and  other things of e ships

    int  x;
    float finalminimumangle; 

    for(x=0;x<c;x++)
    {    
      eships[x].minangle = minimumanglecheck(shipData,shipData[x].minimumangle,finalminimumangle,x);
      eships[x].maxfinalangle = eships[x].minangle + shipData[x].anglerange;
      printf("\nEscortship %c ship min angle is %f and max angle %f:",shipData[x].typenotation,eships[x].minangle,eships[x].maxfinalangle);
    }        

                                                                            //Battleship 
    Bdetails(bshipData);//Print battleship data
    char bt;
    do
    {
        printf("\n\nEnter the Battleship type: ");
        scanf(" %c", &bt);
    } while (checkbt(bt) != 1);

    float maxbmaxrangespeed = bmaxrangespeed(canvasSizeX);
     
    printf("\nBattleships max range velocity : %f",maxbmaxrangespeed);

    float randomBangle = ((float)rand()/RAND_MAX) * 90;
    
    printf("\nRandom angle of Battleship is: %f",randomBangle);


    int BX, BY;
    float searchRadius = (canvasSizeX/2);

    do
    {
        printf("\nEnter the Battleship location point (x y): ");
        scanf("%d %d", &BX, &BY);
        checkSearch(BX, BY, csx, csy);
    } while (BX < 0 || BX > csx || BY < 0 || BY > csy);


                                                    //determine what ship is going to sink.

    int bh = 100;
    int jamcheck =0;
    float impactpower;
    float bms = (maxbmaxrangespeed/4)*3;
    float bms2= (maxbmaxrangespeed/3);
                                               

    float Btime;
    int h;
    
    int CBD=0;
    float Bshellalltime = 0;
    float timetodestroyEships=0;

    for(h=0;h<N;h++)
    {
        
        float maxRange=0, minRange=0;
        float maxVel, maxAng, minVel, minAng,velocity,angle,range;
        float maxVelocity,Btime,minVelocity;

        maxVelocity=(float)rand()/RAND_MAX*(maxbmaxrangespeed-bms)+bms;
        minVelocity=(float)rand()/RAND_MAX*(bms-bms2)+bms2;

        if (shipData[h].maxvelocity == 'D') 
        {
            maxVelocity = (1.2 * maxbmaxrangespeed);            
        } 
        
        velocity=(float)rand()/RAND_MAX*(maxVelocity - minVelocity) +minVelocity;



            for (angle = eships[h].minangle; angle <= eships[h].maxfinalangle; angle++) 
            {
                range = calculateRange(velocity, angle);
                 
                if (range > maxRange) 

                {

                     maxRange = range;
                     eships[h].maxvel = velocity;                     
                     maxAng = angle;
                     
                }
                else
                {
                    minRange = range;
                    eships[h].minvel = velocity;                    
                    minAng = angle;   
                }
           }        
        
        float distance = calculateDistance(BX, BY, ships[h].locx, ships[h].locy);        

                               if (distance <= maxRange && distance>= minRange) 
                                {
                                    
                                    printf("\nBattle ship is in Escortship no %d (type %s) range.distance is %f",h+1,ships[h].ntype,distance);

                                     char *searchtype = ships[h].ntype; 


                                        for (int i = 0; i < 5; i++)
                                        {
                                         if (shipData[i].typenotation == *searchtype)
                                         {
                                            impactpower = shipData[i].impactpower;//check impact power of e ships
                                         }
                                        }

                                    printf("\nBattleship got hit and damaged.Impact power of the escortship is %f\n",impactpower);
                                    int Eangle;
                                    destroyship3(ships,shipData, bt,velocity,Eangle,distance,h,outputFile2,Bshellalltime);

                                    bh = bh - (impactpower*100);//If b ship got hit health will be reduced.

                                    printf("\nBattleship health is %d ",bh); 

                                    if (bh <=0)
                                    {   
                                    int g=0;
                                    destroyship(ships,shipData, bt,velocity,Eangle,distance,h,Bshellalltime,outputFile2,g);//destroy b ship
                                    printf("\n\nBattleship in (%d,%d) got destroyed   by above Escortship/ships.\n",BX,BY);       
                                    CBD++;
                                    
                                    
                                    }

                                }      
    }

                if (CBD==0)
              
                {        
                    printf("\n\nBattleship is not in any escortships ranges\n");

                    float randomBvelocity =maxbmaxrangespeed;
                    
                    Btime = searchEShips2(ships,eships,N, BX, BY, searchRadius,bt,randomBvelocity,Bshellalltime,timetodestroyEships,outputFile2);
                    if (Btime>0)
                    {
                    printf("\nIt took %f seconds to Destroy Escortships.\n",Btime);
                    }

                    printf("\nBattleship health is %d \n",bh); 

                    
                    
                } 
    fclose(outputFile2);
    finaltext(file1,file2);            
    return 0;

}


//-------------------------------------------------------------------------------------------------SIMULATION 5
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


int s1c1(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData)
{
    FILE *outputFile2 = fopen("savenew.txt", "w"); // open file to write data
    if (outputFile2 == NULL)
    {
        printf("Error creating the output file.\n");
        fclose(outputFile2);
        return 1;
    }

    int c = eshipsettings(shipData);
    int N, canvasSizeX, canvasSizeY;
    do
    {     
     printf("\nEnter the canvas square size(10 - 1000) D=D:= ");
     scanf("%d", &canvasSizeX);
    }while(canvasSizeX<10 || canvasSizeX >1000);

    canvasSizeY= canvasSizeX;
    int csx = canvasSizeX + 1;
    int csy = canvasSizeY + 1;

                                                                                 //Escort ship 

    do 
    {
        printf("\nEnter number of escort ships (Less than 1000):");
        scanf("%d", &N);
    }while(N<1 || N >1000);  
    
    generateRandomEscortships(ships,shipData,N,csx,csy);//Generate random  e ships and  other things of e ships

    int  x;
    float finalminimumangle; 

    for(x=0;x<c;x++)
    {    
      eships[x].minangle = minimumanglecheck(shipData,shipData[x].minimumangle,finalminimumangle,x);
      eships[x].maxfinalangle = eships[x].minangle + shipData[x].anglerange;
      printf("\nEscortship %c ship min angle is %f and max angle %f:",shipData[x].typenotation,eships[x].minangle,eships[x].maxfinalangle);

    }        

                                                                            //Battleship 
    
    Bdetails(bshipData);//Print battleship data
    char bt;
    do
    {
        printf("\n\nEnter the Battleship type: ");
        scanf(" %c", &bt);
    } while (checkbt(bt) != 1);
    

    float maxbmaxrangespeed = bmaxrangespeed(canvasSizeX);
     
    printf("\nBattleships max range velocity : %f",maxbmaxrangespeed);


    float randomBangle = ((float)rand()/RAND_MAX) * 90;
    
    printf("\nRandom angle of Battleship is: %f",randomBangle);

    int BX, BY,BNX,BNY;
    double searchRadius = (canvasSizeX/2);

    do
    {
        printf("\nEnter the Battleship location point (x y): ");
       
        scanf("%d %d", &BX, &BY);
       
        checkSearch(BX, BY, csx, csy);
        printf("\nEnter the Battleship next location point (x y): ");
       
        scanf("%d %d", &BNX, &BNY);
        
        checkSearch(BNX, BNY, csx, csy);

   
        
    } while (BX < 0 || BX > csx || BY < 0 || BY > csy||BNX < 0 || BNX > csx || BNY < 0 || BNY > csy||BX==BNX||BY==BNY);

    int bh = 100;
    int jamcheck =0;
    float impactpower;
    float bms = (maxbmaxrangespeed/4)*3;
    float bms2= (maxbmaxrangespeed/3);

     // find the path 
    int maxXl,maxYl,minXl,minYl;
    if (BNX>BX)
    {
        maxXl=BNX;
        minXl=BX;
    }
    else
    {
        maxXl=BX;
        minXl=BNX;
    }
    if (BNY>BY)
    {
        maxYl=BNY;
        minYl=BY;
    }
    else
    {
        maxYl=BY;
        minYl=BNY;
    }
    
    int j=(canvasSizeX/10);
    int NX=minXl;
    int NY=minYl;
    int CBD=0;
    float Btime;
    float time;

    //change location using while loop
    while(NX <=minXl || NY<=maxYl)
    {
            if (CBD>=1)//check b ship destroyed or not
            {
                break;
            }
            else if(CBD<1)
            {

                BY=NY;
                BX=NX;

                printf("\n\n\n--------------Battleship current location is (%d,%d)\n",BX,BY);

                                                                //determine what ship is going to sink.

                int h;

                float Bshellalltime = 0;
                float timetodestroyEships=0;

                for(h=0;h<N;h++)
                {
                    if(CBD >=1)    
                    {
                        break;
                    }
                    else if(CBD == 0)
                    {
                     
                    
                                if (checkdestroy(ships,h)!=1)//check escort ships are destoyed or not
                                {

                                    float maxRange=0, minRange=0;
                                    
                                    float maxVel, maxAng, minVel, minAng,velocity,angle,range;
                                    float maxVelocity,Btime,minVelocity;

                                    maxVelocity=(float)rand()/RAND_MAX*(maxbmaxrangespeed-bms)+bms;
                                    minVelocity=(float)rand()/RAND_MAX*(bms-bms2)+bms2;                                

                                    if (shipData[h].maxvelocity == 'D') 
                                    {
                                        maxVelocity = (1.2 * maxbmaxrangespeed);
                                    } 

                                    velocity=(float)rand()/RAND_MAX*(maxVelocity - minVelocity) +minVelocity;

                                        for (angle = eships[h].minangle; angle <= eships[h].maxfinalangle; angle++) 
                                        {
                                            range = calculateRange(velocity, angle);
                                            
                                            if (range > maxRange) 

                                            {

                                                maxRange = range;
                                                eships[h].maxvel = velocity;                                                
                                                maxAng = angle;
                                               
                                            }
                                            else
                                            {
                                                minRange = range;
                                                eships[h].minvel = velocity;                                                
                                                minAng = angle;   
                                            }
                                    }       


                                    float distance = calculateDistance(BX, BY, ships[h].locx, ships[h].locy);

                               if (distance <= maxRange && distance>= minRange) 
                                {
                                    
                                    printf("\nBattle ship is in Escortship no %d (type %s) range.distance is %f",h+1,ships[h].ntype,distance);

                                     char *searchtype = ships[h].ntype; 


                                        for (int i = 0; i < 5; i++)
                                        {
                                         if (shipData[i].typenotation == *searchtype)
                                         {
                                            impactpower = shipData[i].impactpower;//check impact power of e ship
                                         }
                                        }

                                    printf("\nBattleship got hit and damaged.Impact power of the escortship is %f\n",impactpower);
                                    int Eangle;
                                    destroyship3(ships,shipData, bt,velocity,Eangle,distance,h,outputFile2,Bshellalltime);

                                    bh = bh - (impactpower*100);//If b ship got hit health will be reduced 
                                    printf("\nBattleship health is %d ",bh); 

                                    if (bh <=0)
                                    {   
                                    int g=0;

                                    destroyship(ships,shipData, bt,velocity,Eangle,distance,h,Bshellalltime,outputFile2,g);//destroy b ship
                                    printf("\n\nBattleship in (%d,%d) got destroyed   by above Escortship/ships.\n",BX,BY);       
                                    CBD++;
                                  
                                    }
                                } 
                                }
                    }
                }

                if (CBD==0)
              
                {        
                    printf("\n\nBattleship is not in any escortships ranges\n");

                    float randomBvelocity =maxbmaxrangespeed;
                    
                    Btime = searchEShips2(ships,eships,N, BX, BY, searchRadius,bt,randomBvelocity,Bshellalltime,timetodestroyEships,outputFile2);
                            
                    if (Btime>0)
                    {
                    printf("\nIt took %f seconds to Destroy Escortships.\n",Btime);
                    }

                    printf("\nBattleship health is %d \n",bh); 

                    
                    
                } 
            }

            NX+=j;
            NY+=j;
            time = time + Btime;

    }
    fclose(outputFile2);
    finaltext(file1,file2);
    printf("\n\nIt took %f seconds to end the battle\n",time);
    return 0;
}


//-------------------------------------------------------------------------------------------------SIMULATION 6
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


int s1c2(struct shipData *shipData,struct textfile1 *file1,struct textfile2 *file2,struct bshipData *bshipData)
{
    FILE *outputFile2 = fopen("savenew.txt", "w"); // open file to write data
    if (outputFile2 == NULL)
    {
        printf("Error creating the output file.\n");
        fclose(outputFile2);
        return 1;
    }

    int c = eshipsettings(shipData);//read escortship data
    

    int N, canvasSizeX, canvasSizeY;
    do
    {     
     printf("\nEnter the canvas square size(10 - 1000) D=D:= ");
     scanf("%d", &canvasSizeX);
    }while(canvasSizeX<10 || canvasSizeX >1000);

    canvasSizeY= canvasSizeX;
    int csx = canvasSizeX + 1;
    int csy = canvasSizeY + 1;

                                                                                 //Escort ship 

     do 
    {
        printf("\nEnter number of escort ships (Less than 1000):");
        scanf("%d", &N);
    }while(N<1 || N >1000);

    
    generateRandomEscortships(ships,shipData,N,csx,csy);//Generate random  e ships and  other things of e ships

    int  x;
    float finalminimumangle; 

    for(x=0;x<c;x++)
    {    
      eships[x].minangle = minimumanglecheck(shipData,shipData[x].minimumangle,finalminimumangle,x);
      eships[x].maxfinalangle = eships[x].minangle + shipData[x].anglerange;
      printf("\nEscortship %c ship min angle is %f and max angle %f:",shipData[x].typenotation,eships[x].minangle,eships[x].maxfinalangle);

    }        
    

                                                                            //Battleship 
    
    Bdetails(bshipData);//Print battleship data

    char bt;
    do
    {
        printf("\n\nEnter the Battleship type: ");
        scanf(" %c", &bt);
    } while (checkbt(bt) != 1);
    

    float maxbmaxrangespeed = bmaxrangespeed(canvasSizeX);
     
    printf("\nBattleships max range velocity : %f",maxbmaxrangespeed);


    float randomBangle = ((float)rand()/RAND_MAX) * 90;
    
    printf("\nRandom angle of Battleship is: %f\n",randomBangle);

    int BX, BY,BNX,BNY;
    double searchRadius = (canvasSizeX/2);


    do
    {
        printf("\nEnter the Battleship location point (x y): ");
       
        scanf("%d %d", &BX, &BY);
       
        checkSearch(BX, BY, csx, csy);
        printf("\nEnter the Battleship next location point (x y): ");
       
        scanf("%d %d", &BNX, &BNY);
        
        checkSearch(BNX, BNY, csx, csy);

   
        
    } while (BX < 0 || BX > csx || BY < 0 || BY > csy||BNX < 0 || BNX > csx || BNY < 0 || BNY > csy||BX==BNX||BY==BNY);

    int bh = 100;
    int jamcheck =0;
    float impactpower;
    float bms = (maxbmaxrangespeed/4)*3;
    float bms2= (maxbmaxrangespeed/3);


     // find the path 
    int maxXl,maxYl,minXl,minYl;
    if (BNX>BX)
    {
        maxXl=BNX;
        minXl=BX;
    }
    else
    {
        maxXl=BX;
        minXl=BNX;
    }
    if (BNY>BY)
    {
        maxYl=BNY;
        minYl=BY;
    }
    else
    {
        maxYl=BY;
        minYl=BNY;
    }
    
    int j=(canvasSizeX/10);
    int NX=minXl;
    int NY=minYl;
    int CBD=0;
    float Btime;
    float time;

    while(NX <=minXl || NY<=maxYl)
    {
            if (CBD>=1)
            {
                break;
            }
            else if(CBD<1)
            {

                BY=NY;
                BX=NX;

                printf("\n\n\n--------------Battleship current location is (%d,%d)\n",BX,BY);

                                                                //determine what ship is going to sink.
                
                int h;
                
                
                float Bshellalltime = 0;
                float timetodestroyEships=0;



                for(h=0;h<N;h++)
                {
                    
                    if(CBD >=1)    
                    {
                        break;
                    }
                    else if(CBD == 0)
                    {
                    
                    if (checkdestroy(ships,h)!=1)
                            {

                                float maxRange=0, minRange=0;
                                
                                float maxVel, maxAng, minVel, minAng,velocity,angle,range;
                                float maxVelocity,Btime,minVelocity;

                                maxVelocity=(float)rand()/RAND_MAX*(maxbmaxrangespeed-bms)+bms;

                                minVelocity=(float)rand()/RAND_MAX*(bms-bms2)+bms2;
                               
                                if (shipData[h].maxvelocity == 'D') 
                                {
                                    maxVelocity = (1.2 * maxbmaxrangespeed);
                                } 
                                
                                velocity=(float)rand()/RAND_MAX*(maxVelocity - minVelocity) +minVelocity;
                                
                                if(NX >=(minXl/2) && NY>=(maxYl/2) && CBD==0 && jamcheck ==0)///////////////////////jam check 
                                {
                                    
                                    printf("\n------------------Gun on Battleship is now jammed------------------\n");  
                                    jamcheck++;                          
                                }

                                 if(NX >=(minXl/2) && NY>=(maxYl/2) && CBD==0)
                                {
                                    jamcheck++;                                                      
                                }



                                    for (angle = eships[h].minangle; angle <= eships[h].maxfinalangle; angle++) 
                                    {
                                        range = calculateRange(velocity, angle);
                                        
                                        if (range > maxRange) 

                                        {

                                            maxRange = range;
                                            eships[h].maxvel = velocity;                                        
                                            maxAng = angle;
                                           
                                        }
                                        else
                                        {
                                            minRange = range;
                                            eships[h].minvel = velocity;                                            
                                            minAng = angle;   
                                        }
                                }        
                                
                                float distance = calculateDistance(BX, BY, ships[h].locx, ships[h].locy);

                                if (distance <= maxRange && distance>= minRange) 
                                {
                                    
                                    printf("\nBattle ship is in Escortship no %d (type %s) range.distance is %f",h+1,ships[h].ntype,distance);

                                     char *searchtype = ships[h].ntype; 


                                        for (int i = 0; i < 5; i++)
                                        {
                                         if (shipData[i].typenotation == *searchtype)
                                         {
                                            impactpower = shipData[i].impactpower;//check impact power of e ship
                                         }
                                        }

                              


                                    printf("\nBattleship got hit and damaged.Impact power of the escortship is %f\n",impactpower);
                                    int Eangle;
                                    destroyship3(ships,shipData, bt,velocity,Eangle,distance,h,outputFile2,Bshellalltime);
                                    
                                    
                                    

                                    bh = bh - (impactpower*100);//reduce health of b ship  if hit
                                    printf("\nBattleship health is %d ",bh); 

                                    if (bh <=0)
                                    {   
                                    int g=0;
                                    destroyship(ships,shipData, bt,velocity,Eangle,distance,h,Bshellalltime,outputFile2,g);//destroy b ship

                                    printf("\n\nBattleship in (%d,%d) got destroyed   by above Escortship/ships.\n",BX,BY);       
                                    CBD++;                             
                                    
                                    
                                    }           
                                
                                } 
                            } 
                    }                  
                }

                if (CBD==0)

                {        
                    printf("\n\nBattleship is not in any escortships ranges\n");

                    float randomBvelocity =maxbmaxrangespeed;
                    
                    Btime = searchEShips3(ships,eships,N, BX, BY, searchRadius,bt,randomBvelocity,Bshellalltime,timetodestroyEships,jamcheck,outputFile2);//search and destroy escort  ships

                    printf("\nBattleship health is %d \n",bh); 

                    if (Btime>0)
                    {
                    printf("\nIt took %f seconds to Destroy Escortships.\n",Btime);
                    }                  
                    
                    
                } 
            }

            NX+=j;
            NY+=j;
            time = time + Btime;

    }
    fclose(outputFile2);
    printf("\n\nIt took %f seconds to end the battle\n",time);
    finaltext(file1,file2);
    
    return 0;
}

//Function to search escortships 
float searchEShips(struct eship *ships,struct Eshipvalues *eships, int N, int x, int y,float radius,char bt,float randomBvelocity,float Bshellalltime,float timetodestroyEships,FILE *outputFile2)
{
    printf("\nSearching for Escort ships within the radius of %.2f from point (%d, %d):\n", radius, x, y);    

    int shipsFound = 0;
    float Bangle;
    float distance;    
    
    for (int i = 0; i < N; i++)
    {
        distance = calculateDistance(x, y, ships[i].locx, ships[i].locy);// calculate distance 
        eships[i].distancetoB = distance;
        
        if (distance <= radius)
        {                  
            shipsFound++;
            
            
            printf("\nShip %d: Type: %s, Location: (%d, %d), Distance: %.2f  ", i + 1, ships[i].ntype, ships[i].locx, ships[i].locy, distance);
            
            int g=1;
            float l = destroyship(ships,shipData, bt, randomBvelocity, Bangle,distance,i,Bshellalltime,outputFile2,g);//desroy ship
            
            timetodestroyEships = timetodestroyEships + l;

            printf(" got destroyed by the Battleship\n");

            printf("\nTime to destroy no %d escortship is %f\n",i+1,l);

        }
        else if (distance > radius)
        {
            int g =2;
            destroyship(ships,shipData, bt, randomBvelocity, Bangle,distance,i,Bshellalltime,outputFile2,g);
        }
        
    }  
    
    
    if (shipsFound==0)
    {
        printf("\nNo Escort ships found within the specified radius.\n");
        return 0;
    }
    else
    {
    return (timetodestroyEships);// return time to destroy
    }
}



//same as seachEship but at first this check escortship destroyed or not 
float searchEShips2(struct eship *ships,struct Eshipvalues *eships, int N, int x, int y,float radius,char bt,float randomBvelocity,float Bshellalltime,float timetodestroyEships,FILE *outputFile2)
{
    printf("\nSearching for Escort ships within the radius of %.2f from point (%d, %d):\n", radius, x, y);    

    int shipsFound = 0;
    float Bangle;
    float distance;    
    
    for (int i = 0; i < N; i++)
    {   
         
        if (checkdestroy(ships,i)!=1)// check eship destroyed or not 
        {
        distance = calculateDistance(x, y, ships[i].locx, ships[i].locy);
        eships[i].distancetoB = distance;
        
        if (distance <= radius)
        {                  
            shipsFound++;
            
            
            printf("\nShip %d: Type: %s, Location: (%d, %d), Distance: %.2f  ", i + 1, ships[i].ntype, ships[i].locx, ships[i].locy, distance);
            
            int g = 1;
            float l = destroyship(ships,shipData, bt, randomBvelocity, Bangle,distance,i,Bshellalltime,outputFile2,g);
            
            timetodestroyEships = timetodestroyEships + l;

            printf(" got destroyed by the Battleship\n");

            printf("\nTime to destroy no %d escortship is %f\n",i+1,l);

            
            
        }
        }
    }    
    
    if (shipsFound==0)
    {
        printf("\nNo Escort ships found within the specified radius.\n");
        return 0;
    }
    else
    {
    return (timetodestroyEships);
    }
}

//same as searcheship just added jamcheck feature
float searchEShips3(struct eship *ships,struct Eshipvalues *eships, int N, int x, int y,float radius,char bt,float randomBvelocity,float Bshellalltime,float timetodestroyEships,int jamcheck,FILE *outputFile2)
{
    printf("\nSearching for Escort ships within the radius of %.2f from point (%d, %d):\n", radius, x, y);    

    int shipsFound = 0;
    float Bangle;
    float distance;    
    
    for (int i = 0; i < N; i++)
    {   
         
        if (checkdestroy(ships,i)!=1)// check eship destroyed or not 
        {
        distance = calculateDistance(x, y, ships[i].locx, ships[i].locy);
        eships[i].distancetoB = distance;
        
        if (distance <= radius)
        {                  
            shipsFound++;            
            printf("\nShip %d: Type: %s, Location: (%d, %d), Distance: %.2f  ", i + 1, ships[i].ntype, ships[i].locx, ships[i].locy, distance);         
            
            int g =1;
            float l = destroyship2(ships,shipData, bt, randomBvelocity, Bangle,distance,i,Bshellalltime,outputFile2,g,jamcheck);
            
            timetodestroyEships = timetodestroyEships + l;

            printf(" got destroyed by the Battleship\n");

            printf("\nTime to destroy no %d escortship is %f\n",i+1,l);

            ships[i].destroy=1;
            
        }
        }
    }  
        
    if (shipsFound==0)
    {
        printf("\nNo Escort ships found within the specified radius.\n");
        return 0;
    }
    else
    {
    return (timetodestroyEships);
    }
}

//check  location of battle ship is in canvas rannge
void checkSearch(int BX, int BY, int csx, int csy)
{
    if (BX < 0 || BX > csx || BY < 0 || BY > csy)
    printf("\nInvalid search location. Please enter a valid location.\n");
}

//Check battle ship type
char checkbt(char bt)
{
    if (bt != 'U' && bt != 'M' && bt != 'R' && bt != 'S' && bt != 'u' && bt != 'm' && bt != 'r' && bt != 's')
    {
        printf("\nInvalid Battleship type, Please enter a valid type:\n");
        return 0;
    }
    return 1;
}


//save to textfile and calculate time to destroy
float destroyship(struct eship *ships,struct shipData *shipData, char bt, float randombvelocity, float Bangle,float distance,int i,float Bshellalltime,FILE *outputFile2,int g)
{
 float timeOfFlight;
  
    if (g == 1)//e destroy
    {
    float as=asin((distance * 9.8) / (randombvelocity * randombvelocity));
    Bangle = ((as) / 2);       
     timeOfFlight = (2 * ((randombvelocity * sin(Bangle)) / 9.8));    
    fprintf(outputFile2,"%d,%s,%d,%d,%f",i+1,ships[i].ntype, ships[i].locx, ships[i].locy,timeOfFlight);          
    fprintf(outputFile2,",0,1\n");
    ships[i].destroy=1;

    }
    else if (g == 0)//b destroy
    {
    float as=asin((distance * 9.8) / (randombvelocity * randombvelocity));
    Bangle = ((as) / 2);       
     timeOfFlight = (2 * ((randombvelocity * sin(Bangle)) / 9.8));    
    fprintf(outputFile2,"%d,%s,%d,%d,%f",i+1,ships[i].ntype, ships[i].locx, ships[i].locy,timeOfFlight);  
    fprintf(outputFile2,",1,0\n");

    }
    else if (g == 2)//none
    {
        fprintf(outputFile2,"%d,%s,%d,%d,0",i+1,ships[i].ntype, ships[i].locx, ships[i].locy); 
        fprintf(outputFile2,",0,0\n");
    }
    
    return(timeOfFlight);
}

//save to textfile and calculate time to destroy
float destroyship2(struct eship *ships,struct shipData *shipData, char bt, float randombvelocity, float Bangle,float distance,int i,float Bshellalltime,FILE *outputFile2,int g,int jamcheck)
{
     float timeOfFlight;
  
    if (g == 1)//e destroy
    {
    float as=asin((distance * 9.8) / (randombvelocity * randombvelocity));
    Bangle = ((as) / 2);
    if (jamcheck != 0) 
    {
        float BNMin = ((float)rand()/RAND_MAX)*(30 - 0);//After jammming
        float NBangle=((float)rand()/RAND_MAX)*(90 - BNMin);
        Bangle = (NBangle * M_PI)/180;
    }      

    timeOfFlight = (2 * ((randombvelocity * sin(Bangle)) / 9.8));    
    fprintf(outputFile2,"%d,%s,%d,%d,%f",i+1,ships[i].ntype, ships[i].locx, ships[i].locy,timeOfFlight);         
    fprintf(outputFile2,",0,1\n");
    ships[i].destroy=1;

    }
    else if (g == 0)//b destroy
    {
    float as=asin((distance * 9.8) / (randombvelocity * randombvelocity));
    Bangle = ((as) / 2);
    if (jamcheck != 0) 
    {
        float BNMin = ((float)rand()/RAND_MAX)*(30 - 0);//After jammming
        float NBangle=((float)rand()/RAND_MAX)*(90 - BNMin);
        Bangle = (NBangle * M_PI)/180;
    }      

    timeOfFlight = (2 * ((randombvelocity * sin(Bangle)) / 9.8));    
    fprintf(outputFile2,"%d,%s,%d,%d,%f",i+1,ships[i].ntype, ships[i].locx, ships[i].locy,timeOfFlight);
    fprintf(outputFile2,",1,0\n");

    }
    else if (g == 2)//none
    {
        fprintf(outputFile2,"%d,%s,%d,%d,0",i+1,ships[i].ntype, ships[i].locx, ships[i].locy); 
        fprintf(outputFile2,",0,0\n");
    }
    
    return(timeOfFlight);
}

//save to textfile and calculate time to destroy
float destroyship3(struct eship *ships,struct shipData *shipData, char bt, float randombvelocity, float Bangle,float distance,int i,FILE *outputFile2,float Bshellalltime)
{

   float as=asin((distance * 9.8) / (randombvelocity * randombvelocity));
    Bangle = ((as) / 2);       
    float timeOfFlight = (2 * ((randombvelocity * sin(Bangle)) / 9.8));    
   // fprintf(outputFile2,"%d,%s,%d,%d,%f\n",i+1,ships[i].ntype, ships[i].locx, ships[i].locy,timeOfFlight);
    
    return(timeOfFlight);
}


//Adding random minimum angles to escort ships 
float minimumanglecheck(struct shipData *shipData,float minimumangle,float finalminimumangle,int x)
{   
    int z = 90 - shipData[x].anglerange;
    if (minimumangle =='R')
    {
     finalminimumangle = ((float)rand()/RAND_MAX)*z;
    }    
    else if (minimumangle > 0 || 90 < minimumangle)
    {
    finalminimumangle = minimumangle;
    }
    else 
    {
    printf("\nerror--check eshipsdata.txt file.minimum angle will be randomly generated");
    finalminimumangle =((float)rand()/RAND_MAX)*z;
    }
    
    return(finalminimumangle);
}

//Use to caculate distance between B and E ships
double calculateDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

//battleship shell veloscity for maxximum range
float bmaxrangespeed(int canvasSizeX)
{

    float maxbmaxrangespeed;
    float x = canvasSizeX/2;     
    // Calculate maximum velocity 
    maxbmaxrangespeed = sqrt(x *9.81);    
    return(maxbmaxrangespeed);
}

//calculate the range of the 
float calculateRange(float velocity, float angle)
{    
    float theta = angle * (M_PI) / 180.0;    
    float range = (velocity * velocity * sin(2 * theta)) / 9.8;
    return range;
}

//Savin data to the final text file 
int finaltext(struct textfile1 *file1, struct textfile2 *file2) 
{
    char line1[256];
    char line2[256];

    FILE *outputFile1 = fopen("save.txt", "r");
    if (outputFile1 == NULL) {
        printf("Error opening eshipdata.txt\n");
        
    }

    FILE *outputFile2 = fopen("savenew.txt", "r");
    if (outputFile2 == NULL) {
        printf("Error opening savenew.txt\n");
        fclose(outputFile1);
        
    }

    FILE *outputFile3 = fopen("finaltext.txt", "w");
    if (outputFile3 == NULL) {
        printf("Error creating finaltext.txt\n");
        fclose(outputFile3);

        
    }

    int c = 0;

    while (fgets(line1, sizeof(line1), outputFile1) != NULL) //Read save.txt file data
    {
        sscanf(line1, "%d,%c,%d,%d",
               &file1[c].number,
               &file1[c].typenotation,
               &file1[c].locationx,
               &file1[c].locationy);

        c++;
    }

    int z = 0;

    while (fgets(line2, sizeof(line2), outputFile2) != NULL) //Read savenext.txt 
    {
        sscanf(line2, "%d,%c,%d,%d,%f,%d,%d",
               &file2[z].number,
               &file2[z].typenotation,
               &file2[z].locationx,
               &file2[z].locationy,
               &file2[z].time,
               &file2[z].bdestroy,
               &file2[z].edestroy);
        z++;
    }

    for (int p = 0; p < c; p++) 

    {
        int destroyed = 0;
        
        for (int q = 0; q < z; q++) 
        {
            if (file1[p].number == file2[q].number) // Check what ships destroyed 
            {
                fprintf(outputFile3,"%d,%c,%d,%d,%f,%d,%d\n",file2[p].number, file1[p].typenotation, file1[p].locationx, file2[p].locationy,file2[q].time,file2[q].bdestroy,file2[q].edestroy);

                destroyed = 1;
                break;
            }
        }

        if (destroyed == 0) 
        {
            fprintf(outputFile3, "%d,%c,%d,%d,0,0,0\n", file1[p].number, file1[p].typenotation, file1[p].locationx, file1[p].locationy);
        }
    }

    fclose(outputFile1);
    fclose(outputFile2);
    fclose(outputFile3);
    return 0;
}


//use to check e ship is destroyed or not 

int checkdestroy(struct eship *ships,int i)
{
    return(ships[i].destroy);    
}


//use to output bship detailes in menu

void Bdetails(struct bshipData *bshipData)
{
    FILE *inputbfile = fopen("bshipsdata.txt", "r");

    if (inputbfile == NULL)
    {
        printf("Error opening the input file.\n");
        
    }

    char line[256];

    int c =0;

        // Read ship data from file
    while (fgets(line, sizeof(line), inputbfile) != NULL)
    {
        sscanf(line, "%49[^,],%c,%49[^,]",               
               &bshipData[c].typename[0],
               &bshipData[c].typenotation,
               &bshipData[c].gunname[0]);
        c++;
    }

        for (int i = 0; i < c; i++)
    {

        printf("\n\nType Notation: %c\n", bshipData[i].typenotation);
        printf("Type Name: %s\n", bshipData[i].typename);
        printf("Gun Name: %s\n", bshipData[i].gunname);
        
    }
}



//use to diplay proper statistics in main menu and save them to a file in readable format
void lasttext(struct textfile3 *file3)
{
    FILE *inputFile4 = fopen("finaltext.txt", "r");
    if (inputFile4 == NULL) {
        printf("Error creating finaltext.txt\n");
        fclose(inputFile4);          
        
    }


    FILE *outputFile5 = fopen("statfinaltext.txt", "w");
    if (outputFile5 == NULL) {
        printf("Error creating finaltext.txt\n");
        fclose(outputFile5);
    }
    

    char line1[256];

    int c = 0;
   //read finaltext text file
    while (fgets(line1, sizeof(line1), inputFile4) != NULL) 
    {
        sscanf(line1, "%d,%c,%d,%d,%f,%d,%d",
                            &file3[c].number,
                            &file3[c].type,
                            &file3[c].x,
                            &file3[c].y,
                            &file3[c].time,
                            &file3[c].BD,
                            &file3[c].ED);
        c++;
    } 

    int l=0;
    int z=c;
    for (int i = 0; i < z; i++)//print and write data in file
    {
        printf("Escortship number %d (Type %c) was in (%d,%d)", file3[i].number,file3[i].type,file3[i].x,file3[i].y);
        fprintf(outputFile5,"Escortship number %d (Type %c) was in (%d,%d)", file3[i].number,file3[i].type,file3[i].x,file3[i].y);

        if(file3[i].ED != 0)
        {
        printf(" got destroyed by Battleship.");
        fprintf(outputFile5,"got destroyed by Battleship.");
        }
        if(file3[i].BD != 0)
        {
        printf(" destroyed the Battleship.");
        fprintf(outputFile5," destroyed the Battleship.");
        }
        if((file3[i].ED == 0) && (file3[i].BD == 0))
        {
        printf(" survived.");
        fprintf(outputFile5," survived.");

        }

        if(file3[i].time!=0)
        {
        printf(" Time to destroy is %.6f",file3[i].time);  
        fprintf(outputFile5," Time to destroy is %.6f",file3[i].time);                
        }
        
        printf("\n");
        fprintf(outputFile5,"\n");

        if((file3[i].ED != 0) || (file3[i].BD != 0))
        {
            l++;

        }
    } 
        if(l==0)
        {
            printf("\nAll the ships have been survived.\n");
            fprintf(outputFile5,"\nAll the ships have been survived.\n");
        }

    fclose(inputFile4); 
    fclose(outputFile5);//close opened files
    return;
}