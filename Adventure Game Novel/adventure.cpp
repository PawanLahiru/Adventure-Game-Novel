
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

// Function prototypes
void introduction();
void forest();
void cave();
void village();
void castle();
void mountain();
void lake();
void river();
void desert();
void ending(bool goodEnding);

// Global variables
int score = 0;
int high_score = 0;

// Function to print the title using ASCII art from a file
 void printASCII(string fileName) {
    string line = "";
    ifstream inFile(fileName);
    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open the file: " << fileName << endl;
    }
} 

int main() {

    string fileName = "Title.txt";
    printASCII(fileName);  

    srand(time(0)); // Seed for random number generator
    introduction();
    forest(); // Start the adventure in the forest

    return 0;
}

void introduction() {
    cout << "Welcome to the Rich Adventure Game!" << endl;
    cout << "You are a brave adventurer on a quest to find the hidden treasure of the ancient kingdom." << endl;
    cout << "Your journey begins in a dense forest." << endl;
    forest();
}

void forest() { 

    // Display the contents of forest.txt
     string line = "";
    ifstream inFile("forest.txt");
    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open the file: forest.txt" << endl;
    }  

    // Ask the player where they want to go

    string choice;
    cout << "\nYou are in a dense forest. The trees are tall and the path is narrow." << endl;
    cout << "You see paths leading to various directions: a dark cave, a village, a mountain trail," << endl;
    cout << "and a path along the river." << endl;
    cout << "Where do you want to go? (cave/village/mountain/river): ";
    cin >> choice;

    if (choice == "cave") {
        cave();
    } else if (choice == "village") {
        village();
    } else if (choice == "mountain") {
        mountain();
    } else if (choice == "river") {
        river();
    } else {
        cout << "Invalid choice. Try again." << endl;
        forest();
    }
}
void cave() {

    // Display the contents of cave.txt
    string line = "";
    ifstream inFile("cave.txt");
    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open the file: cave.txt" << endl;
    }  
    
    string choice;
    cout << "\nYou enter the dark cave. It's cold and damp, and you can hear the sound of dripping water." << endl;
    cout << "There are paths leading deeper into darkness and another leading to an exit." << endl;
    cout << "Which path do you take? (darkness/exit): ";
    cin >> choice;

    if (choice == "darkness") {
        int encounter = rand() % 3; // Randomly select an encounter
        if (encounter == 0) {
            cout << "You venture deeper into the darkness and encounter a sleeping dragon!" << endl;
            cout << "Do you want to sneak past it or attack it? (sneak/attack): ";
            cin >> choice;
            if (choice == "sneak") {
                cout << "You quietly sneak past the dragon and find a hidden treasure chest filled with gold and jewels!" << endl;
                score += 50;
                cout << "You take the treasure and carefully make your way out of the cave." << endl;
                village();
            } else {
                cout << "You bravely attack the dragon, but it's too strong for you." << endl;
                cout << "The dragon defeats you, and your adventure ends here." << endl;
                ending(false);
            }
        } else if (encounter == 1) {
            cout << "You find yourself in a maze of tunnels." << endl;
            cout << "After a while, you manage to find your way to an underground lake." << endl;
            cout << "The water is crystal clear, and you can see something shimmering at the bottom." << endl;
            cout << "Do you want to dive in and investigate? (dive/exit): ";
            cin >> choice;
            if (choice == "dive") {
                lake();
            } else {
                cout << "You decide not to risk it and find your way back out of the cave." << endl;
                forest();
            }
        } else {
            cout << "You encounter a group of hostile goblins!" << endl;
            cout << "They attack you on sight." << endl;
            cout << "Do you want to fight back or try to negotiate? (fight/negotiate): ";
            cin >> choice;
            if (choice == "fight") {
                cout << "You fight fiercely against the goblins and manage to defeat them!" << endl;
                cout << "Exhausted, you find a hidden passage deeper into the cave." << endl;
                cave();
            } else {
                cout << "You try to negotiate with the goblins, but they are not interested." << endl;
                cout << "They capture you and lock you in a cell." << endl;
                cout << "Your adventure ends here." << endl;
                ending(false);
            }
        }
    } else if (choice == "exit") {
        cout << "You follow the path to the exit and find yourself back in the forest." << endl;
        forest();
    } else {
        cout << "Invalid choice. Try again." << endl;
        cave();
    }
}
void village() {

    // Display the contents of village.txt
    string line = "";
    ifstream inFile("village.txt");
    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open the file: village.txt" << endl;
    }  
    

    string choice;
    cout << "\nYou arrive at a lively village bustling with traders and adventurers." << endl;
    cout << "You hear rumors of a lost artifact in the nearby desert and a haunted castle to the east." << endl;
    cout << "Do you want to explore the desert, investigate the castle, or stay in the village? (desert/castle/stay): ";
    cin >> choice;

    if (choice == "desert") {
        desert();
    } else if (choice == "castle") {
        castle();
    } else if (choice == "stay") {
        cout << "You decide to rest in the village and talk to the locals." << endl;
        cout << "You learn about a secret tunnel beneath the village that leads to hidden treasure." << endl;
        cout << "Do you want to explore the tunnel or continue exploring above ground? (tunnel/forest): ";
        cin >> choice;
        if (choice == "tunnel") {
            cout << "You find the secret tunnel entrance and descend into the darkness." << endl;
            cout << "Inside, you encounter traps and puzzles left by ancient guardians." << endl;
            cout << "After overcoming challenges, you discover the hidden treasure!" << endl;
            score += 200;
            ending(true);
        } else if (choice == "forest") {
            forest();
        } else {
            cout << "Invalid choice. Try again." << endl;
            village();
        }
    } else {
        cout << "Invalid choice. Try again." << endl;
        village();
    }
}

void castle() {

    // Display the contents of castle.txt
    string line = "";
    ifstream inFile("castle.txt");
    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open the file: castle.txt" << endl;
    }  
    

    string choice;
    cout << "\nYou approach the ancient castle surrounded by a thick mist." << endl;
    cout << "The gate is guarded by mystical creatures who demand a riddle or a duel." << endl;
    cout << "Do you want to solve the riddle, challenge them to a duel, or retreat? (riddle/duel/retreat): ";
    cin >> choice;

    if (choice == "riddle") {
        cout << "You accept the challenge and successfully solve the riddle!" << endl;
        cout << "Impressed, the creatures allow you to enter the castle." << endl;
        cout << "Inside, you meet a cursed knight who seeks redemption." << endl;
        cout << "He asks for your help in breaking the curse by finding a lost artifact." << endl;
        cout << "Do you agree to help him or search for the treasure on your own? (help/treasure): ";
        cin >> choice;
        if (choice == "help") {
            cout << "You agree to help the cursed knight and embark on a quest together." << endl;
            cout << "After many trials and battles, you find the artifact and lift the curse!" << endl;
            score += 300;
            ending(true);
        } else if (choice == "treasure") {
            cout << "You decide to search for the treasure on your own, leaving the knight to his fate." << endl;
            cout << "As you explore deeper, you uncover dark secrets of the castle's past." << endl;
            cout << "In the end, you find the hidden treasure, but at what cost?" << endl;
            score += 300;
            ending(true);
        } else {
            cout << "Invalid choice. Try again." << endl;
            castle();
        }
    } else if (choice == "duel") {
        cout << "You challenge the creatures to a duel, and after a fierce battle, emerge victorious!" << endl;
        cout << "Impressed by your strength, they grant you access to the castle." << endl;
        cout << "Inside, you encounter the castle's ghostly inhabitants." << endl;
        cout << "They offer you a choice: join them in eternal servitude or find a way to break their curse." << endl;
        cout << "What will you do? (join/break): ";
        cin >> choice;
        if (choice == "join") {
            cout << "You accept their offer and become part of the castle's ghostly legion." << endl;
            cout << "Your adventure ends here." << endl;
            ending(false);
        } else if (choice == "break") {
            cout << "You vow to break their curse and find clues scattered throughout the castle." << endl;
            cout << "After solving intricate puzzles and battling restless spirits, you succeed!" << endl;
            score += 250;
            ending(true);
        } else {
            cout << "Invalid choice. Try again." << endl;
            castle();
        }
    } else if (choice == "retreat") {
        cout << "You decide not to risk it and retreat from the castle." << endl;
        forest();
    } else {
        cout << "Invalid choice. Try again." << endl;
        castle();
    }
}
void mountain() {

    // Display the contents of mountain.txt
    string line = "";
    ifstream inFile("mountain.txt");
    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open the file: mountain.txt" << endl;
    } 
     

    string choice;
    cout << "\nYou embark on a treacherous path up the towering mountain." << endl;
    cout << "The air grows thinner as you ascend, and the path becomes increasingly perilous." << endl;
    cout << "You encounter a snowstorm and must decide: push forward or seek shelter? (forward/shelter): ";
    cin >> choice;

    if (choice == "forward") {
        int encounter = rand() % 3; // Randomly select an encounter
        if (encounter == 0) {
            cout << "You stumble upon a hidden cave filled with ancient relics!" << endl;
            cout << "Among the relics, you find a map leading to a forgotten temple." << endl;
            cout << "Do you follow the map or continue your ascent? (temple/ascent): ";
            cin >> choice;
            if (choice == "temple") {
                cout << "You follow the map and discover the ancient temple." << endl;
                cout << "Inside, you face trials of wisdom and courage." << endl;
                cout << "You emerge victorious with ancient treasures and knowledge." << endl;
                score += 200;
                ending(true);
            } else if (choice == "ascent") {
                cout << "You decide to continue your ascent, leaving the map behind." << endl;
                cout << "Near the summit, you find a majestic eagle trapped in a hunter's snare." << endl;
                cout << "Do you free the eagle or leave it to its fate? (free/leave): ";
                cin >> choice;
                if (choice == "free") {
                    cout << "You free the eagle and receive its blessing." << endl;
                    cout << "With newfound strength, you reach the summit and discover a hidden cave." << endl;
                    cave();
                } else if (choice == "leave") {
                    cout << "You leave the eagle and continue your ascent." << endl;
                    cout << "Near the summit, you find a hidden cave and decide to explore it." << endl;
                    cave();
                } else {
                    cout << "Invalid choice. Try again." << endl;
                    mountain();
                }
            } else {
                cout << "Invalid choice. Try again." << endl;
                mountain();
            }
        } else if (encounter == 1) {
            cout << "You encounter a mountain tribe known for their wisdom and hospitality." << endl;
            cout << "They invite you to their village hidden in the clouds." << endl;
            cout << "Do you accept their invitation or continue your journey? (accept/continue): ";
            cin >> choice;
            if (choice == "accept") {
                cout << "You accept their invitation and spend time learning their ancient traditions." << endl;
                cout << "They gift you with a magical talisman for protection on your journey." << endl;
                score += 150;
                ending(true);
            } else if (choice == "continue") {
                cout << "You thank the tribe and continue your journey." << endl;
                forest();
            } else {
                cout << "Invalid choice. Try again." << endl;
                mountain();
            }
        } else {
            cout << "You encounter a dangerous avalanche blocking your path." << endl;
            cout << "Do you attempt to climb over it or find another route? (climb/another): ";
            cin >> choice;
            if (choice == "climb") {
                cout << "You narrowly escape the avalanche and find a hidden cave in the mountainside." << endl;
                cave();
            } else if (choice == "another") {
                cout << "You backtrack and find a safer route around the avalanche." << endl;
                forest();
            } else {
                cout << "Invalid choice. Try again." << endl;
                mountain();
            }
        }
    } else if (choice == "shelter") {
        cout << "You seek shelter from the storm and find a cave to rest in." << endl;
        cout << "Inside the cave, you discover remnants of an ancient campsite." << endl;
        cout << "You find valuable artifacts left behind by previous explorers." << endl;
        score += 100;
        ending(true);
    } else {
        cout << "Invalid choice. Try again." << endl;
        mountain();
    }
}

void lake() {

    // Display the contents of lake.txt
    string line = "";
    ifstream inFile("lake.txt");
    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open the file: lake.txt" << endl;
    }  
    

    string choice;
    cout << "\nYou dive into the crystal-clear lake and swim deeper." << endl;
    cout << "You encounter a hidden underwater cave." << endl;
    cout << "Inside the cave, you find glowing crystals and an ancient statue." << endl;
    cout << "Do you explore the cave further or swim back to the surface? (explore/surface): ";
    cin >> choice;

    if (choice == "explore") {
        cout << "You explore deeper into the cave and find a mystical portal." << endl;
        cout << "The portal transports you to a magical realm filled with mythical creatures." << endl;
        cout << "You embark on a quest to find the portal's key to return home." << endl;
        score += 250;
        ending(true);
    } else if (choice == "surface") {
        cout << "You swim back to the surface with the artifacts you found." << endl;
        cout << "As you emerge from the lake, you see a path leading towards a hidden valley." << endl;
        cout << "Do you follow the path or return to the forest? (valley/forest): ";
        cin >> choice;
        if (choice == "valley") {
            cout << "You follow the path and discover a lush valley untouched by time." << endl;
            cout << "You encounter a wise old sage who imparts ancient wisdom." << endl;
            cout << "With the sage's blessing, you continue your journey." << endl;
            score += 150;
            ending(true);
        } else if (choice == "forest") {
            forest();
        } else {
            cout << "Invalid choice. Try again." << endl;
            lake();
        }
    } else {
        cout << "Invalid choice. Try again." << endl;
        lake();
    }
}

void river() {

    // Display the contents of river.txt
    string line = "";
    ifstream inFile("river.txt");
    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open the file: river.txt" << endl;
    } 
     

    string choice;
    cout << "\nYou follow the path along the riverbank." << endl;
    cout << "The river flows swiftly, and you spot a bridge up ahead." << endl;
    cout << "As you approach the bridge, you notice a troll guarding it." << endl;
    cout << "Do you try to cross the bridge or find another way? (cross/another): ";
    cin >> choice;

    if (choice == "cross") {
        cout << "You approach the troll cautiously and offer a riddle." << endl;
        cout << "The troll, amused, allows you to cross the bridge." << endl;
        cout << "On the other side, you encounter a fork in the road." << endl;
        cout << "Will you take the path leading to a dark forest or a sunlit meadow? (forest/meadow): ";
        cin >> choice;
        if (choice == "forest") {
            cout << "You enter the dark forest and find an abandoned cabin." << endl;
            cout << "Inside, you discover a hidden journal with clues to a buried treasure." << endl;
            score += 100;
            ending(true);
        } else if (choice == "meadow") {
            cout << "You walk through the sunlit meadow and discover a peaceful village." << endl;
            village();
        } else {
            cout << "Invalid choice. Try again." << endl;
            river();
        }
    } else if (choice == "another") {
        cout << "You decide to find another way across the river." << endl;
        cout << "You follow the river upstream and discover a shallow ford." << endl;
        cout << "After safely crossing, you encounter a lone traveler." << endl;
        cout << "They offer you a choice: continue together or part ways? (together/part): ";
        cin >> choice;
        if (choice == "together") {
            cout << "You decide to travel together and share stories of your adventures." << endl;
            cout << "Together, you find a hidden waterfall with a secret cave behind it." << endl;
            cave();
        } else if (choice == "part") {
            cout << "You thank the traveler and continue your journey alone." << endl;
            forest();
        } else {
            cout << "Invalid choice. Try again." << endl;
            river();
        }
    } else {
        cout << "Invalid choice. Try again." << endl;
        river();
    }
}

void desert() {

    // Display the contents of desert.txt
    string line = "";
    ifstream inFile("desert.txt");
    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open the file: desert.txt" << endl;
    } 
     
    string choice;
    cout << "\nYou venture into the vast desert, where the scorching sun beats down relentlessly." << endl;
    cout << "In the distance, you see ancient ruins partially buried in the sand." << endl;
    cout << "Do you explore the ruins or search for an oasis? (ruins/oasis): ";
    cin >> choice;

    if (choice == "ruins") {
        cout << "You explore the ancient ruins and uncover a hidden chamber." << endl;
        cout << "Inside, you find a mysterious artifact guarded by traps." << endl;
        cout << "Do you attempt to take the artifact or leave it? (take/leave): ";
        cin >> choice;
        if (choice == "take") {
            cout << "You carefully navigate the traps and secure the artifact." << endl;
            cout << "As you leave the ruins, a sandstorm brews in the distance." << endl;
            cout << "Do you seek shelter or continue your journey? (shelter/journey): ";
            cin >> choice;
            if (choice == "shelter") {
                cout << "You find refuge in an ancient cave hidden within the ruins." << endl;
                cave();
            } else if (choice == "journey") {
                cout << "You brave the sandstorm and continue your journey through the desert." << endl;
                forest();
            } else {
                cout << "Invalid choice. Try again." << endl;
                desert();
            }
        } else if (choice == "leave") {
            cout << "You decide not to disturb the artifact and leave the ruins." << endl;
            cout << "As you journey through the desert, you encounter a nomadic tribe." << endl;
            cout << "They invite you to their camp for food and shelter." << endl;
            cout << "Do you accept their hospitality or continue alone? (accept/continue): ";
            cin >> choice;
            if (choice == "accept") {
                cout << "You accept the tribe's hospitality and learn about their ancient traditions." << endl;
                cout << "They share tales of lost cities hidden beneath the sands." << endl;
                score += 150;
                ending(true);
            } else if (choice == "continue") {
                cout << "You thank the tribe and continue your journey alone." << endl;
                forest();
            } else {
                cout << "Invalid choice. Try again." << endl;
                desert();
            }
        } else {
            cout << "Invalid choice. Try again." << endl;
            desert();
        }
    } else if (choice == "oasis") {
        cout << "You search for an oasis and find a hidden spring surrounded by lush vegetation." << endl;
        cout << "As you rest and replenish your supplies, you notice a faint trail leading deeper into the desert." << endl;
        cout << "Do you follow the trail or return to the village? (trail/village): ";
        cin >> choice;
        if (choice == "trail") {
            cout << "You follow the trail and discover an ancient tomb buried beneath the dunes." << endl;
            cout << "Inside, you face trials of courage and endurance." << endl;
            cout << "You uncover ancient relics and treasures buried with the long-forgotten ruler." << endl;
            score += 200;
            ending(true);
        } else if (choice == "village") {
            village();
        } else {
            cout << "Invalid choice. Try again." << endl;
            desert();
        }
    } else {
        cout << "Invalid choice. Try again." << endl;
        desert();
    }
}

void ending(bool goodEnding) {

    // Display the contents of ending.txt
    string line = "";
    ifstream inFile("ending.txt");
    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open the file: ending.txt" << endl;
    }  
    

    cout << "\n--- End of Adventure ---" << endl;
    if (goodEnding) {
        cout << "Congratulations! You have completed your quest and achieved a great victory!" << endl;
        cout << "Your final score is: " << score << endl;
        if (score > high_score) {
            high_score = score;
            cout << "You have set a new high score!" << endl;
        } else {
            cout << "Try again to beat your high score of: " << high_score << endl;
        }
    } else {
        cout << "Unfortunately, your adventure has come to an end." << endl;
        cout << "Your final score is: " << score << endl;
        cout << "Better luck next time!" << endl;
    }
    cout << "Thank you for playing the Rich Adventure Game!" << endl;
    exit(0); // Exit the game
}

