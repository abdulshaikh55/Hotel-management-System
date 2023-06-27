// A hotel management program.
#include <iostream>
#include <string>
using namespace std;
// Defined below are the prices of various commodities of the hotel.
#define roomsP 1200
#define ACroomsP 1600
#define pizzaP 100
#define burgerP 110
#define bhelP 40 
#define kebabP 20
#define cokeP 40
#define spriteP 40

// This class holds information about the customer.
class customer{
    private:
        string name, fromDate, tillDate, address;
        double aadharNo, phoneNo;
        int room_no, booking_id, choice;
    public:
        void getInfo();
        void searchCustomer();
}customerInfo[10];

// This function reads basic customer information of customer.
void customer::getInfo(){
    cin.ignore();
    cout << "Enter customer name:";
    getline(cin, name);
    cout << "Enter start date (DD/MM/YY): ";
    getline(cin, fromDate);
    cout << "Enter end date (DD/MM/YY): ";
    getline(cin, tillDate);
    cout << "Enter phone number: ";
    cin >> phoneNo;
    cin.ignore();
    cout << "Enter address: ";
    getline(cin,address);
    cout << "Enter Aadhar no.: ";
    cin >> aadharNo;
    cout << "Enter room no.: ";
    cin >> room_no;
    cout << "Enter booking ID: ";
    cin >> booking_id;
}

// This function takes in the customer's name or phone number and gives out their room no.
void customer :: searchCustomer(){
    string n;
    int u;
    double ph;
    cout << "search customer by:\n1. Name\n2.Phone number";
    cin >> choice;
    switch(choice){
        case 1: 
            cout << "Enter the name: ";
            getline(cin, n);
            for(u=0; u<10; u++){
                if(n==(customerInfo[u].name)){
                    cout << "Customer room no: " << customerInfo[u].room_no;
                }
                cout << "No match. Try phone number.";
            }

        case 2:
            cout << "Enter the phone number";
            cin >> ph;
            for(u=0; u<10; u++){
                if(ph==(customerInfo[u].phoneNo)){
                    cout << "Customer room no: " << customerInfo[u].room_no;
                }
            }
    }
}

class hotel{
    private:
        // These variables hold choices made by user and no. of rooms to book.
        int choice;  // for switch case
        char bin;    // for yes or no questions. bin is short for binary.
        // There are 5 normal rooms, and 5 AC rooms.
        bool N_room[5], ACroom[5];
        // These variables no. foods ordered.
        int rooms = 0, ACrooms, pizza = 0, burger = 0, coke = 0, kebab = 0, sprite = 0, bhel = 0;
        // These variables hold no. of foods in the kitchen.
        int T_rooms = 10, T_ACrooms = 10, T_pizza = 30, T_burger = 30, T_coke = 60, T_kebab = 65, T_sprite = 60, T_bhel = 25;
        // These variables hold no.of foods we sold.
        int S_rooms = 0, S_ACrooms = 0, S_pizza = 0, S_burger = 0, S_coke = 0, S_kebab = 0, S_sprite = 0, S_bhel = 0;

    public:
        void hotelContent();
        void menu();
        void room();
        void bill();
}customerNeeds;

// This area is used by the hotel manager to put what is available in the hotel.
void hotel :: hotelContent(){
    cout<< "\nLet's Start!\n";
    cout << "Enter the no. of pizzas available today: ";
    cin >> T_pizza;
    cout << "Enter the no. of burgers available today: ";
    cin >> T_burger;
    cout << "Enter the no. of kebabs available today: ";
    cin >> T_kebab;
    cout << "Enter the no. of coke available today: ";
    cin >> T_coke;
    cout << "Enter the no. of Sprite available today: ";
    cin >> T_sprite;
    cout << "Enter the no. of Bhel available today: ";
    cin >> T_bhel;
}

// Books the number of rooms.
void hotel :: room(){
    do{
        cout << "Select AC or Non-AC rooms(a/n): ";
        cin >> bin;
        if(bin=='n'){
            cout << "Enter the number of Non AC rooms: ";
            cin >> rooms;
            if(rooms <= T_rooms - S_rooms){
                S_rooms+=rooms;
                cout << "Booking successful.\n";
            }
            else cout << "\nNot enough rooms.\nNo. of rooms available : " << T_rooms - S_rooms << endl;
    
        }
        else{
            cout << "Enter the number of AC rooms: ";
            cin >> rooms;
            if(rooms <= T_ACrooms - S_ACrooms){
                S_ACrooms+= ACrooms;
                cout << "Booking successful.\n";
            }
            else cout << "\nNot enough AC rooms.\nNo. of rooms available : " << T_ACrooms - S_ACrooms << endl;
        }

        cout << "Would you like to continue?(y/n): ";
        cin >> bin;
    }while(bin=='y'||bin=='Y');
}

// Menu for hotel's room to room delivery.
void hotel :: menu(){
    do{
        cout << "# # # # # # Menu # # # # # #\n";
        cout << "1. Pizza\n2. Burger\n3. Coke\n4. Kebab\n5. Sprite\n6. Bhel\n7. Exit\n";
        cout << "# # # # # # # # # # # # # # #\n";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Enter the quantity of Pizzas: ";
                cin >> pizza;
                if(pizza<= T_pizza - S_pizza){
                    cout << "Order successful!";
                    S_pizza += pizza;
                }
                else cout << "\nNot enough pizzas available.\n Pizzas available: " << T_pizza - S_pizza;
                break;

            case 2:
                cout << "Enter the quantity of Burgers: ";
                cin >> burger;
                if(burger<= T_burger - S_burger){
                    cout << "Order successful!";
                    S_burger += burger;
                }    
                else cout << "\nNot enough burgers available.\n Burgers available: " << T_burger - S_burger;
                break;
            
            case 3:
                cout << "Enter the quantity of Coke: ";
                cin >> coke;
                if(coke<= T_coke - S_coke){
                    cout << "Order successful!";
                    S_coke += coke;
                }
                else cout << "\nNot enough Coke available.\n Coke available: " << T_coke - S_coke;
                break;

            case 4:
                cout << "Enter the quantity of Kebabs: ";
                cin >> kebab;
                if(kebab<= T_kebab -S_kebab){
                    cout << "Order successful!";
                    S_kebab += kebab;
                }
                else cout << "\nNot enough Kebabs available.\n Kebabs available: " << T_kebab - S_kebab;
                break;

            case 5:
                cout << "Enter the quantity of Sprite: ";
                cin >> sprite;
                if(sprite<= T_sprite -S_sprite){
                    cout << "Order successful!";
                    S_sprite += sprite;
                }
                else cout << "\nNot enough Sprites available.\n Sprites available: " << T_sprite - S_sprite;
                break;
            case 6:
                cout << "Enter the quantity of Bhel: ";
                cin >> bhel;
                if(sprite<= T_bhel - S_bhel){
                    cout << "Order successful!";
                    S_bhel += bhel;
                }
                else cout << "\nNot enough Bhel available.\n Bhel available: " << T_bhel - S_bhel;
                break;
            case 7:
                break;

            default:
                cout << "Out of scope. Order again please.\n";
                break;
        }
        cout << "\nWould you like to continue ordering? (y/n): ";
        cin >> bin;
    }while(bin=='y' || bin=='Y');
}

// This function prints the bill of commodities customer bought.
void hotel :: bill(){
    cout << "****************Your bill****************\n";
    cout << "\nAC rooms booked: " << ACrooms <<"   bill: " << ACrooms * ACroomsP;
    cout << "\nRooms booked: " << rooms <<"     bill: " << rooms * roomsP;
    cout << "\nPizzas ordered: " << pizza <<"   bill: " << pizza * pizzaP;
    cout << "\nBurgers ordered: " << burger <<"  bill: " << burger * burgerP;
    cout << "\nCoke ordered: " << coke <<"     bill: " << coke * cokeP;
    cout << "\nKebabs ordered: " << kebab <<"   bill: " << kebab * kebabP;
    cout << "\nBhel ordered: " << bhel <<"   bill: " << bhel*bhelP;
    cout << "\n                    Total: " << (rooms * roomsP) + (pizza * pizzaP) + (burger * burgerP) + (coke * cokeP) + (kebab * kebabP);
    cout << "\n*****************************************\n";
}

int main(){
    int what, i=0;
    char bin;
    cout << "HI MANAGER! WHAT WOULD YOU LIKE TO DO TODAY: ";
    do{
        cout << "\n1. Today's inventory\n2. Book a room\n3. Take an order\n4. Make the bill\n5. Never mind\n";
        cin >> what;
        switch(what){
            case 1:
                customerNeeds.hotelContent();
                break;

            case 2:
                customerNeeds.room();
                customerInfo[i].getInfo();
                break;

            case 3:
                customerNeeds.menu();
                break;

            case 4:
                cout << "Would you like to make the bill?(y/n): ";
                cin >> bin;
                if(bin=='y' || bin=='Y'){
                    customerNeeds.bill();
                    exit(0);
                }

            case 5:
                exit(0);

            default:
                cout <<"Out of scope. Please try again.\n";
        }
        i++; // Every time a new customer is added it is in new array index of customerNeeds[].
    }while(what != 4); 
    return 0;
}