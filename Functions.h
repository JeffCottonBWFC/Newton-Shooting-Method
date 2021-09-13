#ifndef Functions_h
#define Functions_h


//General MFunction Class
class MFunction{
public:
	virtual MVector operator()(const double& x, const MVector& y) = 0;
};

//Example system of ODEs
class FunctionF1 : public MFunction{
public:
	virtual MVector operator()(const double& x, const MVector& y){
		MVector temp(2);
		temp[0] = y[0] + x*y[1];
		temp[1] = x*y[0] - y[1];
		return temp;
	}
};

class FunctionF2 : public MFunction{
public:
	virtual MVector operator()(const double& x, const MVector& y){
		MVector temp(2);
		temp[0] = x;
		temp[1] = y[1];
		return temp;
	}
};

class FunctionF3 : public MFunction{
public:
	virtual MVector operator()(const double& x, const MVector& y){
		MVector temp(2);
		temp[0] = y[1];
		temp[1] = (32 + 2*pow(x,3) - y[0]*y[1])/8;
		return temp;
	}
};


//Modified boundary conditions of F3 solving y'' = (32+2x^3-yy')/8 with boundary conditions y(1) = 17, y(3) = 43/3.
class FunctionF4 : public MFunction
{
public:
	MVector operator()(const double& x,const MVector& y)
	{
		MVector temp(4);
		temp[0] = y[1];
		temp[1] = 0.125*(32+2*pow(x,3)-y[0]*y[1]);
		temp[2] = y[3];
		temp[3] = -0.125*(y[1]*y[2] + y[0]*y[3]);
		return temp;
	}
};


class FalknerSkan1 : public MFunction
{
public:
	// constructor to initialise beta
	FalknerSkan1() {beta=0.5;}
	MVector operator()(const double& x,const MVector& y)
	{
		MVector temp(3);
		temp[0] = y[1];
		temp[1] = y[2];
		temp[2] = -y[0] * y[2] - beta*(1-pow(y[1],2));
		return temp;
	}
	void SetBeta(double k) {beta=k;}
private:
	double beta; // class member variable, accessible within
	// all Eqn1p5Derivs member functions
};


class FalknerSkan2 : public MFunction
{
public:
	// constructor to initialise beta
	FalknerSkan2() {beta=0.5;}
	MVector operator()(const double& x,const MVector& y)
	{
		MVector temp(6);
		temp[0] = y[1];
		temp[1] = y[2];
		temp[2] = -y[0] * y[2] - beta*(1-pow(y[1],2));
		temp[3] = y[4];
		temp[4] = y[5];
		temp[5] = -y[0] * y[5] - y[2] * y[3] + 2 * beta * y[1] * y[4];
		return temp;
	}
	void SetBeta(double k) {beta=k;}
private:
	double beta; // class member variable, accessible within
	// all Eqn1p5Derivs member functions
};



#endif /* Functions_h */
