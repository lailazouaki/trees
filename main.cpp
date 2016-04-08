#include "inttree.h"
#include "tree.h"

int main(int argc, char *argv[]){


    IntTree* root = new IntTree(12);

    root->addAsLastSon(new IntTree(8));
    root->getSon(0)->addAsLastSon(new IntTree(4));
    root->getSon(0)->addAsLastSon(new IntTree(9));

    root->addAsLastSon(new IntTree(23));
    root->getSon(1)->addAsLastSon(new IntTree(17));
    root->getSon(1)->addAsLastSon(new IntTree(15));

    root->display("*  ");

    cout<<"Valeur de la racine "<<root->getData()<<endl;
    cout<<"Nombres de fils de la racine "<<root->nbSons()<<endl;

    try{
        root->getSon(-3);
    } catch(out_of_range e){
        cout<<"Out of range: "<<e.what()<<endl;
    }

    try{


        root->setSon(1, new IntTree(343));
        root->setSon(3, new IntTree(34));
    } catch(out_of_range e){
        cout<<"Out of range: "<<e.what()<<endl;
    }


    try {

        root->removeLastSon();
        root->removeLastSon();
        root->removeLastSon();
        root->removeLastSon();

    } catch(length_error e){
        cout<<"Length error: "<<e.what()<<endl;
    }

    Tree<string>* chaines = new Tree<string>("Hello, world");
    chaines->addAsLastSon(new Tree<string>("Comment"));
    chaines->addAsLastSon(new Tree<string>("Qui es-tu?"));

    try{
        chaines->getSon(0)->addAsLastSon(new Tree<string>("Ca va?"));
    } catch(out_of_range e){
        cout<<"Out of range: "<<e.what()<<endl;
    }

    try{
        chaines->addSon(1, new Tree<string>("!"));
    } catch(out_of_range e){
        cout<<"Out of range: "<<e.what()<<endl;
    }


    chaines->display("*  ");


    try{
        try{
            chaines->removeSon(2);
        } catch(length_error e){
            cout<<"Length error: "<<e.what()<<endl;
        }
    } catch(out_of_range e){
        cout<<"Out of range: "<<e.what()<<endl;
    }


    chaines->display("*  ");
    cout<<endl<<endl<<endl;
    chaines->invert_display("*  ");


    Tree<int>* root2 = new Tree<int>(12);

    root2->addAsLastSon(new Tree<int>(8));
    root2->getSon(0)->addAsLastSon(new Tree<int>(4));
    root2->getSon(0)->addAsLastSon(new Tree<int>(9));

    root2->addAsLastSon(new Tree<int>(23));
    root2->getSon(1)->addAsLastSon(new Tree<int>(17));
    root2->getSon(1)->addAsLastSon(new Tree<int>(15));

    cout<<endl<<endl<<endl;
    root2->display("*  ");

    root2->addSon(0, new Tree<int>(34));
    root2->display("*   ");


    cout<<"_________________"<<endl;
    root2->removeSon(2);
    root2->display("*   ");

    cout<<"_________________"<<endl;
    root2->invert_display("*  ");


    Tree<int>* root3 = new Tree<int>(1);
    root3->addAsLastSon(new Tree<int>(2));
    root3->addAsLastSon(new Tree<int>(3));
    root3->addAsLastSon(new Tree<int>(4));

    root3->getSon(0)->addAsLastSon(new Tree<int>(5));
    root3->getSon(0)->addAsLastSon(new Tree<int>(6));
    root3->getSon(0)->getSon(1)->addAsLastSon(new Tree<int>(8));

    root3->getSon(2)->addAsLastSon(new Tree<int>(7));
    root3->getSon(2)->getSon(0)->addAsLastSon(new Tree<int>(9));
    root3->getSon(2)->getSon(0)->addAsLastSon(new Tree<int>(10));
    root3->getSon(2)->getSon(0)->addAsLastSon(new Tree<int>(11));

    root3->getSon(2)->getSon(0)->getSon(0)->addAsLastSon(new Tree<int>(12));
    cout<<"_________________"<<endl;
    root3->display("*   ");
    cout<<"_________________"<<endl;
    root3->breadth_first_display("*   ");

    delete root3;

    return 0;
}
