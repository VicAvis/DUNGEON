#pragma once

class Cell {
private:
    bool isObstacle;
    bool isUnitPresent;
public:
    // Copy Constructor
    Cell(const Cell& other);

    // Copy Assignment Operator
    Cell& operator=(const Cell& other);

    // Move Constructor
    Cell(Cell&& other) noexcept;

    // Move Assignment Operator
    Cell& operator=(Cell&& other) noexcept;

    // Destructor
    ~Cell();

    // Rest of your existing declarations
    Cell();

    void setObstacle(bool obstacle);

    void setUnitPresent(bool unitPresent);

    bool hasObstacle() const;

    bool hasUnitPresent() const;
};