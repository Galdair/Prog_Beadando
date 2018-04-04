
#include <iostream>
#include <fstream>
#include "bag.hpp"
using namespace std;
// Ezzel lehet a manualis es a unit teszt mod kozott valtogatni
//#define NORMAL_MODE
#ifdef NORMAL_MODE

class Menu{
public:
    void writeoptions(){
        cout<<"0. kilepes"<<endl;
        cout<<"1. Zsak felvetele egy elemszammal es utana ertekekkel"<<endl;
        cout<<"2. Zsakbol torles elemmel"<<endl;
        cout<<"3. Zsak jelenlegi tartalmanak kiiratasa"<<endl;
        cout<<"4. egy elem sokasaganak kiirasa"<<endl;
        cout<<"5. Egy uj zsak felvetele elemszammal es elemekkel majd ezek szimmetrikus diffreneciajanak kiiratasa"<<endl;
        cout<<"6. UResseg lekerdezese"<<endl;
        cout<<"7. Egy elem hozzadasa  jelenlegi zsakhoz"<<endl;


    }
    int option_number = 8;
void Run(Bag& main_bag, Bag& bag_other) {
    while (option_number != 0) {
        writeoptions();
        cin >> option_number;
        switch (option_number) {

            case 1:
                int elemszam;
                cin >> elemszam;
                for (int i = 0; i < elemszam; i++) {
                    int temp;
                    cin >> temp;
                    main_bag.PutIn(temp);
                }
                break;
            case 2:
                int elem;
                cin >> elem;
                main_bag.Delete_element(elem);
                break;
            case 3:
                main_bag.WriteOut();
                break;
            case 4:
                int elem_for_cardinality;
                cin >> elem_for_cardinality;
                cout << main_bag.Element_cardinality(elem_for_cardinality) << endl;

                break;
            case 5:

                int elemszam_new;
                cin >> elemszam_new;
                for (int i = 0; i < elemszam_new; i++) {
                    int temp;
                    cin >> temp;
                    bag_other.PutIn(temp);
                }
                main_bag.szimdif(bag_other);
                break;
            case 6:
                if (main_bag.Ures()) {
                    cout << "Ures" << endl;

                } else {
                    cout << "van benne elem" << endl;
                }
                break;
            case 7:
                int element;
                cin >> element;
                main_bag.PutIn(element);
                break;

            default:
                writeoptions();
                break;
        }


    }
}
};



int main()
{
Bag main_bag;
    Bag bag_other;
    main_bag = main_bag;
    Menu menu;
    menu.Run(main_bag,bag_other);

std::cout<<"working main function"<<std::endl;
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "bag.hpp"

TEST_CASE("1..n hossza: 1", "[PutIn]")
{
    Bag b; b.PutIn(2);
    CHECK(!b.Ures());
}

TEST_CASE("1..n hossza: 2", "[PutIn]")
{
    Bag b; b.PutIn(3); b.PutIn(5);

    CHECK(!b.Ures());
}



TEST_CASE("ures zsak letrehozasa", "[bag]")
{
    Bag b;
   CHECK(b.Ures());
}

TEST_CASE("ures zsakba uj elem", "[PutIn]")
{
    Bag b;
    CHECK(b.Ures());
    b.PutIn(0);
    CHECK(!b.Ures());

}

TEST_CASE("0 berakasa 0-t tartalmazo zsakba", "[PutIn]")
{
    Bag b;
    b.PutIn(0); b.PutIn(0);
    b.WriteOut();
    cout<<b.Element_cardinality(0)<<endl;
   CHECK(b.Element_cardinality(0) == 2);
}







TEST_CASE("tobb elemu zsak, egyertelmu maxelem", "[PutIn,Elem Cardinality]")
{
    Bag b;
    b.PutIn(0); b.PutIn(1); b.PutIn(1);b.PutIn(2);

    CHECK((1 == b.Element_cardinality(0) && 2 == b.Element_cardinality(1)) );
}



TEST_CASE("sokszor betenni", "[PutIn]")
{
    Bag b;
    for(int i = 0;i<100;i++){
        b.PutIn(i);
    }
    CHECK(1 == b.Element_cardinality(99));
}
TEST_CASE("feltolt kiurit", "[PutIn,delete]")
{
    Bag b;
    for(int i = 0;i<100;i++){
        b.PutIn(i);
    }

     for(int i = 0;i<100;i++){

         b.Delete_element(i);
    }
    CHECK(0 == b.Element_cardinality(99));
}
TEST_CASE("sokszor kivenni", "[delete]")
{
    Bag b;
    for(int i = 0;i<100;i++){
        b.PutIn(i);
    }

    CHECK(1 == b.Element_cardinality(99));
    for(int i = 0;i<98;i++){
        b.Delete_element(i);
    }
    CHECK(0 == b.Element_cardinality(97));
}
TEST_CASE("egymas utana sokszor kivenni", "[PutIn,delete]")
{
    Bag b;
    for(int i = 0;i<100;i++){
        b.PutIn(i);
    }
    b.Delete_element(99);
    b.Delete_element(99);
    CHECK(0 == b.Element_cardinality(99));
}
TEST_CASE("EGyenlo szimdif", "[szimdif]")
{
    Bag b;
    for(int i = 0;i<10;i++){
        b.PutIn(i);
    }
    Bag a;
    for(int i = 0;i<10;i++){
        a.PutIn(i);
    }

    CHECK(nullptr == b.szimdif_testing(a) );
}
TEST_CASE("Elem torlese meglevo elemekbol", "[delete]")
{
    Bag b;
    for(int i = 0;i<100;i++){
        b.PutIn(i);
    }


    CHECK(1 == b.Element_cardinality(10) );
    b.Delete_element(10);
    CHECK(0 == b.Element_cardinality(10) );
}
TEST_CASE("masolo konstruktor", "[copy const]")
{
    Bag b;
    for(int i = 0;i<100;i++){
        b.PutIn(i);
    }
    CHECK_NOTHROW(Bag c = b);
}
TEST_CASE("ertekadas", "[copy const]")
{
    Bag b;
    for(int i = 0;i<100;i++){
        b.PutIn(i);
    }
    Bag c;
    CHECK_NOTHROW(c = b);
}
TEST_CASE("ertekadas egyenloen", "[copy const]")
{
    Bag b;
    for(int i = 0;i<100;i++){
        b.PutIn(i);
    }
    b = b;
    CHECK_NOTHROW(b = b);
}


#endif

