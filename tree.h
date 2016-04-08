#ifndef TREE_H
#define TREE_H

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class Tree
{
    T data;
    vector<Tree*> sons;

    public:

        /**
         * Constructor. Create a node with given information.
         * @brief Tree
         * @param d information on this node.
         */
        Tree<T>(T d){
            data = d;
        }


        /**
         * Destructor
         */
        virtual ~Tree<T>(){
            cout<<"Cet élément a "<<sons.size()<<" fils"<<endl;
            for(int i = 0 ; i < sons.size() ; i++){
               delete getSon(i);
            }

            cout<<"On libère la mémoire"<<endl;
        }


        /**
         * Return information of this node
         * @brief getData
         * @return
         */
        T getData(){
            return data;
        }

        /**
         * Set information of this node
         * @brief setData
         * @param d new information to give
         */
        void setData(T d){
            data = d;
        }

        /**
         * Return the number of sons of this node
         * @brief nbSons
         * @return sons.size()
         */
        int nbSons(){
            return sons.size();
        }

        /**
         * Return the son at position pos, if any
         * @brief getSon
         * @param pos position of the son (considering left-most son is at position 0)
         * @return son at position pos
         * @throws out_of_range if pos not a valid position (between 0 and nbSons-1)
         */
        Tree<T>* getSon(int pos){
            if(pos < 0 || pos >= sons.size())
                throw out_of_range("La position demandée n'est pas valide");

            return sons.at(pos);
        }

        /**
         * Replace the exisiting son at position pos with newSon
         * @brief setSon
         * @param pos position of the son to be changed (left-most son at position 0)
         * @param newSon son to replace the previous son
         * @throws out_of_range if pos not a valid position (between 0 and nbSons-1)
         */
        void setSon(int pos, Tree* newSon){
            if(pos < 0 || pos >= sons.size())
                throw out_of_range("La position demandée n'est pas valide");

            sons.at(pos) = newSon;
        }


        /**
         * Add newSon as supplementary right-most son of this node
         * @brief addAsLastSon
         * @param newSon to add as supplementary right-most son
         */
        void addAsLastSon(Tree* newSon){
            sons.push_back(newSon);
        }


        /**
         * Remove right-most son of this node
         * @brief removeLastSon
         * @throws length_error if sons is empty
         */
        void removeLastSon(){
            if(nbSons() == 0)
                throw length_error("Il n'y a plus de fils à supprimer");

            sons.pop_back();
        }

        /**
         * Insert extra son at position pos, if pos exists
         * @brief addSon
         * @param pos position of the son to insert
         * @param son element to insert
         */
        void addSon(int pos, Tree<T>* son){
            if(pos < 0 || pos >= sons.size())
                throw out_of_range("La position demandée n'est pas valide");

           sons.insert(sons.begin()+pos, son);
        }

        /**
         * Remove son at positon pos, thus reducing nbSons
         * @brief removeSon
         * @param pos
         */
        void removeSon(int pos){
            if(pos < 0 || pos >= sons.size())
                throw out_of_range("La position demandée n'est pas valide");

            if(nbSons() == 0)
                throw length_error("Il n'y a plus de fils à supprimer");

            sons.erase(sons.begin()+pos);
        }


        /**
         * Display the tree showing the hierarchy
         * Depth-first search descending display
         * @brief display
         * @param prefix
         * @param indent
         */
        void display(string prefix="", string indent="  "){
            cout<<prefix<<data<<endl;

            for(int i = 0 ; i < sons.size() ; i++){
               sons.at(i)->display(prefix+indent, indent);
            }
        }

        /**
         * Display the tree showing the inverted hierarchy
         * Depth-first search ascending display
         * @brief display
         * @param prefix
         * @param indent
         */
        void invert_display(string prefix="", string indent="  "){

            for(int i = 0 ; i < sons.size() ; i++){
               sons.at(i)->invert_display(prefix+indent, indent);
            }

            cout<<prefix<<data<<endl;
        }

        /**
         * Breadth-first search display
         * @brief display
         * @param prefix
         * @param indent
         */

        // Je n'ai pas réussi à afficher sur le même niveau d'indentation un même niveau de profondeur : on perd l'information sur qui est le fils de qui
        // Par contre, les éléments sont bien affichés dans l'ordre de la largeur !
        void breadth_first_display(string prefix="", string indent= "  "){

            vector<Tree<T> *> file;
            file.push_back(this);
            int compteur = 0;
            while(!file.empty()){
                Tree<T>* first_node = file.at(0);
                file.erase(file.begin());

                cout<<prefix;
                for(int j = 0 ; j < compteur ; j++)
                    cout<<indent;

                cout<<first_node->getData()<<endl;

                for(int i = 0 ; i < first_node->nbSons() ; i++){
                    file.push_back(first_node->getSon(i));
                }

                compteur+=1;


            }

        }

        /* Ne fonctionne pas correctement, pour la même raison que pour l'affichage : en
         * utilisant les files, je n'arrive pas à traduire le fait qu'on change de niveau de profondeur
         * Du coup, le compteur prend en compte beaucoup plus d'éléments qu'il ne le devrait.
        */
        int minDepth(){

            vector<Tree<T> *> file;
            file.push_back(this);
            int compteur = 1;

            while(!file.empty()){
                Tree<T>* first_node = file.at(0);
                file.erase(file.begin());

                for(int i = 0 ; i < first_node->nbSons() ; i++){
                    file.push_back(first_node->getSon(i));
                }

                for(int j = 0 ; j < file.size() ; j++){
                    if(first_node->nbSons() == 0)
                        return compteur;
                }


            }

        }


};

#endif // TREE_H
