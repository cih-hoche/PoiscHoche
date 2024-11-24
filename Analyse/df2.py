"""
Analyse des données 2
"""
import pandas as pd
import matplotlib.pyplot as plt

# Lire le fichier CSV → On obtient un DataFrame (= Machin qui ressemble à tableau excel)
df = pd.read_csv("datas/Ucrit_data_Iberian_Peninsula.csv", sep=';')

# On vire tous les individus qui ne sont pas adultes
df = df[df['Life stage'] != 'Juvenile']

# On garde seulement les colonnes qui contiennent des valeurs intéressantes (en nombre).
df = df[['Species',"Total length (mm)", "Ucrit (cm/s)", "Temperature (oC)"]]

# Pour enlever les lignes dans lesquelles il y a des valeurs manquantes
df = df.dropna()

# Fais la moyenne des valeurs par espèce
df = df.groupby(['Species']).mean()

# Afficher le df
print(df)

# Afficher les statistiques sur la température
print(df['Temperature (oC)'].describe())


x = df['Total length (mm)']
y = df['Ucrit (cm/s)']

# Afficher le nuage de points
plt.scatter(x, y, c=df['Temperature (oC)'], cmap='viridis')

# Légendes du graphique
# Echelle de couleurs
plt.colorbar(label='Temperature (oC)')
plt.xlabel('Total length (mm)')
plt.ylabel('Ucrit (cm/s)')
plt.title('Scatter plot of Total length vs Ucrit')

# Faire la moyenne de tous des coordonnées
x_mean = x.mean()
y_mean = y.mean()


# Tracer la droite qui passe par le point moyen et par l'origine du repère
# Calculer le Coefficient directeur de la droite
slope = y_mean / x_mean
print(slope)

#  Afficher la droite
plt.plot(x, slope*x, color='red', label='Line through mean and origin')

# Afficher le point moyen (orange)
plt.scatter(x_mean, y_mean, color='orange', label='Point moyen')

# Afficher le graphique
plt.legend()
plt.show()