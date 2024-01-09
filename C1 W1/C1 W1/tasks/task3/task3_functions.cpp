#include "task3_functions.h"

using namespace std;


string findCorners(std::string filePath)
{
    string result;

    // ************************
    // WRITE YOUR SOLUTION HERE
    // ************************

    // Open the file
    std::ifstream file(filePath);

    // Check if the file is open
    if (!file.is_open()) {
        throw std::invalid_argument("Could not open file");
    }

    int firstLine = -1;
    int firstPos = -1;
    int lastLine = -1;
    int lastPos = -1;

    // Read each line in the file
    std::string line;
    for (int lineNumber = 0; std::getline(file, line); ++lineNumber) {
        size_t pos = 0;

        // Find the first occurrence of '*'
        if (firstPos == -1) {
            firstPos = line.find('*');
            if (firstPos != std::string::npos) {
                firstLine = lineNumber;
            }
        }

        // Find the last occurrence of '*'
        size_t lineLastPos = line.rfind('*');
        if (lineLastPos != std::string::npos) {
            lastLine = lineNumber;
            lastPos = lineLastPos;
        }
    }

    // Close the file
    file.close();

    // Append the coordinates of the top left corner to the result string
    result += "\"topLeft\": [" + std::to_string(firstLine) + ", " + std::to_string(firstPos / 2) + "] ";

    // Append the coordinates of the bottom right corner to the result string
    result += "\"bottomRight\": [" + std::to_string(lastLine) + ", " + std::to_string(lastPos / 2) + "] ";

    // Return the result string
    return result;
}
