# BSQ - Biggest Square Finder

Un programme C qui trouve le plus grand carré vide dans une grille 2D contenant des obstacles.

## Description

**BSQ** (Biggest SQuare) est un projet qui résout le problème de recherche du plus grand carré contiguë pouvant être rempli dans une grille 2D contenant des obstacles.

Le programme utilise l'algorithme de **programmation dynamique** (matrice DP) pour résoudre ce problème de manière efficace en temps O(rows × cols).

## Fonctionnalités

- 📂 Lecture de fichiers contenant des grilles
- 📊 Parsing flexible des formats de grille
- ⚡ Algorithme optimisé en O(n×m) avec programmation dynamique
- ✓ Gestion d'erreurs robuste
- 🎯 Marquage du carré trouvé dans la grille

## Format du fichier d'entrée

Le fichier d'entrée suit ce format :

```
<nombre_de_lignes><caractère_vide><caractère_obstacle><caractère_remplissage>
<grille>
```

**Exemple :**
```
5.ox
.....
.ooo.
.ooo.
.ooo.
.....
```

- `5` : nombre de lignes
- `.` : caractère pour les cases vides
- `o` : caractère pour les obstacles
- `x` : caractère pour marquer le carré trouvé

## Compilation

```bash
make
```

Ou pour nettoyer et recompiler :

```bash
make clean
make
```

## Utilisation

```bash
./bsq <fichier_d'entrée>
```

**Exemple :**
```bash
./bsq map.txt
```

Le programme affiche la grille avec le plus grand carré marqué par le caractère de remplissage spécifié.

## Structure du projet

- `main.c` : Fonction principale et gestion des fichiers
- `bsq.h` : Fichier d'en-tête avec les structures et déclarations
- `ft_parsing.c` : Parsing du fichier d'entrée
- `read_file.c` : Lecture du contenu du fichier
- `solve.c` : Algorithme de résolution (programmation dynamique)
- `min.c` : Fonction utilitaire pour trouver le minimum
- `makefile` : Script de compilation
- `perl.sh` : Script de génération de grilles de test aléatoires

## Algorithme

L'algorithme utilise une **matrice de programmation dynamique (JSP)** :

1. Créer une matrice JSP de même taille que la grille
2. Pour chaque cellule :
   - Si c'est un obstacle : JSP[i][j] = 0
   - Si c'est sur une bordure : JSP[i][j] = 1
   - Sinon : JSP[i][j] = min(JSP[i-1][j], JSP[i][j-1], JSP[i-1][j-1]) + 1
3. Trouver la valeur maximale dans la matrice JSP
4. Marquer le carré correspondant dans la grille
5. Afficher le résultat

**Complexité :**
- Temps : O(rows × cols)
- Espace : O(rows × cols)

## Génération de grilles de test

Utilisez le script `perl.sh` pour générer des grilles de test aléatoires :

```bash
perl perl.sh <largeur> <hauteur> <densité_obstacles> > map_test.txt
./bsq map_test.txt
```

**Exemple :**
```bash
perl perl.sh 100 100 40 > map_test.txt
./bsq map_test.txt
```

## Gestion des erreurs

Le programme gère les erreurs suivantes :

- ❌ Fichier introuvable ou illisible
- ❌ Format de grille invalide
- ❌ Problèmes d'allocation mémoire
- ❌ Grille vide ou invalide

En cas d'erreur, le message `map error` est affiché sur stderr et le programme retourne 1.
