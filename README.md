# PoiscHoche

Projet de simulations de poissons du CIH

## Principe
Chacun peut créer une espèce de poissons qui vont évoluer dans une simulation.

Le but est d'avoir l'espèce qui perdure le plus longtemps possible et/ou qui se reproduit le plus

### Ajout d'espèces de poissons
Chacun peut créer une espèce de poissons et faisant une PR. Il faut fournir une classe de poissons, dépendante d'une classe mère.
Le poisson créé dispose de plusieurs méthodes pour se déplacer, ... Libre à chacun d'employer la méthode qu'il souhaite pour contrôler ses poissons.
La classe de poisson custom sera celle utilisée pour toute une espèce de poisson.

Des attributs (capacités, ...) seront attribués à chaque espèce.
Pour des soucis d'équilibre, les attributs ne pourront être choisis et seront attribués aléatoirement (en respectant certaines règles).

### Attributs des espèces

Chaque attribut apporte un certain nombre de points en fonction de son développement.
Un nombre maximal de point sera définit, ainsi que le fait que certains attributs en limitent d'autres

Attributs:
- Taille
- Carnivore / Herbivore
- Estomac (combien il doit manger)
- Vue (capacité à détecter les poissons alentours)
- Température idéale de vie
- Acidité de l'eau supportée
- Vitesse/Force de la nage (> Epuisement en fonction de la vitesse (à voir avec les courants)) 
- Efficacité de la reproduction (> Variable selon la santé du poisson)
- ...

### Monde de simulation
Les espèces sont mises dans un monde marin de simulation.

#### Éléments 
- Éléments matériels (eau / terre / sable / ...)
- Nourriture végétale
- Température
- Acidité
- Courants
- Pression (plusieurs étages)

Les éléments matériels seront stockés dans un tableau à 2 dimensions (tableau de tableau). De même pour la nourriture

Pour les courants : On stockera le point de départ, d'arrivée, la vitesse et la Force

Pour l'acidité et la température : 
On pourra envisager des points chauds/acides ainsi que l'interaction avec les courants

Avec par exemple des points de température éphémères qui suivent les courants et qui se régulent petit à petit vers une moyenne et des points de température permanents, qui émettent des courants chauds vers des points permanent froids.

#### Génération
La génération du monde est aléatoire.

Certains évènements peuvent aléatoirement se produire.
Par exemple: une rivière qui devient acide du fait de pollution ou une baisse du niveau d'eau.

#### Ressources de base
On mettra des petits poissons en attendant qu'il y en ait beaucoup


## A faire
 - [ ] Liste des choses à faire


## Technique

### Classe mère de poissons

#### Méthodes
- Déplacement
- Vision
- Paramètres du milieu (température, ...)

#### Variables
- Coordonnées
- Vie
- Niveau de faim
