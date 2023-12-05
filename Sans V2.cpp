#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    // Predefined list of bad jokes
    std::vector<std::string> jokes = {
        "Why don't skeletons fight each other? They don't have the guts.",
        "Why did the skeleton go to the party alone? He had no body to go with him.",
        "Why didn't the skeleton cross the road? He didn't have the guts.",
        "What do you call a skeleton who won't work? Lazy bones."
    };

    // Predefined list of Sans' responses
    std::map<std::string, std::string> responses = {
        {"hello", "Heya. You've been busy, huh?"},
        {"bye", "It's a beautiful day outside. Birds are singing, flowers are blooming... on days like these, kids like you... should be burning in hell."},
        {"how are you", "I'm pretty bone-tired, to be honest with ya."},
        {"what's up", "The sky. Or is it the ceiling? Or maybe... it's nothing at all."},
    };

    std::string input;
    while (true) {
        std::cout << "Sans: 'Wanna hear a joke? Type 'joke', or type 'quit' to quit, or ask me something else: ";
        std::getline(std::cin, input);

        if (input == "quit") {
            std::cout << "Sans: 'Heh, catch ya later, kid.'\n";
            break;
        } else if (input == "joke") {
            int randomIndex = rand() % jokes.size(); // Generate a random index
            std::cout << "Sans: '" << jokes[randomIndex] << "'\n";
        } else {
            // Check if the input matches any of the predefined responses
            auto response = responses.find(input);
            if (response != responses.end()) {
                std::cout << "Sans: '" << response->second << "'\n";
            } else {
                std::cout << "Sans: 'Eh, I don't understand that. Try 'joke' or 'quit'.\n";
            }
        }
    }

    return 0;
}
