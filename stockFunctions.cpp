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

  for (int i = startDay + 1 ; i <= endDay ; i++) {
    if (values.at(i) > maxSoFar) {
      maxSoFar = values.at(i);
    }
  }
  return maxSoFar;
}

double average(const std::vector<double>& values , int startDay , int endDay) {
  // Parameters
  double sum = 0;

  // Main Loop
  int count = endDay - startDay + 1;
  for (int i = startDay ; i <= endDay ; i++) {
    sum += values.at(i);
  }
  // Sum / # of observations
  return sum / count;
}

double standardDev(const std::vector<double>& values , int startDay , int endDay) {
  // Parameters
  double avg = average(values , startDay , endDay);
  double sumSquareDiff = 0;

  //Main Loop
  for (int i = startDay ; i <= endDay ; i++) {
    sumSquareDiff += std::pow(values.at(i) - avg , 2);
  }
  //Divide by variance - then sqrt
  return std::sqrt(sumSquareDiff / (endDay - startDay + 1));
}

std::vector<double> parseData(const std::string& csv) {
  // Parameters
  std::vector<double> result;

  size_t start = 0;
  size_t end = csv.find(',');

  // Main Loop
  while (end != std::string::npos) {
    result.push_back(std::stod(csv.substr(start , end - start)));
    start = end + 1;
    end = csv.find (',' , start);
  }
  // Process after final comma
  result.push_back(std::stod(csv.substr(start)));
  return result;
}

std::vector<double> getChangeVector(const std::vector<double>& values) {
  // Parameters
  std::vector<double> changes(values.size());

  // Return Empty Vector if Input is empty
  if (values.empty()) {
    return changes;
  }
  // Main Loop
  for (size_t i = 1 ; i < values.size() ; i++) {
    changes.at(i) = values.at(i) - values.at(i-1);
  }
  return changes;
}

double maxDrawdown(const std::vector<double>& values , int startDay , int endDay) {
  // Parameters
  double minDiff = 0;
  
}
