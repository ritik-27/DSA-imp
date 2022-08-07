#include <iostream>
#include <fstream>
using namespace std;

class Item
{
public:
    string name;
    float price;
    int qty;

    Item(){};
    Item(string n, float p, int q)
    {
        name = n;
        price = p;
        qty = q;
    };
};
int main()
{
    int n;
    string name;
    float price;
    int qty;
    cout << "Enter total number of items: " << endl;
    cin >> n;
    Item *list[n];
    cout << "Enter all items: " << endl;
    ofstream ofs;
    ofs.open("items.txt", ios::app);
    string line;
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << "th item Name, Price, Quantity" << endl;
        cin >> name;
        cin >> price;
        cin >> qty;
        list[i] = new Item(name, price, qty);
        ofs << name << endl;
        ofs << price << endl;
        ofs << qty << endl;
    }
    ofs.close();
    ifstream ifs;
    ifs.open("items.txt");

    while (getline(ifs, line))
    {
        counter++;
    }
    int index = counter / 3;
    cout << "Counter:: " << counter << endl;

    for (int i = 0; i < index; i++)
    {
        Item obj = *list[i];
        ifs >> obj.name >> obj.price >> obj.qty;
        cout << "Name of item: " << obj.name << endl;
        cout << "Price of item: " << obj.price << endl;
        cout << "Quantity of item: " << obj.qty << endl;
        cout << "------------------------------------" << endl;
    }
    ifs.close();
    return 0;
}