using namespace std;

#include "KalmanFilter.h"

// Constructo
KalmanFilter:: KalmanFilter(double process_variance, double measurement_variance, double initial_estimate)
    : Q(process_variance), R(measurement_variance), x_hat(initial_estimate), P(1.0) {}


double KalmanFilter::update(double measurement) {
    // Step 1: PREDICTION
    // Assume the real value hasn't changed much
    double x_hat_prior = x_hat;
    double P_prior = P + Q; // uncertainty increases a bit over time



    // Step 2: UPDATE (CORRECTION)
    // Calculate Kalman Gain: how much we trust new data vs our old estimate
    //formula k:
    double K = P_prior / (P_prior + R);

    // Update the estimated value
    x_hat = x_hat_prior + K * (measurement - x_hat_prior);

    // Update our uncertainty (we become more confident)
    P = (1 - K) * P_prior;

    // Return the filtered (smoothed) estimate
    return x_hat;
}
