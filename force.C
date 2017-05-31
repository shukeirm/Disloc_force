
// =================================================================================================================
// force.C - C++ script for calculating the force per unit length between two infinite straight dislocation segments
// Interaction force is calculated based on Equation (5-17,18) P(117-118) for parallel dislocations
// and Equation (5-35) P123 for Non-parallel dislocations in "Theory of Dislocations" by Hirth and Lothe 1982
//
// Author: Malik SHUKEIR
// Date:   20/1/2017 
// =================================================================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
#include "vect3.h"


int main(void)
{

  std::cout << "\n==================================================\n" 
	    << "  ______   ________   _______   _______   ______    \n"   
	    << " |  ____| |  ____  | |  ___  | |  _____| |  ____|   \n"   
	    << " | |____  | |    | | | |___| | | |       | |____    \n"   
	    << " |  ____| | |    | | |  __  _| | |       |  ____|   \n"   
	    << " | |      | |____| | | |  \\ \\  | |_____  | |____  \n" 
	    << " |_|      |________| |_|   \\_\\ |_______| |______| \n" 
	    << "                                                    \n"   
	    << "==================================================  \n"   << std::endl;

  const double pi = 3.141593;

  double Mu;  //Shear Modulus (GPa)
  double Nu;  //Poisson ratio
 
  std::cout << "\nEnter value of Shear Modulus in GPa: " << std::endl;
  std::cin >> Mu;
  std::cout << "\nEnter value of Poisson ratio: "<< std::endl;
  std::cin >> Nu;

  int n=3;
    
  // Data of dislocation Segment 1:
  // Distance in units of (nm)
  // ------------------------------
  int v[n]= {0,0,0};
  std::cout << "Please enter first Burgers vector:\n";
  
  for ( int i=0; i<n; ++i )
    {
      std::cin >> v[i];  
    }

  Vect3 b1(v[0],v[1],v[2]);     // Burgers vector

  std::cout << "Please enter first dislocation direction:\n";
  
  for ( int i=0; i<n; ++i )
    {
      std::cin >> v[i];  
    }

  Vect3 Psi1(v[0],v[1],v[2]);  // Psi vector

  std::cout << "Please enter arbitrary point on first dislocation:\n";
  
  for ( int i=0; i<n; ++i )
    {
      std::cin >> v[i];  
    }
  Vect3 P1(v[0],v[1],v[2]);     // Arbitrary point on Seg1
  
  // Data of dislocation Segment 2:
  // Distance in units of (nm)
  // ------------------------------
  std::cout << "Please enter second Burgers vector:\n";
  
  for ( int i=0; i<n; ++i )
    {
      std::cin >> v[i];  
    }

  Vect3 b2(v[0],v[1],v[2]);     // Burgers vector

  std::cout << "Please enter second dislocation direction:\n";
  
  for ( int i=0; i<n; ++i )
    {
      std::cin >> v[i];  
    }

  Vect3 Psi2(v[0],v[1],v[2]);  // Psi vector

  std::cout << "Please enter arbitrary point on second dislocation:\n";
  
  for ( int i=0; i<n; ++i )
    {
      std::cin >> v[i];  
    }
  Vect3 P2(v[0],v[1],v[2]);   // Arbitrary point on Seg2
  
  // Calculate R12 the shortest vector from dislocation Seg1 to Seg2
  // ---------------------------------------------------------------
  Vect3 P12(P2-P1);  // Vector from P1 to P2
  Vect3 R12;
  Vect3 F12;
  
  if ((Psi1.Cross(Psi2)).Norm()==0)
    {
      
      std::cout << "\n================================" << std::endl; 
      std::cout << "\ndislocation 1 and 2 are parallel" << std::endl; 
      Vect3 vecParallel = Psi1.Dot(P12)*Psi1.UnitVector();
      std::cout<<vecParallel<<std::endl;
      R12 = P12-vecParallel;
      std::cout<<R12<<std::endl;
      double F_rad = Mu/(2*pi*(R12.Norm()))*(b1.Dot(Psi1))*(b2.Dot(Psi2))+ Mu/(2*pi*(1-Nu)*(R12.Norm()))*((b1.Cross(Psi1)).Dot(b2.Cross(Psi1)));
      double F_theta = Mu/(2*pi*(1-Nu)*pow(R12.Norm(),3))*((b1.Dot(R12))*((b2.Cross(R12)).Dot(Psi1))+(b2.Dot(R12))*((b1.Cross(R12)).Dot(Psi1)));
      double F12x=F_rad*cos(F_theta);
      double F12y=F_rad*sin(F_theta);
      
      F12[0]=F12x; F12[1]=F12y;F12[2]=0;
    }
  else 
    {
      std::cout << "\n====================================" << std::endl; 
      std::cout << "\ndislocation 1 and 2 are not parallel" << std::endl; 
      Vect3 Normal = Psi1.Cross(Psi2);
      R12 = Normal.Dot(P12)/Normal.SquareLength()*Normal;
      F12 = Mu/((Psi1.Cross(Psi2)).Norm())*R12.UnitVector()*(0.5*(b1.Dot(Psi1))*(b2.Dot(Psi2))-(b1.Cross(b2)).Dot(Psi1.Cross(Psi2))
							     +1.0/(1.0-Nu)*((b1.Cross(Psi1)).Dot(R12.UnitVector()))*((b2.Cross(Psi2)).Dot(R12.UnitVector())));
    }
									
									
  double force = F12.Norm();
  std::cout << "\n========================\n" << std::endl;
  std::cout <<  std::fixed << std::showpoint  << std::setprecision(2) << "    F12 = " << force << " N/nm" << std::endl;
  std::cout << "\n========================"   << std::endl;
  return 0;
}
							 
