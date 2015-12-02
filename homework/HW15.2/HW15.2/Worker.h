#ifndef WORKER_H
#define	WORKER_H
#include "Employee.h"

class ProductionWorker : public Employee {
public:
	ProductionWorker();
	ProductionWorker(int, float);
	ProductionWorker(const ProductionWorker& orig);
	~ProductionWorker();
	void setShift(int);
	void setRate(float);
	int getShift();
	float getRate();
private:
	int shift;
	float rate;
};

#endif	