"""
Analyse de données 1
Comme les individus n'ont pas étés regroupés par espèces, chaque point représente un individu et l'espèce sans doute une tache de points
"""
import pandas as pd
import matplotlib.pyplot as plt

# Lire le fichier CSV
df = pd.read_csv("datas/fish_data_wheight_length_ration.csv")

# Afficher le DataFrame
print(df)

# Créer un nuage de points
plt.scatter(df['length'], df['weight'], c=df['w_l_ratio'], cmap='viridis')

# Ajouter une barre d'échelle de couleur
plt.colorbar(label='Weight/Length Ratio')

plt.xlabel('Length')
plt.ylabel('Weight')
plt.title('Scatter plot of Length vs Weight')

plt.show()
