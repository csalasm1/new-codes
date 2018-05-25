#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Particle
{
  double rad = 0.0;
  double mass = 0.0;
  double Rx = 0.0, Ry = 0.0, Rz = 0.0;
  double Vx = 0.0, Vy = 0.0, Vz = 0.0;
  double Fx = 0.0, Fy = 0.0, Fz = 0.0;
};

const double G = -9.81;
const int NSTEPS = 1000;
const double DT = 0.01;
const double K = 253.57;
const double L=2.0;

// function declarations
void initial_conditions(Particle & body);
void compute_force(Particle & body);
void time_integration(Particle & body, const double & dt);
void start_integration(Particle & body, const double & dt);
void print(Particle & body, double time);

int main(void)
{
  Particle ball;

  // start system
  initial_conditions(ball);
  compute_force(ball);
  start_integration(ball, DT);
  print(ball, 0.0);

  // evolve
  for(int istep = 0; istep < NSTEPS; ++istep) {
    time_integration(ball, DT);
    compute_force(ball);
    print(ball, istep*DT);
  }

  return 0;
}

void initial_conditions(Particle & body)
{
  body.Ry = 1.6598;
  body.Vx = 0.23698;
  body.Vy = 0.67;


  body.rad = 0.1;
  body.mass = 0.055;
}

void compute_force(Particle & body)
{
  // reset force
  body.Fx = body.Fy = body.Fz = 0.0;

  // gravitational force
  //body.Fy += body.mass*G;

  // force with ground
  double delta = body.rad - body.Ry;
  if (delta > 0) {
    body.Fy += K*delta;
    // body.Fy -= 1.9876*body.Vy;
  }
      // force with left wall
    delta = body.rad - body.Rx;
    if (delta > 0) {
      body.Fx += K*delta;
    }

    // force with right wall
    delta = body.rad + body.Rx - L;
    if (delta > 0) {
      body.Fx -= K*delta;
    }

    // force with upper wall
    delta = body.rad + body.Ry - L;
    if (delta > 0) {
      body.Fy -= K*delta;
    }

}

void start_integration(Particle & body, const double & dt)
{
  body.Vx -= body.Fx*dt/(2*body.mass);
  body.Vy -= body.Fy*dt/(2*body.mass);
  body.Vz -= body.Fz*dt/(2*body.mass);
}

  void time_integration(Particle & body, const double & dt)
{
  // leap-frog
  body.Vx += body.Fx*dt/(body.mass);
  body.Vy += body.Fy*dt/(body.mass);
  body.Vz += body.Fz*dt/(body.mass);
  body.Rx += body.Vx*dt;
  body.Ry += body.Vy*dt;
  body.Rz += body.Vz*dt;
}

void print(Particle & body, double time)
{
  std::cout << time << "  "
            << body.Rx << "  "
            << body.Ry << "  "
            << body.Rz << "  "
            << body.Vx << "  "
            << body.Vy << "  "
            << body.Vz << "  "
            << "\n";
}
