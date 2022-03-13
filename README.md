# POA_Matrix
todo -> allocate vérif ladresse retournée?
    -> throw des fonctions
    -> allocate et deleteTab pas exacte égal comme nom
    -> srand avec time(null) comme discuté avec lassistant?
    -> check for_each runtime_error dans Matrix.h si vrai ou pas ce que je dis

##
Introduction
Ce laboratoire a pour but de développer un programme permettant de créer des matrices en 2 dimensions qui possèdent comme
éléments des entiers positifs.

## Conception

### Gestion de l'allocation mémoire
Pour la création des matrices, nous avons défini 2 méthodes privées qui sont
allocate() et deleteTab(). La première alloue dynamiquement l'attribut tab qui a eu sa taille
spécifiée en paramètre lors de l'appel au constructeur de la matrice. Cette fonctin d'allocation
est utilisée dans les constructeurs d'une matrice. La méthode deleteTab réalloue la mémoire en 
restituant la taille allouée pour l'attribut tab d'une matrice. C'est dans le destructeur qu'elle 
est appelée.

### Construction d'une matrice
Il y a trois constructeurs de matrice définis, deux sont publics et un privé. Une matrice peut être
créée en spécifiant le nombre de ligne, le nombre de colonne et un modulo correspondant à la valeur
maximale possible qui sera attribuée à un élément de cette matrice. Ce constructeur initialise
 aléatoirement les éléments de la matrice, avec des valeurs entre 0 et n-1 si n est la valeur du modulo.
Si un des trois paramètres vaut zéro, une exception de type runtime_error est levée, en effet la matrice
n'aurait plus de sens à être créée avec une telle valeur.  
Le deuxième constructeur public est celui de copie à partir d'une matrice existante. Ce constructeur 
exploite le constructeur privé qui est défini de façon à pouvoir

### Opérations sur matrices
Les opérations disponibles sont l'addition, la soustraction et la multiplication entre deux matrices. 
Chacune de ces opérations est définie en trois versions différentes :  

    1. Matrix& operation(const Matrix& rhs)
    L'opération s'effectue sur la matrice implicite this et rhs, modifie this puis retourne une référence à this.
    
    2. Matrix operationToCpy(const Matrix& rhs) const
    Une nouvelle matrice temporaire est créée pour y stocker le résultat sans modifier les deux matrices opérandes.
    Le retour de la fonction renvoit cette matrice temporaire.

    3. Matrix* operationDynamic(const Matrix& rhs) const
    Une nouvelle matrice est créée dynamiquement pour y stocker le résultat sans modifier les deux matrices opérandes.
    Le retour de la fonction renvoit un pointeur sur la matrice résultante qui vient d'être allouée.


Pour la mise en oeuvre de ces opérations, la méthode privée for_each est définie pour factoriser le code semblable à chaque opération. 
Cette méthode s'effectue donc sur deux matrices, l'une étant passée implicitement en paramètre et l'autre explicitement. 
Elle attend également en paramètre un pointeur sur une fonction f prenant deux entiers en paramètre. C'est 
cette fonction f qui définira le type d'opération à effectuer entre deux éléments des matrices.  
La méthode for_each lève une exception si la valeur des modulos est différentes dans les 2 matrices.
Si les tailles de matrices diffèrent, le résultat sera de taille max(M1, M2) × max(N1, N2), avec des valeurs
à 0 pour les éléments hors de la taille commune. Il existe cependant un cas où une exception sera levée si 
ces tailles diffèrent, lorsque l'opération choisie correspont à 1ère déclaration qui est définie ci-dessus. En effet,
la matrice implicite ne va pas voir sa taille modifiée pour satisfaire l'opération. Les deux autres déclaration ont 
l'avantage de créer sur le moment une matrice est la taille est adaptée selon la taille correcte au moment de la constructon 
de la matrice qui fera l'objet du résultat.

### Gestion de l'initialisation aléatoire


