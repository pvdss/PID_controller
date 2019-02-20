#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  Kp = Kp;
  Ki = Ki;
  Kd = Kd;
  prev_cte = 0;
  cte_total = 0;
}

void PID::UpdateError(double cte) {
  cte_total += cte;
  p_error = -Kp * cte;
  d_error = -Kd * (cte - prev_cte);
  i_error = -Ki * cte_total;
  prev_cte = cte;
}

double PID::TotalError() {
  return p_error+d_error+i_error;
}

