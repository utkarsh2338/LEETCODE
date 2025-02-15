class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        
        auto calculateAreas = [&](double lineY) -> pair<double, double> {
            double areaAbove = 0.0;
            double areaBelow = 0.0;
            for (const auto& square : squares) {
                double x = square[0]; // x-coordinate of bottom-left corner
                double y = square[1]; // y-coordinate of bottom-left corner
                double l = square[2]; // side length of the square
                if (lineY >= y + l) {
                    // Entire square is below the line
                    areaBelow += l * l;
                } else if (lineY <= y) {
                    // Entire square is above the line
                    areaAbove += l * l;
                } else {
                    // Line intersects the square
                    double heightAbove = y + l - lineY;
                    double heightBelow = lineY - y;
                    areaAbove += heightAbove * l;
                    areaBelow += heightBelow * l;
                }
            }
            return {areaAbove, areaBelow};
        };

        // Determine the search range for y
        double minY = numeric_limits<double>::max();
        double maxY = numeric_limits<double>::lowest();
        for (const auto& square : squares) {
            double y = square[1]; // y-coordinate of bottom-left corner
            double l = square[2]; // side length of the square
            minY = min(minY, y);
            maxY = max(maxY, y + l);
        }

        // Binary search to find the correct y-coordinate
        double precision = 1e-5;
        while (maxY - minY > precision) {
            double midY = (minY + maxY) / 2.0;
            auto [areaAbove, areaBelow] = calculateAreas(midY);
            if (areaAbove > areaBelow) {
                // Move the line higher
                minY = midY;
            } else {
                // Move the line lower
                maxY = midY;
            }
        }

        // Return the minimum y-coordinate
        return minY;
    }
};