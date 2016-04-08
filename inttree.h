#ifndef INTTREE_H
#define INTTREE_H

#include <vector>
#include <iostream>
using namespace std;


/**
 * Node of a tree containing an integer at each node.
 * @brief The IntTree class
 * @author Laila Zouaki
 */


class IntTree
{

    // Node information
    int data;

    // Sequence of sons (empty if none)
    vector<IntTree*> sons;

    public:

        /**
         * Constructor. Create a node with given information.
         * @brief IntTree
         * @param d information on this node.
         */
        IntTree(int d);

        /**
         * Destructor. Free memory when no longer needed.
         */
        ~IntTree();

        /**
         * Return information of this node
         * @brief getData
         * @return
         */
        int getData();

        /**
         * Set information of this node
         * @brief setData
         * @param d new information to give
         */
        void setData(int d);

        /**
         * Return the number of sons of this node
         * @brief nbSons
         * @return sons.size()
         */
        int nbSons();

        /**
         * Return the son at position pos, if any
         * @brief getSon
         * @param pos position of the son (considering left-most son is at position 0)
         * @return son at position pos
         * @throws out_of_range if pos not a valid position (between 0 and nbSons-1)
         */
        IntTree* getSon(int pos);


        /**
         * Replace the exisiting son at position pos with newSon
         * @brief setSon
         * @param pos position of the son to be changed (left-most son at position 0)
         * @param newSon son to replace the previous son
         * @throws out_of_range if pos not a valid position (between 0 and nbSons-1)
         */
        void setSon(int pos, IntTree* newSon);


        /**
         * Add newSon as supplementary right-most son of this node
         * @brief addAsLastSon
         * @param newSon to add as supplementary right-most son
         */
        void addAsLastSon(IntTree* newSon);


        /**
         * Remove right-most son of this node
         * @brief removeLastSon
         * @throws length_error if sons is empty
         */
        void removeLastSon();

        /**
         * Display the tree showing the hierarchy
         * @brief display
         * @param prefix
         * @param indent
         */
        void display(string prefix="", string indent="  ");


};

#endif // INTTREE_H
