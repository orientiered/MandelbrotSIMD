#include <utils.h>
#include <math.h>

doublePair_t runningSTD(double value, int getResult) {
    //function to calculate standard deviation of some value
    //constructed to make calculations online, so static variables
    static doublePair_t result = {};
    static unsigned measureCnt = 0;     //number of values
    static double totalValue = 0;       //sum of value
    static double totalSqrValue = 0;    //sum of value^2
    // getResult > 1 --> calculate meanValue and std and return it
    // getResult = 0 --> store current value
    // getResult < 0 --> reset stored values
    if (getResult > 0) {
        if (measureCnt > 1) {
            result.first = totalValue / measureCnt;
            //printf("%g %g %u\n", totalSqrValue, totalValue, measureCnt);
            result.second = sqrt(totalSqrValue / measureCnt - result.first*result.first) / sqrt(measureCnt - 1);
        }
        return result;
    } else if (getResult == 0) {
        measureCnt++;
        totalValue += value;
        totalSqrValue += value*value;
    } else {
        measureCnt = 0;
        totalValue = totalSqrValue = 0;
    }
    return result;
}
