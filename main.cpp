
#include <iostream>
#include "mVector.h"
#include "OperatorOverloads.h"
#include "Functions.h"
#include "ODESolvers.h"


int main() {
	FunctionF4 f;

	//Solution vector storage
	MVector y(4);

	//Declares
	int maxNewtonSteps = 100;
	double guess = 0;
	double tol = 1e-8;
	double BCVal = 14.33333333333;

	//Applying shooting method using Newton iteration
	for (int i=0; i<maxNewtonSteps; i++){

		// y[0] = y, y[1] = dy/dx, y[2] = Z_1, y[3] = Z_2
		y[0]=17.0; y[1]=guess; y[2]=0.0; y[3]=1.0;

		// solve IVP
		RK4Solve(100, 1.0, 3.0, y, f);

		// calculate residual
		double phi = y[0] - BCVal;
		double phidash = y[2]; // 'Jacobian' phidash = z_1(x=1)

		// exit if converged
		if (std::abs(phi) < tol){
			std::cout << "Solution has converged \n";
			break;
		}

		guess -= phi/phidash; // apply newton step
	}

	//y and y' at x = 3
	std::cout << "(y,dy/dx) = (" << y[0] << ", " << y[1] << ")\n";
	
	
}

//FalknerSkan2 f;
//
////Solution vector storage
//MVector y(6);
//
////Declares
//int maxNewtonSteps = 100;
//double guess = 0.92;
//double tol = 1e-8;
//double BCVal = 1;
//
////Applying shooting method using Newton iteration
//for (int i=0; i<maxNewtonSteps; i++){
//
//	// y[0] = f, y[1] = f', y[2] = f'', y[3] = z1, y[4] = z2, y[5] = z3
//	y[0]=0; y[1]=0; y[2]=guess; y[3]=0; y[4]=0; y[5]=1;
//
//	// solve IVP
//	RK4Solve(100, 0, 20, y, f);
//
//	// calculate residual
//	double phi = y[0] - BCVal;
//	double phidash = y[3]; // 'Jacobian' phidash = z_1(x=1)
//
//	// exit if converged
//	if (std::abs(phi) < tol){
//		std::cout << "Solution has converged \n";
//		break;
//	}
//
//	guess -= phi/phidash; // apply newton step
//}
//
//
//std::cout << "(f,f',f'') = (" << y[0] << ", " << y[1] << ", " << y[2] << ")\n";


/// Solving ODE y'' = 1/8 (32+2x^3-yy') with ICs y(1) = 17, y(3) = 43/3 on range x in [1,3] using Newton Iteration
//
//		FunctionF4 f;
//
//		//Solution vector storage
//		MVector y(4);
//
//		//Declares
//		int maxNewtonSteps = 100;
//		double guess = 0;
//		double tol = 1e-8;
//		double BCVal = 14.33333333333;
//
//		//Applying shooting method using Newton iteration
//		for (int i=0; i<maxNewtonSteps; i++){
//
//			// y[0] = y, y[1] = dy/dx, y[2] = Z_1, y[3] = Z_2
//			y[0]=17.0; y[1]=guess; y[2]=0.0; y[3]=1.0;
//
//			// solve IVP
//			RK4Solve(100, 1.0, 3.0, y, f);
//
//			// calculate residual
//			double phi = y[0] - BCVal;
//			double phidash = y[2]; // 'Jacobian' phidash = z_1(x=1)
//
//			// exit if converged
//			if (std::abs(phi) < tol){
//				std::cout << "Solution has converged \n";
//				break;
//			}
//
//			guess -= phi/phidash; // apply newton step
//		}
//
//		//y and y' at x = 3
//		std::cout << "(y,dy/dx) = (" << y[0] << ", " << y[1] << ")\n";


///	Solving ODE y'' = 1/8 (32+2x^3-yy') with ICs y(1) = 17, y'(1) = 1 on range x in [1,3]
//
//	//Solution vector storage
//	MVector y(2);
//
//	//Selection function to be evaluation as determined in Functions.h file
//	FunctionF3 f;
//
//	//Select intial conditions of Y1 and Y2
//	y[0] = 17; y[1] = 1;
//
//	//Select number of steps for the ODE Solver chosen to perform
//	int NumOfSteps = 200;
//
//	//Insert start and end values of the solution interval
//	double StartValue = 1;
//	double EndValue = 3;
//
//	//Select ODE solver
//	RK4Solve(NumOfSteps,StartValue,EndValue,y,f);
