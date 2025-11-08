

#ifndef KALMANFILTER_H
#define KALMANFILTER_H

class KalmanFilter {
    private:
    double Q;      // Process variance
    double R;      // Measurement variance
    double x_hat;  // Current best estimate
    double P;      // Current uncertainty (confidence)


public:
    // Constructor
    // Q = how much we think the real value can change (process noise)
    // R = how noisy our observed data is (measurement noise)
    // initial_estimate = our first guess of the real value
    KalmanFilter(double process_variance, double measurement_variance, double initial_estimate);

    // Update function
    // Called each time we get a new measurement.
    // Returns the updated (smoothed) estimate.
    double update(double measurement);
};

#endif // KALMANFILTER_H
