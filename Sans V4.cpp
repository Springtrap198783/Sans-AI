#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <thread>
#include <chrono>
#include <random>
#include <fstream>
#include <sstream>

using std::string;
using std::vector;
using std::map;

constexpr int DELAY_DOTS_COUNT = 5;

// Function to convert input to lowercase for easier comparison
string toLowerCase(const string& str) {
    string lowerCaseStr;
    for (auto c : str) {
        lowerCaseStr += tolower(c);
    }
    return lowerCaseStr;
}

// Modern random number generation
int getRandomIndex(int size) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, size - 1);
    return dist(rng);
}

// Print dots with delay
void printDelayDots(int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "\n";
}

// Load jokes from a file
vector<string> loadJokesFromFile(const string& filename) {
    std::ifstream file(filename);
    vector<string> jokes;
    string line;
    while (std::getline(file, line)) {
        jokes.push_back(line);
    }
    return jokes;
}

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    // Predefined list of Sans' responses
    map<string, string> responses = {
        {"hello", "Heya. You've been busy, huh?"},
        {"bye", "It's a beautiful day outside. Birds are singing, flowers are blooming... on days like these, kids like you... should be burning in hell."},
        {"how are you", "I'm pretty bone-tired, to be honest with ya."},
        {"what's up", "The sky. Or is it the ceiling? Or maybe... it's nothing at all."},
    };

    // Load jokes from a file
    vector<string> jokes = loadJokesFromFile("jokes.txt");

    string input;
    while (true) {
        std::cout << "Sans: 'Wanna hear a joke? Type 'joke', or type 'quit' to quit, or ask me something else: ";
        std::getline(std::cin, input);

        // Convert input to lowercase
        string lowerCaseInput = toLowerCase(input);

        if (lowerCaseInput == "quit") {
            std::cout << "Sans: 'Heh, catch ya later, kid.'\n";
            break;
        } else if (lowerCaseInput == "joke") {
            if (!jokes.empty()) {
                int randomIndex = getRandomIndex(jokes.size()); // Generate a random index
                std::cout << "Sans: '" << jokes[randomIndex] << "'\n";
            } else {
                std::cout << "Sans: 'I'm all out of jokes. Ask me something else.'\n";
            }
        } else {
            // Check if the input matches any of the predefined responses
            auto response = responses.find(lowerCaseInput);
            if (response != responses.end()) {
                std::cout << "Sans: '" << response->second << "'\n";
            } else {
                std::cout << "Sans: 'Eh, I don't understand that. ";
                std::cout << "Try 'joke', 'quit', or one of the predefined questions.'\n";
            }
        }

        // Add a delay to simulate Sans' laziness
        printDelayDots(DELAY_DOTS_COUNT);
    }

    return 0;
}
