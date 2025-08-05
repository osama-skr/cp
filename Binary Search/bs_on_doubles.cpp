double binary_search(double low, double high) {
    while (high - low > 1e-6) {  // precision up to 6 decimal places
        double mid = (low + high) / 2.0;
        if (condition(mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return low; // or (low + high) / 2;
}
