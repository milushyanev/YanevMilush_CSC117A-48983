#include "Worker.h"


ProductionWorker::ProductionWorker() {
	shift = 1;
	rate = 0.0;
}
ProductionWorker::ProductionWorker(int s, float r){
	shift = s;
	rate = r;
}
ProductionWorker::ProductionWorker(const ProductionWorker& orig)
{

}

ProductionWorker::~ProductionWorker()
{

}

void ProductionWorker::setShift(int s)
{
	shift = s;
}

void ProductionWorker::setRate(float r)
{
	rate = r;
}

int ProductionWorker::getShift()
{
	return shift;
}

float ProductionWorker::getRate()
{
	return rate;
}