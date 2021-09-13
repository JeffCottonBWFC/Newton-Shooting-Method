#ifndef ODESolvers_h
#define ODESolvers_h

//Euler stepping scheme method
int EulerSolve(int steps, double a, double b, MVector &y, MFunction &f){
	
	if(y.size() != 2){
		std::cout << "Size of y must be 2 to solve a 2D system! \n";
		exit(-1);
	}
	
	//Declare starting value and stepwidth
	double x = a;
	double h = (b-a)/steps;
	
	//Loop through using the Euler stepping scheme
	for(int i = 0; i < steps; i++){
		x = a + i * h;
		y = y + h * f(x,y);
	}
	
	//Output solution to user
	std::cout << y << "\n";
	return 0;
}

//Midpoint solve method
int MidpointSolve(int steps, double a, double b, MVector &y, MFunction &f){
	
	if(y.size() != 2){
		std::cout << "Size of y must be 2 to solve a 2D system! \n";
		exit(-1);
	}
	
	//Declare starting value and stepwidth
	double x = a;
	double h = (b-a)/steps;
	
	//Loop through using the Midpoint stepping scheme
	for(int i = 0; i < steps; i++){
		x = a + i * h;
		y = y + h * f(x + 0.5 * h, y + 0.5 * h * f(x,y));
	}
	
	//Output solution to user
	std::cout << y << "\n";
	return 0;
}

//Runge-Kutta 4 solver
int RK4Solve(int steps, double a, double b, MVector &y, MFunction &f){
	
	MVector k1,k2,k3,k4;
	
	double x = a;
	double h = (b-a)/steps;
	
	for(int i=0; i < steps; i++){
		x = a+i*h;
		k1 = f(x,y);
		k2 = f(x+0.5*h, y+0.5*h*k1);
		k3 = f(x+0.5*h, y+0.5*h*k2);
		k4 = f(x+h, y+h*k3);
		y = y + h/6 * (k1 + 2*k2 + 2*k3 + k4);
	}
	
	//Output solution to user
	std::cout << y << "\n";
	return 0;
}



#endif /* ODESolvers_h */
