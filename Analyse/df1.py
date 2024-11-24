# import pandas as pd
# import matplotlib.pyplot as plt
# import numpy as np
#
# # # Lire le fichier CSV
# # df = pd.read_csv("datas/fish_data_wheight_length_ration.csv")
# # # df['ratio'] = df['weight'] / df['length']
# # # Afficher le DataFrame
# # print(df)
# #
# # # # Créer un nuage de points
# # plt.scatter(df['length'], df['weight'], c=df['w_l_ratio'], cmap='viridis')
# # plt.colorbar(label='Weight/Length Ratio')
# # # plt.scatter(df['length'], df['weight'])
# # plt.xlabel('Length')
# # plt.ylabel('Weight')
# # plt.title('Scatter plot of Length vs Weight')
# # plt.show()
#
# df = pd.read_csv("datas/Ucrit_data_Iberian_Peninsula.csv", sep=';')
# print(df)
# plt.scatter(df['Total length (mm)'], df['Ucrit (cm/s)'], c=df['Temperature (oC)'], cmap='viridis')
# plt.colorbar(label='Weight/Length Ratio')
# plt.xlabel('Total length (mm)')
# plt.ylabel('Ucrit (cm/s)')
# plt.show()
