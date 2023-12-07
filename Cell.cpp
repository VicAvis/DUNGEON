#include "Cell.h"

// Copy Constructor
Cell::Cell(const Cell& other) : isObstacle(other.isObstacle), isUnitPresent(other.isUnitPresent) {}

// Copy Assignment Operator
Cell& Cell::operator=(const Cell& other) {
    if (this != &other) {
        isObstacle = other.isObstacle;
        isUnitPresent = other.isUnitPresent;
    }
    return *this;
}

// Move Constructor
Cell::Cell(Cell&& other) noexcept : isObstacle(false), isUnitPresent(false) {
    // Steal resources from the other object
    isObstacle = other.isObstacle;
    isUnitPresent = other.isUnitPresent;

    // Reset the other object
    other.isObstacle = false;
    other.isUnitPresent = false;
}

// Move Assignment Operator
Cell& Cell::operator=(Cell&& other) noexcept {
    if (this != &other) {
        // Steal resources from the other object
        isObstacle = other.isObstacle;
        isUnitPresent = other.isUnitPresent;

        // Reset the other object
        other.isObstacle = false;
        other.isUnitPresent = false;
    }
    return *this;
}

Cell::Cell() : isObstacle(false), isUnitPresent(false) {}

void Cell::setObstacle(bool obstacle) {
    isObstacle = obstacle;
}

void Cell::setUnitPresent(bool unitPresent) {
    isUnitPresent = unitPresent;
}

bool Cell::hasObstacle() const {
    return isObstacle;
}

bool Cell::hasUnitPresent() const {
    return isUnitPresent;
}

Cell::~Cell() {}