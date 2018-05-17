//=======================================================================
// Name        : Pick-A-Vegetable_Farm.cpp
//=======================================================================

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class summerGardenRowPrototype {
public:
    virtual void setPlantType(string plant) = 0;
    virtual void setHarvestType(bool harvest) = 0;
    virtual void setSoilType(int soil) = 0;
    virtual void setSeason (bool season) = 0;
    virtual void displaySpecs() = 0;
};

class summerPlant : public summerGardenRowPrototype {

public:
    bool harv, seas;
    int soilQuality;
    string plantName, harvestType, plantSeason;

    void setPlantType(string plant) {
        plantName = plant;
    }
    void setSoilType(int soil) {
        soilQuality = soil;
    }
    void setHarvestType(bool harvest) {
        harv = harvest;
    }
    void setSeason(bool season) {
        seas = season;
    }
    void displaySpecs() {
        if (harv == 0){
            harvestType = "Hand";
        }
        else {
            harvestType = "Tool";
        }
        if (seas == 0){
            plantSeason = "Summer";
        }
        else {
            plantSeason = "Winter";
        }
        cout<<"Plant Name - "<<plantName<<endl<<"Harvest Type is by "<<harvestType<<endl<<"Season of "<<plantName<<" is "<<plantSeason<<endl<<"Soil quality is "<<soilQuality<<endl<<endl;
    }

};

class winterGardenRowPrototype {
public:
    virtual void setPlantType(string plant) = 0;
    virtual void setHarvestType(bool harvest) = 0;
    virtual void setSoilType(int soil) = 0;
    virtual void setSeason (bool season) = 0;
    virtual void displaySpecs() = 0;
};

class winterPlant : public winterGardenRowPrototype {
public:
    bool harv, seas;
    int soilQuality;
    string plantName, harvestType, plantSeason;

    void setPlantType(string plant) {
        plantName = plant;
    }
    void setSoilType(int soil) {
        soilQuality = soil;
    }
    void setHarvestType(bool harvest) {
        harv = harvest;
    }
    void setSeason(bool season) {
        seas = season;
    }
    void displaySpecs() {
        if (harv == 0){
            harvestType = "Hand";
        }
        else {
            harvestType = "Tool";
        }
        if (seas == 0){
            plantSeason = "Summer";
        }
        else {
            plantSeason = "Winter";
        }
        cout<<"Plant Name - "<<plantName<<endl<<"Harvest Type is by "<<harvestType<<endl<<"Season of "<<plantName<<" is "<<plantSeason<<endl<<"Soil quality is "<<soilQuality<<endl<<endl;
    }

};

/*
 *
 *
 *
 */
class rowFactory {
public:
    virtual summerGardenRowPrototype* createSummerPlant() = 0;
    virtual winterGardenRowPrototype* createWinterPlant() = 0;
};

class plantFactory : public rowFactory {
    summerGardenRowPrototype* createSummerPlant() {
        return new summerPlant();
    }

    winterGardenRowPrototype* createWinterPlant() {
        return new winterPlant();
    }
};
/*
class winterPlantFactory : public rowFactory {
    winterGardenRowPrototype* createWinterPlant() {
        return new winterPlant();
    }
};*/

class rowCreator {
private:
    summerGardenRowPrototype* _summer;
    winterGardenRowPrototype* _winter;
public:
    void createRow(rowFactory *factory) {
        _summer = factory->createSummerPlant();
        _winter = factory->createWinterPlant();
    }
    summerGardenRowPrototype* getYieldSummer () {return _summer;}
    winterGardenRowPrototype* getYieldWinter () {return _winter;}
};




int main () {

    rowFactory* summer1 = new plantFactory();
    rowFactory* summer2 = new plantFactory();
    rowFactory* winter1 = new plantFactory();
    rowFactory* winter2 = new plantFactory();

    rowCreator newRow;
    newRow.createRow(summer1);
    summerGardenRowPrototype* fruit1 = newRow.getYieldSummer();
    newRow.createRow(summer2);
    summerGardenRowPrototype* fruit2 = newRow.getYieldSummer();
    newRow.createRow(winter1);
    winterGardenRowPrototype* vegetable1 = newRow.getYieldWinter();
    newRow.createRow(winter2);
    winterGardenRowPrototype* vegetable2 = newRow.getYieldWinter();

    fruit1->setHarvestType(0);
    fruit1->setPlantType("Tomato");
    fruit1->setSeason(0);
    fruit1->setSoilType(3);
    fruit1->displaySpecs();

    fruit2->setHarvestType(1);
    fruit2->setPlantType("Carrot");
    fruit2->setSeason(0);
    fruit2->setSoilType(2);
    fruit2->displaySpecs();

    vegetable1->setHarvestType(0);
    vegetable1->setPlantType("Orange");
    vegetable1->setSeason(1);
    vegetable1->setSoilType(2);
    vegetable1->displaySpecs();

    vegetable2->setHarvestType(1);
    vegetable2->setPlantType("Apple");
    vegetable2->setSeason(1);
    vegetable2->setSoilType(1);
    vegetable2->displaySpecs();

}
