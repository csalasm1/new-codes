#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Midpoint(double, double, double);
void Trapezoid(double, double, double);
void Simpson(double, double, double);
int n;
int i=0,j=0,k=0,l=0;
int N[5]={6,10,20,1000,50000};
double S[5][5][5]={0};
double a, b, h, x, xm, f, midpoint=0, trap=0, simp=0;

int main()
{
	cout<<"Enter lower bound: ";
	cin>>a;
	cout<<"Enter upper bound: ";
	cin>>b;

	cout<<"n"<<"   Midpoint rule"<<"   Trapezoid rule"<<"   Simpson's rule"<<endl;// print values in array and return from print function

	double f=1.0/sqrt(1.0-(x*x));

	Midpoint(a,b,f);
	cout<<endl;
	Trapezoid(a,b,f);
	cout<<endl;
	Simpson(a,b,f);

	cout<<"real value: 0.69314718"<<endl;

	//for (j=0; j<5; j++)
		//cout<<S[j][k][l]<<endl;//test

	return 0;
}

void Midpoint(double a, double b, double f)
{
	for (i=0; i<5; i++)//sets h
	{
		n=N[i];
		h=(b-a)/n;
		x=a+(h/2);
		midpoint=0;

		for (j=0; j<n; j++)//sets midpoint sum
		{
			xm=x+(j/n);
			midpoint+=h*(1/xm);
			//midpoint=S[j][k][l];
		}
		cout<<midpoint<<endl;
	}
		//error=abs(sum)-abs(realintegral);
}


void Trapezoid (double a, double b, double f)
{
	double f1=(1/a);
	double f2=(1/b);

	for (i=0; i<5; i++)//prints
	{
		n=N[i];
		h=(b-a)/n;
		trap=(h/2)*(f1+f2);

		for (j=1; j<n; j++)
		{
			x=a+j*h;//sub-division
			trap+=(h/2)*2*(1/x);//should change 1/x to f

		}
		cout<<trap<<endl;

		//error=abs(sum)-abs(realintegral);

	}

}

void Simpson(double a, double b, double f)
{
	double f1=(1/a);
	double f2=(1/b);

	for (i=0; i<5; i++)//sets n
	{
		n=N[i];
		h=(b-a)/n;
		simp=(h/3)*(f1+f2);

		for (j=1; j<(n/2)-1; j++)//sums for 2
		{
			x=a+j*(2*h);//sub-division
			simp+=(h/3)*2*(1/x);//should change 1/x to f
		}

		simp+=(h/3)*4*(1/(a+h));//first x1 is a+h

		for (k=1; k<(n/2)-1; k++)//sums for 4
		{
			//x1 is just a+h not a+h*2
			x=a+k*(2*h);
			simp+=(h/3)*4*(1/x);
		}

		cout<<simp<<endl;
	}

		//error=abs(sum)-abs(realintegral);
}
