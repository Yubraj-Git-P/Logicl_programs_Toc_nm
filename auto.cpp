#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate mean
double mean(double* data, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

// Function to calculate autocorrelation for a given lag
double autocorrelation(double* data, int n, int lag) {
    double meanVal = mean(data, n);
    double num = 0.0, den = 0.0;

    for (int i = 0; i < n - lag; i++) {
        num += (data[i] - meanVal) * (data[i + lag] - meanVal);
    }

    for (int i = 0; i < n; i++) {
        den += (data[i] - meanVal) * (data[i] - meanVal);
    }

    return num / den;
}

int main() {
    int n, lag;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double* data = (double*)malloc(n * sizeof(double));
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    printf("Enter the data points:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &data[i]);
    }

    printf("Enter the lag: ");
    scanf("%d", &lag);

    if (lag >= n) {
        printf("Lag should be less than the number of data points.\n");
        free(data);
        return -1;
    }

    double r = autocorrelation(data, n, lag);
    printf("Autocorrelation for lag %d is: %lf\n", lag, r);

    // Hypothesis testing
    double z = r / sqrt(1.0 / n);
    double criticalValue = 1.96;

    printf("Test statistic Z: %lf\n", z);
    if (fabs(z) > criticalValue) {
        printf("Reject the null hypothesis. Significant autocorrelation detected.\n");
    } else {
        printf("Fail to reject the null hypothesis. No significant autocorrelation detected.\n");
    }

    free(data);
    return 0;
}
