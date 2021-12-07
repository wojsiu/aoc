

depths = []

with open("depths") as depthsF:
    for depth in depthsF:
        depths.append(int(depth))

counter = -1
previous = 0

i = 0


for depth in depths:
    suma = 0
    for j in range (0, 3):
        if j+i < len(depths):
            suma += depths[j+i]
    if suma > previous:
        counter += 1
    previous = suma
    i += 1


print(counter)