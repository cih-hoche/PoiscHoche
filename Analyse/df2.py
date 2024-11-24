
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import stats
from scipy.stats import probplot
# Lire le fichier CSV
df = pd.read_csv("datas/Ucrit_data_Iberian_Peninsula.csv", sep=';')

# Vire tous ceux dont le Life stage est égal à Junevile
df = df[df['Life stage'] != 'Juvenile']

df = df[['Species',"Total length (mm)", "Ucrit (cm/s)", "Temperature (oC)"]]
print(df.columns)
df = df.dropna()

# Fais la moyenne des valeurs par especes
df = df.groupby(['Species']).mean()
# Index(['Species', 'Native', 'Family', 'Total length (mm)', 'Ucrit (cm/s)',
#        'Temperature (oC)', 'Body shape', 'Form factor', 'Life stage',
#        'Time step (min)', 'Wild status'],
#       dtype='object')
print(df)
import seaborn as sns

# Afficher le graphique des probabilités de Temperature (oC)
# df.replace([np.inf, -np.inf], np.nan, inplace=True)
# sns.histplot(df[['Temperature (oC)']], kde=True)
# print(df['Temperature (oC)'])


print(df['Temperature (oC)'].describe())
# plt.title('Probability Plot')
# plt.xlabel('Theoretical Quantiles')
# plt.ylabel('Ordered Values')
# plt.show()
#
# # AFFicher le nuage de point et tracer la droite moyenne
# plt.scatter(df['Total length (mm)'], df['Ucrit (cm/s)'], c=df['Temperature (oC)'], cmap='viridis')
# plt.colorbar(label='Temperature (oC)')
# plt.xlabel('Total length (mm)')
# plt.ylabel('Ucrit (cm/s)')
# plt.title('Scatter plot of Total length vs Ucrit')
#
# x = df['Total length (mm)']
# y = df['Ucrit (cm/s)']
#
# # Faire la moyenne de tous des coordonnées
# x_mean = x.mean()
# y_mean = y.mean()
# # # Tracer la droite qui passe par ce point et par l'origine du repere
# plt.scatter(x_mean, y_mean, color='orange', label='Line through mean and origin')
# # calculer le coef directeur de la droitre
# slope = y_mean / x_mean
# print(slope)
#
# plt.plot(x, slope*x, color='red', label='Line through mean and origin')
#
#
# # plot point
# # plt.plot(x_mean, y_mean, color='red', label='Mean')
#
# # print(x, y)
# # np array from x and y
#
# # Tracer la droite de régression
# # plt.plot(x, trendline, color='orange', label='Linear Regression')
#
# plt.legend()
# #
# plt.show()