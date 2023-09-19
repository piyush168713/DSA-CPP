// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Hero {
    // properties
    private:
    int health = 9;

    public:
    char level;
    char *name;
    static int timeToComplete;

    Hero(){
        cout<<"Constructor Call"<<endl;
        name = new char[100];
    }

    Hero(int health){
        // `this` keyword stores the address of current object e.g. object ramesh
        // `this` keyword points to the current object
        // class is only blueprint/template of object. so `this` keyword don't update value of itself(health) which comes in 
	    // parameter but/instead it updates the value of existing value(health = 9) by the parameter value in object
		// template(class).
        cout<<"Address of this: "<<this<<endl;
        this->health = health;
    }

    Hero(int health, int level){
        this->health = health;
        this->level = level;
    }

    // copy constructor
    Hero(Hero &temp){
        cout<<"Copy Constructor called"<<endl;
        this->health = temp.health;
        this->level = temp.level;

        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
    }
    
    void print(){
        cout<<"Name: "<< this->name << endl;
        cout<<"Health: "<< this->health <<endl;
        cout<<"Level: "<< this->level <<endl;
    }

    // getter and setter
    int getHealth(){
        return health;
    }

    void setHealth(int h){
        health = h;
    }

    char getLevel(){
        return level;
    }
 
    void setLevel(char ch){
        level = ch;
    }

    void setName(char name[]){
        strcpy(this->name, name);
    }

    static int random(){
        return timeToComplete;
    }

    ~Hero(){
        cout<<"Destructor called"<<endl;
    }

};

int Hero::timeToComplete = 5; 

int main() {
    // creation of object
    // Hero ramesh;
    // cout<<"Health is : "<<ramesh.getHealth()<<endl;
    // cout<<"Level is : "<<ramesh.level<<endl;

    // Hero ramesh(10);
    // cout<<"Address of ramesh: "<<&ramesh<<endl;
    // cout<<ramesh.getHealth();

    // copy constructor
    // Hero bat(20, 'B');
    // bat.print();
    // Hero ball(bat);
    // ball.print();

    /*
    // shallow copy
    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('S');
    char name[7] = "Piyush";
    hero1.setName(name); 
    hero1.print();

    // use default copy constructor
    Hero hero2(hero1);
    // hero hero2 = hero1;
    hero2.print();

    hero1.name[0] = 'T';
    hero1.setLevel('M');
    hero1.print();
    hero2.print();
    // name is stored in heap memory/at a address pointer, every variable access the same heap/address so it'll same for all
    // default copy constructor do shallow copy, so remove your own copy constructor l=36-41
    // In shallow copy, everyone points to the same address variable, so that all can use same values, and do shallow copy.
    // and if you're changing the values in your array then it uses the same array so you get the updated value.

    // deep copy 
    // In deep copy, we use a copy constructor and make a entirely different array in the copy constructor.
	// and that array will be used for deep copy.
    // and if you're changing the values in your array then it doesn't show any effect on the other array.
    */

    /*
    // Static - Destructor automatically call
    Hero a;

    // Dynamic - We have to call destructor by own
    Hero *b = new Hero();
    // manually destructor call
    delete b;
    */

    // for static keyword/member
    // cout<< Hero::timeToComplete <<endl;

    // for static fn
    // cout << Hero::random() << endl;

    

    return 0;
}


// inline, friend, polymorphism and its types, 