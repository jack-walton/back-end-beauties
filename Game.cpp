//Made with generative AI

#include <iostream>
#include <cstdlib>
#include <ctime>

class Character {
public:
    Character(const std::string& name, int health, int damage)
        : name(name), health(health), damage(damage) {}

    void attack(Character& target) {
        int attackDamage = rand() % damage + 1;
        std::cout << name << " attacks " << target.getName() << " for " << attackDamage << " damage.\n";
        target.takeDamage(attackDamage);
    }

    void takeDamage(int amount) {
        health -= amount;
        if (health <= 0) {
            health = 0;
            std::cout << name << " has been defeated!\n";
        } else {
            std::cout << name << " takes " << amount << " damage. Remaining health: " << health << "\n";
        }
    }

    bool isAlive() const {
        return health > 0;
    }

    const std::string& getName() const {
        return name;
    }

private:
    std::string name;
    int health;
    int damage;
};

void printMenu() {
    std::cout << "1. Attack\n";
    std::cout << "2. Quit\n";
}

int main() {
    // Seed for random number generation
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Create characters
    Character player("Player", 100, 10);
    Character enemy("Enemy", 50, 5);

    std::cout << "Welcome to the Text-based RPG!\n";

    // Game loop
    while (player.isAlive() && enemy.isAlive()) {
        // Display character information
        std::cout << "Player: " << player.getName() << " | Health: " << player.getName() << "\n";
        std::cout << "Enemy: " << enemy.getName() << " | Health: " << enemy.getName() << "\n";

        // Display menu
        printMenu();

        // Get player's choice
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Process player's choice
        switch (choice) {
            case 1:
                // Player attacks enemy
                player.attack(enemy);
                break;
            case 2:
                // Player quits the game
                std::cout << "Thanks for playing!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }

        // Enemy attacks player
        if (enemy.isAlive()) {
            enemy.attack(player);
        }
    }

    // Game over
    std::cout << "Game over!\n";

    return 0;
}