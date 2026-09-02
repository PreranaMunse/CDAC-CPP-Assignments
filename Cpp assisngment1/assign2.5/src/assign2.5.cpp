//============================================================================
// Name        : 5.cpp
// Author      : prer
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

// distance between two points
inline double distanceBetween(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// degrees to radians
inline double toRadians(double degrees)
{
    return degrees * (M_PI / 180.0);
}

// restrict value within a given range
inline double clamp(double value, double minVal, double maxVal)
{
    if (value < minVal)
        return minVal;
    else if (value > maxVal)
        return maxVal;
    else
        return value;
}

// point inside the safe zone
inline bool isInSafeZone(double x, double y, double cx, double cy, double radius)
{
    double distance = distanceBetween(x, y, cx, cy);
    return distance <= radius;
}

int main()
{

    double homeX = 0.0;
    double homeY = 0.0;


    double radius = 50.0;


    double x1 = 10.0, y1 = 20.0;
    double x2 = 30.0, y2 = 40.0;
    double x3 = 60.0, y3 = 10.0;


    double distance1 = distanceBetween(homeX, homeY, x1, y1);
    cout << "Waypoint 1: (" << x1 << ", " << y1 << ")" << endl;
    cout << "Distance from home: " << distance1 << endl;
    cout << "Inside safe zone: "
         << (isInSafeZone(x1, y1, homeX, homeY, radius) ? "Yes" : "No")
         << endl << endl;


    double distance2 = distanceBetween(homeX, homeY, x2, y2);
    cout << "Waypoint 2: (" << x2 << ", " << y2 << ")" << endl;
    cout << "Distance from home: " << distance2 << endl;
    cout << "Inside safe zone: "
         << (isInSafeZone(x2, y2, homeX, homeY, radius) ? "Yes" : "No")
         << endl << endl;


    double distance3 = distanceBetween(homeX, homeY, x3, y3);
    cout << "Waypoint 3: (" << x3 << ", " << y3 << ")" << endl;
    cout << "Distance from home: " << distance3 << endl;
    cout << "Inside safe zone: "
         << (isInSafeZone(x3, y3, homeX, homeY, radius) ? "Yes" : "No")
         << endl;

    return 0;
}
