// =======================================================================
//
// IMPORTANT NOTE: You should edit this file
//
// =======================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <vector>

#include "traincar.h"

// =======================================================================
// =======================================================================
//
//  HERE'S WHERE YOU SHOULD IMPLEMENT THE FUNCTIONS YOU PROTOTYPED IN
//  THE "TrainCar_prototypes.h" FILE.
//

void DeleteAllCars(TrainCar* t)
{
  //clean up crew
  TrainCar* tmp;
  while(t)
  {
    tmp = t->next;
    delete t;
    t = tmp;
  }
}

void PushBack(TrainCar* &t, TrainCar* x)
{
  //if x has a previous, go to farthest previous (just a thought)

  //two cases
  //1. train already has values in it.
  //2. train has nothing
  TrainCar* tail = t;

  if(x == NULL)
  {
    return;
  }

  if(t == NULL)
  {
    t = x;
    return;
  }

  while(tail->next)
    tail = tail->next;

  tail->next = x;
  x->prev = tail;
}

void PushFront(TrainCar* &t, TrainCar* x)
{
  if(!t)
  {
    t = x;
    return;
  }
  //puts a value in the front of a list.
  t->prev = x;
  x->next = t;
  t = x;
}

TrainCar* popFront(TrainCar* &t)
{
  //takes the front element from a list
  TrainCar* tmp = t;
  if(!t)
    return t;
  t = t->next;
  if(!t)
    return tmp;
  t->prev = NULL;
  tmp->next = NULL;
  return tmp;
}

TrainCar* popBack(TrainCar* &t)
{
  //removes the last element from a list and returns it
  TrainCar* temp = t;
  while(temp->next)
    temp = temp->next;

  temp->prev->next = NULL;
  temp->prev = NULL;

  return temp;
}

int getHorse(TrainCar* t)
{
  //engines have horsepower of 3000
  int totalHorse = 0;
  TrainCar* tmp = t;
  while(tmp)
  {
    if(tmp->isEngine())
      totalHorse += 3000;
    tmp = tmp->next;
  }
  return totalHorse;
}

int getTotalWeight(TrainCar* t)
{
  //calculate the total weight based on give info
  int totalWeight = 0;
  TrainCar* tmp = t;
  while(tmp)
  {
    if(tmp->isEngine())
      totalWeight += 150;
    else if(tmp->isFreightCar())
      totalWeight += tmp->getWeight();
    else
      totalWeight += 50;
    tmp = tmp->next;
  }
  return totalWeight;
}

float CalculateSpeed(TrainCar* t)
{
  //use getHorse and getTotalWeight to calculate the speed currently
  int horse = getHorse(t);
  float top = (horse * 550.0 * 3600.0);
  float bottom = 2000 * 0.02 * 5280 * getTotalWeight(t);
  return top/bottom;
}

float AverageDistanceToDiningCar(TrainCar* t)
{
  //eventually divide by the amount of passenger cars.
  //overall temporary pointer, temporary right pointer and temporary left pointer, respectively.
  TrainCar* tmp = t;
  TrainCar* tmpright;
  TrainCar* tmpleft;
  //average distances
  float avg = 0.0;
  //total distances passenger cars are from dining halls.
  int totalDist = 0;
  //total number of passenger cars.
  int numPassCars = 0;
  //distance to the right counter
  int distRight = 0;
  //distance to the left counter
  int distLeft = 0;
  //basically keep going through passenger cars until null (none left)
  while(tmp)
  {
    //begin analysis if on a passenger car.
    if(tmp->isPassengerCar())
    {
      tmpright = tmp;
      tmpleft = tmp;
      while(tmpright && !tmpright->isDiningCar())
      {
        if(tmpright->isEngine())
        {
          //-1 because it hits an engine.
          distRight = 9999;
          break;
        }
        if(!tmpright)
          break;
        distRight++;
        tmpright = tmpright->next;
      }
      while(tmpleft && !tmpleft->isDiningCar())
      {
        if(tmpleft->isEngine())
        {
          //-1 because it hits an engine.
          distLeft = 9999;
          break;
        }
        if(!tmpleft)
          break;

        distLeft++;
        tmpleft = tmpleft->prev;
      }
      //determining which one (left or right) is closer to a dining hall
      if(distLeft <= distRight)
        totalDist += distLeft;
      else
        totalDist += distRight;
      //if passenger car add to total count
      numPassCars++;

      //reset values (can't use list to store multiple vals)
      distLeft = 0;
      distRight = 0;
    }
    tmp = tmp->next;
  }
  //Calculate the averages
  avg = float(totalDist)/float(numPassCars);
  return avg;
}

int ClosestEngineToSleeperCar(TrainCar* t)
{
  //overall temporary pointer, temporary right pointer and temporary left pointer, respectively.
  TrainCar* tmp = t;
  TrainCar* tmpright;
  TrainCar* tmpleft;
  //set closest to some arbitrarily large number so it changes
  int closest = 9999;

  while(tmp)
  {
    //left and right counters to 0
    int rightCount = 0;
    int leftCount = 0;
    //tmp points to a sleeping car
    if(tmp->isSleepingCar())
    {
      tmpright = tmp;
      tmpleft = tmp;
      while(tmpright && !tmpright->isEngine())
      {
        rightCount++;
        tmpright = tmpright->next;
      }
      if(!tmpright)
        rightCount = 9999;
      while(tmpleft && !tmpleft->isEngine())
      {
        leftCount++;
        tmpleft = tmpleft->prev;
      }
      if(!tmpleft)
        leftCount = 9999;
    }
    //
    if(rightCount <= leftCount && rightCount < closest && rightCount != 0)
      closest = rightCount;

    else if(leftCount < rightCount && leftCount < closest && leftCount != 0)
      closest = leftCount;

    tmp = tmp->next;
  }
  //in the case of an infinite distance
  if(closest == 9999)
    closest = -1;
  return closest;
}

void TotalWeightAndCountCars(TrainCar* t, int& total_weight, int& num_engines, int& num_freight,
   int& num_passenger, int& num_dining, int& num_sleeping)
   {
     total_weight = 0;
     num_engines = 0;
     num_freight = 0;
     num_passenger = 0;
     num_dining = 0;
     num_sleeping = 0;
     TrainCar* tmp = t;
     //looping over entire train, adding to total_weight and other counters.

     while(tmp)
     {
       if(tmp->isEngine())
       {
         num_engines++;
       }
       else if(tmp->isFreightCar())
       {
         num_freight++;
       }
       else if(tmp->isPassengerCar())
       {
         num_passenger++;
       }
       else if(tmp->isDiningCar())
       {
         num_dining++;
       }
       else if(tmp->isSleepingCar())
       {
         num_sleeping++;
       }
       total_weight += tmp->getWeight();
      tmp = tmp->next;
     }
   }

std::vector<TrainCar*> ShipFreight(TrainCar* &eng, TrainCar* &freight, int minSpeed, int maxCars)
{
  //what I'm returning
  std::vector<TrainCar*> out;
  //make sure freight and eng are not null and repeat until.
  while(freight && eng)
  {
    //at least one engine is present so counter starts at 1
    int counter = 1;
    TrainCar* tmp = popFront(eng);
    //always points to the front of the train.
    //TrainCar* temp;
    //I was getting 1 extra then maxCars
    while(maxCars-1 > counter && freight)
    {

      while(CalculateSpeed(tmp) >= minSpeed && counter < maxCars-1)
      {
        //take the next freight pointer and push it into the tmp pointer.
        PushBack(tmp, popFront(freight));
        counter++;
      }

      //in the event that speed is below minSpeed and maxCars has been reached.
      if(counter == maxCars && CalculateSpeed(tmp) < minSpeed)
      {
        //remove the last element in temp and puts it at the front of freight
        PushFront(freight ,popBack(tmp));
        counter--;
        //no longer can add anything to this train.
        break;
      }
      //added an engine.
      else if(counter < maxCars && CalculateSpeed(tmp) < minSpeed)
      {
        //go to the last engine
        while(tmp->next->isEngine())
        {
          tmp = tmp->next;
        }
        //Unlinking and relinking in order to put an engine in the proper place.
        TrainCar* tmp3 = popFront(eng);
        tmp3->prev = tmp;
        tmp3->next = tmp->next;
        tmp->next = tmp3;
        tmp3->next->prev = tmp3;
        counter++;
        //go all the way back to the front of the engines.
        while(tmp->prev)
          tmp = tmp->prev;
      }
    }
    //put heads that include cars in each train into the vector to return
    out.push_back(tmp);
  }
  return out;
}


void Separate(TrainCar* t1, TrainCar* t2, TrainCar* t3)
{

  TrainCar* T1 = t1;
  TrainCar* T2 = t2;
  TrainCar* T3 = t3;
  //find the length of the traincar, t1
  int count = 0;
  int count2 = 0;
  int engineCount = 0;

  while(!T1)
  {
    ++count;
    T1 = T1->next;
    //location of the first engine
    if(T1->isEngine())
    {
      engineCount = count;
    }
  }
  //to handle even count of train cars
  if(count%2 == 0 && !T1)
  {
      while(count2 < count/2 && T1)
      {
        T2 = T1;
        T1 = T1->next;
        T2 = T2->next;
        count2++;
      }
      while(count2 < count && T1)
      {
        T3 = T1;
        T1 = t1->next;
        T3 = T3->next;
        count2++;
      }
  }
}
