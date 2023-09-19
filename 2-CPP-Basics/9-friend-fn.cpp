/*
#include <iostream>
using namespace std;

class GFG {
private:
	int private_variable;

protected:
	int protected_variable;

public:
	GFG()
	{
		private_variable = 10;
		protected_variable = 99;
	}

	// friend class declaration
	friend class F;
};

// Here, class F is declared as a
// friend inside class GFG. Therefore,
// F is a friend of class GFG. Class F
// can access the private members of
// class GFG.
class F {
public:
	void display(GFG &t)
	{
		cout << "The value of Private Variable = "
			<< t.private_variable << endl;
		cout << "The value of Protected Variable = "
			<< t.protected_variable << endl;
	}
};

// Driver code
int main()
{
	GFG g;
	F fri;
	fri.display(g);
	return 0;
}

*/

#include<iostream>
using namespace std;

class Box{
    private:
    int length;

    public:
    Box() : length(0) {}
    friend int printLength(Box);
};

int printLength(Box b){
    b.length += 10;
    return b.length;
}

int main(){
    Box b;
    cout<<"Length: "<< printLength(b)<<endl;
    return 0;
}