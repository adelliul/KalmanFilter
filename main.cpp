

#include <iostream>
#include <vector>
#include "KalmanFilter.h"  

int main() {
    // Example data: noisy price readings
    std::vector<double> prices = {5050.25, 5050.5, 5050.75, 5049.75, 5051.0, 5050.8, 5051.5};

    // Create a KalmanFilter object
    // Q = 0.01 (real value changes slowly)
    // R = 0.25 (data is a bit noisy)
    // initial_estimate = first price
    KalmanFilter kf(0.01, 0.25, prices[0]);

    std::cout << "NoisyPrice FilteredPrice";

    // Loop through each price and update our estimate
    for (double price : prices) {
        double filtered = kf.update(price);
        std::cout << price << "\t\t" << filtered << "\n";
    }

    // When we run this:
    // The left column is the raw (noisy) data,
    // The right column is the smoother Kalman filter estimate.
    return 0;
}
