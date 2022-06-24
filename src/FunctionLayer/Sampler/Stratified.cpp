#include "Stratified.h"


void StratifiedSampler::generateSamples1D(std::vector<double> &samples) {
    double invSPP = (double)1 / samplesPerPixel;
    for (int i = 0; i < samplesPerPixel; ++i) {
        samples[i] = std::min((i + rng()) * invSPP, ONEMINUSEPSILON);
    }      
}

void StratifiedSampler::generateSamples2D(std::vector<Point2d> &samples) {
    double dx = (double)1 / sppSqrt,
           dy = (double)1 / sppSqrt;
    for (int x = 0; x < sppSqrt; ++x)
        for (int y = 0; y < sppSqrt; ++y) {
            samples[x + y * sppSqrt].x = std::min((x + rng()) * dx, ONEMINUSEPSILON);
            samples[x + y * sppSqrt].y = std::min((y + rng()) * dy, ONEMINUSEPSILON);
        }
}