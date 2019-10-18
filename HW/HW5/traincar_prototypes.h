// =======================================================================
//
// IMPORTANT NOTE: You should edit this file
//                 This file is #include'd from traincar.h and main.cpp
//
// =======================================================================
//
// There are a number of additional functions used in main.cpp that
// you need to declare and implement.  Study main.cpp and the provided
// output to determine the arguments, return type, and overall
// behavior.
//
// Add all required additional function prototypes here
// (you may also add your own helper function prototypes here too)
//
// Implement these functions in "traincar.cpp"
//

//Deletes the nodes to the train/cars
void DeleteAllCars(TrainCar* t);

//essentially appends a value to the end
void PushBack(TrainCar* &t, TrainCar* x);

//puts a value in the front of a list.
void PushFront(TrainCar* &t, TrainCar* x);

//takes the first value off of a list.
TrainCar* popFront(TrainCar* &t);

//takes the last value off a list.
TrainCar* popBack(TrainCar* &t);

//calculates the horsepower
int getHorse(TrainCar* t);

//calculates the total weight
int getTotalWeight(TrainCar* t);

//calculates the speed gives cars and engine info
float CalculateSpeed(TrainCar* t);

//Calculates the average distance from passenger cars to dining cars
float AverageDistanceToDiningCar(TrainCar* t);

//Calculates the average distance from Engine to Sleeper cars.
int ClosestEngineToSleeperCar(TrainCar* t);

void TotalWeightAndCountCars(TrainCar* t, int& tweight, int& engines, int& numFreight,
   int& numPassenger, int& numDining, int& numSleeping);

//looks through the list, freight returns the number and deletes it from the list.
TrainCar* TakeHighest(TrainCar* &freight);

//given the minimum speed, max cars, number of freight cars and max number of engines available, use the fewest amount of engines/trains to transport goods.
std::vector<TrainCar*> ShipFreight(TrainCar* &eng, TrainCar* &freight, int minSpeed, int maxCars);

/*take an engine, set currentweight = weight of engine, while still freight cars take the highest that the engine can carry until it. Add feight car to engine adding
weight to current weight. Take highest.*/

//seperate car, t1, into t2 and t3 with varying number of engines.
void Separate(TrainCar* t1, TrainCar* t2, TrainCar* t3);
