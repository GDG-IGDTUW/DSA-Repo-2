#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Restaurant {
public:
    string name;
    string cuisine;
    unordered_map<string, double> menu;

    // Default Constructor
    Restaurant() : name(""), cuisine(""){}

    Restaurant(string name, string cuisine) : name(name), cuisine(cuisine) {}

    void addItem(string item, double price) {
        menu[item] = price;
    }
};

class User{
    string name, username, password, email, phone, address;
    
public:
    // Parameterized Constructor
    User(string name, string username, string password, string email, string phone, string address) : name(name), username(username), password(password), email(email), phone(phone), address(address) {}

    // Default Constructor
    User(){
        name = username = password = email = phone = address;
    }

    // Getters
    void getName() const {cout<<"\nName:" << name;}
    void getUserName() const {cout<<"\nUserName:" << username;}
    void getemail() const {cout<<"\nEmail:" << email;}
    void getPhone() const {cout<<"\nPhone:" << phone;}
    void getAddress() const {cout<<"\nAddress:" << address;}
    void getPassword() const {cout<<"\nPassword is a private attribute and can't be shown to you.";}

    // Setters
    void setName(const string& name){this->name = name;}
    void setUserName(const string& username) {this->username = username;}
    void setEmail(const string& email){this->email = email;}
    void setPhone(const string& phone){this->phone = phone;}
    void setAddress(const string& address){this->address = address;}
    void setPassword(const string& inputPassword){this->password = inputPassword;}

    // Password Handling
    bool validatePassword(const string& inputPassword){
        return inputPassword == this->password;
    }
};

class FoodDeliverySystem {
private:
    unordered_map<string, Restaurant> restaurants;
    unordered_map<int, string> orders;
    int orderIdCounter = 100;

public:
    void addRestaurant(string name, string cuisine) {
        restaurants[name] = Restaurant(name, cuisine);
        cout << "Restaurant '" << name << "' added successfully!" << endl;
    }

    void addMenuItem(string restaurantName, string item, double price) {
        if (restaurants.find(restaurantName) != restaurants.end()) {
            restaurants[restaurantName].addItem(item, price);
            cout << "Item '" << item << "' added to the menu of " << restaurantName << endl;
        } else {
            cout << "Restaurant not found." << endl;
        }
    }

    void placeOrder(string restaurantName, vector<string> items) {
        if (restaurants.find(restaurantName) != restaurants.end()) {
            double totalPrice = 0;
            for (const auto& item : items) {
                if (restaurants[restaurantName].menu.find(item) != restaurants[restaurantName].menu.end()) {
                    totalPrice += restaurants[restaurantName].menu[item];
                }
            }
            int orderId = orderIdCounter++;
            orders[orderId] = restaurantName + " | " + "Items: ";
            for (const auto& item : items) orders[orderId] += item + " ";
            orders[orderId] += "| Total: $" + to_string(totalPrice);
            cout << "Order placed successfully. Order ID: " << orderId << endl;
        } else {
            cout << "Restaurant not found." << endl;
        }
    }

    void viewOrderHistory() {
        if (orders.empty()) {
            cout << "No orders placed yet." << endl;
        } else {
            cout << "Order History:" << endl;
            for (const auto& entry : orders) {
                cout << "Order ID: " << entry.first << " | Details: " << entry.second << endl;
            }
        }
    }

    void cancelOrder(int orderId) {
        if (orders.find(orderId) != orders.end()) {
            orders.erase(orderId);
            cout << "Order ID " << orderId << " has been cancelled." << endl;
        } else {
            cout << "Order not found." << endl;
        }
    }
};


int main() {
    FoodDeliverySystem system;
    User u1;

    u1.setName("Kashish");
    u1.setEmail("example.com");
    u1.setPassword("abcd");
    u1.setPhone("1234567890");
    u1.setUserName("k10");
    u1.setAddress("Delhi");

    u1.getName();
    u1.getemail();
    u1.getAddress();
    u1.getPassword();

    // system.addRestaurant("Pizza Palace", "Italian");
    // system.addMenuItem("Pizza Palace", "Margherita Pizza", 10);
    // system.addMenuItem("Pizza Palace", "Garlic Bread", 5);
    // system.placeOrder("Pizza Palace", {"Margherita Pizza", "Garlic Bread"});
    // system.viewOrderHistory();
    return 0;
}