#include "inttree.h"

IntTree:: IntTree(int d){
    data = d;
}

IntTree:: ~IntTree(){

}


// Return information of this node
int IntTree:: getData(){
    return data;
}

// Set information of this node
void IntTree:: setData(int d){
    data = d;
}

// Return the number of sons of this node
int IntTree:: nbSons(){
    return sons.size();
}

 //￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼// Return the son at position pos, if any (considering left-most son is at position 0)
IntTree* IntTree:: getSon(int pos){
    if(pos < 0 || pos >= sons.size())
        throw out_of_range("La position demandée n'est pas valide");

    return sons.at(pos);
}

// Replace the exisiting son at position pos with newSon (left-most son at position 0)
void IntTree:: setSon(int pos, IntTree* newSon){
    if(pos < 0 || pos >= sons.size())
        throw out_of_range("La position demandée n'est pas valide");

    sons.at(pos) = newSon;
}

// Add newSon as supplementary right-most son of this node
void IntTree:: addAsLastSon(IntTree* newSon){
    sons.push_back(newSon);
}

// Remove right-most son of this node
void IntTree:: removeLastSon(){
    if(nbSons() == 0)
        throw length_error("Il n'y a plus de fils à supprimer");

    sons.pop_back();

}

// Display tree
void IntTree:: display(string prefix, string indent){
    cout<<prefix<<data<<endl;

    for(int i = 0 ; i < sons.size() ; i++){
       sons.at(i)->display(prefix+indent, indent);
    }
}
