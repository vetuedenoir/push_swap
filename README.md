# Push_swap

## Présentation du projet
Push_swap est un projet d'algorithmie visant à trier une suite d'entiers en utilisant un ensemble restreint d'instructions pour manipuler deux piles, a et b.
L'objectif est de développer un programme en C, qui calcule et affiche la séquence d'instructions la plus courte possible pour ordonner les entiers fournis en entrée.
Ce projet permet de se familiariser avec les concepts de tri, de complexité algorithmique, et d'optimisation.

## Instructions disponibles
Le programme utilise les instructions suivantes pour manipuler les piles :

- sa (swap a) : Intervertit les deux premiers éléments au sommet de la pile a.
- sb (swap b) : Intervertit les deux premiers éléments au sommet de la pile b.
- ss : Exécute sa et sb simultanément.
- pa (push a) : Déplace le premier élément du sommet de b vers le sommet de a.
- pb (push b) : Déplace le premier élément du sommet de a vers le sommet de b.
- ra (rotate a) : Décale d’une position vers le haut tous les éléments de la pile a, le premier devenant le dernier.
- rb (rotate b) : Décale d’une position vers le haut tous les éléments de la pile b, le premier devenant le dernier.
- rr : Exécute ra et rb simultanément.
- rra (reverse rotate a) : Décale d’une position vers le bas tous les éléments de la pile a, le dernier devenant le premier.
- rrb (reverse rotate b) : Décale d’une position vers le bas tous les éléments de la pile b, le dernier devenant le premier.
- rrr : Exécute rra et rrb simultanément.


## Exécution
Le programme push_swap prend en entrée une liste d'entiers en tant qu'arguments et génère une suite d'instructions
pour trier ces entiers dans la pile a en utilisant le moins d'opérations possible.

Exemple d'exécution :

![push-swap32514](https://github.com/user-attachments/assets/bc4ac9b2-760e-4ce6-9727-6c6b71286a7e)

## Bonus

En complement un testeur a ete concue. Il lis les instructions dans l'entre standare et les executes pour trier la listes de nombre.
si elle est trier il ecrit ok sinon ko.

Exemple :

![push-swap-checkeur](https://github.com/user-attachments/assets/f8e5bc00-6446-45a7-9d5f-07b3f53c5f1a)




