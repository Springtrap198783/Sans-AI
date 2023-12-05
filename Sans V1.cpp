#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    // Predefined list of bad jokes
    std::vector<std::string> jokes = {
        "Why don't skeletons fight each other? They don't have the guts.",
        "Why did the skeleton go to the party alone? He had no body to go with him.",
        "Why didn't the skeleton cross the road? He didn't have the guts.",
        "What do you call a skeleton who won't work? Lazy bones."
    };

    std::string input;
    while (true) {
        std::cout << "Sans: 'Wanna hear a joke? Type 'joke' or 'quit' to quit: ";
        std::getline(std::cin, input);

        if (input == "quit") {
            std::cout << "Sans: 'Heh, catch ya later, kid.'\n";
            break;
        } else if (input == "joke") {
            int randomIndex = rand() % jokes.size(); // Generate a random index
            std::cout << "Sans: '" << jokes[randomIndex] << "'\n";
        } else {
            std::cout << "Sans: 'Eh, I don't understand that. Try 'joke' or 'quit'.\n";
        }
    }

    return 0;
}
