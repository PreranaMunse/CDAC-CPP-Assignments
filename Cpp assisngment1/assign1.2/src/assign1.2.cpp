
#include <bits/stdc++.h>

using namespace std;

int main() {

    int N;

    double temperature[100];

    cout << "Reading entered : " << endl;

    cin >> N;

    if (N < 1 || N > 100) {

        cout << "Invalid N. Must be between 1 and 100." << endl;

        return 0;

    }

    cout << "Enter " << N << " temperature readings:" << endl;

    for (int i = 0; i < N; i++) {

        cin >> temperature[i];

    }

    cout << "Valid Readings :" << endl;

    int skipped = 0;

    for (int i = 0; i < N; i++) {

        if (temperature[i] < 0) {

            skipped++;

            continue;

        }

        cout << temperature[i] << " ";

    }

    cout << endl;

    cout << "Skipped (errors) : " << skipped << endl;

    bool foundCritical = false;

    for (int i = 0; i < N; i++)

    {

        if (temperature[i] >= 45)

        {

            cout << "First CRITICAL: Index " << i << " -> "
                 << temperature[i] << " °C" << endl;

            foundCritical = true;

            break;

        }

    }

    if (!foundCritical){

        cout << " First CRITICAL : none found" << endl;

    }

    // min max

    double minTemp = 0;

    double maxTemp = 0;

    double sum = 0;

    int validCount = 0;

    int normal = 0;

    int warning = 0;

    int critical = 0;

    int shutdown = 0;

    bool firstValid = true;

    for (int i = 0; i < N; i++) {

        if (temperature[i] < 0) {

            continue;

        }

        // min and max

        if (firstValid) {

            minTemp = temperature[i];

            maxTemp = temperature[i];

            firstValid = false;

        }

        else {

            if (temperature[i] < minTemp) {

                minTemp = temperature[i];

            }

            if (temperature[i] > maxTemp) {

                maxTemp = temperature[i];

            }

        }



        sum = sum + temperature[i];

        validCount++;



        if (temperature[i] < 30) {

            normal++;

        }

        else if (temperature[i] < 45) {

            warning++;

        }

        else if (temperature[i] < 60) {

            critical++;

        }

        else {

            shutdown++;

        }

    }

    double average = sum / validCount;

    cout << "Min : " << minTemp << " °C" << endl;

    cout << "Max : " << maxTemp << " °C" << endl;

    cout << "Avg : " << average << " °C" << endl;

    cout << "Normal: " << normal << endl;

    cout << "Warning: " << warning << endl;

    cout << "Critical: " << critical << endl;

    cout << "Shutdown: " << shutdown << endl;

    return 0;
}
