//
// Created by gabor on 2018.03.26..
//

#ifndef PROGRAMOZAS_BEADANDO_1_BAG_HPP
#define PROGRAMOZAS_BEADANDO_1_BAG_HPP


class Bag {
public:
    struct element_and_cardinality{
        int element;
        int cardinality;
    };


    Bag();
    Bag(int* input_tomb,int input_meret);
    Bag(const Bag& masolando_bag);
    ~Bag();
    bool Ures();
    Bag& Szim_Dif(const Bag& other_bag);
    Bag& operator =(const Bag& bag_assginemnt);
    void PutIn(int new_bag_element);
    void szimdif(const Bag& other_bag);
    void WriteOut();
    void Delete_element(int element_to_be_deleted);
    int Element_cardinality(int element_to_count);
    element_and_cardinality* szimdif_testing(const Bag& other_bag);
    element_and_cardinality* get_tarolotomb();

private:
    element_and_cardinality* tarolo_tomb;
    unsigned long long tarolo_meret;




};


#endif //PROGRAMOZAS_BEADANDO_1_BAG_HPP
