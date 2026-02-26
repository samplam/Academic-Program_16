""" This Python program creates a list comprehension of 1000 odd integers with an integrated IF condition. The list is then
displayed in a table format with 10 elements per line. """

import time

# Start performance measurement of the processing.
debut = time.perf_counter()

# Create the list.
liste = [i for i in range(2000) if i%2 != 0]

# Display the list.
ligne = ""
separateur = "-" * 71
print(separateur)
for i in range(0, len(liste)):
    if liste[i] < 10:
        espacement = '    |'
    elif 10 <= liste[i] < 100:
        espacement = '   |'
    elif 100 <= liste[i] < 1000:
        espacement = '  |'
    else:
        espacement = ' |'
    ligne += " " + str(liste[i]) + espacement
    if (i+1)%10 == 0:
        print(f"|{ligne}")
        ligne = ""
        print(separateur)

# End performance measurement and display the result.
fin = time.perf_counter()
print(f"Temps de traitement : {fin - debut:.6f} secondes")