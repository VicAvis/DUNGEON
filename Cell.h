#pragma once

class Cell {
private:
    bool isObstacle;
    bool isUnitPresent;
public:
    Cell();
    ~Cell();
    void setObstacle(bool obstacle);
    bool hasObstacle() const;
    void setUnitPresent(bool unitPresent);
    bool hasUnitPresent() const;
};