#include "cellimpl.h"
#include <cstdio>

CellImpl::~CellImpl () {
}

int CellImpl::getState() const {
    return m_state;
}

void CellImpl::setState(int state) {
    m_state = state;
}
void CellImpl::checkNeighbours(Cell **grid, unsigned int x, unsigned int y, unsigned int w, unsigned int h, int *states) {
    /*
     * Ceci est une fonction qui prend en argument :
     * - la grille de cellules
     * - la pos xy
     * - les dimensions de la grille
     * - un tableau de 8 cases pour foutre les �tats
     *
     * Elle modifie le tableau � 8 cases en indiquant le status de chacun de ses voisins
     */
    for(unsigned char i=0; i<8; i++) {states[i] = 0;}
    //w--;
    //h--;
    // si la case n'estpas coll�e au c�t� gauche
    if(x>0) {
        //si il y a une case au dessus
        if(y>0) {
            // Cas si il y a une case en diagonale en haut gauche
            states[0] = grid[(x-1)+((y-1)*w)]->getState();
        }
        // en dessous
        if(y<h) {
            // Cas si il y a une case en diagonale en bas gauche
            states[2] = grid[(x-1)+((y+1)*w)]->getState();
        }
        // Cas s'il y a une case � gauche
        states[1] = grid[(x-1)+(y*w)]->getState();
    }
    // si la case n'est pas coll�e � droite
    if(x<w) {
        //si il y a une case au dessus
        if(y>0) {
            // Cas si il y a une case en diagonale en haut droite
            states[6] = grid[(x+1)+((y-1)*w)]->getState();
        }
        if(y<h) {
            // Cas si il y a une case en diagonale en bas droite
            states[4] = grid[(x+1)+((y+1)*w)]->getState();
        }
        // Cas s'il y a une case � droite
        states[5] = grid[(x+1)+(y*w)]->getState();
    }
    if(y>0) {
        // Case du haut
        states[7] = grid[(x)+((y-1)*w)]->getState();
    }
    if(y<h) {
        // Case du bas
        states[3] = grid[(x)+((y+1)*w)]->getState();
    }


}
