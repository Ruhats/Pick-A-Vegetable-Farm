//=======================================================================
// Name        : Pick-A-Vegetable_Farm.cpp
//=======================================================================

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;


//============================================================================
// START OF ABSTRACT FACTORY PATTERN
//============================================================================

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
public:
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

//============================================================================
// END OF ABSTRACT FACTORY PATTERN
//============================================================================

//============================================================================
// START OF COMPOSITE PATTERN
//============================================================================

/*
 * Composite Pattern
 * Component
 */

class customerComponent {
public:
    virtual ~customerComponent(){};
    virtual void addName(customerComponent *c){};
    virtual void discard(customerComponent *c){};
    virtual void display(int indent){};
    string getName(){return name;};
protected:
    customerComponent(string name):name(name){};
private:
    string name;

};

/*
 * Composite Pattern
 * Leaf
 */

class primitiveElement:public customerComponent {
public:
    primitiveElement(string name) : customerComponent(name) {};

    void addName(customerComponent* c) {cout << "Cannot add to a PrimitiveElement\n";};

    void discard(customerComponent* c) {cout << "Cannot remove from a PrimitiveElement\n";};

    void display(int indent) {
		for(int i = 1;i <= indent;i++) { cout <<"-";}
		cout << " " << getName() << endl;
	}
};

/*
 * Composite Pattern
 * Composite
 */
class compositeElement:public customerComponent {
public:
    compositeElement(string name) : customerComponent(name) {};

    void addName(customerComponent* c) {nameElement.push_back(c);};

    void discard(customerComponent* c) {
		for (unsigned int i= 0; i< nameElement.size(); i++) {
			if (nameElement[i]->getName() == c->getName()) {
				nameElement.erase(nameElement.begin()+i);
				return;
			}
		}
	}

    void display(int indent) {
		for(int i = 1;i <= indent;i++) { cout <<"-";}
		cout << getName() <<  endl;

		// Display each child element on this node
		for (unsigned int i= 0; i< nameElement.size(); i++) {
			nameElement[i]->display(indent+2);
		}
	}

private:
	vector<customerComponent*> nameElement;

};

/*
 * RELATION BETWEEN
 * Abstract Factory Pattern AND Composite Pattern
 */

void customerBasket () {

    customerComponent* customer = new compositeElement("Customer");
    customer->addName(new primitiveElement("Customer #1"));
    customer->addName(new primitiveElement("Customer #2"));
    customer->addName(new primitiveElement("Customer #3"));
    customer->display(1);
    cout << endl;
}

//============================================================================
// END OF COMPOSITE PATTERN
//============================================================================

//============================================================================
// START OF COMMAND PATTERN
//============================================================================

/*
 * Command Pattern
 * Abstract Command
 */

class camera {
public:
    virtual void record() = 0;
    virtual void deleteRecord() = 0;
protected:
    camera(){};
};

/*
 * Command Pattern
 * Receiver
 */

class monitor {
public:
    monitor() : currentRecord(0) {};
    void action (int _operator, int operand) {
        switch(_operator) {
        case 1:
            currentRecord = operand;
            break;
        case 2:
            currentRecord = operand;
            break;
        case 3:
            currentRecord = operand;
            break;
        case 4:
            currentRecord = operand;
            break;
        default:
            break;
        }
        cout<<"Customer # " << currentRecord << " is being monitored "<<endl;
    }
private:
    int currentRecord;
};

/*
 * Command Pattern
 * Concrete Command
 */

class monitorCommand : public camera {
public:
    monitorCommand(monitor *mon, int op, int operand): _monitor(mon), _operator(op), _operand(operand) {}

    void record(){
        _monitor->action(_operator, _operand);
    }

    void deleteRecord(){
        _monitor->action(_operator, Undo(_operand));
    }

private:
    int Undo(int _operand){
        switch(_operand){
        case 1:
            _operand = 0;
            break;
        case 2:
            _operand = 0;
            break;
        case 3:
            _operand = 0;
            break;
        case 4:
            _operand = 0;
            break;
        default:
            break;
        }
        return _operand;
    }

    monitor* _monitor;
    int _operator;
    int _operand;
};

/*
 * Command Pattern
 * Invoker
 */

 class User {
public:
	User(): current(0) {};
	void Redo(int levels) {
		cout << "\n---- Redo " << levels << " levels " << endl;
		for (int i = 0; i < levels; i++) {
			if (current < _rec.size()) {
				camera *command = _rec[current++];
				command->record();
			}
		}
	}
	void Undo(int levels) {
		cout << "\n" << levels <<" Number of customers has exit the system " << endl;
		cout << "\n"<< "Clearing " << levels << "Recordings" << endl;
		for (int i = 0; i < levels; i++) {
			if (current > 0) {
				camera *command = _rec[--current];
				command->deleteRecord();
			}
		}
	}
	void saveRec(camera *command) {
		command->record();
		_rec.push_back(command);
		current++;
	}
private:
    monitor* _monitor;
	vector<camera *> _rec;
	unsigned int current;
};

/*
 * RELATION BETWEEN
 * Composite Pattern AND Command Pattern
 */

void recordCustomer () {

	camera *command = NULL;
	User *user = new User();
	monitor *mon = new monitor();

	command = new monitorCommand(mon, 1, 1);
	user->saveRec(command);
	command = new monitorCommand(mon, 2, 2);
	user->saveRec(command);
	command = new monitorCommand(mon, 3, 3);
	user->saveRec(command);
	command = new monitorCommand(mon, 4, 0);
	user->saveRec(command);

	user->Undo(2);
	user->Redo(1);
    cout << endl;
}

//============================================================================
// END OF COMMAND PATTERN
//============================================================================

//============================================================================
// START OF OBSERVER PATTERN
//============================================================================

class Investor;

/*
 * Observer Pattern
 * Subject
 */

class Stock {
public:
	virtual ~Stock(){};
	Stock(string symbol, double price) : symbol(symbol), _price(price) {};
	Stock(){};
	virtual void Attach (Investor* investor);
	virtual void Detach (Investor* investor);
	virtual void Notify();
	string	getSymbol() {return symbol;}
	void	setSymbol(string value) {symbol = value;}
	virtual double	getPrice() {return 0;};
	virtual void setPrice(double value) {};
protected:
	string symbol;
	double _price;
	vector<Investor*> investors;
};

/*
 * Observer Pattern
 * Concrete Subject
 */

class farm : public Stock {
public:
	farm(string symbol, double price): Stock (symbol, price){};
	double getPrice() {return _price;}
	void setPrice(double value) {
		_price = value;
		Notify();
	}
};

/*
 * Observer Pattern
 * Abstract Observer
 */

class Observer {
public:
	virtual ~Observer(){};
	virtual void Update(Stock *stock) = 0;
};

/*
 * Observer Pattern
 * Concrete Observer
 */

class Investor : public Observer {

public:
	Investor(string name): _customer_name(name) {};
	void Update(Stock *stock) {
        _stock = stock;
        _stock_price = stock->getPrice();
        _vegetable_name = stock->getSymbol();
        cout << "Notified " + _customer_name + " for " + _vegetable_name +
                "'s " + "price change to " << _stock_price << "\n";
	}
	Stock getStock() { return *_stock; }
    void setStock(Stock *value) { _stock = value; }
    string getName() { return _customer_name; }

private:
    Stock *_stock;
    string _customer_name;
    string _vegetable_name;
    double _stock_price;
};

/*
 * Observer Pattern
 * Register the Observers
 */

void Stock::Attach(Investor* investor) {
      investors.push_back(investor);
}

/*
 * Observer Pattern
 * Unregister from the list of Observers
 */

void Stock::Detach(Investor* investor) {
	for (unsigned int i= 0; i< investors.size(); i++) {
		if (investors[i]->getName() == investor->getName()) {
			investors.erase(investors.begin()+i);
			return;
		}
	}
}

/*
 * Observer Pattern
 * Notify the Observers
 */

void Stock::Notify() {
	for (unsigned int i = 0; i < investors.size(); i++) {
		investors[i]->Update(this);
	}
}

/*
 * RELATION BETWEEN
 * Iterator Pattern AND Observer Pattern
 */

 void notifyPrice () {

    Investor* customer = new Investor("Customers");

    farm* veg1 = new farm("Vegetable #1", 10.00);
    farm* veg2 = new farm("Vegetable #2", 15.00);
    farm* veg3 = new farm("Vegetable #3", 20.00);
    veg1->Attach(customer);
    veg2->Attach(customer);
    veg3->Attach(customer);

    veg1->setPrice(9.50);
    veg2->setPrice(12.50);
    veg3->setPrice(22.50);


    delete veg1;
    delete veg2;
    delete veg3;
}

//============================================================================
// END OF OBSERVER PATTERN
//============================================================================

//============================================================================
// START OF ITERATOR PATTERN
//============================================================================

/*
 * Iterator Pattern
 * Iterated Items
 */

class Item {
public:
    Item(string name): _name(name){};
    string getName() {
        return _name;
    }
private:
    string _name;
};

/*
 * Iterator Pattern
 * Abstract Iterator
 */

class abstractBasket {
public:
	virtual void First() = 0;
	virtual void Next() = 0;
    virtual bool IsDone () const = 0;
	virtual Item* CurrentItem() const = 0 ;
protected:
	abstractBasket(){};
};

class Collection;

/*
 * Iterator Pattern
 * Concrete Iterator
 */

class CollectionIterator : public abstractBasket {
public:
    CollectionIterator(const Collection *collection);
    void First();
    void Next();
    Item* CurrentItem() const;
	bool IsDone() const;
private:
    const Collection *_collection;
    int _current;
};

/*
 * Iterator Pattern
 * Abstract Aggregate
 */

class AbstractAggregate {
public:
	 virtual ~AbstractAggregate(){};
	 virtual abstractBasket* CreateIterator() = 0;
	 virtual void add(Item *) = 0; 		// Not needed for iteration.
	 virtual int getCount () const = 0; // Needed for iteration.
	 virtual Item * get(int) const = 0; // Needed for iteration.
protected:
	AbstractAggregate(){};
};

/*
 * Iterator Pattern
 * Concrete Aggregate
 */

class Collection : public AbstractAggregate {
private:
	 vector<Item*> _items;
public:
	CollectionIterator* CreateIterator() {
		return new CollectionIterator(this);
    }
    int getCount () const {return _items.size(); }
    void add(Item *item) {_items.push_back(item);};
    Item * get(int index) const { return _items[index];};
};

CollectionIterator::CollectionIterator(const Collection *collection) :
	_collection(collection), _current(0) {
}
void CollectionIterator::First() {
	_current = 0;
}
void CollectionIterator::Next()  {
	_current++;
}
Item *CollectionIterator::CurrentItem() const {
	return (IsDone()?NULL:_collection->get(_current));
}
bool CollectionIterator::IsDone() const {
	return _current >= _collection->getCount();
}

void printAggregate(abstractBasket& i) {
	cout << "Iterating over collection:" << endl;
	for(i.First();  !i.IsDone(); i.Next()) {
		cout << i.CurrentItem()->getName() << endl;
	}
	cout << endl;
}

/*
 * RELATION BETWEEN
 * Command Pattern AND Iterator Pattern
 */

void createBasket () {

    AbstractAggregate *aggregate = new Collection();
	aggregate->add(new Item("Vegetable Slot #1"));
	aggregate->add(new Item("Vegetable Slot #2"));
	aggregate->add(new Item("Vegetable Slot #3"));

	abstractBasket *iterator = aggregate->CreateIterator();

    printAggregate(*iterator);
	delete iterator;

}
//============================================================================
// END OF ITERATOR PATTERN
//============================================================================

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

    cout<<"=============================="<<endl;
    cout<<"       VEGETABLE LIST"<<endl;
    cout<<"=============================="<<endl;

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

    summerVegetable3->setHarvestType(0);
    summerVegetable3->setPlantType("Cucumber");
    summerVegetable3->setSeason(0);
    summerVegetable3->setSoilType(1);
    summerVegetable3->displaySpecs();


    winterVegetable1->setHarvestType(1);
    winterVegetable1->setPlantType("Spinach");
    winterVegetable1->setSeason(1);
    winterVegetable1->setSoilType(2);
    winterVegetable1->displaySpecs();

    winterVegetable2->setHarvestType(0);
    winterVegetable2->setPlantType("Cabbage");
    winterVegetable2->setSeason(1);
    winterVegetable2->setSoilType(1);
    winterVegetable2->displaySpecs();

    winterVegetable3->setHarvestType(1);
    winterVegetable3->setPlantType("Potato");
    winterVegetable3->setSeason(1);
    winterVegetable3->setSoilType(2);
    winterVegetable3->displaySpecs();

    cout<<"=============================="<<endl;
    cout<<" Default Basket for Customers"<<endl;
    cout<<"=============================="<<endl;
    cout<<endl;

    AbstractAggregate *aggregate = new Collection();
	aggregate->add(new Item("Basket Slot #1"));
	aggregate->add(new Item("Basket Slot #2"));
	aggregate->add(new Item("Basket Slot #3"));

	abstractBasket *iterator = aggregate->CreateIterator();

    printAggregate(*iterator);
	delete iterator;

    cout<<"=============================="<<endl;
    cout<<" List of Customers in the Farm"<<endl;
    cout<<"=============================="<<endl;
    cout<<endl;

    customerComponent* root = new compositeElement("Customer");
    root->addName(new primitiveElement("Customer "));

    customerComponent* customer = new compositeElement("Customer List");
    customer->addName(new primitiveElement("Customer #1"));
    customer->addName(new primitiveElement("Customer #2"));
    customer->addName(new primitiveElement("Customer #3"));
    root->addName(customer);
    customer->display(1);
    cout << endl;

    cout<<"=============================="<<endl;
    cout<<"  Customer Monitoring System"<<endl;
    cout<<"=============================="<<endl;

    camera *command = NULL;
	User *user = new User();
	monitor *mon = new monitor();

	cout << endl;
	command = new monitorCommand(mon, 1, 1);
	user->saveRec(command);
	command = new monitorCommand(mon, 2, 2);
	user->saveRec(command);
	command = new monitorCommand(mon, 3, 3);
	user->saveRec(command);
	command = new monitorCommand(mon, 4, 0);
	user->saveRec(command);
    cout << endl;

    cout<<"=============================="<<endl;
    cout<<"    Price Update System"<<endl;
    cout<<"=============================="<<endl;
    cout<<endl;

    Investor* customer1 = new Investor("Customers");
    Investor* customer2 = new Investor("Customers");
    Investor* customer3 = new Investor("Customers");

    farm* veg1 = new farm("Vegetable #1", 10.00);
    farm* veg2 = new farm("Vegetable #2", 15.00);
    farm* veg3 = new farm("Vegetable #3", 20.00);
    veg1->Attach(customer1);
    veg2->Attach(customer2);
    veg3->Attach(customer3);

    veg1->setPrice(9.50);
    veg2->setPrice(12.50);
    veg3->setPrice(22.50);

    delete veg1;
    delete veg2;
    delete veg3;
}
