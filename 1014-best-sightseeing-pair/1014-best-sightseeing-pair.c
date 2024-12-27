int maxScoreSightseeingPair(int* values, int valuesSize) {
        int ans = 0;
        int Prev = values[0];   // value[0] + 0

        for (int j = 1; j < valuesSize; j++) {
            ans = fmax(ans, Prev + values[j] - j);   // calculate (value[i] + i) + (value[j] - j)
            Prev = fmax(Prev, values[j] + j);    // update value[i] + i
        }

        return ans;
}

// Bijoy Sing's solution.
// Yen Huynh's solution.