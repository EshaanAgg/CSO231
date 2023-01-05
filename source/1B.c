#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MIN_PID 300
#define MAX_PID 5000

// Defining all the functions of the API
int get_random();
int allocate_map(void);
int allocate_PID();
void release_PID();

bool *PID_map;

/*
    Driver code to test the functionality
*/
int main()
{
    // initiate PID map
    if (allocate_map() == -1)
    {
        printf("Unable to create the PID map\n");
        printf("Exiting.\n");
        return 0;
    }

    // Sample PID for feature release
    int PID1, PID2;

    // Allocate PIDs
    for (int i = 0; i < 1000; i++)
    {
        int PID = allocate_PID();
        if (i == 3)
            PID1 = PID;
        if (i == 4)
            PID2 = PID;
        printf("PID: %d\n", PID);
    }

    // Release PIDs
    release_PID(PID1);
    release_PID(1000);
    release_PID(PID2);
}

/*
    Creates and initializes a data structure for representing PIDs
    Returns —1 if unsuccessful, 1 if successful
*/
int allocate_map(void)
{
    srand(time(0));
    PID_map = malloc(sizeof(bool) * MAX_PID);
    return PID_map == NULL ? -1 : 1;
}

/*
    Allocates and returns a PID
    Returns -1 if unable to allocate a PID (all PIDs are in use)
*/
int allocate_PID()
{
    int PID = get_random();
    while (PID_map[PID] == true)
    {
        PID = get_random();
    }
    PID_map[PID] = true;
    return PID;
}

/*
    Releases a PID
*/
void release_PID(int PID)
{
    if (PID_map[PID] == true)
    {
        PID_map[PID] = false;
        printf("Release PID %d\n", PID);
    }
    else
    {
        printf("PID %d is not associated with any process\n", PID);
    }
}

/*
    Returns a random number between the max and min PID
*/
int get_random()
{
    return (rand() % (MAX_PID - MIN_PID + 1) + MIN_PID);
}