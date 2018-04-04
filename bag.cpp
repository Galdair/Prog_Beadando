//
// Created by gabor on 2018.03.26..
//

#include "bag.hpp"
#include <iostream>
Bag::Bag() {
 tarolo_meret = 0;
    tarolo_tomb = nullptr;
}

Bag::Bag(int *input_tomb,int input_meret) {
    tarolo_tomb = new element_and_cardinality[input_meret];
 for(int i = 0;i< input_meret;i++) {
     if (Element_cardinality(input_tomb[i]) == 0)
         tarolo_tomb[i].element = input_tomb[i];

     else {
         for (int j = 0; j < tarolo_meret; j++) {
                if(input_tomb[i] == tarolo_tomb[j].element)
                {
                    tarolo_tomb[j].cardinality++;
                }
         }
     }
 }
    for(int i =0;i<tarolo_meret;i++){
        tarolo_tomb[i].cardinality = Element_cardinality(tarolo_tomb[i].element);
    }
}

Bag::Bag(const Bag &masolando_bag) {
    tarolo_meret = masolando_bag.tarolo_meret;

    tarolo_tomb = new element_and_cardinality[masolando_bag.tarolo_meret];
    for(int i = 0;i< masolando_bag.tarolo_meret;i++) {

            tarolo_tomb[i].element = masolando_bag.tarolo_tomb[i].element;
            tarolo_tomb[i].cardinality = masolando_bag.tarolo_tomb[i].cardinality;


    }


}

Bag::~Bag() {
delete[] tarolo_tomb;
}

bool Bag::Ures() {
    return tarolo_meret == 0;
}

Bag &Bag::Szim_Dif(const Bag &other_bag) {
    Bag end_bag;
    for(int i =0;i< tarolo_meret;i++){
        bool benne_van = false;
        for(int j = 0;j<other_bag.tarolo_meret;j++){
            if(tarolo_tomb[i].element == other_bag.tarolo_tomb[j].element){
                benne_van = true;

            }

        }
        if(!benne_van){
            end_bag.PutIn(tarolo_tomb[i].element);
        }
    }
    for(int i =0;i< other_bag.tarolo_meret;i++){
        bool benne_van = false;
        for(int j = 0;j<tarolo_meret;j++){
            if(tarolo_tomb[j].element == other_bag.tarolo_tomb[i].element){
                benne_van = true;

            }

        }
        if(!benne_van){
            end_bag.PutIn(other_bag.tarolo_tomb[i].element);
        }
    }
    std::cout<<"this is element number"<<end_bag.Ures()<<std::endl;
    return end_bag;
}

Bag &Bag::operator=(const Bag &bag_assginemnt) {
    if(&bag_assginemnt == this){
        return *this;
    }
    else {
        delete[] tarolo_tomb;
        tarolo_meret = bag_assginemnt.tarolo_meret;
        tarolo_tomb = new element_and_cardinality[tarolo_meret];
        for (int i = 0; i < tarolo_meret; i++) {
            tarolo_tomb[i] = bag_assginemnt.tarolo_tomb[i];
        }
    }
}

void Bag::PutIn(int new_bag_element) {

    if (Element_cardinality(new_bag_element) == 0) {
        unsigned long long int off_by_one = tarolo_meret + 1;
        element_and_cardinality *temporary_container = new element_and_cardinality[off_by_one];
        for (int i = 0; i < tarolo_meret; i++) {
            temporary_container[i] = tarolo_tomb[i];

        }
        temporary_container[tarolo_meret].element = new_bag_element;
        temporary_container[tarolo_meret].cardinality = 1;
        delete[] tarolo_tomb;
        tarolo_meret++;
        tarolo_tomb = new element_and_cardinality[tarolo_meret];
        for (int i = 0; i < tarolo_meret; i++) {
            tarolo_tomb[i] = temporary_container[i];

        }
        delete[] temporary_container;
    }
    else{
        for(int i = 0;i<tarolo_meret;i++){
            if(tarolo_tomb[i].element == new_bag_element){
                tarolo_tomb[i].cardinality++;
            }
        }
    }
}

void Bag::WriteOut() {
    for(int i = 0;i<tarolo_meret;i++){
        std::cout<<tarolo_tomb[i].element<<" "<<tarolo_tomb[i].cardinality<<",";
    }
    std::cout<<std::endl;
}

void Bag::Delete_element(int element_to_be_deleted) {
    if(tarolo_meret-1 != 0) {
        element_and_cardinality *temporary_container = new element_and_cardinality[tarolo_meret - 1];
        int new_element_index = 0;
        int old_element_index = 0;
        while (old_element_index < tarolo_meret) {
            if (element_to_be_deleted != tarolo_tomb[old_element_index].element) {
                temporary_container[new_element_index] = tarolo_tomb[old_element_index];
                new_element_index++;

            }
            old_element_index++;
        }
        delete[] tarolo_tomb;
        tarolo_meret = tarolo_meret - 1;
        tarolo_tomb = new element_and_cardinality[tarolo_meret];
        for (int i = 0; i < tarolo_meret; i++) {
            tarolo_tomb[i] = temporary_container[i];

        }
        delete[] temporary_container;
    }
    else {
        tarolo_meret = 0;
        tarolo_tomb = nullptr;
    }
}

void Bag::szimdif(const Bag &other_bag) {
    Bag end_bag;
    for(int i =0;i< tarolo_meret;i++){
        bool benne_van = false;
        for(int j = 0;j<other_bag.tarolo_meret;j++){
            if(tarolo_tomb[i].element == other_bag.tarolo_tomb[j].element){
                benne_van = true;

            }

        }
        if(!benne_van){
            end_bag.PutIn(tarolo_tomb[i].element);
        }
    }
    for(int i =0;i< other_bag.tarolo_meret;i++){
        bool benne_van = false;
        for(int j = 0;j<tarolo_meret;j++){
            if(tarolo_tomb[j].element == other_bag.tarolo_tomb[i].element){
                benne_van = true;

            }

        }
        if(!benne_van){
            end_bag.PutIn(other_bag.tarolo_tomb[i].element);
        }
    }
    std::cout<<"this is element number"<<end_bag.Ures()<<std::endl;
    end_bag.WriteOut();
}


int Bag::Element_cardinality(int element_to_count) {

    int cardinality = 0;
    for(int i=0;i< tarolo_meret;i++){
        if(element_to_count == tarolo_tomb[i].element){
            cardinality = tarolo_tomb[i].cardinality;

        }
    }
return cardinality;
}

Bag::element_and_cardinality *Bag::szimdif_testing(const Bag &other_bag) {
    Bag end_bag;
    for(int i =0;i< tarolo_meret;i++){
        bool benne_van = false;
        for(int j = 0;j<other_bag.tarolo_meret;j++){
            if(tarolo_tomb[i].element == other_bag.tarolo_tomb[j].element){
                benne_van = true;

            }

        }
        if(!benne_van){
            end_bag.PutIn(tarolo_tomb[i].element);
        }
    }
    std::cout<<"this is element number"<<end_bag.Ures()<<std::endl;
    return end_bag.get_tarolotomb();
}

Bag::element_and_cardinality *Bag::get_tarolotomb() {
    return tarolo_tomb;
}
