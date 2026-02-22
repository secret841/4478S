#pragma once

#include "main.h"
#include "motors.h"
#include "robo_class.h"
#include "functions.h"

struct storage
{
    int priority;
    int originalTime; 
    float propoTime = 0; 
}; 

void reallocateTime(storage StorageArray[], storage StorageArrayCopy[])
{
    int size = sizeof(StorageArray) / sizeof(StorageArray[0]); //Calculates size of array
    int timeReq = 0; 

    //Calculates how much time is needed originally and compare to how much time we actually have.
    for (int i = 0; i < size; i++)
    {
        timeReq += StorageArray[i].originalTime;         
    }

    int count = 1; 
    int timeReqOg = timeReq; //Makes fixed variable
    while (timeReq > maxTime)
    {
        //Breaks loop if we ever exceed far too many things
        if (count > timeReqOg / 10)
        {  
            break; 
        }
        //Subtract time with modulo
        for (int i = 0; i < size; i++)
        {
            //Ensures that each block has some time to go home with (200ms)
            if (count % StorageArray[i].priority == 0 && StorageArray[i].originalTime > 200)
            {
                timeReq -= 20; 
                StorageArray[i].originalTime -= 20; 
                
            }
        }
        count++; 
    }
  
    //Calculates proportion of time taken off of each function
    for (int i = 0; i < size; i++)
    {
        StorageArray[i].propoTime =  float(StorageArray[i].originalTime) / StorageArrayCopy[i].originalTime;
    }

    //Compare proportions and finalize times
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            //If one's priority is the same or greater yet their proportion times don't match
            bool proportionMatch1 = (StorageArray[i].propoTime < StorageArray[j].propoTime - 0.125);
            bool proportionMatch2 =  (StorageArray[i].propoTime - StorageArray[j].propoTime) > 0.125; 
            
            if ((StorageArray[i].priority >= StorageArray[j].priority) && (proportionMatch1 || StorageArray[j].priority >= StorageArray[i].priority && proportionMatch2))
            {
                while (proportionMatch1)
                {
                    proportionMatch1 = fabs(StorageArray[j].propoTime - StorageArray[i].propoTime) > 0.125; //Continuous check
                    StorageArray[j].originalTime -= 2; 
                    StorageArray[i].originalTime += 2; 
                    StorageArray[i].propoTime =  float(StorageArray[i].originalTime) / StorageArrayCopy[i].originalTime;
                }
                while (proportionMatch2)
                {
                    proportionMatch2 =  fabs(StorageArray[i].propoTime - StorageArray[j].propoTime) > 0.125; //Continuous check
                    StorageArray[j].originalTime += 2; 
                    StorageArray[i].originalTime -= 2; 
                    StorageArray[i].propoTime =  float(StorageArray[i].originalTime) / StorageArrayCopy[i].originalTime;
                }
            }
            
        }
    }

     //Tells us how much time each of our original functions are now given
    for (int i = 0; i < size; i++)
    {
        //Makes sure everyone at least has min of 200 ms (once again)
        if (StorageArray[i].originalTime < 200)
        {
            StorageArray[i].originalTime = 200;
        }
    }
}