#include "stockFunctions.h"
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>      // I was looking at libraries that streamlined potentially long for loops and found one that might work for this assignment

double percentChange(const std::vector<double>& values , int startDay , int endDay) {
  return ((values.at(endDay) - values.at(startDay)) / values.at(startDay)) * 100;
}

double highestValue(const std::vector<double>& values , int startDay , int endDay) {
  double maxSoFar = values.at(startDay);

  for (int = startDay + 1 ; i <= endDay ; i++) {
    if (values.at(i) > maxSoFar) {
      maxSoFar = values.at(i);
    }
  }
  return maxSoFar;
}

double average(const std::vector<double>& values , int startDay , int endDay) {
  return 0.0;
}

double standardDev(const std::vector<double>& values , int startDay , int endDay) {
  return 0.0;
}

std::vector<double> parseData(const std::string& csv) {
  return std::vector<double>();
}

std::vector<double> getChangeVector(const std::vector<double>& values) {
  return std::vector<double>();
}

double maxDrawdown(const std::vector<double>& values , int startDay , int endDay) {
  return 0.0;
}
