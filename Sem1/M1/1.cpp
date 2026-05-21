//Варіант 2
#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;
int main() {
    int n;
    cin >> n;
    int min_temp = INT_MAX;
    int max_temp = INT_MIN;
    double sum = 0.0;
    int valid_count = 0;
    int nonneg_count = 0;
    int bins[10] = {0};
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        if (temp < -50 || temp > 50) {
            continue;
        }
        valid_count++;
        sum += temp;
        if (temp < min_temp) {
            min_temp = temp;
        }
        if (temp > max_temp) {
            max_temp = temp;
        }
        if (temp >= 0) {
            nonneg_count++;
        }
        int bin_index;
        if (temp == 50) {
            bin_index = 9;
        } else {
            bin_index = (temp + 50) / 10;
        }
        bins[bin_index]++;
    }
    double avg = 0.0;
    if (valid_count > 0) {
        avg = sum / valid_count;
    }
    cout << "min=" << min_temp << " max=" << max_temp << " avg=" << setprecision(2) << avg << endl;
    cout << "nonneg=" << nonneg_count << endl;
    for (int i = 0; i < 10; ++i) {
        int start, end;
        if (i == 9) {
            start = 40;
            end = 50;
        } else {
            start = i * 10 - 50;
            end = i * 10 - 41;
        }
        cout << "[" << start << ";" << end << "]=" << bins[i] << endl;
    }
    return 0;
}