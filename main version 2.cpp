//=======================================================================
// Name        : Pick-A-Vegetable_Farm.cpp
//=======================================================================

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

/*
 * Abstract Factory Pattern
 * Abstract Product 1
 */

class summerGardenRowPrototype {
public:
    virtual void setPlantType(string plant) = 0;
    virtual void setHarvestType(bool harvest) = 0;
    virtual void setSoilType(int soil) = 0;
    virtual void setSeason (bool season) = 0;
    virtual void displaySpecs() = 0;
};

/*
 * Abstract Factory Pattern
 * Concrete Product 1.1
 */

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

/*
 * Abstract Factory Pattern
 * Abstract Product 2
 */

class winterGardenRowPrototype {
public:
    virtual void setPlantType(string plant) = 0;
    virtual void setHarvestType(bool harvest) = 0;
    virtual void setSoilType(int soil) = 0;
    virtual void setSeason (bool season) = 0;
    virtual void displaySpecs() = 0;
};

/*
 * Abstract Factory Pattern
 * Concrete Product 2.1
 */

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
 * Abstract Factory Pattern
 * Abstract Factory
 */

class rowFactory {
public:
    virtual summerGardenRowPrototype* createSummerPlant() = 0;
    virtual winterGardenRowPrototype* createWinterPlant() = 0;
};

/*
 * Abstract Factory Pattern
 * Concrete Factory
 */

class plantFactory : public rowFactory {
    summerGardenRowPrototype* createSummerPlant() {
        return new summerPlant();
    }

    winterGardenRowPrototype* createWinterPlant() {
        return new winterPlant();
    }
};

/*
 * Abstract Factory Pattern
 * Client
 */

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




class customerComponent {
public:
    string name;
    int cost, amount;
    virtual ~customerComponent(){};
    virtual void addName(customerComponent *c){};
    virtual void addCost(customerComponent *c){};
    virtual void addAmount(customerComponent *c){};
    virtual void discard(customerComponent *c){};
    virtual void display(int indent){};
    string getName(){return name;};
    int getCost(){return cost;};
    int getAmount(){return amount;};
protected:
    customerComponent(string name, int cost, int amount):name(name){}; cost(cost){}; amount(amount){};
    //customerComponent(int cost):cost(cost){};
    //customerComponent(int amount):amount(amount){};

};

class primitiveElement:public customerComponent {
public:
    primitiveElement(string name) : customerComponent(name) {};
    primitiveElement(int cost) : customerComponent(cost) {};
    primitiveElement(int amount) : customerComponent(amount) {};

    void addName(compositeElement* c) {cout << "Cannot add to a PrimitiveElement\n";};

    void addCost(compositeElement* c) {cout << "Cannot add to a PrimitiveElement\n";};

    void addAmount(compositeElement* c) {cout << "Cannot add to a PrimitiveElement\n";};

    void Display(int indent) {
		for(int i = 1;i <= indent;i++) { cout <<"-";}
		cout << " " << getName() << endl;
	}
};

class compositeElement:public customerComponent {
public:
    compositeElement(string name) : customerComponent(name) {};
    compositeElement(int cost) : customerComponent(cost) {};
    compositeElement(int amount) : customerComponent(amount) {};

    void addName(compositeElement* c) {nameElement.push_back(c);};

    void addCost(compositeElement* c) {costElement.push_back(c);};

    void addAmount(compositeElement* c) {costElement.push_back(c);};

    void discard(compositeElement* c) {
		for (unsigned int i= 0; i< nameElement.size(); i++) {
			if (nameElement[i]->getName() == c->getName()) {
				nameElement.erase(nameElement.begin()+i);
				return;
			}
			if (costElement[i]->getCost() == c->getCost()) {
				costElement.erase(costElement.begin()+i);
				return;
			}
			if (amountElement[i]->getCost() == c->getCost()) {
				amountElement.erase(amountElement.begin()+i);
				return;
			}
		}
	}

    void Display(int indent) {
		for(int i = 1;i <= indent;i++) { cout <<"-";}
		cout << + getName() + getAmount() + getCost() <<  endl;

		// Display each child element on this node
		for (unsigned int i= 0; i< elements.size(); i++) {
			elements[i]->Display(indent+2);
		}
	}

private:
	vector<customerComponent*> nameElement;
	vector<customerComponent*> costElement;
	vector<customerComponent*> amountElement;
compositeElement(string name) : customerComponent(name) {};
    compositeElement(int cost) : customerComponent(cost) {};
    compositeElement(int amount) : customerComponent(amount) {};

};



int main () {

    rowFactory* summer1 = new plantFactory();
    rowFactory* summer2 = new plantFactory();
    rowFactory* summer3 = new plantFactory();
    rowFactory* winter1 = new plantFactory();
    rowFactory* winter2 = new plantFactory();
    rowFactory* winter3 = new plantFactory();

    rowCreator newRow;
    newRow.createRow(summer1);
    summerGardenRowPrototype* summerVegetable1 = newRow.getYieldSummer();
    newRow.createRow(summer2);
    summerGardenRowPrototype* summerVegetable2 = newRow.getYieldSummer();
    newRow.createRow(summer3);
    summerGardenRowPrototype* summerVegetable3 = newRow.getYieldSummer();
    newRow.createRow(winter1);
    winterGardenRowPrototype* winterVegetable1 = newRow.getYieldWinter();
    newRow.createRow(winter2);
    winterGardenRowPrototype* winterVegetable2 = newRow.getYieldWinter();
    newRow.createRow(winter3);
    winterGardenRowPrototype* winterVegetable3 = newRow.getYieldWinter();

    summerVegetable1->setHarvestType(0);
    summerVegetable1->setPlantType("Tomato");
    summerVegetable1->setSeason(0);
    summerVegetable1->setSoilType(3);
    summerVegetable1->displaySpecs();

    summerVegetable2->setHarvestType(1);
    summerVegetable2->setPlantType("Carrot");
    summerVegetable2->setSeason(0);
    summerVegetable2->setSoilType(2);
    summerVegetable2->displaySpecs();

    summerVegetable2->setHarvestType(0);
    summerVegetable2->setPlantType("Cucumber");
    summerVegetable2->setSeason(0);
    summerVegetable2->setSoilType(1);
    summerVegetable2->displaySpecs();


    winterVegetable1->setHarvestType(0);
    winterVegetable1->setPlantType("Orange");
    winterVegetable1->setSeason(1);
    winterVegetable1->setSoilType(2);
    winterVegetable1->displaySpecs();

    winterVegetable2->setHarvestType(1);
    winterVegetable2->setPlantType("Apple");
    winterVegetable2->setSeason(1);
    winterVegetable2->setSoilType(1);
    winterVegetable2->displaySpecs();

    winterVegetable2->setHarvestType(1);
    winterVegetable2->setPlantType("Potato");
    winterVegetable2->setSeason(1);
    winterVegetable2->setSoilType(2);
    winterVegetable2->displaySpecs();

}
