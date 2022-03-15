//
// Created by dimde on 3/11/2022.
//

#ifndef POA_MATRIX_RANDUNSIGNED_H
#define POA_MATRIX_RANDUNSIGNED_H


/**
 * De Bleser Dimitri et Peer Vincent
 */
class RandUnsigned {

   /**
    * Constructeur privé
    */
   RandUnsigned();

public :

   /**
    * Obtient une instance unique de la classse
    * @return Référence sur l'instance unique
    */
   static RandUnsigned& getInstance();

   /**
    * Obtien un unsigned pseudo aléatoire
    * @param max valeur max voulue
    * @return unsigned pseudo aléatoire
    */
   unsigned getUnsigned(unsigned max);

   /**
    * Enlève le constructeur par copie
    */
   RandUnsigned(const RandUnsigned&) = delete;
   /**
   * Enlève opérateur d'affectation
   */
   void operator=(const RandUnsigned&) = delete;
};


#endif //POA_MATRIX_RANDUNSIGNED_H
