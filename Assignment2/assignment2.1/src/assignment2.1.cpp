//============================================================================
// Name        : 1.cpp
// Author      : prer
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class Product{

private:

	int productId;
	string name;
	double price;
	int quantity;

public:
	void acceptDetails();
	void displayDetails() const;
	double totalValue() const;
	bool isLowStock(int threshold) const;
	string getName() const;
};

void Product::acceptDetails()
{
	cout << "Enter Product ID " << endl;
	cin >> productId;

	cout << "Enter Name" << endl;
	cin >> name;

	cout << "Enter The Price" << endl;
	cin >> price;

	cout << "Enter the Quantity" << endl;
	cin >> quantity;
}

void Product::displayDetails() const{

	cout << productId << "   ";
	cout << name << "   ";
	cout << price << "   ";
	cout << quantity << "   ";
	cout << totalValue() << endl;
}

string Product::getName() const{
	return name;
}

double Product::totalValue() const{

	return  price * quantity;
}

bool Product::isLowStock(int threshold) const
{
	if(quantity < threshold)
	{
		return true;
    }
	else
	{
		return false;
    }
}

// -------function overloading

// integer quantity
double reorderCost(int qty, double unitPrice)
{
	return qty * unitPrice;
}

// fractional (by weight)
double reorderCost(double qty, double unitPrice)
{
	return qty * unitPrice;
}

// with tax
double reorderCost(int qty, double unitPrice, double taxRate)
{
	double cost = qty * unitPrice;

	double tax = cost * taxRate / 100;

	return cost + tax ;
}


// If no discount is passed, apply 10% by default
double applyDiscount(double price, double discountPercent = 10.0)
{
	double discount = price * discountPercent / 100;

	return price - discount;
}


int main() {

	Product products[5];

	for (int i=0; i < 5; i++){
		products[i].acceptDetails();
	}

	for(int i = 0; i < 5; i++)
	    {
	        products[i].displayDetails();
	    }
	int highest = 0;

	for(int i = 1; i < 5; i++)
	{
	    if(products[i].totalValue() > products[highest].totalValue())
	    {
	        highest = i;
	    }
	}



	cout << "Highest Value Product : "
	     << products[highest].getName()
	     << " (Rs. "
	     << products[highest].totalValue()
	     << ")";

	int threshold;
	cout << "Enter stock threshold: ";
	cin >> threshold;

	cout << "Low Stock (threshold: " << threshold << ") : ";

	for(int i = 0; i < 5; i++)
	{
	    if(products[i].isLowStock(threshold))
	    {
	        cout << products[i].getName() << " ";
	    }
	}

	//--------- function overloading

	// Integer qty

	int qty1 = 10;
	double price1 = 250.00;
	cout << "\nInteger Quantity:" << endl;
	cout << "Quantity = " << qty1 << endl;
	cout << "Unit Price = Rs. " << price1 << endl;
	cout << "Reorder Cost = Rs. " << reorderCost(qty1, price1) << endl;


	// Double qty
	double qty2 = 5.5;
	double price2 = 100.00;
	cout << "\nFractional Quantity:" << endl;
	cout << "Quantity = " << qty2 << endl;
	cout << "Unit Price = Rs. " << price2 << endl;
	cout << "Reorder Cost = Rs. " << reorderCost(qty2, price2) << endl;


	// Integer qty tax
	int qty3 = 20;
	double price3 = 150.00;
	double taxRate = 18.0;
	cout << "\nReorder Cost With Tax:" << endl;
	cout << "Quantity = " << qty3 << endl;
	cout << "Unit Price = Rs. " << price3 << endl;
	cout << "Tax Rate = " << taxRate << "%" << endl;
	cout << "Reorder Cost With Tax = Rs. " << reorderCost(qty3, price3, taxRate) << endl;


	// Discount with default argument

	double originalPrice = 1000.00;
	cout << "\nDiscount With Default 10%:" << endl;
	cout << "Original Price = Rs. " << originalPrice << endl;
	cout << "Price After Discount = Rs. " << applyDiscount(originalPrice) << endl;


	// Discount with user-specified percentage

	double discountPercent = 20.0;
	cout << "\nDiscount With 20%:" << endl;
	cout << "Original Price = Rs. " << originalPrice << endl;
	cout << "Discount = " << discountPercent << "%" << endl;
	cout << "Price After Discount = Rs. " << applyDiscount(originalPrice, discountPercent) << endl;
	return 0;
}
